#include <stdlib.h> /* Y'en aura bien besoin (pour le exit) */
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <gd.h> /* On va utiliser gd */
/* Théoriquement il faut inclure stdio.h
   MAIS c'est fait dans gd.h donc ... */
#include <gdfontt.h> /*on va utiliser la police gdFontTiny */
#include <gdfonts.h> /*on va utiliser la police gdFontSmall */
#include <gdfontmb.h> /*on va utiliser la police gdFontMediumBold */
#include <gdfontl.h> /*on va utiliser la police gdFontLarge */
#include <gdfontg.h> /*on va utiliser la police gdFontGiant */
using namespace std;
int main(void) {




    string line;
    int k=0; //nombre de lignes

      ifstream myfile ("resultatRequete.txt");

      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
         // cout << line << '\n';
          k++;
        }
        myfile.close();
      }
     // cout <<i<<endl;

      string lines[k];
      //string ll;
        ifstream myfiles ("resultatRequete.txt");
        int j = 0;
        if (myfiles.is_open())
        {
          while ( getline (myfiles,line) )
          {
            lines[j] = line;
           // cout << lines[j] << '\n';
            j++;

          }
          myfiles.close();
        }





    gdImagePtr image; /* Pointeur vers notre image */
      gdFontPtr mesPolices[5]; /* tableau des polices */
      FILE *image_png; /* Fichier image PNG */
      int blanc, bleu, noir; /* Nos deux couleurs */
      //string query = "TATA FO JE SUIS AU TRAVAIL";
     // string jeuDonnees = "";
 string jeuDonnees[k] = {};    // -> accessible
    //  string str ="rjrj";
     // str.size();

  int taille[3];    // -> accessible


//for (int g=0; g<3; g++)
//{
  for (int j=0; j<k; j++)
  {
      for (int i=0; i<7; i++)
      {
          jeuDonnees[j] += lines[10*j+i] + " | ";
      }

     // taille[j] = jeuDonnees[j].size();
      taille[j] = jeuDonnees[j].size();

     // cout<<taille[j]<<endl;
         cout<<jeuDonnees[j]<<endl;
  }
    // strings récupéres
   //      cout<<jeuDonnees[0]<<endl;
    //     cout<<jeuDonnees[1]<<endl;

}
