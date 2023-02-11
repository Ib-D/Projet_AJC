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
 * @brief programme permettant la réalisation d'un histogramme comparant la fluidité sur 4 zones différentes
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
    int nbPoint=6300; // nombre de lignes à traiter 
    
    int coeff = 60;  // coefficient à multiplier pour améliorer l'affichage de l'histogramme

    /*
     * comptage du nombre de fois que le trafic est fluide sur Av_Victor_Hugo
     */
    int comptFluideVH=0;
    for (int i=0; i<nbPoint; i++)
    {
        if (lines[i*10 + 6] == "etatTrafic : Fluide" && lines[i*10 + 2] == "libelle : Av_Victor_Hugo" ) 
        {
        comptFluideVH++;
        }
     }
      cout <<"NbFluide = "<<comptFluideVH<<endl;
      comptFluideVH = comptFluideVH*coeff;
      
    /*
     * comptage du nombre de fois que le trafic est fluide sur Bd_St_Michel
     */
    int comptFluideBSM=0;
    for (int i=0; i<nbPoint; i++)  
    {

        if (lines[i*10 + 6] == "etatTrafic : Fluide" && lines[i*10 + 2] == "libelle : Bd_St_Michel") 
        {
        comptFluideBSM++;
        }
     }
      cout <<"NbInconnu = "<<comptFluideBSM<<endl;
      comptFluideBSM = comptFluideBSM*coeff;

    /*
     * comptage du nombre de fois que le trafic est fluide sur Av_Kleber
     */
    int comptFluideAK=0;
    for (int i=0; i<nbPoint; i++)  
    {

        if (lines[i*10 + 6] == "etatTrafic : Fluide" && lines[i*10 + 2] == "libelle : Av_Kleber")  
        {
        comptFluideAK++;
        }
     }
      cout <<"NbPresaturé = "<<comptFluideAK<<endl;
      comptFluideAK = comptFluideAK*coeff;

    /*
     * comptage du nombre de fois que le trafic est fluide sur Rivoli
     */
    int comptFluideR=0;
    for (int i=0; i<nbPoint; i++)
    {
        if (lines[i*10 + 6] == "etatTrafic : Fluide" && lines[i*10 + 2] == "libelle : Rivoli")
        {
        comptFluideR++;
        }
     }
      cout <<"NbSaturé = "<<comptFluideR<<endl;
      comptFluideR = comptFluideR*coeff;

     
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
  bleu = gdImageColorAllocate(image, 153, 204, 255);
  noir = gdImageColorAllocate(image, 0, 0, 0);
  marron = gdImageColorAllocate(image, 204, 102, 0);
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
      
      int hFluideVH =800 - round(comptFluideVH*600/3000);
      int hFluideBSM =800 - round(comptFluideBSM*600/3000);
      int hFluideAK =800 - round(comptFluideAK*600/3000);
      int hFluideR =800 - round(comptFluideR*600/3000);

            
       /*
        * réalisation du titre de l'histogramme avec la date mise à jour automatiquement
        */ 
       
       string trafic ="ÉTUDE COMPARATIVE DE LA FLUIDITÉ SUR 4 ZONES - JOURNÉE DU ";
       string trafic2="          ";  // variable qui va contenir la date extraite
       string trafic3;  // variable qui va contenir le titre complet
        /* extraction de la date*/
       for (int i=0; i<10; i++)
       {
          trafic2[i] = lines[k-7][13+i];
       //   cout<<lines[k-7][13+i]<<endl;
       }
       
       // cout<<trafic2<<endl;
       trafic3 = trafic + trafic2;
       cout << trafic3<<endl;
       char tt[trafic3.size()];
       
       /* récupération du titre avec la date complète */
       for (int i=0; i<trafic3.size(); i++)
       {
          tt[i] = trafic3[i];
       }
       
     cout << tt <<endl;

    /*
     * titres des batons de l'histogramme
     */ 
	char fluide[] ="AV VICTOR HUGO";
	char inconnu[] ="BD ST MICHEL";
	char prest[] ="AV KLEBER";
	char sature[] ="RIVOLI";
	
      /*
     * calcul des pourcentage des batons de l'histogramme
     */                         
   float pourcFluideVH = (comptFluideVH*100.0)/(comptFluideVH + comptFluideBSM + comptFluideAK + comptFluideR);
   float pourcFluideBSM = (comptFluideBSM*100.0)/(comptFluideVH + comptFluideBSM + comptFluideAK + comptFluideR);
   float pourcFluideAK = (comptFluideAK*100.0)/(comptFluideVH + comptFluideBSM + comptFluideAK + comptFluideR);
   float pourcFluideR = (comptFluideR*100.0)/(comptFluideVH + comptFluideBSM + comptFluideAK + comptFluideR); 
   
    /* conversion de valeurs numérique en chaines de caractère */
    string pF = to_string(pourcFluideVH);         
    string pI = to_string(pourcFluideBSM);         
    string pP = to_string(pourcFluideAK);         
    string pS = to_string(pourcFluideR);
    
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
	char pFstr [8];          
	char pIstr [8];          
	char pPstr [8];          
	char pSstr [8];
	
        
        for (int i=0; i<8; i++)
       {
	   pFstr [i] = pF2[i];          
	   pIstr [i] = pI2[i];          
	   pPstr [i] = pP2[i];          
	   pSstr [i] = pS2[i];
       }
        
         int brect[8];
        char str[]  = "/home/ajc/Téléchargements/dejavu-sans/DejaVuSans.ttf";        
   
        /**
     * @brief réalisation des rectangles de l'histogramme et affichages des textes
     */
	gdImageFilledRectangle(image, 200, hFluideVH, 280, 800, rouge);
	gdImageFilledRectangle(image, 400, hFluideBSM, 480, 800, marron);
	gdImageFilledRectangle(image, 600, hFluideAK, 680, 800, vert);
	gdImageFilledRectangle(image, 800, hFluideR, 880, 800, bleu);
	
    	gdImageStringFT(image, brect, noir, str, 18, 0, 300, 70, tt); // le titre
    	gdImageStringFT(image, brect, noir, str, 13, 0, 100, 825, fluide); 
   	gdImageStringFT(image, brect, noir, str, 13, 0, 310, 825, inconnu); 
    	gdImageStringFT(image, brect, noir, str, 13, 0, 530, 825, prest); 
    	gdImageStringFT(image, brect, noir, str, 13, 0, 770, 825, sature); 

   	gdImageStringFT(image, brect, noir, str, 12, 0, 210, 700, pFstr); 
   	gdImageStringFT(image, brect, noir, str, 12, 0, 410, 700, pIstr); 
   	gdImageStringFT(image, brect, noir, str, 12, 0, 610, 700, pPstr); 
   	gdImageStringFT(image, brect, noir, str, 12, 0, 810, 700, pSstr);
	
	

 
	
	
        
	/* Ouvrir le fichier image en écriture. */
	image_png = fopen("../root/HistogrmCompareZone.png", "w");
	/* Créer l'image au format PNG. */
	gdImagePng(image, image_png);
	/* On ferme le fichier de l'image. */
	fclose(image_png);
	/* On détruit l'image. */
	gdImageDestroy(image);
	exit (0);
}

