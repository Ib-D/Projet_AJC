#!/usr/bin/env python3

from json import dumps
import requests

# url = "https://opendata.paris.fr/api/records/1.0/search/?dataset=velib-disponibilite-en-temps-reel&q=&facet=name&facet=is_installed&facet=is_renting&facet=is_returning&facet=nom_arrondissement_communes"    Api Vélib


#url = "https://opendata.paris.fr/api/records/1.0/search/?dataset=ascenseurs-escalators-tele-surveillance-temps-reel&q=&rows=28&sort=statut&facet=equipement&facet=arrondissement&facet=heure_ouverture&facet=statut"

#url = "https://opendata.paris.fr/api/records/1.0/search/?dataset=ascenseurs-escalators-tele-surveillance-temps-reel&q=&rows=16&sort=statut&facet=equipement&facet=arrondissement&facet=heure_ouverture&facet=statut"


url = "https://opendata.paris.fr/api/records/1.0/search/?dataset=comptages-routiers-permanents&q=&rows=3000&sort=t_1h&facet=libelle&facet=t_1h&facet=etat_trafic&facet=libelle_nd_amont&facet=libelle_nd_aval"   # Comptage Routier

reponse = requests.get(url)
print(reponse)

contenu_txt = reponse.text
print(type(contenu_txt))

contenu = reponse.json()
print(type(contenu))


print(dumps(contenu))

f= open("apiCreation3.json","w")

f.write(dumps(contenu))

