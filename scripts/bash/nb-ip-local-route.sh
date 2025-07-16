#!/bin/bash

req=`snmpwalk -v 1 -c public 192.168.33.16 1.3.6.1.2.1.4.21.1.8 | cut -d ":" -f 4`
nbroute=0

# direct link is represented by '3' (string) 
for i in $req
do
	if [ "$i" == "3" ]; then
		nbroute=`expr $nbroute + 1`
	fi
done

echo $nbroute
