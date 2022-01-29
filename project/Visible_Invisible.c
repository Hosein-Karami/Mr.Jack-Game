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
int counter,m,n;
bool exist_character(int i,int j){
    counter=0;
    object *temp;
    temp=home[i][j].objects;
    if(temp==NULL)
        return false;
    while(temp!=NULL){
        if(1<=temp->value && temp->value<=8)
            counter++;
        temp=temp->next;
    }
    if(counter)
        return true;
    return false;
}
bool search_jack(int i,int j,int jack){
    object *temp=home[i][j].objects;
    while(temp!=NULL){
        if(temp->value==jack+1){
            n=i;
            m=j;
            return true;
        }
        temp=temp->next;
    }
    return false;
}
bool exist_on_lamp(int i,int j){
    if(home[i][j].objects==NULL)
        return false;
    if(home[i][j].objects->value==9)
        return true;
    return false;
}
bool search_1(int i,int j){
    if(i!=8) {
        if (exist_on_lamp(i + 1, j))
            return true;
    }
    if(i!=0) {
        if (exist_on_lamp(i - 1, j))
            return true;
    }
    if(i!=8 && j!=12) {
        if (exist_on_lamp(i + 1, j + 1))
            return true;
    }
    if(i!=8 && j!=0) {
        if (exist_on_lamp(i + 1, j - 1))
            return true;
    }
    if(i!=0 && j!=12) {
        if (exist_on_lamp(i - 1, j + 1))
            return true;
    }
    if(i!=0 && j!=0) {
        if (exist_on_lamp(i - 1, j - 1))
            return true;
    }
    return false;
}
bool temp_search(int i,int j){
    if(exist_character(i,j))
        return true;
    return false;
}
bool search_2(int i,int j){
    if(i!=8) {
        if (temp_search(i + 1, j))
            return true;
    }
    if(i!=0) {
        if (temp_search(i - 1, j))
            return true;
    }
    if(i!=8 && j!=12) {
        if (temp_search(i + 1, j + 1))
            return true;
    }
    if(i!=8 && j!=0) {
        if (temp_search(i + 1, j - 1))
            return true;
    }
    if(i!=0 && j!=12) {
        if (temp_search(i - 1, j + 1))
            return true;
    }
    if(i!=0 && j!=0) {
        if (temp_search(i - 1, j - 1))
            return true;
    }
    return false;
}
void print(int i,int j,int *temp_innocent_save){
    object *temp=home[i][j].objects;
    while(temp!=NULL){
         if(1<=temp->value && temp->value<=8) {
             temp_innocent_save[temp->value-1]=1;
         }
         temp=temp->next;
    }
}
int Visible_Invisible(int jack,char characters[8][20],int *innocents){
    int result;
     for(int i=0;i<9;i++){
         for(int j=0;j<13;j++){
             if(search_jack(i,j,jack))
                 break;
         }
     }
     for(int i=0;i<9;i++){
         for(int j=0;j<13;j++){
             if(exist_character(i,j)){
                 if(counter>1)
                     home[i][j].on=1;
                 else if(search_1(i,j))
                     home[i][j].on=1;
                 else if(search_2(i,j))
                     home[i][j].on=1;
             }
         }
     }
     if(home[n][m].on) {
         result=1;
         printf("\nJack is visible.\n");
         for(int i=0;i<9;i++){
             for(int j=0;j<13;j++){
                 if(exist_character(i,j)){
                     if(home[i][j].on==0)
                         print(i,j,innocents);
                 }
             }
         }
     }
     else {
         printf("\nJack is invisible.\n");
         result=0;
         for(int i=0;i<9;i++){
             for(int j=0;j<13;j++){
                 if(home[i][j].on)
                     print(i,j,innocents);
             }
         }
     }
     printf("These players are innocent:\n");
     for(int i=0;i<8;i++){
         if(innocents[i]!=0)
             printf("%s  ",characters[i]);
     }
     printf("\n");
     return result;
}