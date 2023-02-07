
#include <iostream>
#include <string>
#include <cstdio>
#include </usr/include/sqlite3.h>
#include <fstream>
#include <stdio.h>




 
using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
    fprintf(stderr, "%s: ", (const char*)data);
 
    for (int i = 0; i < argc; i++) {
	printf("%s : %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
 
    //printf("\n");
    return 0;
}

int main(int argc, char** argv)
{

	ifstream file("/home/ajc/developpement/linuxEmbarque/buildroot-2022.11/Ajout/overlay/projetFinal/apiCreation3.json");

   
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("/home/ajc/developpement/linuxEmbarque/buildroot-2022.11/Ajout/overlay/projetFinal/comptageRoutier2", &DB);
    string query = "SELECT * FROM comptageRoutier WHERE id <= ((SELECT count(identifiant) FROM comptageRoutier) -0) AND id >= ((SELECT count(identifiant) FROM comptageRoutier) -9000);";
 //   string query2 = "SELECT horodatage, debitHoraire FROM comptageRoutier WHERE id <= ((SELECT count(id) FROM comptageRoutier) + 17 - 1000) AND id >= ((SELECT count(id) FROM comptageRoutier) + 17 - 1000 - 10);";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
  //  sqlite3_exec(DB, query2.c_str(), callback, NULL, NULL);
   
   string nom = "\'DURANT\'";
    
   // string myquery = "INSERT INTO utilisateur (id,nom,prenom,email,date_naissance,pays,ville,code_postal,nombre_achat) VALUES(8,'FALL', 'Moussa', 'toto@gmail.com','10/04/2000','Egypte','Dakar','9999',95);";
 
     
    // string myquery = "INSERT INTO utilisateur2 (nom,prenom,email,date_naissance,pays,ville,code_postal,nombre_achat) VALUES(" + str + ", 'Issa', 'toto@gmail.com','10/04/2000','Cameroun'," + nom + ",'7777'," + nom + ");";
    
 
    sqlite3_close(DB);
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





