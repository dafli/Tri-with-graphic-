#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//tri par selection
void triSelect(int t[], int max)
{
  int  i, j;

  for(i = 0; i<max; i++) {
      int posmin = i;

      for(j = i + 1; j < max; j++)
        if(t[j] < t[posmin])
          posmin = j;

      int tmp = t[i];
      t[i] = t[posmin];
      t[posmin] = tmp;
    }
}

//tri abulle
void triABulle(int t[],int max) {

  int i;
  while(max >0){

      for(i=0;i<max-1 ;i++)

        if(t[i]>t[i+1])
          {
            int tmp=t[i];
            t[i]=t[i+1];
            t[i+1]=tmp;
          }
      max--;
    }

}

// le tri par insertion
void triInsertion(int t[],int max)
{

  int i,pos ,tmp ;

  for(i=1;i < max ; i++)
    {
      tmp = t[i];
      pos  = i;
      while  ( ( pos > 0 )  &&  ( tmp < t[pos-1] ) ){

          t[pos] = t[pos-1];
          pos = pos-1;
        }
      t[pos] = tmp;
    }

}

// triShell 

void triShell(int tab[], int maxSaisi)
{ int pas=0, i, j, temp;
  while ( pas < maxSaisi) // Calcul du pas
    pas = 3*pas+1;
  while (pas != 0) // tant que le pas est > 0
    { pas = pas/3;
      for(i= pas; i < maxSaisi; i++)
        { temp = tab[i]; // valeur à décaler éventuellement
          j = i;
          while((j>(pas-1)) && (tab[j-pas]> temp))
            { tab[j] = tab[j-pas]; // échange des valeurs
              j = j-pas;
            }
          tab[j] = temp;
        }
    }
}

int partitionner(int tableau[], int p, int r) { 
  int pivot = tableau[p], i = p-1, j = r+1,temp;
  while (1) { do j--;
      while (tableau[j] > pivot);
      do i++;
      while (tableau[i] < pivot);
      if (i < j) {
          temp = tableau[i];
          tableau[i] = tableau[j];
          tableau[j] = temp;
        } else return j; } }
void triRapide_(int *tableau, int p, int r) {

  int q;
  if (p < r) {
      q = partitionner(tableau, p, r);
      triRapide_(tableau, p, q); triRapide_(tableau, q+1, r); }


}

void  triRapide(int *t,int max){
  triRapide_(t,0,max);
}
