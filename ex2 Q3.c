
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

void empilerdeuxpiles(Pile p1, Pile p2) ;
int main()
{
    Pile mapile1,mapile2;
  int i,n,p1,p2;
    mapile1=creerPile();
     mapile2=creerPile();
  
  
    printf("saisir taille pile1\n");
    scanf("%d",&p1);
    puts("saisir taile pile 2");
    scanf("%d",&p2);
    puts("Remplissage de 1 ere Pile");
    for(i=0;i<p1;i++){
    puts("saisir une entier");
    scanf("%d",&n);
    empiler(&mapile1,n);
		}
	puts("Remplissage de 2 eme Pile");
    for(i=0;i<p2;i++){
    puts("saisir une entier");
    scanf("%d",&n);
    empiler(&mapile2,n);
}
    puts("Affichage de deux piles");
empilerdeuxpiles(mapile1,mapile2);
afficher(mapile1);
    return 0;
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





void empilerdeuxpiles(Pile p1, Pile p2)
{
	
Pile p3=creerPile();

while(!estVide(p2)){
empiler(&p3,sommet(p2));
depiler(&p2);	
}

while(!estVide(p3)){
empiler(&p1,sommet(p3));
depiler(&p3);	
}

}


	
	

