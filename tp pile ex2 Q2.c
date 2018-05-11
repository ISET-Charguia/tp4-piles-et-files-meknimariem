#include <stdio.h>
#include <stdlib.h>
//Type Pile
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

void couper(Pile p, int i);

int main()
{ int i,j;
	Pile p ; 
	
	p=creerPile();
	  for(j=0; j<20; j+=2)
        empiler(&p,j);
        
    afficher(p);
    
	printf("donner  i\n");
	scanf ("%d",&i);
	
	
	couper(p,i);
	
   
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

void couper (Pile p, int i ) 
{ 
	Pile Res,tmp ;
	
	Res=creerPile();
	tmp=creerPile();
	
	while(!estVide(p))
			{
			empiler(&tmp,sommet(p));
            depiler(&p);
		}
		
	while ( !estVide(tmp) && i>0 )
				{
				empiler(&Res,sommet(tmp));
				empiler(&p,sommet(tmp));
				depiler(&tmp);
				i--;
			}
				while ( !estVide(tmp)  )
				{
				
				empiler(&p,sommet(tmp));
				depiler(&tmp);
			
			}
    printf("\n\n");
	afficher (Res);
	printf("\n\n");
	afficher(p);
}
			
