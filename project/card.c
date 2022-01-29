#include <time.h>
#include <stdlib.h>
void card(int *cards){
    time_t t = time(NULL);
    srand(t);
    int card_1,card_2,card_3,card_4;
    card_1=(rand()%8);
    cards[0]=card_1;
    while(1){
        card_2=(rand()%8);
        if(card_2!=card_1){
            cards[1]=card_2;
            break;
        }
    }
    while(1){
        card_3=(rand()%8);
        if((card_3!=card_1)&&(card_3!=card_2)){
            cards[2]=card_3;
            break;
        }
    }
    while(1){
        card_4=(rand()%8);
        if((card_4!=card_1)&&(card_4!=card_2)&&(card_4!=card_3)){
            cards[3]=card_4;
            break;
        }
    }
    int index=4;
    for(int i=0;i<8;i++){
        if((i==card_1)||(i==card_2)||(i==card_3)||(i==card_4))
            continue;
        cards[index]=i;
        index++;
    }
}