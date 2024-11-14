#include<stdio.h>
#include<stdlib.h>

struct LISTA{
    int date;
    struct LISTA *urmator;
    struct LISTA *anterior;
};
struct LISTA *lista = NULL;

struct LISTA* inserareNod(struct LISTA* lista,int data);
void afisare(struct LISTA* lista);
struct LISTA* inserare1(struct LISTA* lista,int data);

int main(){
    int i, n, x,temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d",&temp);
        lista = inserareNod(lista,temp);
    }
    afisare(lista);
    /*
    ...
    */

    scanf("%d", &x);

   lista= inserare1(lista,x);
    afisare(lista);

    return 0;
}

struct LISTA* inserareNod(struct LISTA* lista,int data){
    struct LISTA *nodNou, *nodCurent;

    nodNou = (struct LISTA *) malloc(sizeof(struct LISTA));
    if(!nodNou){
        printf("Memoria nu a putut fi alocata!\n");
        exit(1);
    }
//    scanf("%d", &nodNou->date);
    nodNou->date=data;
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
void afisare(struct LISTA* lista){
    struct LISTA* nodcurent;
    while(lista){
        //printf("%d\n",lista->date);

        nodcurent=lista;
        lista=lista->urmator;
    }
    while(nodcurent){
        printf("%d\n",nodcurent->date);
        nodcurent=nodcurent->anterior;
    }
}
struct LISTA* inserare1(struct LISTA* lista,int data){
    struct LISTA* nod=NULL;
    nod= inserareNod(nod,data);
    while(lista){
        nod= inserareNod(nod,lista->date);
        lista=lista->urmator;
    }

    return nod;
}