#!/bin/sh

res=$(tail -n1 /tmp/compteur.txt)

x=$(($res+1))

echo $x >> /tmp/compteur.txt
#echo "Le resultat est : $res"
#echo "Le resultat incremente : $x"
