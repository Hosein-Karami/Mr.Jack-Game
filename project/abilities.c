#include <stdlib.h>
#include "temp_ability.h"
#include "delete.h"
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
object *newnode_temp(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_temp(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
void abilities(int a){
    int end=0,x,y;
    if(a==1){
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++){
                if(home[i][j].type_of_home==6 && home[i][j].objects!=NULL){
                    home[i][j].objects=NULL;
                    x=i;
                    y=j;
                    end=1;
                }
                if(end)
                    break;
            }
            if(end)
                break;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++){
                if(home[i][j].type_of_home==6 && home[i][j].objects==NULL && (i!=x || j!=y)){
                    home[i][j].objects= newnode_temp(11);
                    return;
                }
            }
        }
    }
    if(a==2){
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++){
                if(home[i][j].type_of_home==2 && home[i][j].objects!=NULL){
                    home[i][j].objects=NULL;
                    x=i;
                    y=j;
                    end=1;
                }
                if(end)
                    break;
            }
            if(end)
                break;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++){
                if(home[i][j].type_of_home==2 && home[i][j].objects==NULL && (i!=x || j!=y)){
                    home[i][j].objects= newnode_temp(9);
                    return;
                }
            }
        }
    }
    if(a==3){
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++){
                if(home[i][j].type_of_home==4 && temp_ability(i,j)){
                    delete(i,j,10);
                    x=i;
                    y=j;
                    end=1;
                }
                if(end)
                    break;
            }
            if(end)
                break;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++){
                if(home[i][j].type_of_home==4 && (temp_ability(i,j)==0) && (i!=x || j!=y)){
                    if(home[i][j].objects==NULL)
                        home[i][j].objects= newnode_temp(10);
                    else
                        addend_temp(home[i][j].objects, newnode_temp(10));
                    return;
                }
            }
        }
    }
}