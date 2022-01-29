#include <stdlib.h>
#include <time.h>
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
object *newnode_77(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void addend_77(object *head,object *newnode){
    object *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next);
    curr->next=newnode;
    newnode->pervious=curr;
}
int search_tunnel_block_cc(object *temp){
    while(temp!=NULL){
        if(temp->value==10)
            return 0;
        temp=temp->next;
    }
    return 1;
}
int search_tunnel_block_3(object *temp){
    while(temp!=NULL){
        if(temp->value==10)
            return 0;
        temp=temp->next;
    }
    return 1;
}
void tunnel_cc(int *row,int *coloumn,int card,int *counter){
    for(int i=0;i<9;i++){
        for(int j=0;j<13;j++){
            if((i!=*row || j!=*coloumn) && home[i][j].type_of_home==4 && search_tunnel_block_3(home[i][j].objects)){
                if(home[i][j].objects==NULL)
                    home[i][j].objects= newnode_77(card);
                else
                    addend_77(home[i][j].objects, newnode_77(card));
                delete(*row,*coloumn,card);
                *row=i;
                *coloumn=j;
                (*counter)++;
                return;
            }
        }
    }
}
int move_stealthy_c(int *row,int *coloumn,int card,int visible){
    int counter=1,want,answer;
    time_t t = time(NULL);
    srand(t);
    want=(rand()%4)+1;
    while(1) {
        if(counter>want)
            break;
        if (home[*row][*coloumn].type_of_home == 4) {
            if (search_tunnel_block_cc(home[*row][*coloumn].objects)) {
                answer = (rand() % 2);
                if (answer)
                    tunnel_cc(row, coloumn, card, &counter);
            }
            answer = (rand() % 2);
            if (answer == 0)
                break;
        }
        answer = (rand() % 6) + 1;
        if(answer==1 && (*row)!=0){
            if(home[(*row)-1][*coloumn].type_of_home==5)
                continue;
            if(home[(*row)-1][*coloumn].type_of_home==6 && home[(*row)-1][*coloumn].objects!=NULL)
                continue;
            if(home[(*row)-1][*coloumn].type_of_home==6 && visible==1)
                continue;
            if(want==counter && home[(*row)-1][*coloumn].type_of_home!=3 && home[(*row)-1][*coloumn].type_of_home!=4  && home[(*row)-1][*coloumn].type_of_home!=6)
                continue;
            if(home[(*row)-1][*coloumn].objects==NULL)
                home[(*row)-1][*coloumn].objects=newnode_77(card);
            else
                addend_77(home[(*row)-1][*coloumn].objects, newnode_77(card));
            delete(*row,*coloumn,card);
            (*row)--;
            counter++;
        }
        else if(answer==2 && (*row)!=0 && (*coloumn)!=0){
            if(home[(*row)-1][(*coloumn)-1].type_of_home==5)
                continue;
            if(home[(*row)-1][(*coloumn)-1].type_of_home==6 && home[(*row)-1][(*coloumn)-1].objects!=NULL)
                continue;
            if(home[(*row)-1][(*coloumn)-1].type_of_home==6 && visible==1)
                continue;
            if(want==counter && home[(*row)-1][(*coloumn)-1].type_of_home!=3 && home[(*row)-1][(*coloumn)-1].type_of_home!=4  && home[(*row)-1][(*coloumn)-1].type_of_home!=6)
                continue;
            if(home[(*row)-1][(*coloumn)-1].objects==NULL)
                home[(*row)-1][(*coloumn)-1].objects=newnode_77(card);
            else
                addend_77(home[(*row)-1][(*coloumn)-1].objects, newnode_77(card));
            delete(*row,*coloumn,card);
            (*row)--;
            (*coloumn)--;
            counter++;
        }
        else if(answer==3 && (*row)!=0 && (*coloumn)!=12){
            if(home[(*row)-1][(*coloumn)+1].type_of_home==5)
                continue;
            if(home[(*row)-1][(*coloumn)+1].type_of_home==6 && home[(*row)-1][(*coloumn)+1].objects!=NULL)
                continue;
            if(home[(*row)-1][(*coloumn)+1].type_of_home==6 && visible==1)
                continue;
            if(want==counter && home[(*row)-1][(*coloumn)+1].type_of_home!=3 && home[(*row)-1][(*coloumn)+1].type_of_home!=4  && home[(*row)-1][(*coloumn)+1].type_of_home!=6)
                continue;
            if(home[(*row)-1][(*coloumn)+1].objects==NULL)
                home[(*row)-1][(*coloumn)+1].objects=newnode_77(card);
            else
                addend_77(home[(*row)-1][(*coloumn)+1].objects, newnode_77(card));
            delete(*row,*coloumn,card);
            (*row)--;
            (*coloumn)++;
            counter++;
        }
        else if(answer==4 && (*row)!=8){
            if(home[(*row)+1][*coloumn].type_of_home==5)
                continue;
            if(home[(*row)+1][*coloumn].type_of_home==6 && home[(*row)+1][*coloumn].objects!=NULL)
                continue;
            if(home[(*row)+1][*coloumn].type_of_home==6 && visible==1)
                continue;
            if(want==counter && home[(*row)+1][*coloumn].type_of_home!=3 && home[(*row)+1][*coloumn].type_of_home!=4  && home[(*row)+1][*coloumn].type_of_home!=6)
                continue;
            if(home[(*row)+1][*coloumn].objects==NULL)
                home[(*row)+1][*coloumn].objects=newnode_77(card);
            else
                addend_77(home[(*row)+1][*coloumn].objects, newnode_77(card));
            delete(*row,*coloumn,card);
            (*row)++;
            counter++;
        }
        else if(answer==5 && (*row)!=8 && (*coloumn)!=0){
            if(home[(*row)+1][(*coloumn)-1].type_of_home==5)
                continue;
            if(home[(*row)+1][(*coloumn)-1].type_of_home==6 && home[(*row)+1][(*coloumn)-1].objects!=NULL)
                continue;
            if(home[(*row)+1][(*coloumn)-1].type_of_home==6 && visible==1)
                continue;
            if(want==counter && home[(*row)+1][(*coloumn)-1].type_of_home!=3 && home[(*row)+1][(*coloumn)-1].type_of_home!=4  && home[(*row)+1][(*coloumn)-1].type_of_home!=6)
                continue;
            if(home[(*row)+1][(*coloumn)-1].objects==NULL)
                home[(*row)+1][(*coloumn)-1].objects=newnode_77(card);
            else
                addend_77(home[(*row)+1][(*coloumn)-1].objects, newnode_77(card));
            delete(*row,*coloumn,card);
            (*row)++;
            (*coloumn)--;
            counter++;
        }
        else if(answer==6 && (*row)!=8 && (*coloumn)!=12){
            if(home[(*row)+1][(*coloumn)+1].type_of_home==5)
                continue;
            if(home[(*row)+1][(*coloumn)+1].type_of_home==6 && home[(*row)+1][(*coloumn)+1].objects!=NULL)
                continue;
            if(home[(*row)+1][(*coloumn)+1].type_of_home==6 && visible==1)
                continue;
            if(want==counter && home[(*row)+1][(*coloumn)+1].type_of_home!=3 && home[(*row)+1][(*coloumn)+1].type_of_home!=4 && home[(*row)+1][(*coloumn)+1].type_of_home!=6)
                continue;
            if(home[(*row)+1][(*coloumn)+1].objects==NULL)
                home[(*row)+1][(*coloumn)+1].objects=newnode_77(card);
            else
                addend_77(home[(*row)+1][(*coloumn)+1].objects, newnode_77(card));
            delete(*row,*coloumn,card);
            (*row)++;
            (*coloumn)++;
            counter++;
        }
    }
    return counter;
}