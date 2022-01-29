#include <stdio.h>
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
map home[9][13];
bool search_4(object *temp,int card){
    if(temp==NULL )
        return false;
    if(temp->value==9 || temp->value==11)
        return false;
    while(temp!=NULL){
        if(temp->value==card)
            return true;
        temp=temp->next;
    }
    return false;
}
void ability_of_william(int i,int j,char character[8][20]){
     int answer;
     printf("\nSelect a character that you want to replace with:\n");
     for(int z=0;z<8;z++)
         printf("%d)%s\n",z+1,character[z]);
     while(1){
         scanf("%d",&answer);
         if(answer!=3)
             break;
         else {
             Beep(900,690);
             printf("You can not replace with yourself.choose another:");
         }
     }
     int select_i,select_j;
    object *temp_1,*temp_2;
     while(1) {
         printf("Please enter the cordinate of your selected character:\n");
         printf("Row :");
         scanf("%d", &select_i);
         printf("\nColoumn :");
         scanf("%d", &select_j);
         if(search_4(home[select_i-1][select_j-1].objects,answer)) {
             temp_1 = home[i][j].objects, temp_2 = home[select_i - 1][select_j - 1].objects;
             break;
         }
         else {
             Beep(900,690);
             printf("Please enter the correct cordinate.\n");
         }
     }
     while(1){
        if(temp_2->value==answer){
            temp_2->value=3;
            break;
        }
        temp_2=temp_2->next;
     }
     while(1){
        if(temp_1->value==3){
            temp_1->value=answer;
            break;
        }
        temp_1=temp_1->next;
     }

     printf("\n");
}