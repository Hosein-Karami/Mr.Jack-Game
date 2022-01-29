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
void print_board(char obj[11][3]){
    printf("\n\n");
    system("cls");
    object *temp[9][13];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 13; j++)
            temp[i][j] = home[i][j].objects;
    }
    int index_i=-1,index_j;
    for(int i=0;i<=54;i++){
        if(i%6==0){
            printf("   ");
            for(int j=0;j<13;j++)
                printf("****     ");
            index_i++;
            printf("\n");
        }
        else if(i%6==1){
            index_j=0;
            printf("  ");
            for(int j=0;j<13;j++){
                if(home[index_i][index_j].type_of_home==1){
                    printf("* H  *   ");
                    index_j++;
                }
                else if(home[index_i][index_j].type_of_home==2){
                    printf("* L  *   ");
                    index_j++;
                }
                else if(home[index_i][index_j].type_of_home==3){
                    printf("*    *   ");
                    index_j++;
                }
                else if(home[index_i][index_j].type_of_home==4){
                    printf("* T  *   ");
                    index_j++;
                }
                else if(home[index_i][index_j].type_of_home==5){
                    printf("* E  *   ");
                    index_j++;
                }
                else{
                    printf("* EX *   ");
                    index_j++;
                }
            }
            printf("\n");
        }
        else if(i%6==2) {
            printf(" ");
            index_j = 0;
            for (int j = 0; j < 115;) {
                if (temp[index_i][index_j] == NULL) {
                    printf("*      * ");
                    j += 9;
                    index_j++;
                    continue;
                } else {
                    printf("*%s ", obj[temp[index_i][index_j]->value - 1]);
                    j += 5;
                    temp[index_i][index_j] = temp[index_i][index_j]->next;
                }
                if (temp[index_i][index_j] == NULL) {
                    printf("   ");
                    j += 4;
                } else {
                    printf("%s ", obj[temp[index_i][index_j]->value - 1]);
                    j += 4;
                    temp[index_i][index_j] = temp[index_i][index_j]->next;
                }
                printf("* ");
                index_j++;
            }
            printf("\n");
        }
        else if(i%6==3){
            index_j=0;
            printf("*");
            for(int j=0;j<115;){
                if(temp[index_i][index_j]==NULL){
                    printf("        *");
                    index_j++;
                    j+=9;
                    continue;
                }
                else{
                    printf("%s ",obj[temp[index_i][index_j]->value-1]);
                    j+=4;
                    temp[index_i][index_j]=temp[index_i][index_j]->next;
                }
                if(temp[index_i][index_j]==NULL){
                    printf("     *");
                    index_j++;
                    j+=6;
                    continue;
                }
                else{
                    printf("%s ",obj[temp[index_i][index_j]->value-1]);
                    j+=4;
                    temp[index_i][index_j]=temp[index_i][index_j]->next;
                }
                if(temp[index_i][index_j]==NULL){
                    printf("  *");
                    j+=4;
                    index_j++;
                    continue;
                }
                else{
                    printf("%s*",obj[temp[index_i][index_j]->value-1]);
                    temp[index_i][index_j]=temp[index_i][index_j]->next;
                    index_j++;
                    j+=4;
                }
            }
            printf("\n");
        }
        else if(i%6==4){
            printf(" ");
            index_j = 0;
            for (int j = 0; j < 115;) {
                if (temp[index_i][index_j] == NULL) {
                    printf("*      * ");
                    j += 9;
                    index_j++;
                    continue;
                } else {
                    printf("*%s ", obj[temp[index_i][index_j]->value - 1]);
                    j += 5;
                    temp[index_i][index_j] = temp[index_i][index_j]->next;
                }
                if (temp[index_i][index_j] == NULL) {
                    printf("   ");
                    j += 4;
                } else {
                    printf("%s ", obj[temp[index_i][index_j]->value - 1]);
                    j += 4;
                    temp[index_i][index_j] = temp[index_i][index_j]->next;
                }
                printf("* ");
                index_j++;
            }
            printf("\n");
        }
        else if(i%6==5){
            index_j=0;
            printf("  ");
            for(int j=0;j<115;){
                if(temp[index_i][index_j]==NULL){
                    printf("*    *   ");
                    j+=9;
                    index_j++;
                }
                else{
                    printf("* %s *   ",obj[temp[index_i][index_j]->value-1]);
                    index_j++;
                    j+=9;
                }
            }
            printf("\n");
        }
    }
}


