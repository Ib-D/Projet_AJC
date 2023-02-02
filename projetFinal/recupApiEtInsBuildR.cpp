
#include <iostream>
#include <string>
#include <cstdio>
#include <sqlite3.h>
#include <fstream>
#include </usr/include/jsoncpp/json/json.h>
#include <stdio.h>




 
using namespace std;

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
	// this will contain complete JSON data
	Json::Value obj;
	// reader reads the data and stores it in completeJsonData
	reader.parse(file, obj);
	// complete JSON data
	//cout << "Complete JSON data: " << endl << completeJsonData << endl;
	// get the value associated with name key

	//string str = string(obj["parameters"]["dataset"].asString());
	//str = "\'" + str + "\'";
 
 	int x = 3000;
		
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
	
	
	
   
    sqlite3* DB;
    char* messaggeError;
    //int exit = sqlite3_open("/home/ajc/developpement/SQLITE/test3", &DB);
    int exit = sqlite3_open("/home/ajc/developpement/linuxEmbarque/buildroot-2022.11/Ajout/overlay/projetFinal/comptageRoutier2", &DB);
    string query = "SELECT * FROM comptageRoutier WHERE id=10;";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    
   //cout <<"Last name: " << obj["parameters"]["facet"][1].asString() <<endl;
   /*
   string param1 = obj["nhits"].asString();
   string param2 = obj["records"][0]["recordid"].asString(); 
   string param3 = obj["parameters"]["facet"][1].asString();   
   string param4 = obj["records"][0]["fields"]["duedate"].asString();  
   
    

   //cout <<"First name: " << f <<endl;
   // return 1;

   //param2 = "\'" + param2 + "\'";
   //param3 = "\'" + param3 + "\'";
   string paramm3 = "\'" + param3 + "\'";
   param4 = "\'" + param4 + "\'";

   
   cout <<"Last name: " << paramm3 <<endl;
   
   */
    
 
   // cout << "STATE OF TABLE BEFORE INSERT" << endl;
 
    // sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    
   // string nom = "\'FALL\'";
   
   string nom = "\'DURANT\'";
    
   // string myquery = "INSERT INTO utilisateur (id,nom,prenom,email,date_naissance,pays,ville,code_postal,nombre_achat) VALUES(8,'FALL', 'Moussa', 'toto@gmail.com','10/04/2000','Egypte','Dakar','9999',95);";
 
     
    // string myquery = "INSERT INTO utilisateur2 (nom,prenom,email,date_naissance,pays,ville,code_postal,nombre_achat) VALUES(" + str + ", 'Issa', 'toto@gmail.com','10/04/2000','Cameroun'," + nom + ",'7777'," + nom + ");";
    


    
    for (int i=0; i<x; i++)
	{
     
	  string myquery = "INSERT INTO comptageRoutier (identifiant,libelle,horodatage,debitHoraire,tauxOccupation,etatTrafic,etatArc,libelleAmont,libelleAval) VALUES(" + str1[i] + "," + str2[i] + "," + str3[i] + "," + str4[i] + "," + str5[i] + "," + str6[i] + ","+ str7[i] + "," + str8[i] + ","+ str9[i] + ");";
     
     cout << myquery <<endl;
    string sql(myquery);
 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
	cerr << "Error Insert" << endl;
	sqlite3_free(messaggeError);
    }
    else
	cout << "Records created Successfully!" << endl;
 
    cout << "STATE OF TABLE AFTER INSERT" << endl;
 
   // sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
 
   /*
    sql = "DELETE FROM utilisateur WHERE id >= 6 AND id <=8;";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
	cerr << "Error DELETE" << endl;
	sqlite3_free(messaggeError);
    }
    else
	cout << "Record deleted Successfully!" << endl;
 
    cout << "STATE OF TABLE AFTER DELETE OF ELEMENT" << endl;
    
   */ 
    //sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
 
 }
 
    sqlite3_close(DB);
    
    cout << "Fin quemu..." <<endl;
    return (0);
    
}

/*
	"id"	INTEGER NOT NULL UNIQUE,
	"identifiant"	TEXT,
	"libelle"	TEXT,
	"horodatage"	TEXT,
	"debitHoraire"	NUMERIC,
	"tauxOccupation"	NUMERIC,
	"etatTrafic"	TEXT,
	"etatArc"	TEXT,
	"libelleAmont"	TEXT,
	"libelleAval"	TEXT,

*/





