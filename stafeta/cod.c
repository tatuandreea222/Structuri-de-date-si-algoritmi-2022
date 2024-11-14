#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cursa
{
    char persoana1[11];
    char persoana2[11];
    float timp;
    struct Cursa * urmator;
}Cursa;

struct Cursa *cap=NULL;
struct Cursa *ultim=NULL;
struct Cursa *  adauga_la_sfarsit(struct Cursa* cursa,char persoana1[],char persoana2[],float timp)
{
    struct Cursa *nodcurent=NULL, *nodnou=NULL;
    nodnou=malloc(sizeof(Cursa));
    strcpy(nodnou->persoana1,persoana1);
    strcpy(nodnou->persoana2,persoana2);
    nodnou->timp=timp;
    nodnou->urmator=NULL;

    if(!cursa)
    {
        return nodnou;
    }
    else
    {
        nodcurent=cursa;
        while(nodcurent->urmator!=NULL)
        {
            nodcurent=nodcurent->urmator;
        }
        nodcurent->urmator=nodnou;
    }
    return cursa;
}
void afisare_lista(struct Cursa * head)
{
    struct Cursa *nodcurent;
    if(head==NULL)
    {
        printf("Atentie,lista este goala!\n");
        return;
    }
    nodcurent=head;
    while(nodcurent!=NULL)
    {
        printf("%s ",nodcurent->persoana1);
        printf("%s ",nodcurent->persoana2);
        printf("%.2f\n", nodcurent->timp);
        nodcurent=nodcurent->urmator;
    }
}
void minim(struct Cursa* cursa)
{
    struct Cursa *nodcurent;
  float t_minim;
  char nume1[11];
  char nume2[11];
    t_minim=10;
    nodcurent=cursa;
    while(nodcurent!=NULL)
    {
        
        if(t_minim>nodcurent->timp)
        {
            t_minim=nodcurent->timp;
            strcpy(nume1,nodcurent->persoana1);
            strcpy(nume2,nodcurent->persoana2);
        }
        nodcurent=nodcurent->urmator;
    }
  
    printf("%s ",nume1);
    printf("%s ",nume2);
    printf("%.2f\n", t_minim);
  
}
void prag(struct Cursa* cursa, float media)
{
    struct Cursa *nodcurent;
    nodcurent=cursa;
    while(nodcurent!=NULL)
    {
        if(nodcurent->timp>media)
        {
            printf("%s ",nodcurent->persoana1);
        printf("%s ",nodcurent->persoana2);
        printf("%.2f\n", nodcurent->timp);
        }
        nodcurent=nodcurent->urmator;
    }
}
void stafeta(struct Cursa* cursa, float vector)
{
    struct Cursa *nodcurent;
    nodcurent=cursa;
    while(nodcurent!=NULL)
    {
        if(nodcurent->timp==vector)
        {
            printf("%s ",nodcurent->persoana1);
        printf("%s ",nodcurent->persoana2);
        printf("%.2f\n", nodcurent->timp);
        }
        nodcurent=nodcurent->urmator;
    }
}
void bonus(struct Cursa* cursa, float vector,int nr)
{
    struct Cursa *nodcurent;
    nodcurent=cursa;
    while(nodcurent!=NULL)
    {
        if(nodcurent->timp==vector)
        {
            printf("%s ",nodcurent->persoana1);
            printf("%d ",nr/2);
            printf("%s ",nodcurent->persoana2);
            printf("%d\n",nr/2);
        }
        nodcurent=nodcurent->urmator;
    }
}
int main()
{
    struct Cursa *cursa=NULL;
    int nr_perechi,comanda,i;
    float timp,media=0;
    char persoana1[11];
    char persoana2[11];
    scanf("%d",&nr_perechi);
    float vector[nr_perechi+1];
    for(i=0;i<nr_perechi;i++)
    {
        scanf("%s",persoana1);
        scanf("%s",persoana2);
        scanf("%f",&timp);
        media+=timp;
        vector[i]=timp;
       cursa=adauga_la_sfarsit(cursa,persoana1,persoana2,timp); 
    }
    
    media=media/nr_perechi;
    scanf("%d",&comanda);
    switch(comanda)
    {
        case 1:
        {
            afisare_lista(cursa);
            break;
        }
        case 2:
        {
            minim(cursa);
            break;
        }
        case 3:
        {
            prag(cursa,media);
            break;
        }
        case 4:
        {
            float aux;
            int j;
            for(i=0;i<nr_perechi;i++)
            {
                for(j=i+1;j<nr_perechi-1;j++)
                {
                    if(vector[i]>vector[j])
                    {
                    aux=vector[j];
                    vector[j]=vector[i];
                    vector[i]=aux;
                    }
                }
            }
            for(i=0;i<nr_perechi;i++)
            {
                stafeta(cursa,vector[i]);
            }
            break;
        }
        case 5:
        {
            float aux;
            int j;
            for(i=0;i<nr_perechi;i++)
            {
                for(j=i+1;j<nr_perechi-1;j++)
                {
                    if(vector[i]>vector[j])
                    {
                    aux=vector[j];
                    vector[j]=vector[i];
                    vector[i]=aux;
                    }
                }
            }
            bonus(cursa,vector[0],10000);
            bonus(cursa,vector[1],5000);
            bonus(cursa,vector[2],2000);
            break;
        }
    }
    return 0;
}