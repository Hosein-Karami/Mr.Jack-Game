#include <stdio.h>
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
int temp_ability(int i,int j){
    object *temp=home[i][j].objects;
     if(temp==NULL)
         return 0;
     while(temp!=NULL){
         if(temp->value==10)
             return 1;
         temp=temp->next;
     }
    return 0;
}