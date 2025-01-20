#!/bin/bash
#resultat=0
if [ -z $1 ]; then
	echo Vide
else
#	resultat=`expr $resultat * $1`
#	$1 `expr $1 - 1`
	resultat=`expr $1 - 1`
	expr $1 * `./$0 $resultat`
fi


#bash -x script (pour voir le traitement ligne par ligne
