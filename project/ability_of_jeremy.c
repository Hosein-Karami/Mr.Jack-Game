#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
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
object *newnode_5(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_5(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
map home[9][13];
bool search_3(object *temp){
    if(temp==NULL )
        return false;
    while(temp!=NULL){
        if(temp->value==10)
            return true;
        temp=temp->next;
    }
    return false;
}
void delete_3(int i,int j,int card){
    if(home[i][j].objects->value==card) {
        home[i][j].objects = home[i][j].objects->next;
        return;
    }
    if(home[i][j].objects->next->value==card){
        home[i][j].objects->next=home[i][j].objects->next->next;
        return;
    }
    if(home[i][j].objects->next->next->value==card){
        home[i][j].objects->next->next=home[i][j].objects->next->next->next;
        return;
    }
    if(home[i][j].objects->next->next->next->value==card){
        home[i][j].objects->next->next->next=home[i][j].objects->next->next->next->next;
        return;
    }
    if(home[i][j].objects->next->next->next->next->value==card){
        home[i][j].objects->next->next->next->next=home[i][j].objects->next->next->next->next->next;
        return;
    }
    if(home[i][j].objects->next->next->next->next->next->value==card){
        home[i][j].objects->next->next->next->next->next=home[i][j].objects->next->next->next->next->next->next;
        return;
    }
    if(home[i][j].objects->next->next->next->next->next->next->value==card){
        home[i][j].objects->next->next->next->next->next->next=home[i][j].objects->next->next->next->next->next->next->next;
        return;
    }
    if(home[i][j].objects->next->next->next->next->next->next->next->value==card){
        home[i][j].objects->next->next->next->next->next->next->next=home[i][j].objects->next->next->next->next->next->next->next->next;
        return;
    }
}
void ability_of_jeremy() {
     int row,coloumn;
     while(1){
         printf("Please enter the cordinate of the house that you want to delete the tunnel blocker:\n");
         printf("Row : ");
         scanf("%d",&row);
         printf("Coloumn : ");
         scanf("%d",&coloumn);
         if(home[row-1][coloumn-1].type_of_home!=4){
             Beep(900,690);
             printf("This house can not has a tunnel blocker,Choose another.\n");
             continue;
         }
         if(search_3(home[row-1][coloumn-1].objects)==false){
             Beep(900,690);
             printf("This house does not have a tunnel blocker,Choose another.\n");
             continue;
         }
         delete_3(row-1,coloumn-1,10);
         while(1){
             printf("Please enter the cordinate of the house that you want to place the tunnel blocker:\n");
             printf("Row : ");
             scanf("%d",&row);
             printf("Coloumn : ");
             scanf("%d",&coloumn);
             if(home[row-1][coloumn-1].type_of_home!=4){
                 Beep(900,690);
                 printf("This house can not has a tunnel blocker,Choose another.\n");
                 continue;
             }
             if(search_3(home[row-1][coloumn-1].objects)){
                 Beep(900,690);
                 printf("This house has a tunnel blocker,Choose another.\n");
                 continue;
             }
             if(home[row-1][coloumn-1].objects==NULL)
                 home[row-1][coloumn-1].objects= newnode_5(10);
             else
                 addend_5(home[row-1][coloumn-1].objects, newnode_5(10));
             break;
         }
         break;
     }
}

