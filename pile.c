
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int expr(char expre[]);



int main()
{
	Pile maPile1,maPile2;
    maPile1=creerPile();
    maPile2=creerPile();
    int i;
    empiler(&maPile2,5);
    for(i=0; i<50; i+=3)
    {
        empiler(&maPile1,i);
        empiler(&maPile2,i);
	}
	
	printf("la pile 1 \n");
	afficher(maPile1);
	
	printf("la pile 2 \n");
	afficher(maPile2);
	
	
	
    return 0;
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

int expr (char ch )
{
	int i=0;
	Pile p=creerPile();
	Pile p1=creerPile();
	Pile p2=creerPile();
	Pile p3=creerPile();
	
	
	for(i=0;i<strlen(ch);i++){
	switch(ch[i]){
		case '(': empiler(&p,ch[i]);empiler(&p1,i);break;
		case ')': if(!estVide(p))return 0;
			depiler(&p);empiler(&p2,i);	
		}
	}
		if(!estVide(p)){
			return 0;
		}
		while(!estVide(p1)){
		empiler(&p3,sommet(p1));
		depiler(&p1);		
		}
		return 1 ;
		while(!estVide(p3)){
		printf("\n(%d,%d)",sommet(p3),sommet(p2));
		depiler(&p3);
		depiler(&p2);	
		}


}
