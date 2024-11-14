#include <stdio.h>
#include <stdlib.h>

struct Persoana
{
  char nume[10];
  int identificator;
  int secventa[20];
  float putere;
  float distanta;
};

int main()
{
    int nr_persoane,i,j,c;
    scanf("%d",&nr_persoane);
    struct Persoana *persoana=NULL;
    persoana=(struct Persoana*)malloc(nr_persoane*sizeof(struct Persoana));
    for(i=0;i<nr_persoane;i++)
    {
        scanf("%s",&((persoana+i)->nume));
        scanf("%d",&((persoana+i)->identificator));
        for(j=0;j<20;j++)
        {
            scanf("%d",&((persoana+i)->secventa[j]));
        }
    }
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        {
            for(i=0;i<nr_persoane;i++)
            {
                printf("%s\n",(persoana+i)->nume);
                printf("%d\n",(persoana+i)->identificator);
                for(j=0;j<20;j++)
                {
                    printf("%d ",(persoana+i)->secventa[j]);
                }
                printf("\n");
            }
            break;
        }
        case 2:
        {
            int P,P_maxi, contor;
            for(i=0;i<nr_persoane;i++)
            {
                (persoana+i)->putere=0;
                for(j=0;j<20;j++)
                {
                    (persoana+i)->putere+=((persoana+i)->secventa[j])*((persoana+i)->secventa[j]);
                }
                (persoana+i)->putere= (persoana+i)->putere/20.0;
            }
            P_maxi=persoana->putere;
            for(i=1;i<nr_persoane;i++)
            {
                if(P_maxi<(persoana+i)->putere)
                {
                    P_maxi=(persoana+i)->putere;
                    contor=i;
                }
            }
            printf("%s\n",(persoana+contor)->nume);
            break;
        }
        case 3:
        {
            int identificator_nou;
            scanf("%d",&identificator_nou);
            for(i=0;i<nr_persoane;i++)
            {
                if((persoana+i)->identificator==identificator_nou)
                {
                    printf("%s\n",(persoana+i)->nume);
                }
            }
            break;
        }
        case 4:
        {
            int secventa_noua[20],semnal_ap,contor;
            for(i=0;i<20;i++)
            {
                scanf("%d",&secventa_noua[i]);
            }
            for(i=0;i<nr_persoane;i++)
            {
                (persoana+i)->distanta=0;
                for(j=0;j<20;j++)
                {
                    (persoana+i)->distanta+=(((persoana+i)->secventa[j])-secventa_noua[j])*(((persoana+i)->secventa[j])-secventa_noua[j]);
                }
            }
            semnal_ap=persoana->distanta;
            for(i=1;i<nr_persoane;i++)
            {
                if(semnal_ap>(persoana+i)->distanta)
                {
                    semnal_ap=(persoana+i)->distanta;
                    contor=i;
                }
            }
            printf("%s\n",(persoana+contor)->nume);
            break;
        }
    }
    return 0;
}