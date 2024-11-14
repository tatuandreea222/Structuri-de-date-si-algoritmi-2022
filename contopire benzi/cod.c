#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nod
{
  char cod[10];
  struct nod * next;
};

int isEmpty( struct nod *front)
{
    if(front == NULL)
    {
        return 1;
    }
    return 0;
}
struct nod * enqueue (struct nod *front, char cod[])
{
    struct nod *cell= (struct nod *)malloc(sizeof (struct nod));
    cell->next = NULL;
    strcpy(cell->cod,cod);
    if(isEmpty(front))
    {
        return cell;
    }
    struct nod * temp = front;
    while(temp->next!= NULL)
    {
        temp=temp->next;
        
    }
    temp->next=cell;
    return front;
}

struct nod * dequeue(struct nod *front)
{
    if(isEmpty(front))
    {
        return NULL;
    }
    struct nod * temp = front;
    front= front ->next;
    free(temp);
    return front;
}

void front(struct nod * coada)
{
    if(!isEmpty(coada))
    {
        printf("%s\n", coada->cod);
    }
}

int main()
{
    int b1,b2,i;
    scanf("%d",&b1); //"%d%d"
    scanf("%d",&b2);
    struct nod * coada1=NULL;
    struct nod * coada2=NULL;
    char cod[10];
    for(i=0; i<b1; ++i)
    {
        scanf("%s", cod);
        coada1=enqueue(coada1,cod);
    }
    for(i=0; i<b2; ++i)
    {
        scanf("%s", cod);
        coada2=enqueue(coada2,cod);
    }
    while(!isEmpty(coada1) || !isEmpty(coada2))
    {
        if(!isEmpty(coada2))
        {
            front(coada2);
            coada2=dequeue(coada2);
        }
        if(!isEmpty(coada1))
        {
            front(coada1);
            coada1=dequeue(coada1);
        }
    }
 
    return 0;
}