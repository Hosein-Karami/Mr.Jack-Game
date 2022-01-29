#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include "ability_of_lesterd.h"
#include "ability_of_js.h"
#include "delete.h"
#include "print_board.h"
#include "ability_of_jeremy.h"
#include "ability_of_sherlock.h"
#include "ability_of_watson.h"
#include "ability_of_william.h"
#include "move_of_stealthy.h"
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
object *newnode_6(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_2(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
int search2(object *temp,int card){
    if(temp==NULL )
        return 0;
    if(temp->value==9 || temp->value==11)
        return 0;
    while(temp!=NULL){
        if(temp->value==card)
            return 1;
        temp=temp->next;
    }
    return 0;
}
int function(object *temp,int jack,char characters[8][20]){
    int answer;
    while(1) {
        printf("Which character do you want to arrest?\n");
        for (int i = 0; i < 8; i++)
            printf("%d)%s\n", i + 1, characters[i]);
        while(1) {
            scanf("%d", &answer);
            if(1<=answer && answer<=8)
                break;
            Beep(900,690);
            printf("Choose among 1 and 8 :");
        }
        if(search2(temp,answer)==0){
            Beep(900, 690);
            printf("This character does not exist in this house.Do you want to choose another(1=YES,0=NO)?");
            int want;
            while(1) {
                scanf("%d", &want);
                if(want==0 || want==1)
                    break;
                Beep(900,690);
                printf("Choose between 1 and 0 :");
            }
            if(want)
                continue;
            else
                return 0;
        }
        object *temp_2 = temp;
        while (temp_2 != NULL) {
            if (temp_2->value == answer)
                break;
            temp_2 = temp_2->next;
        }
        if (jack != answer - 1)
            return -1;
        else {
            while (temp != NULL) {
                if (temp->value == jack + 1)
                    return 1;
                temp = temp->next;
            }
        }
    }
}
int function_2(int i,int j,int round,int turn,int jack,int card,char characters[8][20]){
    if(((round%2==1)&&((turn==2)||(turn==3)))||((round%2==0)&&((turn==1)||(turn==4)))){
        if(home[i][j].type_of_home==6 && card==jack)
            return 1;
        if(home[i][j].type_of_home==6 & card!=jack)
            return 2;
    }
    else if(((round%2==0)&&((turn==2)||(turn==3)))||((round%2==1)&&((turn==1)||(turn==4)))){
        if(home[i][j].objects->next==NULL)
            return 0;
        else{
            printf("Do you want to arrest anybody(1=YES,0=NO)?\n");
            int answer;
            while(1) {
                scanf("%d", &answer);
                if(answer==1 || answer==0)
                    break;
                Beep(900,690);
                printf("Choose between 1 and 0 :");
            }
            if(answer){
                int result=function(home[i][j].objects,jack,characters);
                     if(result==1)
                         return 2;
                     if(result==-1)
                         return -1;
                }
           }
       }
    return 0;
}
int search_tunnel_block(object *temp){
    while(temp!=NULL){
        if(temp->value==10)
            return 0;
        temp=temp->next;
    }
    return 1;
}
int movement(int *row,int *coloumn,int card,int visible){
    int answer,counter=1;
    while(1){
        if(counter==4)
            break;
        if(counter!=1){
            printf("Do you want to continue(1=YES,0=NO)?");
            while(1) {
                scanf("%d", &answer);
                if(answer==1 || answer==0)
                    break;
                Beep(900,690);
                printf("Choose between 1 and 0 :");
            }
            if(answer==0)
                break;
        }
        if(home[*row][*coloumn].type_of_home==4){
             if(search_tunnel_block(home[*row][*coloumn].objects)){
                 printf("Do you want to use tunnel(1=YES,0=NO)?");
                 while(1) {
                     scanf("%d", &answer);
                     if(answer==1 || answer==0)
                         break;
                     Beep(900,690);
                     printf("Choose between 1 and 0 :");
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
                         if(home[i-1][j-1].type_of_home==4 && (search_tunnel_block(home[i-1][j-1].objects))){
                             if(home[i-1][j-1].objects==NULL)
                                 home[i-1][j-1].objects= newnode_6(card);
                             else
                                 addend_2(home[i-1][j-1].objects, newnode_6(card));
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
            printf("Do you want to continue(1=YES,0=NO)?");
            while(1) {
                scanf("%d", &answer);
                if(answer==1 || answer==0)
                    break;
                else{
                    Beep(900,690);
                    printf("Please enter a valid input.\n");
                }
            }
            if(answer==0)
                break;
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
            if(home[(*row)-1][*coloumn].type_of_home!=3 && home[(*row)-1][*coloumn].type_of_home!=4 && home[(*row)-1][*coloumn].type_of_home!=6){
                Beep(900,690);
                printf("You can not go there.\n");
                continue;
            }
            if(home[(*row)-1][*coloumn].type_of_home==6 && home[(*row)-1][*coloumn].objects!=NULL){
                Beep(900,690);
                printf("The city exit is blocked.\n");
                continue;
            }
            if(home[(*row)-1][*coloumn].type_of_home==6 && visible==1){
                Beep(900,690);
                printf("Jack is visible and characters can not exit from city.\n");
                continue;
            }
            if(home[(*row)-1][*coloumn].objects==NULL)
                home[(*row)-1][*coloumn].objects=newnode_6(card);
            else
                addend_2(home[(*row)-1][*coloumn].objects, newnode_6(card));
            delete(*row,*coloumn,card);
            (*row)--;
            counter++;
        }
        else if(answer==2 && (*row)!=0 && (*coloumn)!=0){
            if(home[(*row)-1][(*coloumn)-1].type_of_home!=3 && home[(*row)-1][(*coloumn)-1].type_of_home!=4 && home[(*row)-1][(*coloumn)-1].type_of_home!=6){
                Beep(900,690);
                printf("You can not go there.\n");
                continue;
            }
            if(home[(*row)-1][(*coloumn)-1].type_of_home==6 && home[(*row)-1][(*coloumn)-1].objects!=NULL){
                Beep(900,690);
                printf("The city exit is blocked.\n");
                continue;
            }
            if(home[(*row)-1][(*coloumn)-1].type_of_home==6 && visible==1){
                Beep(900,690);
                printf("Jack is visible and characters can not exit from city.\n");
                continue;
            }
            if(home[(*row)-1][(*coloumn)-1].objects==NULL)
                home[(*row)-1][(*coloumn)-1].objects=newnode_6(card);
            else
                addend_2(home[(*row)-1][(*coloumn)-1].objects, newnode_6(card));
            delete(*row,*coloumn,card);
            (*row)--;
            (*coloumn)--;
            counter++;
        }
        else if(answer==3 && (*row)!=0 && (*coloumn)!=12){
            if(home[(*row)-1][(*coloumn)+1].type_of_home!=3 && home[(*row)-1][(*coloumn)+1].type_of_home!=4 && home[(*row)-1][(*coloumn)+1].type_of_home!=6){
                Beep(900,690);
                printf("You can not go there.\n");
                continue;
            }
            if(home[(*row)-1][(*coloumn)+1].type_of_home==6 && home[(*row)-1][(*coloumn)+1].objects!=NULL){
                Beep(900,690);
                printf("The city exit is blocked.\n");
                continue;
            }
            if(home[(*row)-1][(*coloumn)+1].type_of_home==6 && visible==1){
                Beep(900,690);
                printf("Jack is visible and characters can not exit from city.\n");
                continue;
            }
            if(home[(*row)-1][(*coloumn)+1].objects==NULL)
                home[(*row)-1][(*coloumn)+1].objects=newnode_6(card);
            else
                addend_2(home[(*row)-1][(*coloumn)+1].objects, newnode_6(card));
            delete(*row,*coloumn,card);
            (*row)--;
            (*coloumn)++;
            counter++;
        }
        else if(answer==4 && (*row)!=8){
            if(home[(*row)+1][*coloumn].type_of_home!=3 && home[(*row)+1][*coloumn].type_of_home!=4 && home[(*row)+1][*coloumn].type_of_home!=6){
                Beep(900,690);
                printf("You can not go there.\n");
                continue;
            }
            if(home[(*row)+1][*coloumn].type_of_home==6 && home[(*row)+1][*coloumn].objects!=NULL){
                Beep(900,690);
                printf("The city exit is blocked.\n");
                continue;
            }
            if(home[(*row)+1][*coloumn].type_of_home==6 && visible==1){
                Beep(900,690);
                printf("Jack is visible and characters can not exit from city.\n");
                continue;
            }
            if(home[(*row)+1][*coloumn].objects==NULL)
                home[(*row)+1][*coloumn].objects=newnode_6(card);
            else
                addend_2(home[(*row)+1][*coloumn].objects, newnode_6(card));
            delete(*row,*coloumn,card);
            (*row)++;
            counter++;
        }
        else if(answer==5 && (*row)!=8 && (*coloumn)!=0){
            if(home[(*row)+1][(*coloumn)-1].type_of_home!=3 && home[(*row)+1][(*coloumn)-1].type_of_home!=4 && home[(*row)+1][(*coloumn)-1].type_of_home!=6){
                Beep(900,690);
                printf("You can not go there.\n");
                continue;
            }
            if(home[(*row)+1][(*coloumn)-1].type_of_home==6 && home[(*row)+1][(*coloumn)-1].objects!=NULL){
                Beep(900,690);
                printf("The city exit is blocked.\n");
                continue;
            }
            if(home[(*row)+1][(*coloumn)-1].type_of_home==6 && visible==1){
                Beep(900,690);
                printf("Jack is visible and characters can not exit from city.\n");
                continue;
            }
            if(home[(*row)+1][(*coloumn)-1].objects==NULL)
                home[(*row)+1][(*coloumn)-1].objects=newnode_6(card);
            else
                addend_2(home[(*row)+1][(*coloumn)-1].objects, newnode_6(card));
            delete(*row,*coloumn,card);
            (*row)++;
            (*coloumn)--;
            counter++;
        }
        else if(answer==6 && (*row)!=8 && (*coloumn)!=12){
            if(home[(*row)+1][(*coloumn)+1].type_of_home!=3 && home[(*row)+1][(*coloumn)+1].type_of_home!=4 && home[(*row)+1][(*coloumn)+1].type_of_home!=6){
                Beep(900,690);
                printf("You can not go there.\n");
                continue;
            }
            if(home[(*row)+1][(*coloumn)+1].type_of_home==6 && home[(*row)+1][(*coloumn)+1].objects!=NULL){
                Beep(900,690);
                printf("The city exit is blocked.\n");
                continue;
            }
            if(home[(*row)+1][(*coloumn)+1].type_of_home==6 && visible==1){
                Beep(900,690);
                printf("Jack is visible and characters can not exit from city.\n");
                continue;
            }
            if(home[(*row)+1][(*coloumn)+1].objects==NULL)
                home[(*row)+1][(*coloumn)+1].objects=newnode_6(card);
            else
                addend_2(home[(*row)+1][(*coloumn)+1].objects, newnode_6(card));
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
void temp_board_2(char obj[10][3]){
    strcpy(obj[0],"SG");
    strcpy(obj[1],"IL");
    strcpy(obj[2],"WG");
    strcpy(obj[3],"SH");
    strcpy(obj[4],"JB");
    strcpy(obj[5],"JW");
    strcpy(obj[6],"MS");
    strcpy(obj[7],"JS");
    strcpy(obj[8],"ON");
    strcpy(obj[9],"BL");
    strcpy(obj[10],"NO");
}
int function_3(int start_i,int start_j,int final_i,int final_j,int sergent_i,int sergent_j){
    int temp_1=sqrt(pow((start_i-sergent_i),2)+pow((start_j-sergent_j),2));
    int temp_2=sqrt(pow((final_i-sergent_i),2)+pow((final_j-sergent_j),2));
    if(temp_2>temp_1)
        return 0;
    return 1;
}
void ability_of_goodley(int sergent_i,int sergent_j,char characters[8][20],int visible){
    int counter=0,i,j,answer;
    char obj[11][3];
    temp_board_2(obj);
    while(1){
        if(counter==3)
            break;
        printf("You can move characters %d houses.\n",3-counter);
        printf("Which character do you want to move(you should make them near to S.Goodley)?\n");
        for(int z=0;z<8;z++)
            printf("%d)%s\n",z+1,characters[z]);
        while(1) {
            scanf("%d", &answer);
            if(1<=answer && answer<=8)
                break;
            Beep(900,690);
            printf("Choose among 1 and 8 :");
        }
        if(answer==1){
            Beep(900,690);
            printf("You can not move yourself.choose another.\n");
            continue;
        }
        int row,coloumn,temp_counter;
        temp_counter=0;
        while(1){
            printf("Please enter the cordinate of %s:\n",characters[answer-1]);
            printf("Row : ");
            scanf("%d",&row);
            printf("Coloumn : ");
            scanf("%d",&coloumn);
            if(search2(home[row-1][coloumn-1].objects,answer))
                break;
            Beep(900,690);
            printf("Please enter the correct cordinate.\n");
        }
        row--;
        coloumn--;
        i=row;
        j=coloumn;
        while(1){
            if(answer==7)
                temp_counter= move_of_stealthy(&row,&coloumn,answer,visible);
            else
                temp_counter=movement(&row,&coloumn,answer,visible);
            if(function_3(i,j,row,coloumn,sergent_i,sergent_j)){
                if(counter+temp_counter-1>3){
                    Beep(900, 690);
                    printf("You can not do this move.\n");
                    delete(row,coloumn,answer);
                    if(home[i][j].objects==NULL)
                        home[i][j].objects= newnode_6(answer);
                    else
                        addend_2(home[i][j].objects, newnode_6(answer));
                    break;
                }
                counter+=temp_counter-1;
                print_board(obj);
                break;
            }
            else {
                Beep(900, 690);
                printf("You should make characters near to yourself.\n");
                delete(row, coloumn, answer);
                if (home[i][j].objects == NULL)
                    home[i][j].objects = newnode_6(answer);
                else
                    addend_2(home[i][j].objects, newnode_6(answer));
                row=i;
                coloumn=j;
            }
        }
        if(counter!=3) {
            printf("Do you want to continue(1=YES,0=NO)?");
            while(1) {
                scanf("%d", &answer);
                if(answer==1 || answer==0)
                    break;
                Beep(900, 690);
                printf("Choose between 1 and 0 : ");
            }
            if (answer == 0)
                break;
        }
    }
}
int move(int row,int coloumn,int round,int turn,int visible,int card,int jack,char characters[8][20],int *temp_for_sherlock){
    int result;
    if(card==0) {
        int want;
        printf("Do you want to use your ability before movement(1=YES,0=NO)?");
        while(1) {
            scanf("%d", &want);
            if(want==0 || want==1)
                break;
            Beep(900, 690);
            printf("Choose between 0 and 1 : ");
        }
        if(want)
            ability_of_goodley(row,coloumn,characters,visible);
        movement(&row,&coloumn,card+1,visible);
        if(want==0)
            ability_of_goodley(row,coloumn,characters,visible);
    }
    else if(card==1){
        printf("%s\n",characters[card]);
        movement(&row,&coloumn,card+1,visible);
        ability_of_lesterd();
    }
    else if(card==2){
        int want;
        printf("%s\n",characters[card]);
        printf("You can move or use your ability.which one do you want(1=Move,2=Ability)?");
        while(1) {
            scanf("%d", &want);
            if(want==1 || want==2)
                break;
            Beep(900, 690);
            printf("Choose between 1 and 2 : ");
        }
        if(want==2)
            ability_of_william(row,coloumn,characters);
        else{
            movement(&row,&coloumn,card+1,visible);
        }
    }
    else if(card==3){
        printf("%s\n",characters[card]);
        movement(&row,&coloumn,card+1,visible);
        ability_of_sherlock(temp_for_sherlock,characters);
        printf("If undrestand please press enter:\n");
        getchar();
    }
    else if(card==4){
        printf("%s\n",characters[card]);
        int answer;
        printf("Do you want to use your ability before moving(1=YES,0=NO)?");
        while(1) {
            scanf("%d", &answer);
            if(answer==1 || answer==0)
                break;
            Beep(900, 690);
            printf("Choose between 0 and 1 : ");
        }
        if(answer)
            ability_of_jeremy();
        movement(&row,&coloumn,card+1,visible);
        if(answer==0)
            ability_of_jeremy();
    }
    else if(card==5){
        movement(&row,&coloumn,card+1,visible);
        ability_of_watson(row,coloumn,0);
    }
    else if(card==6){
        move_of_stealthy(&row,&coloumn,card+1,visible);
    }
    else if(card==7){
        printf("%s\n",characters[card]);
        int answer;
        printf("Do you want to use your ability before moving(1=YES,0=NO)?");
        while(1) {
            scanf("%d", &answer);
            if(answer==1 || answer==0)
                break;
            Beep(900, 690);
            printf("Choose between 0 and 1 : ");
        }        if(answer)
            ability_of_JS();
        movement(&row,&coloumn,card+1,visible);
        if(answer==0)
            ability_of_JS();
      }
    result=function_2(row,coloumn,round,turn,jack,card,characters);
    return result;
}