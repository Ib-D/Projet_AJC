#!/usr/bin/env python3

from json import dumps
import requests


url = "https://opendata.paris.fr/api/records/1.0/search/?dataset=comptages-routiers-permanents&q=&rows=10000&sort=t_1h&facet=libelle&facet=t_1h&facet=etat_trafic&facet=libelle_nd_amont&facet=libelle_nd_aval"   # Comptage Routier 10.000 par jour

reponse = requests.get(url)
print(reponse)

contenu_txt = reponse.text
print(type(contenu_txt))

contenu = reponse.json()
print(type(contenu))


print(dumps(contenu))

f= open("apiCreation3.json","w")

f.write(dumps(contenu))

