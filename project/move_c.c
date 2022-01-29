#include <time.h>
#include <stdlib.h>
#include "cordinate.h"
#include "move_stealthy_c.h"
#include "ability_of_william_c.h"
#include "delete.h"
#include "ability_of_sherlock_c.h"
#include "ability_of_watson.h"
#include "abilities.h"
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
object *newnode_11(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_11(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
int search_tunnel_block_c(object *temp){
    while(temp!=NULL){
        if(temp->value==10)
            return 0;
        temp=temp->next;
    }
    return 1;
}
void tunnel_c(int *row,int *coloumn,int card,int *counter){
    for(int i=0;i<9;i++){
        for(int j=0;j<13;j++){
            if((i!=*row || j!=*coloumn) && home[i][j].type_of_home==4 && search_tunnel_block_c(home[i][j].objects)){
                if(home[i][j].objects==NULL)
                    home[i][j].objects= newnode_11(card);
                else
                    addend_11(home[i][j].objects, newnode_11(card));
                delete(*row,*coloumn,card);
                *row=i;
                *coloumn=j;
                (*counter)++;
                return;
            }
        }
    }
}
int search_cc(object *temp,int card){
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
int function_cc(object *temp,int jack){
    int answer;
    time_t t = time(NULL);
    srand(t);
    while(1) {
        answer=(rand()%8)+1;
        if(search_cc(temp,answer)==0){
            int want;
            want=(rand()%2);
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
int function_c(int i,int j,int round,int turn,int jack,int card){
    time_t t = time(NULL);
    srand(t);
    if(((round%2==1)&&((turn==2)||(turn==3)))||((round%2==0)&&((turn==1)||(turn==4)))){
        if(home[i][j].type_of_home==6 && card==jack)
            return 1;
        if(home[i][j].type_of_home==6 && card!=jack)
            return -1;
    }
    else if(((round%2==0)&&((turn==2)||(turn==3)))||((round%2==1)&&((turn==1)||(turn==4)))){
        if(home[i][j].objects->next==NULL)
            return 0;
        else{
            int answer;
            answer=(rand()%2);
            if(answer){
                int result=function_cc(home[i][j].objects,jack);
                if(result==1)
                    return 2;
                if(result==-1)
                    return -1;
            }
        }
    }
    return 0;
}
int movement_c(int *row,int *coloumn,int card,int visible){
    int answer,counter=1;
    time_t t = time(NULL);
    srand(t);
    while(1) {
        if (counter == 4)
            break;
        if (counter != 1) {
            answer = (rand() % 2);
            if (answer == 0)
                break;
        }
        if (home[*row][*coloumn].type_of_home == 4) {
            if (search_tunnel_block_c(home[*row][*coloumn].objects)) {
                answer = (rand() % 2);
                if (answer)
                    tunnel_c(row, coloumn, card, &counter);
            }
            answer = (rand() % 2);
            if (answer == 0)
                break;
        }
        answer = (rand() % 6) + 1;
        if (answer == 1 && (*row) != 0) {
            if (home[(*row) - 1][*coloumn].type_of_home != 3 && home[(*row) - 1][*coloumn].type_of_home != 4 && home[(*row) - 1][*coloumn].type_of_home != 6)
                continue;
            if (home[(*row) - 1][*coloumn].type_of_home == 6 && home[(*row) - 1][*coloumn].objects != NULL)
                continue;
            if (home[(*row) - 1][*coloumn].type_of_home == 6 && visible == 1)
                continue;
            if (home[(*row) - 1][*coloumn].objects == NULL)
                home[(*row) - 1][*coloumn].objects = newnode_11(card);
            else
                addend_11(home[(*row) - 1][*coloumn].objects, newnode_11(card));
            delete(*row, *coloumn, card);
            (*row)--;
            counter++;
        } else if (answer == 2 && (*row) != 0 && (*coloumn) != 0) {
            if (home[(*row) - 1][(*coloumn) - 1].type_of_home != 3 &&
                home[(*row) - 1][(*coloumn) - 1].type_of_home != 4 &&
                home[(*row) - 1][(*coloumn) - 1].type_of_home != 6)
                continue;
            if (home[(*row) - 1][(*coloumn) - 1].type_of_home == 6 && home[(*row) - 1][(*coloumn) - 1].objects != NULL)
                continue;
            if (home[(*row) - 1][(*coloumn) - 1].type_of_home == 6 && visible == 1)
                continue;
            if (home[(*row) - 1][(*coloumn) - 1].objects == NULL)
                home[(*row) - 1][(*coloumn) - 1].objects = newnode_11(card);
            else
                addend_11(home[(*row) - 1][(*coloumn) - 1].objects, newnode_11(card));
            delete(*row, *coloumn, card);
            (*row)--;
            (*coloumn)--;
            counter++;
        } else if (answer == 3 && (*row) != 0 && (*coloumn) != 12) {
            if (home[(*row) - 1][(*coloumn) + 1].type_of_home != 3 &&
                home[(*row) - 1][(*coloumn) + 1].type_of_home != 4 &&
                home[(*row) - 1][(*coloumn) + 1].type_of_home != 6)
                continue;
            if (home[(*row) - 1][(*coloumn) + 1].type_of_home == 6 && home[(*row) - 1][(*coloumn) + 1].objects != NULL)
                continue;
            if (home[(*row) - 1][(*coloumn) + 1].type_of_home == 6 && visible == 1)
                continue;
            if (home[(*row) - 1][(*coloumn) + 1].objects == NULL)
                home[(*row) - 1][(*coloumn) + 1].objects = newnode_11(card);
            else
                addend_11(home[(*row) - 1][(*coloumn) + 1].objects, newnode_11(card));
            delete(*row, *coloumn, card);
            (*row)--;
            (*coloumn)++;
            counter++;
        } else if (answer == 4 && (*row) != 8) {
            if (home[(*row) + 1][*coloumn].type_of_home != 3 && home[(*row) + 1][*coloumn].type_of_home != 4 &&
                home[(*row) + 1][*coloumn].type_of_home != 6)
                continue;
            if (home[(*row) + 1][*coloumn].type_of_home == 6 && home[(*row) + 1][*coloumn].objects != NULL)
                continue;
            if (home[(*row) + 1][*coloumn].type_of_home == 6 && visible == 1)
                continue;
            if (home[(*row) + 1][*coloumn].objects == NULL)
                home[(*row) + 1][*coloumn].objects = newnode_11(card);
            else
                addend_11(home[(*row) + 1][*coloumn].objects, newnode_11(card));
            delete(*row, *coloumn, card);
            (*row)++;
            counter++;
        } else if (answer == 5 && (*row) != 8 && (*coloumn) != 0) {
            if (home[(*row) + 1][(*coloumn) - 1].type_of_home != 3 &&
                home[(*row) + 1][(*coloumn) - 1].type_of_home != 4 &&
                home[(*row) + 1][(*coloumn) - 1].type_of_home != 6)
                continue;
            if (home[(*row) + 1][(*coloumn) - 1].type_of_home == 6 && home[(*row) + 1][(*coloumn) - 1].objects != NULL)
                continue;
            if (home[(*row) + 1][(*coloumn) - 1].type_of_home == 6 && visible == 1)
                continue;
            if (home[(*row) + 1][(*coloumn) - 1].objects == NULL)
                home[(*row) + 1][(*coloumn) - 1].objects = newnode_11(card);
            else
                addend_11(home[(*row) + 1][(*coloumn) - 1].objects, newnode_11(card));
            delete(*row, *coloumn, card);
            (*row)++;
            (*coloumn)--;
            counter++;
        } else if (answer == 6 && (*row) != 8 && (*coloumn) != 12) {
            if (home[(*row) + 1][(*coloumn) + 1].type_of_home != 3 &&
                home[(*row) + 1][(*coloumn) + 1].type_of_home != 4 &&
                home[(*row) + 1][(*coloumn) + 1].type_of_home != 6)
                continue;
            if (home[(*row) + 1][(*coloumn) + 1].type_of_home == 6 && home[(*row) + 1][(*coloumn) + 1].objects != NULL)
                continue;
            if (home[(*row) + 1][(*coloumn) + 1].type_of_home == 6 && visible == 1)
                continue;
            if (home[(*row) + 1][(*coloumn) + 1].objects == NULL)
                home[(*row) + 1][(*coloumn) + 1].objects = newnode_11(card);
            else
                addend_11(home[(*row) + 1][(*coloumn) + 1].objects, newnode_11(card));
            delete(*row, *coloumn, card);
            (*row)++;
            (*coloumn)++;
            counter++;
        }
    }
    return counter;
}
void ability_of_goodley_c(int visible){
    int counter=0,answer,temp_counter;
    while(1){
        if(counter>=3)
            break;
        answer=(rand()%8)+1;
        if(answer==1)
            continue;
        int row,coloumn;
        temp_counter=0;
        cordinate(&row,&coloumn,answer);
            if(answer==7)
                temp_counter= move_stealthy_c(&row,&coloumn,answer,visible);
            else
                temp_counter=movement_c(&row,&coloumn,answer,visible);
            counter+=temp_counter;
        if(counter<3) {
            answer=(rand()%2);
            if (answer == 0)
                break;
        }
    }
}
int move_c(int row,int coloumn,int round,int turn,int visible,int card,int jack,int *temp_for_sherlock){
    time_t t = time(NULL);
    srand(t);
    if(card==0) {
        int want;
        want=(rand()%2);
       if(want)
            ability_of_goodley_c(visible);
        movement_c(&row,&coloumn,card+1,visible);
        if(want==0)
            ability_of_goodley_c(visible);
    }
    else if(card==1){
        movement_c(&row,&coloumn,card+1,visible);
        abilities(1);
    }
    else if(card==2){
        int want;
        want=(rand()%2)+1;
        if(want==2)
            ability_of_william_c(row,coloumn);
        else{
            movement_c(&row,&coloumn,card+1,visible);
        }
    }
    else if(card==3){
        movement_c(&row,&coloumn,card+1,visible);
        ability_of_sherlock_c(temp_for_sherlock);
    }
    else if(card==4){
        int answer;
        answer=rand()%2;
        if(answer)
            abilities(3);
        movement_c(&row,&coloumn,card+1,visible);
        if(answer==0)
            abilities(3);
    }
    else if(card==5){
        movement_c(&row,&coloumn,card+1,visible);
        ability_of_watson(row,coloumn,1);
    }
    else if(card==6){
        move_stealthy_c(&row,&coloumn,card+1,visible);
    }
    else if(card==7){
        int answer;
        answer=rand()%2;
        if(answer)
            abilities(2);
        movement_c(&row,&coloumn,card+1,visible);
        if(answer==0)
            abilities(2);
    }
    int result;
    result=function_c(row,coloumn,round,turn,jack,card);
    return result;
}