#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Loterie
{
    char nume[31];
    char prenume[31];
    int val_juc[100];
    struct Loterie* urmator; 
}Loterie;

struct Loterie *cap= NULL;
struct Loterie *ultim=NULL;
struct Loterie * adauga_la_sfarsit(struct Loterie * loterie, char nume[], char prenume[], int val_j[100],int nr)
{
    struct Loterie *nodcurent=NULL, *nodnou=NULL;
    nodnou=malloc(sizeof(Loterie));
    strcpy(nodnou->nume,nume);
    strcpy(nodnou->prenume,prenume);
    int i;
    for(i=0;i<nr;i++)
    {
        nodnou->val_juc[i]=val_j[i];
       // printf("%d ", nodnou->val_juc[i]);
    }
    if(!loterie)
    {
        return nodnou;
    }
    else
    {
        nodcurent=loterie;
        while(nodcurent->urmator!=NULL)
        {
            nodcurent=nodcurent->urmator;
        }
        nodcurent->urmator=nodnou;
    }
    return loterie;
    
}
void afisare(struct Loterie * head,int nr)
{
    struct Loterie *nodcurent=NULL;
    int i;
    if(head==NULL)
    {
        printf("Atentie,lista este goala!\n");
        return;
    }
    nodcurent=head;
    while(nodcurent!=NULL)
    {
        printf("%s ", nodcurent->nume);
        printf("%s ", nodcurent->prenume);
        for(i=0;i<nr;i++)
        {
            printf("%d ", nodcurent->val_juc[i]);
        }
        printf("\n");
        nodcurent=nodcurent->urmator;
    }
}

void numere_ghicite(struct Loterie * head,int N,int loto[7])
{
    int i,j,contor,k,maxim=0;
    struct Loterie *nodcurent=NULL;
    nodcurent=head;
    while(nodcurent!=NULL)
    {
        contor=0; 
        maxim=0;
        for(i=0;i<N;i++)
        {
            contor=0;
           for(j=i;j<6+i;j++)
           {
               for(k=0;k<6;k++)
               {
                   if(nodcurent->val_juc[j]==loto[k])
                    {
                        contor++;
                    }
               }
               if(maxim<contor)
               {
                   maxim=contor;
               }
           }
        }
       printf("%s ", nodcurent->nume);
        printf("%s ", nodcurent->prenume);
        printf("%d\n", maxim);
        nodcurent=nodcurent->urmator;
    }
}


int main()
{
    struct Loterie *loterie=NULL;
    int i,j,c,k,N,loto[7];
    char nume[31];
    char prenume[31];
    scanf("%d",&c);
    scanf("%d",&k);
    scanf("%d",&N);
    int val_juc[N+1];
    for(i=0;i<6;i++)
    {
        scanf("%d",&loto[i]);
    }
    for(i=0;i<k;i++)
    {
        scanf("%s",nume);
        scanf("%s",prenume);
        for(j=0;j<N;j++)
        {
            scanf("%d",&val_juc[j]);
        }
        loterie=adauga_la_sfarsit(loterie,nume,prenume,val_juc,N);
    }
    
    switch(c)
    {
        case 1:
        {
            afisare(loterie,N);
            break;
        }
        case 2:
        {
            numere_ghicite(loterie,N,loto);
        }
    }
    return 0;
}