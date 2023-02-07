#include <stdlib.h> /* Y'en aura bien besoin (pour le exit) */
#include <stdlib.h> /* Pour le getenv */
#include <string.h>
#include </usr/include/gd.h> /* On va utiliser gd */
/* Théoriquement il faut inclure stdio.h 
   MAIS c'est fait dans gd.h donc ... */
#include </usr/include/gdfontmb.h> /* On va utiliser la police gdFontMediumBold */
int main(void) {
  gdImagePtr image; /* Pointeur vers notre image */
  FILE *image_png_in; /* Fichier image PNG */
  int jaune; /* Notre couleur */
  char *texte;
  int long_texte; /* La taille du texte */
  /* récupère le texte */
  printf ("Debug1\n");
  if ( !(texte = getenv("QUERY_STRING")) ) {
  	texte = "Erreur !";
	}
  long_texte = strlen(texte);
    printf ("Debug2\n");
  /* On ouvre l'image initiale */
  if ( !(image_png_in = fopen ("/root/bout_in.png", "rb")) ) {
  	fprintf (stderr, "Impossible de trouver l'image bout_in.png.\n\n");
  	exit (1);
  }
  image = gdImageCreateFromPng(image_png_in);
  /* On ferme le fichier de l'image. */
  fclose(image_png_in);
  /* On alloue une couleur. */
  jaune = gdImageColorResolve(image, 0xff, 0xff, 0);
  /*
   * On écrit le texte
   */
  gdImageString(image, gdFontMediumBold,
                (image->sx-long_texte*gdFontMediumBold->w)/2,
                (image->sy-gdFontMediumBold->h)/2,
                texte, jaune);
  /* Envoyer l'image au format PNG. */
  printf ("Content-type: image/png\n\n");
  gdImagePng(image, stdout);
  /* On détruit l'image. */
  gdImageDestroy(image);
  exit (0);
}

