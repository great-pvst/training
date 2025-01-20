<!DOCTYPE html>

<html lang="fr">

<head>
	<title> Mesures des capteurs </title>
	<script src="jquery.min.js"></script>
	<script src="highcharts.js"></script>
	<script src="exporting.js"></script>
</head>

<body>
<?php
	echo "byGabin&Ardy <br>";
	$base = mysqli_connect('Localhost', 'pi', 'GabinArdyAG23.', 'BD_SAE301');
	$requete=mysqli_query($base, "SELECT Temp, Vsolaire, Pconso FROM Mesures");

	$nbE = mysqli_num_rows($requete);
	$i = 0;

	// Choix des champs de table
	while ($row = mysqli_fetch_array($requete)) // pour toutes valeurs de la requete
		{
			$varTemp[] = array($row['Temp']/100); // Temp = nom de champ dans BD
			$varPanneauSolaire[] = array($row['Vsolaire']/100);
			$varPuissanceConso[] = array($row['Pconso']/1000);
		}
	$Tab0 = [];
	$Tab1 = [];
	$Tab2 = [];
        for($i = 0; $i < 30; $i++)
		{
			$Tab0[$i] = $varTemp[$nbE - 30 + $i];
			$Tab1[$i] = $varPanneauSolaire[$nbE - 30 + $i];
			$Tab2[$i] = $varPuissanceConso[$nbE - 30 + $i];
                	echo "<br>[".( $nbE + $i + 1)."]. ".json_encode($Tab0[$i]);
			echo json_encode($Tab1[$i]);
			echo json_encode($Tab2[$i]);
		}


	//$varTemp = array(18.91, 19.21, 18.81);
	$Tab0 = json_encode($Tab0, JSON_NUMERIC_CHECK);
	//echo $varTemp;
        //$varPanneauSolaire = array(3.61, 1.81, 2.51);
	//foreach ($varPanneauSolaire as &$val)
	//	{ $val = $val *10; }
        $Tab1 = json_encode($Tab1, JSON_NUMERIC_CHECK);
        //echo $varPanneauSolaire;
	//$varPuissanceConso = array(3000, 1900, 2600);
	//foreach ($varPuissanceConso as &$val)
	//	{ $val = $val/1000; }
        $Tab2 = json_encode($Tab2, JSON_NUMERIC_CHECK);
        //echo $varPuissanceConso;

	mysqli_free_result($requete);
	mysqli_close($base);
?>

	<script type="text/javascript">
	$(function() {
		$('#conteneur').highcharts ({
			chart: { type: 'column'},
			title: { text: 'Premier essai' },
			xAxis: { categories: [ 'Jan', 'Fev', 'Mar' ] },
			yAxis: { min: 0, title: { text: 'Axe Y' } },
			series: [{ name:'Temp', data: <?php echo $Tab0; ?>},
				{ name : 'Psolaire', data: <?php echo $Tab1; ?>},
				{ name: 'Pconso', data: <?php echo $Tab2; ?>}
				]
			});
		});
	</script>
	<div id="conteneur" style="margin: 0pt auto; min-width: 800px; height: 500px;"></div>
</body>
</html>
