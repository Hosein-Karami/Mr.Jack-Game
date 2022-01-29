#include <stdio.h>
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
object *temp_undo[9][13];
void undo_save(int *cards,int *temp_for_sherlock){
     FILE *undo= fopen("Undo.bin","wb");
     if(undo==NULL){
         return;
     }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 13; j++)
            temp_undo[i][j] = home[i][j].objects;
    }
    int x=0,counter=1;
    for(int i=0;i<8;i++)
        fwrite(&cards[i], sizeof(int),1,undo);
    for(int i=0;i<8;i++)
        fwrite(&temp_for_sherlock[i], sizeof(int),1,undo);
    while(1){
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++){
                if(temp_undo[i][j]==NULL)
                    fwrite(&x, sizeof(int),1,undo);
                else{
                    fwrite(&(temp_undo[i][j]->value), sizeof(int),1,undo);
                    temp_undo[i][j]=temp_undo[i][j]->next;
                }
            }
        }
        if(counter==9)
            break;
        counter++;
    }
    fclose(undo);
}