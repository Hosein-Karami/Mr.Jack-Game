#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
object *newnode_4(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
map home[9][13];
bool search_6(object *temp){
    if(temp==NULL )
        return false;
    while(temp!=NULL){
        if(temp->value==11)
            return true;
        temp=temp->next;
    }
    return false;
}
void ability_of_lesterd(){
    int row,coloumn;
    while(1){
        printf("Please enter the cordinate of the house that you want to delete the city blocker:\n");
        printf("Row : ");
        scanf("%d",&row);
        printf("Coloumn : ");
        scanf("%d",&coloumn);
        if(home[row-1][coloumn-1].type_of_home!=6){
            Beep(900,690);
            printf("This house can not has a city blocker,Choose another.\n");
            continue;
        }
        if(search_6(home[row-1][coloumn-1].objects)==false){
            Beep(900,690);
            printf("This house does not have a city blocker,Choose another.\n");
            continue;
        }
        home[row-1][coloumn-1].objects=NULL;
        while(1){
            printf("Please enter the cordinate of the house that you want to place the city blocker:\n");
            printf("Row : ");
            scanf("%d",&row);
            printf("Coloumn : ");
            scanf("%d",&coloumn);
            if(home[row-1][coloumn-1].type_of_home!=6){
                Beep(900,690);
                printf("This house can not has a city blocker,Choose another.\n");
                continue;
            }
            if(search_6(home[row-1][coloumn-1].objects)){
                Beep(900,690);
                printf("This house has a city blocker,Choose another.\n");
                continue;
            }
                home[row-1][coloumn-1].objects= newnode_4(11);
            break;
        }
        break;
    }
}