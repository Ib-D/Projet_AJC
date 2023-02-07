#include <stdlib.h> /* Y'en aura bien besoin (pour le exit) */
#include <gd.h> /* On va utiliser gd */
/* Théoriquement il faut inclure stdio.h
   MAIS c'est fait dans gd.h donc ... */
int main(void) {
  gdImagePtr image; /* Pointeur vers notre image */
  FILE *image_png; /* Fichier image PNG */
  int rouge, blanc; /* Deux couleurs */
  /* On créée un image de 100 par 100 */
  image = gdImageCreate(100, 100);
  /*
   * On "alloue" deux couleurs.
   * Notez que la première sera la couleur de fond
   *
   * En paramètres : - l'image
   *                 - les valeurs de rouge, vert et bleu (de 0 à 255)
   */
  blanc = gdImageColorAllocate(image, 255, 255, 255);
  rouge = gdImageColorAllocate(image, 255, 0, 0);
  /*
   * On trace la croix, deux rectangles pleins qui se croisent
   * le premier de x=20,y=45 à x=80,y=55
   * le second de x=45,y=20 à x=55,y=80
   * tous les deux de couleurs rouge.
   */
  gdImageFilledRectangle(image, 20, 45, 80, 55, rouge);
  gdImageFilledRectangle(image, 45, 20, 55, 80, rouge);
  /* Ouvrir le fichier image en écriture. */
  image_png = fopen("expl1.png", "w");
  /* Créer l'image au format PNG. */
  gdImagePng(image, image_png);
  /* On ferme le fichier de l'image. */
  fclose(image_png);
  /* On détruit l'image. */
  gdImageDestroy(image);
  exit (0);
}

