#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int valeur;
    struct cellule *suivant;
} Cellule;

typedef Cellule * Pile;

Pile creerPile();

int estVide(Pile p);

void empiler(Pile *p, int x);

void depiler(Pile *p);

int sommet(Pile p);

void afficher(Pile p);

void identique(Pile p1,Pile p2);


int main()
{
	Pile p1;Pile p2;
	int i;
	p1=creerPile();
	p2=creerPile();

    for(i=0; i<20; i+=2)
        {
			empiler(&p1,i);
			empiler(&p2,i);
		} 	
    afficher(p1);	
    afficher(p2);
    
    identique(p1,p2) ;
        
        	

return 0 ;

}

Pile creerPile()
{
    return NULL;
}

int estVide(Pile p) {
    return p==NULL;
} 


void empiler(Pile *p, int x) {
    Cellule *nouv;
    nouv = (Cellule *)malloc(sizeof(*nouv));
    nouv->valeur=x;
    nouv->suivant=*p;
    *p=nouv;
}

void depiler(Pile *p) {
    if(!estVide(*p)){
    Pile ancien;
    ancien = *p;
    *p = (*p)->suivant;
    free(ancien);
    }
    else
        printf("La pile est dÃ©jÃ  vide!\n");
}

int sommet(Pile p) {
    return p->valeur;
}

void afficher(Pile p) {
    Pile tmp;
    tmp = creerPile();
    if(estVide(p)){
        printf("La pile est vide!\n");
    }
    else{
        while(!estVide(p)){
            printf("%d\n",sommet(p));
            empiler(&tmp,sommet(p));
            depiler(&p);
        }
        while(!estVide(tmp)){
            empiler(&p,sommet(tmp));
            depiler(&tmp);
        }
    }
}



void identique (Pile p1,Pile p2)

{ 
	Pile  tmp1; Pile tmp2;
  tmp1 = creerPile();
    tmp2 = creerPile();
  if (  estVide(p1) || estVide(p2) )
  {
	 printf("n'est pas ident") ;
  } 
  else 
    { 
		while (  !estVide(p1) && !estVide(p2) && sommet(p1)==sommet(p2) )
			{	
				empiler(&tmp1,sommet(p1)) ;
				depiler(&p1);
				empiler(&tmp2,sommet(p2)) ;
				depiler(&p2);
			}
		}

   if ( estVide(p1) && estVide(p2) )
  printf("identique ");
  else printf("n'est pas ident") ;
     
     
     
        while(!estVide(tmp1))
        {
            empiler(&p1,sommet(tmp1));
            depiler(&tmp1);
		}
        
         while(!estVide(tmp2))
          {
            empiler(&p2,sommet(tmp2));
            depiler(&tmp2);
          }

}
