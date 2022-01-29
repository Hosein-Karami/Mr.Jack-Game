#include <stdio.h>
#include <windows.h>
#include <time.h>
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
void ability_of_watson(int i,int j,int computer) {
    int direction;
    time_t t = time(NULL);
    srand(t);
    if(computer)
        direction=(rand()%6)+1;
    else {
        printf("Please enter the direction that want to on(1=North 2=North_West 3=North_East 4=South 5=South_West 6=South_East):");
        while (1) {
            scanf("%d", &direction);
            if (1 <= direction && direction <= 6)
                break;
            Beep(900, 690);
            printf("You should choose between 1 to 6.\n");
        }
    }
    if(direction==1){
        while(1){
            i--;
            if(i==-1)
                return;
            if(home[i][j].type_of_home==1)
                return;
            home[i][j].on=1;
        }
    }
    if(direction==2){
        while(1){
            i--;
            j--;
            if(i==-1||j==-1)
                return;
            if(home[i][j].type_of_home==1)
                return;
            home[i][j].on=1;
        }
    }
    if(direction==3){
        while(1){
            i--;
            j++;
            if(i==-1||j==13)
                return;
            if(home[i][j].type_of_home==1)
                return;
            home[i][j].on=1;
        }
    }
    if(direction==4){
        while(1){
            i++;
            if(i==9)
                return;
            if(home[i][j].type_of_home==1)
                return;
            home[i][j].on=1;
        }
    }
    if(direction==5){
        while(1){
            i++;
            j--;
            if(i==9||j==-1)
                return;
            if(home[i][j].type_of_home==1)
                return;
            home[i][j].on=1;
        }
    }
    if(direction==6){
        while(1){
            i++;
            j++;
            if(i==9||j==13)
                return;
            if(home[i][j].type_of_home==1)
                return;
            home[i][j].on=1;
        }
    }
}