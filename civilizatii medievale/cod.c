#include <stdio.h>
#include <stdlib.h>

struct Muncitori{
    int fermieri;
    int padurari;
    int fierari;
    int mineri;
};

struct Soldati{
    int cavaleri;
    int arcasi;
    int calareti;
    int pozitii[10];
    // char cav;
    // char cav2[20]; // cav2 <-> &cav2[0]
};

struct Comercianti{
    int negustori_ambulanti;
    int negustori_sedentari;
};

struct Civilizatie{
    struct Muncitori muncitori; // <-> int muncitori
    struct Soldati soldati;
    struct Comercianti comercianti;
    int populatie_totala;
    int nr_soldati;
};

void initializare_civilizatie(struct Civilizatie * p){
    p->populatie_totala = 0;
    p->nr_soldati = 0;
    // Initializare muncitori:
    scanf("%d", &((p->muncitori).fermieri));
    p->populatie_totala += (p->muncitori).fermieri;
    scanf("%d", &((p->muncitori).padurari));
    p->populatie_totala += (p->muncitori).padurari;
    scanf("%d", &((p->muncitori).fierari));
    p->populatie_totala += (p->muncitori).fierari;
    scanf("%d", &((p->muncitori).mineri));
    p->populatie_totala += (p->muncitori).mineri;
    
    // Initializare Soldati:
    scanf("%d", &((p->soldati).cavaleri));
    p->populatie_totala += (p->soldati).cavaleri;
    p->nr_soldati += (p->soldati).cavaleri;
    scanf("%d", &((p->soldati).arcasi));
    p->populatie_totala += (p->soldati).arcasi;
    p->nr_soldati += (p->soldati).arcasi;
    scanf("%d", &((p->soldati).calareti));
    p->populatie_totala += (p->soldati).calareti;
    p->nr_soldati += (p->soldati).calareti;
    // scanf("%c", &(p->soldati).cav);
    // scanf("%s", (p->soldati).cav2); // <-> scanf("%s", &(p->soldati).cav2[0]);
    
    // Initializare Comercianti:
    scanf("%d", &((p->comercianti).negustori_ambulanti));
    scanf("%d", &((p->comercianti).negustori_sedentari));
}

void afisare_civilizatie(struct Civilizatie * p){
    printf("%d\n", ((p->muncitori).fermieri));
    printf("%d\n", ((p->muncitori).padurari));
    printf("%d\n", ((p->muncitori).fierari));
    printf("%d\n", ((p->muncitori).mineri));
    
    printf("%d\n", ((p->soldati).cavaleri));
    printf("%d\n", ((p->soldati).arcasi));
    printf("%d\n", ((p->soldati).calareti));
    
    printf("%d\n", ((p->comercianti).negustori_ambulanti));
    printf("%d\n", ((p->comercianti).negustori_sedentari));
}

int main(){
    int test;
    struct Civilizatie * p_civ = NULL;
    
    scanf("%d", &test);
    
    switch(test){
        case 1:{
            int nr_civilizatii;
            scanf("%d", &nr_civilizatii);
            
            p_civ = malloc(nr_civilizatii*sizeof(struct Civilizatie)); // alocare memorie in mod dinamic
            for (int i=0; i<nr_civilizatii; i++){
                initializare_civilizatie(p_civ+i);
            }
            
            printf("%d\n", nr_civilizatii);
            for (int i=0; i<nr_civilizatii; i++){
                afisare_civilizatie(p_civ+i);
            }
            break;
        }
        case 2:{
            int nr_civilizatii;
            scanf("%d", &nr_civilizatii);
            
            p_civ = malloc(nr_civilizatii*sizeof(struct Civilizatie)); // alocare memorie in mod dinamic
            for (int i=0; i<nr_civilizatii; i++){
                initializare_civilizatie(p_civ+i);
            }
            
            // for (int i=0; i<nr_civilizatii; i++){
            //     printf("Civilizatia %d - populatie totala:%d\tnr. total soldati:%d\n", i, (p_civ+i)->populatie_totala, (p_civ+i)->nr_soldati);
            // }
            
            int pop_max = p_civ->populatie_totala;
            int idx_pop_max = 0;
            for (int i=1; i<nr_civilizatii; i++){
                if (((p_civ+i)->populatie_totala) > pop_max){
                    pop_max = (p_civ+i)->populatie_totala;
                    idx_pop_max = i;
                }
                if (((p_civ+i)->populatie_totala) == pop_max){
                    if ((p_civ+i)->nr_soldati > (p_civ+idx_pop_max)->nr_soldati){
                        idx_pop_max = i;
                    }
                }
            }
            
            printf("%d\n", idx_pop_max);
            
            break;
        }
    }
    
    return 0;
}