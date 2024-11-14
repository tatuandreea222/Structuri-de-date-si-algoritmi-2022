#include <stdio.h>
#include <stdlib.h>

struct COADA
{
    int timpPrelucrare;
    struct COADA *urmator;
};

struct COADA *par= NULL;
struct COADA *impar= NULL;

struct COADA* enqueue(struct COADA *head, int timp);
void afisare(struct COADA * head);
int suma(struct COADA * head);
int main()
{
    int i,n,tPrel;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tPrel);
        if(i%2==0)
        {
            par=enqueue(par, tPrel);
        }
        else
        {
            impar=enqueue(impar, tPrel);
        }
    }
    afisare(par);
    afisare(impar);
    printf("%d\n",suma(par));
    printf("%d\n",suma(impar));
    return 0;
}

struct COADA* enqueue(struct COADA *head, int timp)
{
    struct COADA *nodNou, *nodCurent;
    nodNou=(struct COADA*) malloc(sizeof(struct COADA));
    if(!nodNou)
    {
        printf("Memoria nu a putut fi alocata!\n");
        exit(1);
    }
    nodNou->timpPrelucrare=timp;
    nodNou->urmator=NULL;

    if(!head)
    {
        return nodNou;
    }
    else
    {
        nodCurent=head;
        while(nodCurent->urmator!=NULL)
        {
            nodCurent=nodCurent->urmator;
        }
        nodCurent->urmator=nodNou;
        return head;
    }
}
void afisare(struct COADA* head)
{
 while(head)
 {
     printf("%d\n",head->timpPrelucrare);
     head=head->urmator;
 }
}

int suma(struct COADA * head)
{
    int suma=0;
    while(head)
    {
        suma=suma+head->timpPrelucrare;
        head=head->urmator;
    }
    return suma;
}