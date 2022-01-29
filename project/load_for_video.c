#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "print_board.h"
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
object *newnode_22(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_22(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
void load_for_video(char obj[11][3],int computer){
    FILE *load;
    if(computer)
        load= fopen("Video_c.bin","rb");
    else
        load=fopen("Video.bin","rb");
    int counter,round,turn,temp_2;
    while((fread(&round,sizeof(int),1,load))!=EOF){
       if(feof(load)) {
            system("cls");
            break;
       }
        counter=1;
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++)
                home[i][j].objects=NULL;
        }
        fread(&turn,sizeof(int),1,load);
        while(counter<=9){
            for(int i=0;i<9;i++) {
                for(int j=0;j<13;j++) {
                    fread(&temp_2, sizeof(int), 1, load);
                    if (temp_2){
                        if(home[i][j].objects==NULL)
                            home[i][j].objects= newnode_22(temp_2);
                        else
                            addend_22(home[i][j].objects, newnode_22(temp_2));
                    }
                }
            }
            counter++;
        }
        print_board(obj);
        printf("Round : %d    Turn : %d",round,turn);
        Sleep(6000);
    }
}
