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
object *newnode_2(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
map home[9][13];
void save_and_load_2(int *round,int *player_jack,int *jack,int *cards,int *temp_for_sherlock,int *turn,int save_temp,int *type_of_map,int *temp_innocent_save){
    FILE *load=fopen("save.bin","rb");
    if(load==NULL){
        printf("Sorry the load file did not open.\n");
        return;
    }
    fseek(load,1082*(save_temp-1)*sizeof(int),SEEK_SET);
    fread(type_of_map,sizeof(int),1,load);
    fread(round, sizeof(int),1,load);
    fread(turn,sizeof(int),1,load);
    fread(player_jack,sizeof(int),1,load);
    fread(jack,sizeof(int),1,load);
    for(int i=0;i<8;i++)
        fread(&temp_innocent_save[i],sizeof(int),1,load);
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
                          home[i][j].objects= newnode_2(temp);
                      else
                          addend(home[i][j].objects, newnode_2(temp));
                }
            }
        }
        if(counter==9)
            break;
        counter++;
    }
    fclose(load);
}