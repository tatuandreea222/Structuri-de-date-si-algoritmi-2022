#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct CLIENT
{
    char nume[51];
    int nr_produse;
    int pret_produs;
    int pret_total;
    int suma_reducere;
    struct CLIENT* urmator;
}CLIENT;
struct CLIENT *cap= NULL;
struct CLIENT *ultim=NULL;

void adauga_la_sfarsit(char nume[],int nr_produse,int pret_produs,int pret_total,int suma_reducere)
{
    struct CLIENT *nou=malloc(sizeof(CLIENT));
    struct CLIENT *cursor=NULL;
    cursor=cap;
    int gasit=0,y;
    while(cursor!=NULL)
    {
        y=strcmp(nume,cursor->nume);
        
        if(y==0)
        {
            gasit=1;
            break;
        }
        cursor=cursor->urmator;
    }
    if(gasit==1)
    {
        cursor->nr_produse+=nr_produse;
        cursor->pret_total+=pret_total;
        cursor->suma_reducere+=suma_reducere;
    }
    else
    {
     strcpy(nou->nume,nume);
    nou->nr_produse=nr_produse;
    nou->pret_produs=pret_produs;
    nou->pret_total=pret_total;
    nou->suma_reducere+=suma_reducere;
    nou->urmator=NULL;   
    }
    
    if (cap==NULL)
    {
        cap=nou;
    }
    else{
        ultim->urmator=nou;
    }
    ultim=nou;
}
  
int main()
{

    int n;
    scanf("%d",&n);
    char nume[51];
    int nr_produse;
    int pret_produs;
    int pret_total;
    int suma_reducere;
    while(scanf("%s%d%d",nume,&nr_produse,&pret_produs)!=EOF)
    {
        pret_total=nr_produse*pret_produs;
        suma_reducere=(nr_produse-(nr_produse/5))*pret_produs;
        adauga_la_sfarsit(nume,nr_produse,pret_produs,pret_total,suma_reducere);
    }

    if(n==1)
    {
        int gasit=0;
    struct CLIENT *cursor=NULL;
        cursor=cap;
        
        while(cursor!=NULL)
        {
            if(cursor->nr_produse>=20 || cursor->pret_total>=1000)
            {
                printf("%s\n", cursor->nume);
                gasit=1;
            }
            cursor=cursor->urmator;
        }
        if(!gasit)
        {
            printf("-\n");
        }
    }
    
    if(n==2)
    {
        struct CLIENT *cursor=NULL;
        cursor=cap;
         int proba,contor=0,gasit=0;
        while(cursor!=NULL)
        {
           if(cursor->suma_reducere!=-1)
           {
               proba=cursor->suma_reducere;
               break;
           }
           cursor=cursor->urmator;
        }
        cursor=cap;
        while(cursor!=NULL)
        {
           if(proba==cursor->suma_reducere)
           {
               contor++;
           }
           cursor=cursor->urmator;
        }
        cursor=cap;
        if(contor>1)
        {
            gasit=1;
            while(cursor!=NULL)
            {
             if(proba==cursor->suma_reducere)
             {
                printf("%s ", cursor->nume);
             }
           cursor->suma_reducere=-1;
           cursor=cursor->urmator;
            }
        }
        if(gasit==0)
        {
            printf("-\n");
        }
        
    }
    
}
