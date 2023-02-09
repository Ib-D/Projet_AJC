#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <gd.h>

#include <gdfontt.h>
#include <gdfonts.h>
#include <gdfontmb.h>
#include <gdfontl.h>
#include <gdfontg.h>
#include <math.h>

using namespace std;

/**
 * @brief programme permettant la réalisation d'un histogramme sur une zone précise : Rivoli
 * @return
 */
int main(void) {


   /*
    * récupération du fichier contenant le résultat des requêtes 
    */ 
    string line;
    int k=0; // le nombre de ligne

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

        string lines[k];
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
    
    int coeff = 30;  // coefficient à multiplier pour améliorer l'affichage de l'histogramme
    /*
     * comptage du nombre de fois que le trafic est fluide sur Rivoli
     */ 
    int comptFluide=0;
    for (int i=0; i<nbPoint; i++)  
    {
        if (lines[i*10 + 6] == "etatTrafic : Fluide" && lines[i*10 + 2] == "libelle : Rivoli" )  
        {
        comptFluide++;
        }
     }
      cout <<"NbFluide = "<<comptFluide<<endl;
      comptFluide = comptFluide*coeff;

    /*
     * comptage du nombre de fois que le trafic est inconnu sur Rivoli
     */ 
    int comptInconnu=0;
    for (int i=0; i<nbPoint; i++)   
    {
        if (lines[i*10 + 6] == "etatTrafic : Inconnu" && lines[i*10 + 2] == "libelle : Rivoli") 
        {
        comptInconnu++;
        }
     }
      cout <<"NbInconnu = "<<comptInconnu<<endl;
      comptInconnu = comptInconnu*coeff;

    /*
     * comptage du nombre de fois que le trafic est pré-saturé sur Rivoli
     */ 
    int comptPresat=0;
    for (int i=0; i<nbPoint; i++)    
    {
        if (lines[i*10 + 6] == "etatTrafic : Pré-saturé" && lines[i*10 + 2] == "libelle : Rivoli") 
        {
        comptPresat++;
        }
     }
      cout <<"NbPresaturé = "<<comptPresat<<endl;
      comptPresat = comptPresat*coeff;
      
    /*
     * comptage du nombre de fois que le trafic est saturé sur Rivoli
     */ 
    int comptSatur=0;
    for (int i=0; i<nbPoint; i++)   
    {
        if (lines[i*10 + 6] == "etatTrafic : Saturé" && lines[i*10 + 2] == "libelle : Rivoli")
        {
        comptSatur++;
        }
     }
      cout <<"NbSaturé = "<<comptSatur<<endl;
      comptSatur = comptSatur*coeff;

     
      /*
       * création de l'image
       */ 
    gdImagePtr image; /* Pointeur vers notre image */
    gdFontPtr mesPolices[5]; /* tableau des polices */
    FILE *image_png; /* Fichier image PNG */
    
    string jeuDonnees = "";

  int rouge, blanc, noir, bleu, marron, vert; 
  /* On créée un image de 1500 par 1000 */
  image = gdImageCreate(1500, 1000);
  
  /* création des couleurs */
  blanc = gdImageColorAllocate(image, 255, 255, 255);
  bleu = gdImageColorAllocate(image, 0, 0, 88);
  noir = gdImageColorAllocate(image, 0, 0, 0);
  marron = gdImageColorAllocate(image, 80, 25, 25);
  rouge = gdImageColorAllocate(image, 153, 0, 0);
  vert = gdImageColorAllocate(image, 0, 102, 51);

   /* polices utilisées */
    mesPolices[0] = gdFontTiny;
    mesPolices[1] = gdFontSmall;
    mesPolices[2] = gdFontMediumBold;
    mesPolices[3] = gdFontLarge;
    mesPolices[4] = gdFontGiant;


     /*
      * calcul des coordonnées y1(sommet des rectangles de l'histogramme)
      */ 
      int hFluide =800 - round(comptFluide*600/3000);
      int hInconnu =800 - round(comptInconnu*600/3000);
      int hPresat =800 - round(comptPresat*600/3000);
      int hSat =800 - round(comptSatur*600/3000);

       /*
        * réalisation du titre de l'histogramme avec la date mis à jours automatiquement
        */        
       string trafic ="ETAT DU TRAFIC A RIVOLI - JOURNEE DU ";
       string trafic2="          ";
        string trafic3;  // variable qui va contenir le titre complet
        unsigned char tt[trafic3.size()];  // variable qui va contenir le titre complet
        
        /* extraction de la date*/
        for (int i=0; i<10; i++)
        {
          trafic2[i] = lines[k-7][13+i];
          // cout<<lines[k-7][13+i]<<endl;
        }

        //cout<<trafic2<<endl;
       trafic3 = trafic + trafic2;
       cout << trafic3<<endl;
       
       /* récupération de la date complète */
       for (int i=0; i<trafic3.size(); i++)
       {
          tt[i] = trafic3[i];
       }

     cout << tt <<endl;
    
    /*
     * titres des batons de l'histogramme
     */  
    unsigned char fluide[] ="TRAFIC FLUIDE";
    unsigned char inconnu[] ="TRAFIC INCONNU";
    unsigned char prest[] ="TRAFIC PRE-SATURE";
    unsigned char sature[] ="TRAFIC SATURE";

    /*
     * calcul des pourcentage des batons de l'histogramme
     */ 
   float pourcFluide = (comptFluide*100.0)/(comptFluide + comptInconnu + comptPresat + comptSatur);
   float pourcInconnu = (comptInconnu*100.0)/(comptFluide + comptInconnu + comptPresat + comptSatur);
   float pourcPresat = (comptPresat*100.0)/(comptFluide + comptInconnu + comptPresat + comptSatur);
   float pourcSatur = (comptSatur*100.0)/(comptFluide + comptInconnu + comptPresat + comptSatur);

   /* conversion de valeurs numérique en chaines de caractère */
    string pF = to_string(pourcFluide);
    string pI = to_string(pourcInconnu);
    string pP = to_string(pourcPresat);
    string pS = to_string(pourcSatur);
    
    /* récupération des 5 premiers chiffres */
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
        
        string pF2 = pFF + " %";
        string pI2 = pII + " %";
        string pP2 = pPP + " %";
        string pS2 = pSS + " %";
        
        /* conversion de string en unsigned char pour pouvoir les mettre sur l'histogramme */
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

     /**
     * @brief réalisation des rectangles de l'histogramme et affichages des textes
     */     
    gdImageFilledRectangle(image, 200, hFluide, 250, 800, marron);
    gdImageFilledRectangle(image, 400, hInconnu, 450, 800, rouge);
    gdImageFilledRectangle(image, 600, hPresat, 650, 800, vert);
    gdImageFilledRectangle(image, 800, hSat, 850, 800, bleu);

    gdImageString(image, mesPolices[4], 300, 70, tt, noir);
    gdImageString(image, mesPolices[4], 100, 820, fluide, noir);
    gdImageString(image, mesPolices[4], 300, 820, inconnu, noir);
    gdImageString(image, mesPolices[4], 500, 820, prest, noir);
    gdImageString(image, mesPolices[4], 700, 820, sature, noir);

    gdImageString(image, mesPolices[4], 130, 700, pFstr, noir);
    gdImageString(image, mesPolices[4], 330, 700, pIstr, noir);
    gdImageString(image, mesPolices[4], 530, 700, pPstr, noir);
    gdImageString(image, mesPolices[4], 730, 700, pSstr, noir);
        
  /* Ouvrir le fichier image en écriture. */
  image_png = fopen("../root/HistogrmZone4.png", "w");

  /* Créer l'image au format PNG. */
  gdImagePng(image, image_png);
  /* On ferme le fichier de l'image. */
  fclose(image_png);
  /* On détruit l'image. */
  gdImageDestroy(image);
  exit (0);
}

