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
object *newnode_3(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
map home[9][13];
void ability_of_JS(){
    int row,coloumn;
    bool end=false;
    while(end==false) {
        printf("please enter the row and coloumn of the house that you want to turn off the lamp:\n");
        printf("Row:");
        scanf("%d", &row);
        printf("Coloumn:");
        scanf("%d", &coloumn);
        if (home[row - 1][coloumn - 1].type_of_home == 2) {
            if(home[row-1][coloumn-1].objects==NULL){
                Beep(900,690);
                printf("This house does not have a on lamp.choose another.\n");
                continue;
            }
            while (1) {
                int row_2, coloumn_2;
                printf("Please enter the row and coloumn of the house that you want to turn on the lamp:\n");
                printf("Row:");
                scanf("%d", &row_2);
                printf("Coloumn:");
                scanf("%d", &coloumn_2);
                if (home[row_2 - 1][coloumn_2 - 1].type_of_home == 2) {
                    if(home[row_2-1][coloumn_2-1].objects!=NULL){
                        Beep(900,690);
                        printf("This house has a on lamp.choose another.\n");
                        continue;
                    }
                        home[row-1][coloumn-1].objects=NULL;
                        home[row_2 - 1][coloumn_2 - 1].objects=newnode_3(9);
                    end=true;
                    break;
                }
                else{
                    Beep(900,690);
                    printf("This house is not a house that can has a lamp.try again.\n");
                }
            }
        }
        else{
            Beep(900,690);
            printf("This house is not a house that can has a lamp.try again.\n");
        }
    }
}