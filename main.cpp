#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tris.h"
#include <winbgim.h>

int nombreTests = 50;

void afficherTableau(int tab[], int taille)
{
  int i;
  for(i = 0; i < taille; i++)
    printf("%d \n", tab[i]);
}

void remplireTableau(int tab[], int taille)
{
  int i;
  for (i = 0; i < taille; i++)
    tab[i] = rand()%10;
}

double profileFunction(void (*f)(int*, int), int *tab, int max)
{
  clock_t debut = clock();
  f(tab, max);
  clock_t fin = clock();
  return (double) (fin - debut) / CLOCKS_PER_SEC;
}

double faireTri(int nombreElements, void (*tri)(int[], int))
{
  int *tableau = (int*) malloc(nombreElements * sizeof(int));
  remplireTableau(tableau, nombreElements);
  return profileFunction(tri, tableau, nombreElements);
}


// transformation du repère original vers le nouveau repère 
int _x(int x) {
  return x +50  ;
}

int _y(int y) {
  return 550 - y;
}


void Tracer(void (*tri)(int[], int)) {
  int i;
  for(i = 0; i < nombreTests; ++i) {
      int nombreElements = 1000*i+1000 ;
      double sec = faireTri(nombreElements, tri);
      lineto(_x((int)(nombreElements*0.015) ), _y((int) (sec*25)));
      printf("%d : lineto(%d, %d) \n",nombreElements, _x(nombreElements / 1000), _y((int) sec *25));
    }
}
int main()
{
  // initialise le generateur de nombre aléatoire

  srand(time(NULL));

  int i;
  initwindow(900,600);
  line(50, 50, 50, 550);
  line(50, 47, 45, 52);
  line(50, 47, 55, 52);
  line(50, 550, 850, 550);

  for(i=1;i<51;i++)
    line(50+i*15, 552, 50+i*15, 548);

  for(i=1;i<21;i++)
    line(48, 550-i*25, 52, 550-i*25);

  outtextxy(65,45 ,"le temps");
  outtextxy(780,530 ,"nb d'elements");
  outtextxy(850,545 ,">");

  line(270, 60, 500, 60);
  line(270, 60, 270, 170);
  line(270, 60, 270, 170);
  line(270, 170, 500, 170);
  line(500, 170, 500, 60);
  setcolor(COLOR(255,24,0));
  outtextxy(300,70 ,"---- : Tri SELECTION ");
  setcolor(COLOR(235, 234, 4));
  outtextxy(300,85 ,"---- : Tri INSERTION ");
  setcolor(COLOR(0, 0, 255));
  outtextxy(300,100 ,"---- : Tri A BULLE  ");
  setcolor(COLOR(0, 255, 0));
  outtextxy(300,120 ,"---- : Tri  RAPIDE ");
  setcolor(COLOR(102, 0, 102));
  outtextxy(300,140 ,"---- : Tri  SHELL ");

  moveto(_x(0), _y(0));
  setcolor(COLOR(0, 255, 0));
  Tracer(triRapide);

  moveto(_x(0), _y(0));
  setcolor(COLOR(235, 234, 4));
  Tracer( triInsertion);

  moveto(_x(0), _y(0));
  setcolor(COLOR(255,24,0));
  Tracer(triSelect);

  moveto(_x(0), _y(0));
  setcolor(COLOR(102, 0, 102));
  Tracer( triShell);

  moveto(_x(0), _y(0));
  setcolor(COLOR(0, 0, 255));
  Tracer(triABulle);

  getch();
  return 0;
}


