#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "delete.h"
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
object *newnode_7(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_7(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
int search_tunnel_block_2(object *temp){
    while(temp!=NULL){
        if(temp->value==10)
            return 0;
        temp=temp->next;
    }
    return 1;
}
int move_of_stealthy(int *row,int *coloumn,int card,int visible){
     int counter=1,want,answer;
     while(1) {
         printf("How many houses do you want to go(between 1 to 4)?");
         scanf("%d", &want);
         if(1<=want && want<=4)
             break;
         Beep(900,690);
         printf("Please enter a correct input.\n");
     }
     while(counter<=want){
         if(home[*row][*coloumn].type_of_home==4){
             if(search_tunnel_block_2(home[*row][*coloumn].objects)){
                 printf("Do you want to use tunnel(1=YES,0=NO)?");
                 while(1) {
                     scanf("%d", &answer);
                     if(answer==0 || answer==1)
                         break;
                     Beep(900,690);
                     printf("Choose between 0 and 1 : ");
                 }
                 if(answer) {
                     int i, j;
                     while(1) {
                         printf("Please enter the row and coloumn of the tunnel that you want to go:\n");
                         printf("Row : ");
                         scanf("%d", &i);
                         printf("\n");
                         printf("Coloumn : ");
                         scanf("%d", &j);
                         if(home[i-1][j-1].type_of_home==4 && (search_tunnel_block_2(home[i-1][j-1].objects))){
                             if(home[i-1][j-1].objects==NULL)
                                 home[i-1][j-1].objects= newnode_7(card);
                             else
                                 addend_7(home[i-1][j-1].objects, newnode_7(card));
                             delete(*row,*coloumn,card);
                             *row=i-1;
                             *coloumn=j-1;
                             counter++;
                             break;
                         }
                         else {
                             Beep(900,690);
                             printf("You cant do this work with this inputs.please try again.\n");
                         }
                     }
                 }
             }
         }
         printf("Please enter the direction that want to go(1=North 2=North_West 3=North_East 4=South 5=South_West 6=South_East):");
         while(1){
             scanf("%d",&answer);
             if(1<=answer && answer<=6)
                 break;
             else {
                 Beep(900,690);
                 printf("Please inter a correct direction.\n");
             }
         }
         if(answer==1 && (*row)!=0){
             if(home[(*row)-1][*coloumn].type_of_home==5){
                 Beep(900,690);
                 printf("You can not go there.\n");
                 continue;
             }
             if(home[(*row)-1][*coloumn].type_of_home==6 && home[(*row)-1][*coloumn].objects!=NULL){
                 Beep(900,690);
                 printf("The city export is blocked.\n");
                 continue;
             }
             if(home[(*row)-1][*coloumn].type_of_home==6 && visible==1){
                 Beep(900,690);
                 printf("Jack is visible and characters can not exit from city.\n");
                 continue;
             }
             if(want==counter && home[(*row)-1][*coloumn].type_of_home!=3 && home[(*row)-1][*coloumn].type_of_home!=4  && home[(*row)-1][*coloumn].type_of_home!=6){
                 Beep(900,690);
                 printf("You should choose another direction.\n");
                 continue;
             }
             if(home[(*row)-1][*coloumn].objects==NULL)
                 home[(*row)-1][*coloumn].objects=newnode_7(card);
             else
                 addend_7(home[(*row)-1][*coloumn].objects, newnode_7(card));
             delete(*row,*coloumn,card);
             (*row)--;
             counter++;
         }
         else if(answer==2 && (*row)!=0 && (*coloumn)!=0){
             if(home[(*row)-1][(*coloumn)-1].type_of_home==5){
                 Beep(900,690);
                 printf("You can not go there.\n");
                 continue;
             }
             if(home[(*row)-1][(*coloumn)-1].type_of_home==6 && home[(*row)-1][(*coloumn)-1].objects!=NULL){
                 Beep(900,690);
                 printf("The city export is blocked.\n");
                 continue;
             }
             if(home[(*row)-1][(*coloumn)-1].type_of_home==6 && visible==1){
                 Beep(900,690);
                 printf("Jack is visible and characters can not exit from city.\n");
                 continue;
             }
             if(want==counter && home[(*row)-1][(*coloumn)-1].type_of_home!=3 && home[(*row)-1][(*coloumn)-1].type_of_home!=4  && home[(*row)-1][(*coloumn)-1].type_of_home!=6){
                 Beep(900,690);
                 printf("You should choose another direction.\n");
                 continue;
             }
             if(home[(*row)-1][(*coloumn)-1].objects==NULL)
                 home[(*row)-1][(*coloumn)-1].objects=newnode_7(card);
             else
                 addend_7(home[(*row)-1][(*coloumn)-1].objects, newnode_7(card));
             delete(*row,*coloumn,card);
             (*row)--;
             (*coloumn)--;
             counter++;
         }
         else if(answer==3 && (*row)!=0 && (*coloumn)!=12){
             if(home[(*row)-1][(*coloumn)+1].type_of_home==5){
                 Beep(900,690);
                 printf("You can not go there.\n");
                 continue;
             }
             if(home[(*row)-1][(*coloumn)+1].type_of_home==6 && home[(*row)-1][(*coloumn)+1].objects!=NULL){
                 Beep(900,690);
                 printf("The city export is blocked.\n");
                 continue;
             }
             if(home[(*row)-1][(*coloumn)+1].type_of_home==6 && visible==1){
                 Beep(900,690);
                 printf("Jack is visible and characters can not exit from city.\n");
                 continue;
             }
             if(want==counter && home[(*row)-1][(*coloumn)+1].type_of_home!=3 && home[(*row)-1][(*coloumn)+1].type_of_home!=4  && home[(*row)-1][(*coloumn)+1].type_of_home!=6){
                 Beep(900,690);
                 printf("You should choose another direction.\n");
                 continue;
             }
             if(home[(*row)-1][(*coloumn)+1].objects==NULL)
                 home[(*row)-1][(*coloumn)+1].objects=newnode_7(card);
             else
                 addend_7(home[(*row)-1][(*coloumn)+1].objects, newnode_7(card));
             delete(*row,*coloumn,card);
             (*row)--;
             (*coloumn)++;
             counter++;
         }
         else if(answer==4 && (*row)!=8){
             if(home[(*row)+1][*coloumn].type_of_home==5){
                 Beep(900,690);
                 printf("You can not go there.\n");
                 continue;
             }
             if(home[(*row)+1][*coloumn].type_of_home==6 && home[(*row)+1][*coloumn].objects!=NULL){
                 Beep(900,690);
                 printf("The city export is blocked.\n");
                 continue;
             }
             if(home[(*row)+1][*coloumn].type_of_home==6 && visible==1){
                 Beep(900,690);
                 printf("Jack is visible and characters can not exit from city.\n");
                 continue;
             }
             if(want==counter && home[(*row)+1][*coloumn].type_of_home!=3 && home[(*row)+1][*coloumn].type_of_home!=4  && home[(*row)+1][*coloumn].type_of_home!=6){
                 Beep(900,690);
                 printf("You should choose another direction.\n");
                 continue;
             }
             if(home[(*row)+1][*coloumn].objects==NULL)
                 home[(*row)+1][*coloumn].objects=newnode_7(card);
             else
                 addend_7(home[(*row)+1][*coloumn].objects, newnode_7(card));
             delete(*row,*coloumn,card);
             (*row)++;
             counter++;
         }
         else if(answer==5 && (*row)!=8 && (*coloumn)!=0){
             if(home[(*row)+1][(*coloumn)-1].type_of_home==5){
                 Beep(900,690);
                 printf("You can not go there.\n");
                 continue;
             }
             if(home[(*row)+1][(*coloumn)-1].type_of_home==6 && home[(*row)+1][(*coloumn)-1].objects!=NULL){
                 Beep(900,690);
                 printf("The city export is blocked.\n");
                 continue;
             }
             if(home[(*row)+1][(*coloumn)-1].type_of_home==6 && visible==1){
                 Beep(900,690);
                 printf("Jack is visible and characters can not exit from city.\n");
                 continue;
             }
             if(want==counter && home[(*row)+1][(*coloumn)-1].type_of_home!=3 && home[(*row)+1][(*coloumn)-1].type_of_home!=4  && home[(*row)+1][(*coloumn)-1].type_of_home!=6){
                 Beep(900,690);
                 printf("You should choose another direction.\n");
                 continue;
             }
             if(home[(*row)+1][(*coloumn)-1].objects==NULL)
                 home[(*row)+1][(*coloumn)-1].objects=newnode_7(card);
             else
                 addend_7(home[(*row)+1][(*coloumn)-1].objects, newnode_7(card));
             delete(*row,*coloumn,card);
             (*row)++;
             (*coloumn)--;
             counter++;
         }
         else if(answer==6 && (*row)!=8 && (*coloumn)!=12){
             if(home[(*row)+1][(*coloumn)+1].type_of_home==5){
                 Beep(900,690);
                 printf("You can not go there.\n");
                 continue;
             }
             if(home[(*row)+1][(*coloumn)+1].type_of_home==6 && home[(*row)+1][(*coloumn)+1].objects!=NULL){
                 Beep(900,690);
                 printf("The city export is blocked.\n");
                 continue;
             }
             if(home[(*row)+1][(*coloumn)+1].type_of_home==6 && visible==1){
                 Beep(900,690);
                 printf("Jack is visible and characters can not exit from city.\n");
                 continue;
             }
             if(want==counter && home[(*row)+1][(*coloumn)+1].type_of_home!=3 && home[(*row)+1][(*coloumn)+1].type_of_home!=4 && home[(*row)+1][(*coloumn)+1].type_of_home!=6){
                 Beep(900,690);
                 printf("You should choose another direction.\n");
                 continue;
             }
             if(home[(*row)+1][(*coloumn)+1].objects==NULL)
                 home[(*row)+1][(*coloumn)+1].objects=newnode_7(card);
             else
                 addend_7(home[(*row)+1][(*coloumn)+1].objects, newnode_7(card));
             delete(*row,*coloumn,card);
             (*row)++;
             (*coloumn)++;
             counter++;
         }
         else {
             Beep(900,690);
             printf("You can not go there.\n");
         }
     }
    return counter;
}