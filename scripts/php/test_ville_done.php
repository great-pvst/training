<!DOCTYPE html>
<html>
<head>
	<title>Liste déroulante et base de données</title>
</head>
<body>

<?php
// Connexion à la base de données
$connexion_bdd = mysqli_connect("mysql_serv", "username", "password", "db_name");

// Vérification de la connexion
if (!$connexion_bdd) {
    die("Connection failed: " . mysqli_connect_error());
}

// Requête pour extraire les noms de la base de données
$requete_sql = "SELECT nom FROM ville";
$resultat = mysqli_query($connexion_bdd, $requete_sql);

// Création de la liste déroulante
echo "<form method='post'>";
echo "<select name='nom'>";
while ($row = mysqli_fetch_array($resultat)) {
    echo "<option value='" . $row['nom'] . "' >" . $row['nom'] . "</option>";
}
echo "</select>";
echo "<input type='submit' value='Afficher les informations'>";
echo "</form>";

// Affichage des informations correspondantes
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $nom = $_POST['nom'];
    //$prenom = $_POST['prenom'];
    $requete_sql_ = "SELECT * FROM ville WHERE nom='$nom'";
    $resultat_ = mysqli_query($connexion_bdd, $requete_sql_);
    while ($row = mysqli_fetch_array($resultat_)) {
    	echo "Nom : " . $row['nom'] . "<br>";
    	echo "Surface (km2) : " . $row['surface'] . "<br>";
    	echo "Densité : " . $row['densite'] . "<br>";
    	/*echo "Prenom : " . $row['prenom'] . "<br>";
    	echo "Ville principale : " . $row['villeP'] . "<br>";
    	echo "Ville secondaire : " . $row['villeS'] . "<br>";
    	echo "Adresse principale : " . $row['adresseP'] . "<br>";
    	echo "Adresse secondaire: " . $row['adresseS'] . "<br>";
    	echo "Date début : " . $row['dateD'] . "<br>";
    	echo "Date fin : " . $row['dateF'] . "<br>";
    	echo "Groupe : " . $row['groupe'] . "<br>"; 
    	//echo "Nom : " . $row['nom'] . "<br>";
     */ //echo "Nom : " . $_POST['nom'] . "<br>";

        
  }
}

// Fermeture de la connexion à la base de données
mysqli_close($connexion_bdd);
?>

</body>
</html>