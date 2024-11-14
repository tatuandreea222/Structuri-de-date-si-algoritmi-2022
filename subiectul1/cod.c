#include<stdio.h>
#include<stdlib.h>

struct LISTA{
    int date;
    struct LISTA *urmator;
    struct LISTA *anterior;
};
struct LISTA *lista = NULL;

struct LISTA* inserareNod();
void afisare_lista(struct LISTA * head){
    struct LISTA * nod_curent;

    if (head == NULL) {
        printf("Atentie, lista este goala!\n");
        return;
    }

    nod_curent = head;

    while (nod_curent != NULL) {
        /* afisare valoare curenta si pozitionare nod urmator */
        printf("%d\n", nod_curent -> date);
        nod_curent = nod_curent->urmator;
    }
}
struct LISTA* interschimbare(struct LISTA * lista)
{
    struct LISTA *nodcurent;
    int nodinter;
    nodcurent=lista;
    while(nodcurent->urmator!=NULL)
    {
        nodcurent = nodcurent->urmator;
    }
    nodinter=nodcurent->date;
    nodcurent->date=lista->date;
    nodcurent->urmator=NULL;
    nodcurent->anterior=nodcurent;
    lista->date=nodinter;
    lista=lista->urmator;
    lista->anterior=NULL;
    return lista;

}
int main(){
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        lista = inserareNod();
    
    afisare_lista(lista);
    interschimbare(lista);
    afisare_lista(lista);



    return 0;
}

struct LISTA* inserareNod(){
    struct LISTA *nodNou, *nodCurent;

    nodNou = (struct LISTA *) malloc(sizeof(struct LISTA));
    if(!nodNou){
        printf("Memoria nu a putut fi alocata!\n");
        exit(1);
    }
    scanf("%d", &nodNou->date);
    nodNou->anterior = NULL;
    nodNou->urmator  = NULL;

    if(!lista){
        return nodNou;
    }
    else{
        nodCurent = lista;
        while(nodCurent->urmator)
            nodCurent = nodCurent->urmator;
        nodCurent->urmator = nodNou;
        nodNou->anterior   = nodCurent;
        return lista;   
    }
}