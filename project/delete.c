#include <stdlib.h>
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
void delete(int i,int j,int card){
    int freee=0;
    if(home[i][j].objects->value==card) {
        if(home[i][j].objects->next!=NULL)
            freee=1;
        home[i][j].objects = home[i][j].objects->next;
        if(freee)
             free(home[i][j].objects->next);
        return;
    }
    if(home[i][j].objects->next->value==card){
        if(home[i][j].objects->next->next!=NULL)
            freee=1;
        home[i][j].objects->next=home[i][j].objects->next->next;
        if(freee)
            free(home[i][j].objects->next->next);
        return;
    }
    if(home[i][j].objects->next->next->value==card){
        if(home[i][j].objects->next->next->next!=NULL)
            freee=1;
        home[i][j].objects->next->next=home[i][j].objects->next->next->next;
        if(freee)
            free(home[i][j].objects->next->next->next);
        return;
    }
    if(home[i][j].objects->next->next->next->value==card){
        if(home[i][j].objects->next->next->next->next!=NULL)
            freee=1;
        home[i][j].objects->next->next->next=home[i][j].objects->next->next->next->next;
        if(freee)
            free(home[i][j].objects->next->next->next->next);
        return;
    }
    if(home[i][j].objects->next->next->next->next->value==card){
        if(home[i][j].objects->next->next->next->next->next!=NULL)
            freee=1;
        home[i][j].objects->next->next->next->next=home[i][j].objects->next->next->next->next->next;
        if(freee)
            free(home[i][j].objects->next->next->next->next->next);
        return;
    }
    if(home[i][j].objects->next->next->next->next->next->value==card){
        if(home[i][j].objects->next->next->next->next->next->next!=NULL)
            freee=1;
        home[i][j].objects->next->next->next->next->next=home[i][j].objects->next->next->next->next->next->next;
        if(freee)
            free(home[i][j].objects->next->next->next->next->next->next);
        return;
    }
    if(home[i][j].objects->next->next->next->next->next->next->value==card){
        if(home[i][j].objects->next->next->next->next->next->next->next!=NULL)
            freee=1;
        home[i][j].objects->next->next->next->next->next->next=home[i][j].objects->next->next->next->next->next->next->next;
        if(freee)
            free(home[i][j].objects->next->next->next->next->next->next->next);
        return;
    }
    if(home[i][j].objects->next->next->next->next->next->next->next->value==card){
        if(home[i][j].objects->next->next->next->next->next->next->next->next!=NULL)
            freee=1;
        home[i][j].objects->next->next->next->next->next->next->next=home[i][j].objects->next->next->next->next->next->next->next->next;
        if(freee)
            free(home[i][j].objects->next->next->next->next->next->next->next->next);
        return;
    }
}