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
#include <math.h> /*on va utiliser la police gdFontGiant */

using namespace std;
/* Théoriquement il faut inclure stdio.h
   MAIS c'est fait dans gd.h donc ... */
int main(void) {


   // Récup file
    string line;
    int k=0;

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

    int size;
    int somme = 0;
    int moyenne;
    int nbPoint=6300;

    int comptFluide=0;
    for (int i=0; i<nbPoint; i++)    // nombre de fois qu'une données est etudiées
    {
     // size = lines[i*10 + 4].size();
     // char recupStr[3];
        if (lines[i*10 + 6] == "etatTrafic : Fluide")  // on ne prend pas les champs vides (débit horaires)
        {
        comptFluide++;
        }
     }
      cout <<"NbFluide = "<<comptFluide<<endl;

    int comptInconnu=0;
    for (int i=0; i<nbPoint; i++)    // nombre de fois qu'une données est etudiées
    {
     // size = lines[i*10 + 4].size();
     // char recupStr[3];
        if (lines[i*10 + 6] == "etatTrafic : Inconnu")  // on ne prend pas les champs vides (débit horaires)
        {
        comptInconnu++;
        }
     }
      cout <<"NbInconnu = "<<comptInconnu<<endl;


    int comptPresat=0;
    for (int i=0; i<nbPoint; i++)    // nombre de fois qu'une données est etudiées
    {
     // size = lines[i*10 + 4].size();
     // char recupStr[3];
        if (lines[i*10 + 6] == "etatTrafic : Pré-saturé")  // on ne prend pas les champs vides (débit horaires)
        {
        comptPresat++;
        }
     }
      cout <<"NbPresaturé = "<<comptPresat<<endl;


    int comptSatur=0;
    for (int i=0; i<nbPoint; i++)    // nombre de fois qu'une données est etudiées
    {
     // size = lines[i*10 + 4].size();
     // char recupStr[3];
        if (lines[i*10 + 6] == "etatTrafic : Saturé")  // on ne prend pas les champs vides (débit horaires)
        {
        comptSatur++;
        }
     }
      cout <<"NbSaturé = "<<comptSatur<<endl;


/*
    for (int i=0; i<nbPoint; i++)    // nombre de fois qu'une données est etudiées
    {
     // size = lines[i*10 + 4].size();
     // char recupStr[3];
        if (size > 16)  // on ne prend pas les champs vides (débit horaires)
        {
      for (int j=0; j<3; j++)
      {

          recupStr[j] = lines[i*10 + 4][size -3+j];
      }
       //  cout <<"taille : "<<size<<endl;
             cout <<"recup = " << recupStr<<endl;
             somme += stoi(recupStr);
        }


     } */

    // cout << "somme = "<<somme<<endl;
    // moyenne = somme / 3 ;

    gdImagePtr image; /* Pointeur vers notre image */
      gdFontPtr mesPolices[5]; /* tableau des polices */
      FILE *image_png; /* Fichier image PNG */

      //string query = "TATA FO JE SUIS AU TRAVAIL";
      string jeuDonnees = "";




  int rouge, blanc, noir, bleu; /* Deux couleurs */
  /* On créée un image de 100 par 100 */
  image = gdImageCreate(1500, 1000);
  /*
   * On "alloue" deux couleurs.
   * Notez que la première sera la couleur de fond
   *
   * En paramètres : - l'image
   *                 - les valeurs de rouge, vert et bleu (de 0 à 255)
   */
  blanc = gdImageColorAllocate(image, 255, 255, 255);
  rouge = gdImageColorAllocate(image, 255, 0, 0);
  noir = gdImageColorAllocate(image, 0, 0, 0);
  /*
   * On trace la croix, deux rectangles pleins qui se croisent
   * le premier de x=20,y=45 à x=80,y=55
   * le second de x=45,y=20 à x=55,y=80
   * tous les deux de couleurs rouge.
   */
 // gdImageFilledRectangle(image, 20, 45, 80, 55, rouge);


      mesPolices[0] = gdFontTiny;
      mesPolices[1] = gdFontSmall;
      mesPolices[2] = gdFontMediumBold;
      mesPolices[3] = gdFontLarge;
      mesPolices[4] = gdFontGiant;

  int tmp_larg, larg = 0, haut = 80; /* Dimension de l'image */
  int posx = 15, posy = 15; /* Position du texte */
  int long_message;
 //   unsigned char message[] ="TOTO";


 //  long_message = sizeof (message);
      /* On calcule les dimensions de l'image */
     // for (i=0 ; i<2 ; i++) {

     /*
        haut += mesPolices[4]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[4]->w + 20 )
                        ) ? tmp_larg : larg;
    */
      // image = gdImageCreate(larg, haut);


  //    }
      /* On créée un image de larg par haut */
      /* On alloue deux couleurs. */
      int hFluide =800 - round(comptFluide*600/3000);
      int hInconnu =800 - round(comptInconnu*600/3000);
      int hPresat =800 - round(comptPresat*600/3000);
      int hSat =800 - round(comptSatur*600/3000);

      blanc = gdImageColorAllocate(image, 255, 255, 255);
      bleu = gdImageColorAllocate(image, 0, 0, 88);
            noir = gdImageColorAllocate(image, 0, 0, 0);
      /*
       * On écrit le texte avec les cinq polices en bleu.
       * On remet à jour la hauteur
       */
  //    for (i=0 ; i<2 ; i++) {
        posy += mesPolices[4]->h;
       
       string trafic ="ETAT GENERAL DU TRAFIC DE LA JOURNEE DU ";
       string trafic2="          ";
           string trafic3;  
       unsigned char tt[trafic3.size()];
       for (int i=0; i<10; i++)
       {
          trafic2[i] = lines[k-7][13+i];
          cout<<lines[k-7][13+i]<<endl;
       }
       
       // =trafic + lines[k-7];
              cout<<trafic2<<endl;
       trafic3 = trafic + trafic2;
       cout << trafic3<<endl;
       unsigned char titre[trafic3.size()];
       for (int i=0; i<trafic3.size(); i++)
       {
          tt[i] = trafic3[i];
       }
       
     cout << tt <<endl;
      // cout<<lines[k-7]<<endl;
     //  titre[43]='T';
       //       titre[44]='T';
              /*
       for (int i=0; i<10; i++)
       {
          titre[42+i] = lines[k-7][13+i];
       }*/
       
       float ss = 14.0/3;
   string s = to_string(ss);         
       cout <<"valeur = "<<s<<endl;

              unsigned char fluide[] ="trafic fluide";
                     unsigned char inconnu[] ="trafic inconnu";
                            unsigned char prest[] ="trafic presature";
                            unsigned char sature[] ="trafic sature";
                            
   float pourcFluide = (comptFluide*100.0)/(comptFluide + comptInconnu + comptPresat + comptSatur);
   float pourcInconnu = (comptInconnu*100.0)/(comptFluide + comptInconnu + comptPresat + comptSatur);
   float pourcPresat = (comptPresat*100.0)/(comptFluide + comptInconnu + comptPresat + comptSatur);
   float pourcSatur = (comptSatur*100.0)/(comptFluide + comptInconnu + comptPresat + comptSatur); 
   
   string pF = to_string(pourcFluide);         
      string pI = to_string(pourcInconnu);         
         string pP = to_string(pourcPresat);         
            string pS = to_string(pourcSatur);
            
      string pFF="     ";
      string pII="     ";
      string pPP="     ";
      string pSS ="     ";         
      for (int i=0; i<5; i++)        
       {     
           pFF[i] = pF[i];
           pII[i] = pI[i];
           pPP[i] = pP[i];
           pSS[i] = pS[i];         
       }     
        cout <<"test : "<< pFF <<endl;   
                cout <<"test : "<< pPP <<endl;   
            
   string pF2 = pFF + " %";  
      string pI2 = pII + " %";  
         string pP2 = pPP + " %";  
            string pS2 = pSS + " %";  
  unsigned char pFstr [8];          
    unsigned char pIstr [8];          
      unsigned char pPstr [8];          
        unsigned char pSstr [8];
        
        for (int i=0; i<8; i++)
       {
            pFstr [i] = pF2[i];          
    	 pIstr [i] = pI2[i];          
     	 pPstr [i] = pP2[i];          
        pSstr [i] = pS2[i];
       }
        
                  
    cout << pF <<endl;              
        cout << pI <<endl;              
            cout << pP <<endl;              
                cout << pS <<endl;              
   
	gdImageFilledRectangle(image, 200, hFluide, 250, 800, noir);
	gdImageFilledRectangle(image, 400, hInconnu, 450, 800, noir);
	gdImageFilledRectangle(image, 600, hPresat, 650, 800, noir);
	gdImageFilledRectangle(image, 800, hSat, 850, 800, noir);
	gdImageString(image, mesPolices[4], 300, 70, tt, noir);
	gdImageString(image, mesPolices[4], 100, 800, fluide, noir);
	gdImageString(image, mesPolices[4], 300, 800, inconnu, noir);
	gdImageString(image, mesPolices[4], 500, 800, prest, noir);
	gdImageString(image, mesPolices[4], 700, 800, sature, noir);

	gdImageString(image, mesPolices[4], 130, 700, pFstr, noir);
	gdImageString(image, mesPolices[4], 330, 700, pIstr, noir);
	gdImageString(image, mesPolices[4], 530, 700, pPstr, noir);
	gdImageString(image, mesPolices[4], 730, 700, pSstr, noir);
        
 // gdImageString(image, mesPolices[4], 20, 50, line34, noir);
  /* Ouvrir le fichier image en écriture. */
  image_png = fopen("../root/HistogrmJournee.png", "w");
 //   image_png = fopen("Histogrm.png", "w");
  /* Créer l'image au format PNG. */
  gdImagePng(image, image_png);
  /* On ferme le fichier de l'image. */
  fclose(image_png);
  /* On détruit l'image. */
  gdImageDestroy(image);
  exit (0);
}

