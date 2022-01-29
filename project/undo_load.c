#include <stdio.h>
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
object *newnode_undo(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_undo(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}

void undo_load(int *cards,int *temp_for_sherlock){
    FILE *undo= fopen("Undo.bin","rb");
    if(undo==NULL){
        printf("Sorry.we can not open the undo file.\n");
        return;
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<13;j++)
            home[i][j].objects=NULL;
    }
    for(int i=0;i<8;i++){
        fread(&cards[i],sizeof(int),1,undo);
    }
    for(int i=0;i<8;i++)
        fread(&temp_for_sherlock[i], sizeof(int),1,undo);
    int temp,counter=1;
    while(1){
        for(int i=0;i<9;i++) {
            for(int j=0;j<13;j++) {
                fread(&temp, sizeof(int), 1, undo);
                if (temp){
                    if(home[i][j].objects==NULL)
                        home[i][j].objects= newnode_undo(temp);
                    else
                        addend_undo(home[i][j].objects, newnode_undo(temp));
                }
            }
        }
        if(counter==9)
            break;
        counter++;
    }
    fclose(undo);
}