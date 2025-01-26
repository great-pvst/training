<!DOCTYPE html>
<html>
<head>
	<title>Liste déroulante et base de données</title>
	<link href="style/style.css" rel="stylesheet">
	<link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Manrope&display=swap" rel="stylesheet">    
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Montserrat&display=swap" rel="stylesheet"> 
</head>
<body>
<header>
<h1>Bienvenue sur l'annuaire des étudiants de R&T</h1>
</header>

<main>
<section>
		Ce site répertorie les informations des étudiants du département 
		Réseaux & Télécoms et leur lieu de résidence principale, et secondaire 
		s'il y en a.
	<div class="container1">
		<?php
		// Connexion à la base de données
		$connexion_bdd = mysqli_connect("mysql_serv", "username", "password", "db_name");
		// Vérification de la connexion
		if (!$connexion_bdd) {
    	die("Connection failed: " . mysqli_connect_error());
		}
		// Requête pour extraire les noms de la base de données
		$requete_sql = "SELECT nom FROM personne";
		$resultat = mysqli_query($connexion_bdd, $requete_sql);
		// Création de la liste déroulante
		echo "<form method='post'>";
		echo "Nom : <select name='nom' require><option disabled selected>Veuillez sélectionner un nom</option><br>";
		while ($row = mysqli_fetch_array($resultat)) {
    		echo "<option value='" . $row['nom'] . "' >" . $row['nom'] . "</option>";
		}
		echo "</select>";
		echo "<br><br>";
		echo "<input type='submit' value='Afficher les informations'>";
		echo "</form>";
		?>
	</div>

	<div class="container2">
		<?php
		// Affichage des informations correspondantes au nom

		//echo "<main>";
		$faible = 'faible';
		$moyen = 'moyenne';
		$fort = 'forte';
		if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    		$nom = $_POST['nom'];
    		$requete_sql_ = "SELECT * FROM personne, ville WHERE personne.villeP=ville.nom_ville AND nom='$nom'"; // OR personne.villeS=ville.nom_ville' 
    		$resultat_ = mysqli_query($connexion_bdd, $requete_sql_);
    		while ($row = mysqli_fetch_array($resultat_)) {
    			echo "Nom : " . $row['nom'] . "<br>";
    			echo "Prenom : " . $row['prenom'] . "<br>";
    			echo "Ville principale : " . $row['villeP'] . "<br>";
    			if($row['densite'] > 200) {
    				echo "Densité : " . $row['densite'] . " hab/km2 (".$fort.") <br>";
					} elseif($row['densite'] < 200 && $row['densite'] > 100) {
						echo "Densité : " . $row['densite'] . " hab/km2 (".$moyen.") <br>";
						} else {
							echo "Densité : " . $row['densite'] . " hab/km2 (".$faible.") <br>";
						}
    			echo "Surface : " . $row['surface'] . " km2<br>";
    			echo "Adresse principale : " . $row['adresseP'] . "<br>";
    			// check de la ville secondaire
    			if($row['villeS']= !NULL) {
    				if($_SERVER['REQUEST_METHOD'] == 'POST') {
    					$nom = $_POST['nom'];
    					$requete_sql_2 = "SELECT * FROM personne, ville WHERE personne.villeS=ville.nom_ville AND nom='$nom'"; // OR personne.villeS=ville.nom_ville 
    					$resultat_2 = mysqli_query($connexion_bdd, $requete_sql_2);
    					while($row2 = mysqli_fetch_array($resultat_2)) {
    						echo "Ville secondaire : " . $row2['villeS'] . "<br>";
    						if($row2['densite'] > 200) {
    							echo "Densité : " . $row2['densite'] . " hab/km2 (".$fort.") <br>";
								} elseif($row2['densite'] < 200 && $row2['densite'] > 100) {
									echo "Densité : " . $row2['densite'] . " hab/km2 (".$moyen.") <br>";
									} else {
										echo "Densité : " . $row2['densite'] . " hab/km2 (".$faible.") <br>";
									}
    						echo "Surface : " . $row2['surface'] . " km2<br>";
    						echo "Adresse secondaire : " . $row2['adresseS'] . "<br>";
    				}
    			}
    		}
    			echo "Date début : " . $row['dateD'] . "<br>";
    			echo "Date fin : " . $row['dateF'] . "<br>";
    			echo "Groupe : " . $row['groupe'] . "<br>";   
  		}
		}
		// Fermeture de la connexion à la base de données
		mysqli_close($connexion_bdd);
		//echo "</main>";
		?>
	</div>
</section>
<footer> A Bientôt ! </footer>
</main>
</body>
</html>