#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Punct{
    float x;
    float y;
};

struct Patrulater{
    struct Punct punct[4];
};

float distanta(struct Punct p1, struct Punct p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int main(){
    int nr_patrulatere;
    int test;
    struct Patrulater *p_patrulater = NULL;
    
    scanf("%d", &nr_patrulatere);
    
    p_patrulater = malloc(nr_patrulatere*sizeof(struct Patrulater));
    
    for (int i=0; i<nr_patrulatere; i++){
        for (int j=0; j<4; j++){
            scanf("%f%f", &((p_patrulater+i)->punct[j]).x, &((p_patrulater+i)->punct[j]).y);
        }
    }
    
    scanf("%d", &test);
    
    switch(test){
        case 1:{
            for (int i=0; i<nr_patrulatere; i++){
                for (int j=0; j<4; j++){
                    printf("%f %f\n", ((p_patrulater+i)->punct[j]).x, ((p_patrulater+i)->punct[j]).y);
                }
            }
            break;
        }
        case 2:{
            int count = 0;
            for (int i=0; i<nr_patrulatere; i++){
                float lat1, lat2, lat3, lat4;
                lat1 = distanta((p_patrulater+i)->punct[0], (p_patrulater+i)->punct[1]);
                lat2 = distanta((p_patrulater+i)->punct[1], (p_patrulater+i)->punct[2]);
                lat3 = distanta((p_patrulater+i)->punct[2], (p_patrulater+i)->punct[3]);
                lat4 = distanta((p_patrulater+i)->punct[3], (p_patrulater+i)->punct[0]);
                // printf("%f %f %f %f\n", lat1, lat2, lat3, lat4);
                if ((lat1 == lat2) && (lat2 == lat3) && (lat3 == lat4)){
                    count++;
                }
            }
            printf("%d", count);
            break;
        }
    }
    
    
    return 0;
}