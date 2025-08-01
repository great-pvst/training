#!/bin/bash

# Définir la date limite (6 mois en arrière)
date_limite=$(date -d "6 months ago" +"%Y-%m-%d")

# Récupérer la liste des utilisateurs et de leurs dates de création
liste_utilisateurs=$(awk -F: '$3 >= 1000 {print $1,$3}' /etc/passwd)

# Parcourir la liste des utilisateurs
while read -r utilisateur uid; do
  # Récupérer la date de création de l'utilisateur
  date_creation=$(chage -l $utilisateur | grep "Last password change" | awk '{print $4}')

  # Convertir la date au format YYYY-MM-DD
  date_creation=$(date -d "$date_creation" +"%Y-%m-%d")

  # Comparer la date de création avec la date limite
  if [[ $date_creation < $date_limite ]]; then
    # Supprimer l'utilisateur
    userdel -r $utilisateur
    echo "Utilisateur $utilisateur supprimé."
  fi
done <<< "$liste_utilisateurs"