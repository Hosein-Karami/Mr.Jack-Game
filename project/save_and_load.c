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
object *temp[9][13];
void save_and_load(int round,int player_jack,int jack,int *cards,int *temp_for_sherlock,int turn,int type_of_map,int *temp_innocent_save){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 13; j++)
            temp[i][j] = home[i][j].objects;
    }
    FILE *saves=fopen("save.bin","ab");
    if(saves==NULL){
        printf("Sorry we can not open the save file.\n");
        return;
    }
    fwrite(&type_of_map,sizeof(int),1,saves);
    fwrite(&round,sizeof(int),1,saves);
    fwrite(&turn,sizeof(int),1,saves);
    fwrite(&player_jack,sizeof(int),1,saves);
    fwrite(&jack, sizeof(int),1,saves);
    for(int i=0;i<8;i++)
        fwrite(&temp_innocent_save[i],sizeof(int),1,saves);
    int x=0,counter=1;
    for(int i=0;i<8;i++)
            fwrite(&cards[i], sizeof(int),1,saves);
    for(int i=0;i<8;i++)
        fwrite(&temp_for_sherlock[i], sizeof(int),1,saves);
    while(1){
    for(int i=0;i<9;i++){
        for(int j=0;j<13;j++){
            if(temp[i][j]==NULL)
                fwrite(&x, sizeof(int),1,saves);
            else{
                fwrite(&(temp[i][j]->value), sizeof(int),1,saves);
                temp[i][j]=temp[i][j]->next;
            }
        }
      }
    if(counter==9)
        break;
    counter++;
    }
    fclose(saves);
}

