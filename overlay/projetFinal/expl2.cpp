#include <stdlib.h> /* Y'en aura bien besoin (pour le exit) */
#include <iostream>
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
    gdImagePtr image; /* Pointeur vers notre image */
      gdFontPtr mesPolices[5]; /* tableau des polices */
      FILE *image_png; /* Fichier image PNG */
      int blanc, bleu; /* Nos deux couleurs */
      unsigned char message[] = "Hello World !"; /* Un message original */
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
      /* On calcule la longueur du message */
      long_message = sizeof (message);
      cout<<"taille message = " << long_message<<endl;
      /* On calcule les dimensions de l'image */
      for (i=0 ; i<5 ; i++) {
        haut += mesPolices[i]->h;
        larg = ( larg < (
         tmp_larg = long_message*mesPolices[i]->w + 20 )
                        ) ? tmp_larg : larg;
      }
      /* On créée un image de larg par haut */
      image = gdImageCreate(larg, haut);
      /* On alloue deux couleurs. */
      blanc = gdImageColorAllocate(image, 255, 255, 255);
      bleu = gdImageColorAllocate(image, 0, 0, 88);
      /*
       * On écrit le texte avec les cinq polices en bleu.
       * On remet à jour la hauteur
       */
      for (i=0 ; i<5 ; i++) {
        posy += mesPolices[i]->h;
        gdImageString(image, mesPolices[i], posx, posy, message, bleu);
      }
      /* Ouvrir le fichier image en écriture. */
      image_png = fopen("expl2CPP.png", "w");
      /* Créer l'image au format PNG. */
      gdImagePng(image, image_png);
      /* On ferme le fichier de l'image. */
      fclose(image_png);
      /* On détruit l'image. */
      gdImageDestroy(image);
      exit (0);

}

