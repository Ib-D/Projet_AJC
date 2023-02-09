
#include <iostream>
#include <string>
#include <cstdio>
#include <sqlite3.h>
#include <fstream>
#include </usr/include/jsoncpp/json/json.h>
#include <stdio.h>




 
using namespace std;
/**
 * @brief callback -> fonction callback permettant d'afficher la requête effectuée 
 * @param data
 * @param argc
 * @param argv
 * @param azColName
 * @return 
 */

static int callback(void* data, int argc, char** argv, char** azColName)
{
    fprintf(stderr, "%s: ", (const char*)data);
 
    for (int i = 0; i < argc; i++) {
	printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
 
    printf("\n");
    return 0;
}

int main(int argc, char** argv)
{

	ifstream file("/home/ajc/developpement/linuxEmbarque/buildroot-2022.11/Ajout/overlay/projetFinal/apiCreation3.json");
	// json reader
	Json::Reader reader;
	// L'ensemble des données sont contenues dans l'objet obj
	Json::Value obj;
	// reader lit les données et les stocke dans obj
	reader.parse(file, obj);
 
 	int x = 10000;  // nombre de données à injecter dans la base de données
    
    // données à extraire de l'API de comptage routier sur Paris
		string str1[x],str2[x],str3[x],str4[x],str5[x],str6[x],str7[x],str8[x],str9[x];
	for (int i=0; i<x; i++)
	{
		str1[i] = "\'" + string(obj["records"][i]["fields"]["iu_ac"].asString()) + "\'";
		str2[i] = "\'" + string(obj["records"][i]["fields"]["libelle"].asString()) + "\'";
		str3[i] = "\'" + string(obj["records"][i]["fields"]["t_1h"].asString()) + "\'";  // Pb str3[0]
		str4[i] = "\'" + string(obj["records"][i]["fields"]["q"].asString()) + "\'";
		str5[i] = "\'" + string(obj["records"][i]["fields"]["k"].asString()) + "\'";
		str6[i] = "\'" + string(obj["records"][i]["fields"]["etat_trafic"].asString()) + "\'";
		str7[i] = "\'" + string(obj["records"][i]["fields"]["etat_barre"].asString()) + "\'";
		str8[i] = "\'" + string(obj["records"][i]["fields"]["libelle_nd_amont"].asString()) + "\'";
		str9[i] = "\'" + string(obj["records"][i]["fields"]["libelle_nd_aval"].asString()) + "\'";
	}
	
	
	
    /**
     * @brief DB -> base de données à laquelle on veut accéder
     */
    sqlite3* DB;
    char* messaggeError; // message d'erreur en cas de problème 
    int exit = sqlite3_open("/home/ajc/developpement/linuxEmbarque/buildroot-2022.11/Ajout/overlay/projetFinal/comptageRoutier2", &DB);
    string query = "SELECT * FROM comptageRoutier WHERE id=10;";  // exemple de requête -> en guise de test
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); // execution de la requête et affichage grâce à la fonction callback
    
    /*
     * insersion de 10000 données dans la base de données
     */  
    
    for (int i=0; i<x; i++)
	{
     
	string myquery = "INSERT INTO comptageRoutier (identifiant,libelle,horodatage,debitHoraire,tauxOccupation,etatTrafic,etatArc,libelleAmont,libelleAval) VALUES(" + str1[i] + "," + str2[i] + "," + str3[i] + "," + str4[i] + "," + str5[i] + "," + str6[i] + ","+ str7[i] + "," + str8[i] + ","+ str9[i] + ");";
     
    cout << myquery <<endl;
    string sql(myquery);
 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
	cerr << "Erreur d'insersion" << endl;
	sqlite3_free(messaggeError);
    }
    else
	cout << "Réussite de l'insersion!" << endl;
 
    //  cout << "Affichage du résultat de la requête" << endl;
 
    // sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
 
    }
 
    sqlite3_close(DB);
    return (0);
    
}






