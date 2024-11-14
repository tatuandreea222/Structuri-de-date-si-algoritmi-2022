include <stdio.h>
#include <stdlib.h>



int main()
{
    struct date_angajat
    {
      char nume[256];
      char prenume[256];
      float salariu_pe_ora;
      int nr_ore;
      float salariu_final;
    };
    struct date_angajati angajati_companie[100];
    
    int i, nr_angajati, ora_limita=160;
    float salariu_minim;
    
    do
    {
        //printf("introduceti nr angajati: ");
        scanf("%d", &nr_angajati);
        if((nr_angajati<1) || (nr_angajati>100))
        {
            printf("Nr invalid");
        }
    }while((nr_angajati<1) || (nr_angajati>100));
    
    for(i=0;i<nr_angajati;i++)
    {
        scanf("%s", angajati_companie[i].nume);
        scanf("%s", angajati_companie[i].prenume);
        scanf("%f", angajati_companie[i].salariu_pe_ora);
        scanf("%d", angajati_companie[i].nr_ore);
    }
    
    scanf("%f", &salariu_minim);
    for(i=0;i<nr_angajati;i++)
    {
        angajati_companie[i].salariu_final=angajati_companie[i].salariu_pe_ora*companie_angajati.nr_ore;
        if(companie_angajati.nr_ore>ora_limita)
        {
            angajati_companie[i].salariu_final+=angajati_companie[i].salariu_pe_ora*(angajati_companie[i].nr_ore-160)*0.5;
        }
    }
    
    for(i=0;i<nr_angajati;i++)
    {
        if(angajati_companie[i].salariu_final>salariu_minim)
        {
            printf("%s %s - %.2f\n", angajati_companie[i].nume, angajati_companie[i].prenume, angajati_companie[i].salariu_final);
        }
    }
    
    
    
    
    return 0;
}