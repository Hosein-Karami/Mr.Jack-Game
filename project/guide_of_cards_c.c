#include <time.h>
#include <stdlib.h>
int guide_of_cards_c(int *cards){
    time_t t = time(NULL);
    srand(t);
    int answer;
    while(1){
        answer=(rand()%4);
        if(cards[answer]!=-1)
            break;
    }
    int temp=cards[answer];
    cards[answer]=-1;
    return temp;
}