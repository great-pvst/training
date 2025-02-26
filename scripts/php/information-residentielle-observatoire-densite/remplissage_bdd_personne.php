<?php 
	$database = "db_name";
	$username = "username";
	$password = "password";
	$servername ="mysql_serv";
	$row = 1;
	
	if (($handle = fopen("donnees.csv", "r")) !== FALSE) {
		// Create connection
    	$connection = mysqli_connect($servername, $username, $password, $database);
    	// Check connection
      if (!$connection) {
        die("Échec de la connexion : " . mysqli_connect_error());
      }
   	echo "Connexion réussie";
   	while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
   		$requetesql = "INSERT INTO personne VALUES (NULL, '$data[0]', '$data[1]', '$data[2]','$data[3]','$data[4]','$data[5]','$data[6]','$data[7]','$data[8]')";
    		if (mysqli_query($connection, $requetesql)) {
        		echo "Nouvel enregistrement créé avec succès";
    		} else {
        		die ("Erreur : " . $requetesql . "<br>" . mysqli_error($connection));
    		}	   	
        $row++;
    	}
    	mysqli_close($connection);
   fclose($handle);
}
?>