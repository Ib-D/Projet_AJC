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
     return 0;
}
/**
 * @brief main -> programme permettant l'affichage des 9000 derniers enregistrements, en vue de les mettre dans un fichier .txt
 */
int main(int argc, char** argv)
{

   ifstream file("/home/ajc/developpement/linuxEmbarque/buildroot-2022.11/Ajout/overlay/projetFinal/apiCreation3.json");

   /**
     * @brief affichage des 9000 derniers enregistrements, en vue de les mettre dans un fichier .txt
     */
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("/home/ajc/developpement/linuxEmbarque/buildroot-2022.11/Ajout/overlay/projetFinal/comptageRoutier2", &DB);
    string query = "SELECT * FROM comptageRoutier WHERE id <= ((SELECT count(identifiant) FROM comptageRoutier) -0) AND id >= ((SELECT count(identifiant) FROM comptageRoutier) -9000);";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return (0);
    
}












