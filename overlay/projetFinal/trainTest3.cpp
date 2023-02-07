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
    int k=0;

      ifstream myfile ("donnesRangees.txt");

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
        ifstream myfiles ("donnesRangees.txt");
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
 string jeuDonnees[10] = {};    // -> accessible
    //  string str ="rjrj";
     // str.size();

 int taille[10];    // -> accessible


//for (int g=0; g<3; g++)
//{
   int x;
   unsigned char message[]=""; /* Un message original */


      int long_message; /* La taille du message */
      int tmp_larg, larg = 0, haut = 40; /* Dimension de l'image */
      int posx = 10, posy = 10; /* Position du texte */
      int i; /* Ca ressemble à une variable pour une boucle for ;-) */
      /* on remplit le tableau */
      mesPolices[0] = gdFontTiny;
      mesPolices[1] = gdFontSmall;
      mesPolices[2] = gdFontMediumBold;
      mesPolices[3] = gdFontLarge;
      mesPolices[4] = gdFontGiant;


   
//  for (int j=0; j<10; j++)
//  {
      j=2;
      taille[j] = lines[j].size();

      cout<<taille[j]<<endl;
      cout<<lines[j]<<endl;
      x=taille[j];
      for (int i=0; i<taille[j]; i++)
      {
      	message[i] = (char)lines[j][i];
      }
	 cout<<message<<endl;
	 

      /* On calcule la longueur du message */
     // long_message = sizeof(mess5[0]);
      long_message = taille[j];
      cout<<"taille message = " << long_message<<endl;
      /* On calcule les dimensions de l'image */


     // for (i=0 ; i<2 ; i++) {
        haut += mesPolices[4]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[3]->w + 20 )
                        ) ? tmp_larg : larg;
     // }



      /*
        haut += mesPolices[4]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[4]->w + 20 )
                        ) ? tmp_larg : larg;
      */

      /* On créée un image de larg par haut */
      image = gdImageCreate(larg, haut);
      /* On alloue deux couleurs. */
      blanc = gdImageColorAllocate(image, 255, 255, 255);
      bleu = gdImageColorAllocate(image, 0, 0, 88);
      noir = gdImageColorAllocate(image, 0, 0, 0);

        posy += mesPolices[4]->h;
        gdImageString(image, mesPolices[3], posx, posy, message, noir);
        
        
                unsigned char mess[10] ={"fgfgfh"};

                haut += mesPolices[4]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[3]->w + 20 )
                        ) ? tmp_larg : larg;
     // }



      /*
        haut += mesPolices[4]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[4]->w + 20 )
                        ) ? tmp_larg : larg;
      */

      /* On créée un image de larg par haut */
      image = gdImageCreate(larg, haut);
      /* On alloue deux couleurs. */
      blanc = gdImageColorAllocate(image, 255, 255, 255);
      bleu = gdImageColorAllocate(image, 0, 0, 88);
      noir = gdImageColorAllocate(image, 0, 0, 0);

        posy += mesPolices[4]->h;
        gdImageString(image, mesPolices[3], posx, posy, mess, noir);
        

        
                        unsigned char mess2[10] ={"tototo"};

                haut += mesPolices[4]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[3]->w + 20 )
                        ) ? tmp_larg : larg;
     // }



      /*
        haut += mesPolices[4]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[4]->w + 20 )
                        ) ? tmp_larg : larg;
      */

      /* On créée un image de larg par haut */
      image = gdImageCreate(larg, haut);
      /* On alloue deux couleurs. */
      blanc = gdImageColorAllocate(image, 255, 255, 255);
      bleu = gdImageColorAllocate(image, 0, 0, 88);
      noir = gdImageColorAllocate(image, 0, 0, 0);

        
                posy += mesPolices[4]->h;
        gdImageString(image, mesPolices[3], posx, posy, mess2, noir);
        
        
        
/*        
        
     j=3;
      taille[j] = lines[j].size();

      cout<<taille[j]<<endl;
      cout<<lines[j]<<endl;
      x=taille[j];
      for (int i=0; i<taille[j]; i++)
      {
      	message[i] = (char)lines[j][i];
      }
	 cout<<message<<endl;
	 


      long_message = taille[j];
      cout<<"taille message = " << long_message<<endl;




        haut += mesPolices[4]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[3]->w + 20 )
                        ) ? tmp_larg : larg;




      image = gdImageCreate(larg, haut);

      blanc = gdImageColorAllocate(image, 255, 255, 255);
      bleu = gdImageColorAllocate(image, 0, 0, 88);
      noir = gdImageColorAllocate(image, 0, 0, 0);

        posy += mesPolices[4]->h;
        gdImageString(image, mesPolices[3], posx, posy, message, noir);
        
        
 */       
        

//  }
  



 // }

       //      posy += mesPolices[4]->h;

        //      gdImageString(image, mesPolices[3], posx, posy, mm, noir);

      /*

        posy += mesPolices[4]->h;
        gdImageString(image, mesPolices[4], posx, posy, message, noir);
      */

      /* Ouvrir le fichier image en écriture. */
      image_png = fopen("Test.png", "w");
      /* Créer l'image au format PNG. */
      gdImagePng(image, image_png);
      /* On ferme le fichier de l'image. */
      fclose(image_png);
      /* On détruit l'image. */
      gdImageDestroy(image);
  


      
      
      

      exit (0);

    return (0);
      



}

   
   

