#include <stdlib.h> /* Y'en aura bien besoin (pour le exit) */
#include </usr/include/gd.h> /* On va utiliser gd */
#include <string.h>
/* Théoriquement il faut inclure stdio.h
   MAIS c'est fait dans gd.h donc ... */
#include </usr/include/gdfontt.h> /*on va utiliser la police gdFontTiny */
#include </usr/include/gdfonts.h> /*on va utiliser la police gdFontSmall */
#include </usr/include/gdfontmb.h> /*on va utiliser la police gdFontMediumBold */
#include </usr/include/gdfontl.h> /*on va utiliser la police gdFontLarge */
#include </usr/include/gdfontg.h> /*on va utiliser la police gdFontGiant */
int main(void) {


    int k=0;

 FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("resultatRequete.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
      //  printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
                  k++;
    }
/*
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);

*/



     // cout <<i<<endl;
        int j = 0;
      char *lines[k];


          fp = fopen("resultatRequete.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
      //  printf("Retrieved line of length %zu:\n", read);
      //  printf("%s", line);
       //           k++;

           *lines[j] = *line;
           // cout << lines[j] << '\n';
            j++;
    }
    
    
       printf("%s", lines[0]);
              printf("%s", lines[0]);
                     printf("%s", lines[0]);
    
  /*
      //string ll;
        ifstream myfiles ("resultatRequete.txt");

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

   */



  gdImagePtr image; /* Pointeur vers notre image */
  gdFontPtr mesPolices[5]; /* tableau des polices */
  FILE *image_png; /* Fichier image PNG */
  int blanc, bleu; /* Nos deux couleurs */
 // string str = "Salut ";
  char *message = "Salut"; /* Un message original */
  char *mess[3];
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
  long_message = strlen(message);
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
  image_png = fopen("Expl3C.png", "w");
  /* Créer l'image au format PNG. */
  gdImagePng(image, image_png);
  /* On ferme le fichier de l'image. */
  fclose(image_png);
  /* On détruit l'image. */
  gdImageDestroy(image);
  exit (0);
}

