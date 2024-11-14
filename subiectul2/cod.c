#include<stdio.h>
#include<stdlib.h>

struct LISTA{
    int date;
    struct LISTA *urmator;
};
struct LISTA *lista = NULL;

struct LISTA* inserareNod();
void afisare (struct LISTA* head);
struct LISTA* mutare(struct LISTA* lista,int data);

int main(){
    struct LISTA *head = NULL;
    struct LISTA *p1 = NULL;
    struct LISTA *nod=NULL;
    int i, n,temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d",&temp);
        head = inserareNod(head,temp);
    }
    afisare(head);
    scanf("%d",&temp);

    p1=inserareNod(p1,temp);
    nod=head;
    while(nod->urmator!=head){

        p1=inserareNod(p1,nod->date);
        nod=nod->urmator;
    }
    p1= inserareNod(p1,nod->date);
    afisare(p1);

    return 0;
}

struct LISTA* inserareNod(struct LISTA* lista,int data){
    struct LISTA *nodNou, *nodCurent;
    nodNou = (struct LISTA*) malloc(sizeof(struct LISTA));
    if(!nodNou){
        printf("Memoria nu a putut fi alocata!\n");
        exit(1);
    }
//    scanf("%d", &nodNou->date);
    nodNou->date=data;
    if(!lista){
        nodNou -> urmator = nodNou;
        return nodNou;
    } else{
        nodCurent = lista;
        while(nodCurent->urmator != lista)
            nodCurent=nodCurent->urmator;
        nodCurent->urmator = nodNou;
        nodNou->urmator = lista;

    }
    return lista;
}
void afisare (struct LISTA* lista){
    struct LISTA *nodNou;
    nodNou=lista;
    while(nodNou->urmator!=lista){
        printf("%d",nodNou->date);
        printf("\n");

        nodNou=nodNou->urmator;

    }
    printf("%d",nodNou->date);
    printf("\n");

}