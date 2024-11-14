#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Robot
{
    char comanda[15];
    struct Robot * urmator;
}Robot;

struct Robot * adauga_la_final(struct Robot * robot,char comanda[15])
{
    struct Robot *nodcurent=NULL, *nodnou=NULL;
    nodnou=malloc(sizeof(Robot));
    strcpy(nodnou->comanda,comanda);
    if(!robot)
    {
        return nodnou;
    }
    else
    {
        nodcurent=robot;
        while(nodcurent->urmator!=NULL)
        {
            nodcurent=nodcurent->urmator;
        }
        nodcurent->urmator=nodnou;
    }
    return robot;
}
void afisare(struct Robot *robot)
{
    struct Robot *nodcurent;
    nodcurent=robot;
    while(nodcurent->urmator!=NULL)
    {
        printf("%s\n",nodcurent->comanda);
        nodcurent=nodcurent->urmator;
    }
}

struct Robot * sterge_din_lista(struct Robot * head)
{
        struct Robot * nod_sters;
    struct Robot * nod_curent;
    if (head == NULL) {
        printf("Atentie: lista este goala.");
        return NULL;
    }

    if(head->urmator == NULL){
        free(head);
        return NULL;
    }
    nod_curent = head;

    while(nod_curent->urmator->urmator != NULL){
        nod_curent = nod_curent->urmator;
            }
        nod_sters = nod_curent->urmator;
        nod_curent->urmator = NULL;
        free(nod_sters);
        return head;
}

int main()
{
    struct Robot *robot=NULL;
    int test;
    char comanda[15];
    scanf("%d",&test);
    switch(test)
    {
        case 1:
        {
            while(scanf("%s",comanda)!=EOF)
            {
                robot=adauga_la_final(robot,comanda);
            }
            afisare(robot);
            printf("executa");
            break;
        }
        case 2:
        {
            while(scanf("%s",comanda)!=EOF)
            {
                if(strcmp(comanda,"sterge")==0)
                {
                    sterge_din_lista(robot);
                }
                else
                {
                    robot=adauga_la_final(robot,comanda);
                }
            }
            afisare(robot);
            break;
        }
    }
    return 0;
}