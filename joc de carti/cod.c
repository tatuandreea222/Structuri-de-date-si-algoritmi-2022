#include <stdio.h>
#include <stdlib.h>

struct Jucator
{
  char nume[22];
  int carti[3];
};

void creare_jucator(struct Jucator *j)
{
    int i;
    scanf("%s",j->nume);
    for(i=0;i<3;i++)
    {
        scanf("%d",&(j->carti[i]));
    }
}

void afisare_jucator(struct Jucator *j)
{
    int i;
    printf("%s\n",j->nume);
    for(i=0;i<2;i++)
    {
        printf("%d\n",j->carti[i]);
    }
    printf("%d",j->carti[i]);
}

int suma(struct Jucator *j)
{
    int i,suma=0;
    for(i=0;i<3;i++)
    {
        suma+=j->carti[i];
    }
    return suma;
}
int nr_maxim (struct Jucator *j)
{
    int i,maxi=j->carti[0];
    for(i=1;i<3;i++)
    {
        if(maxi<j->carti[i])
        {
            maxi=j->carti[i];
        }
    }
    return maxi;
}
int main()
{
    
    int test,i,j;
    scanf("%d",&test);
    struct Jucator *jucator=NULL;
    switch(test)
    {
        case 1:
        {
            int nr_jucatori;
            scanf("%d",&nr_jucatori);
            jucator=(struct Jucator*) malloc(nr_jucatori*sizeof(struct Jucator));
            for(i=0;i<nr_jucatori;i++)
            {
                creare_jucator(jucator+i);
            }
            for(i=0;i<nr_jucatori;i++)
            {
                afisare_jucator(jucator+i);
                printf("\n");
            }
            break;
        }
        case 2:
        {
            int nr_jucatori;
            scanf("%d",&nr_jucatori);
            jucator=(struct Jucator*) malloc(nr_jucatori*sizeof(struct Jucator));
            for(i=0;i<nr_jucatori;i++)
            {
                creare_jucator(jucator+i);
            }   
            int suma_carti=suma(jucator);
            int index_jucator=0;
            for(i=1;i<nr_jucatori;i++)
            {
                if(suma_carti<suma(jucator+i))
                {
                    suma_carti=suma(jucator+i);
                    index_jucator=i;
                }
                if(suma_carti == suma(jucator+i))
                {
                    if(nr_maxim(jucator+i)>nr_maxim(jucator+index_jucator))
                    {
                        index_jucator=i;
                    }
                }
            }
            printf("%s",(jucator+index_jucator)->nume);
            break;
        }
    }
 
    return 0;
}