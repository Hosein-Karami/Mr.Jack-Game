#include <time.h>
#include <stdlib.h>
#include "cordinate.h"
typedef struct st{
    int value;
    struct st *next;
    struct st *pervious;
}object;
typedef struct st_1{
    object *objects;
    int type_of_home;
    int on;
}map;
map home[9][13];
void ability_of_william_c(int i,int j){
    time_t t = time(NULL);
    srand(t);
    int answer;
    while(1){
        answer=(rand()%8)+1;
        if(answer!=3)
            break;
    }
    int select_i,select_j;
    object *temp_1,*temp_2;
    cordinate(&select_i,&select_j,answer);
    temp_1 = home[i][j].objects, temp_2 = home[select_i][select_j].objects;
    while(1){
        if(temp_2->value==answer){
            temp_2->value=3;
            break;
        }
        temp_2=temp_2->next;
    }
    while(1){
        if(temp_1->value==3){
            temp_1->value=answer;
            break;
        }
        temp_1=temp_1->next;
    }
}