#!/bin/sh

cpt = `cat /tmp/compteur.txt`

cpt = `expr $cpt + 1`
echo "compteur = $cpt"

echo $cpt > /tmp/compteur.txt
