#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void ability_of_sherlock(int *temp_for_sherlock,char characters[8][20]){
    int clear=1;
    for(int i=0;i<8;i++){
        if(temp_for_sherlock[i]!=-1)
            clear=0;
    }
    if(clear){
        printf("The identity of jack is clear.");
        return;
    }
    time_t t = time(NULL);
    srand(t);
    int temp;
    while(1){
        temp=(rand()%8);
        if(temp_for_sherlock[temp]!=-1){
            printf("A person that is innocent:%s\n",characters[temp]);
            temp_for_sherlock[temp]=-1;
            break;
        }
    }
}