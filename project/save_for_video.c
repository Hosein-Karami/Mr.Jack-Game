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
void save_for_video(int round,int turn,int computer) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 13; j++)
            temp[i][j] = home[i][j].objects;
    }
    FILE *save;
    if(round==1 && turn==1) {
        if(computer)
             save = fopen("Video_c.bin", "wb");
        else
             save= fopen("Video.bin","wb");
    }
    else {
        if(computer)
               save = fopen("Video_c.bin", "ab");
        else
               save = fopen("Video.bin","ab");
    }
    fwrite(&round,sizeof(int),1,save);
    fwrite(&turn,sizeof(int),1,save);
    int x=0,counter=1;
    while(1){
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++){
                if(temp[i][j]==NULL)
                    fwrite(&x, sizeof(int),1,save);
                else{
                    fwrite(&(temp[i][j]->value), sizeof(int),1,save);
                    temp[i][j]=temp[i][j]->next;
                }
            }
        }
        if(counter==9)
            break;
        counter++;
    }
    fclose(save);
}