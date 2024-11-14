#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nod
{
    char nume[100];
    struct nod* next;
};

//alocare memorie nod
struct nod* nod_nou(char nume[])
{
    struct nod* nodNou = (struct nod*)malloc(sizeof(struct nod));
    strcpy(nodNou->nume, nume);
    nodNou->next = NULL;
    return nodNou;
}

//afisare lista
void afiseaza(struct nod* lista)
{
    struct nod* pointer = lista;
    while (pointer != NULL)
    {
        printf("%s\n", pointer->nume);
        pointer = pointer->next;
    }
    return;
}

//stergere
struct nod* sterge(struct nod* lista, struct nod* deSters)
{
    if (lista == deSters)
    {
        struct nod* temp = lista;
        lista = lista->next;
        free(temp);
        return lista;
    }

    struct nod* pointer = lista;
    while (pointer->next != deSters)
        pointer = pointer->next;

    struct nod* temp = pointer->next;
    pointer->next = temp->next;
    free(temp);
    return lista;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    struct nod* jucatori = NULL;
    for (i = 0; i < n; ++i)
    {
        char nume[100];
        scanf("%s", nume);
        struct nod* pointer = jucatori;
        if (pointer == NULL)
            jucatori = nod_nou(nume);
        else
        {
            while (pointer->next != NULL)
                pointer = pointer->next;
            pointer->next = nod_nou(nume);
        }
    }
    afiseaza(jucatori);

    while (n > 1)
    {
        struct nod* pointer = jucatori;
        struct nod* pointerMin;
        int minim = 15;
        for (i = 0; i < n; ++i)
        {
            int x;
            scanf("%d", &x);
            if (minim > x)
            {
                minim = x;
                pointerMin = pointer;
            }
            pointer = pointer->next;
        }
        jucatori = sterge(jucatori, pointerMin);
        afiseaza(jucatori);
        n--;
    }
    return 0;
}