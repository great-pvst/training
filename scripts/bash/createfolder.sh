#!/bin/bash

# another way to create folders
if [ $# -eq 0 ]; then
	nbfolders=0
	echo "Combien de dossiers souhaitez-vous créer ?"
	read nbfolders
	
	until ((1 > $nbfolders))
	do
		read -p "Nom du dossier ? " name
		mkdir "$name"
		nbfolders=$(($nbfolders - 1))
	done
	echo "Les dossiers ont été créés"
else
	echo "Le script n'est pas exécuté"

fi
