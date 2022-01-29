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
object *newnode_cc(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_c(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
map home[9][13];
void load_c(int *round,int *jack,int *cards,int *temp_for_sherlock,int *turn,int save_temp,int *type_of_map,int *computer_role,int *innocents){
    FILE *load=fopen("save_c.bin","rb");
    if(load==NULL){
        printf("Sorry the load file did not open.\n");
        return;
    }
    fseek(load,1082*(save_temp-1)*sizeof(int),SEEK_SET);
    fread(computer_role,sizeof(int),1,load);
    fread(type_of_map,sizeof(int),1,load);
    fread(round, sizeof(int),1,load);
    fread(turn,sizeof(int),1,load);
    fread(jack,sizeof(int),1,load);
    for(int i=0;i<8;i++)
        fread(&innocents[i],sizeof(int),1,load);
    int temp,counter=1;
    for(int i=0;i<8;i++){
        fread(&cards[i],sizeof(int),1,load);
    }
    for(int i=0;i<8;i++)
        fread(&temp_for_sherlock[i], sizeof(int),1,load);
    while(1){
        for(int i=0;i<9;i++) {
            for(int j=0;j<13;j++) {
                fread(&temp, sizeof(int), 1, load);
                if (temp){
                    if(home[i][j].objects==NULL)
                        home[i][j].objects= newnode_cc(temp);
                    else
                        addend_c(home[i][j].objects, newnode_cc(temp));
                }
            }
        }
        if(counter==9)
            break;
        counter++;
    }
    fclose(load);
}