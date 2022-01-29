#include <time.h>
#include <stdlib.h>
void ability_of_sherlock_c(int *temp_for_sherlock){
    int clear=1;
    for(int i=0;i<8;i++){
        if(temp_for_sherlock[i]!=-1)
            clear=0;
    }
    if(clear)
        return;
    time_t t = time(NULL);
    srand(t);
    int temp;
    while(1){
        temp=(rand()%8);
        if(temp_for_sherlock[temp]!=-1){
            temp_for_sherlock[temp]=-1;
            break;
        }
    }
}