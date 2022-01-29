#include <stdio.h>
#include <stdbool.h>
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
bool search_character(int character,object *temp){
     if(temp==NULL)
         return false;
     while(temp!=NULL){
         if(temp->value==character)
             return true;
         temp=temp->next;
     }
    return false;
}
void cordinate(int *row,int *coloumn,int character){
     for(int i=0;i<9;i++){
         for(int j=0;j<13;j++) {
             if (home[i][j].type_of_home!=5 && home[i][j].type_of_home!=1) {
                 if (search_character(character, home[i][j].objects)) {
                     *row = i;
                     *coloumn = j;
                     return;
                 }
             }
         }
     }
}