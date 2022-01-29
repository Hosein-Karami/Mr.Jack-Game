#include <stdio.h>
#include <windows.h>
int guide_of_cards(int *cards) {
    int answer;
    printf("\n\n\n");
    printf("********************************************************************************************************************************\n");
    for(int i=0;i<4;i++) {
        if (cards[i] == 0) {
            printf("* %d)Sergent Goodley:                                                                                                           *\n",i+1);
            printf("* Move 1 to 3 houses                                                                                                           *\n");
            printf("* Optionally,it brings the game characters closer to himself total of 3 houses                                                 *\n");
        } else if (cards[i] == 1) {
            printf("* %d)Inspecteur Lestrade:                                                                                                       *\n",i+1);
            printf("* Move 1 to 3 houses                                                                                                           *\n");
            printf("* After moving,he remove one of the blocking cards and place it on another exit                                                *\n");
        } else if (cards[i] == 2) {
            printf("* %d)William Gual:                                                                                                              *\n",i+1);
            printf("* Move 1 to 3 houses                                                                                                           *\n");
            printf("* he can move or Change his location with another character                                                                    *\n");
        } else if (cards[i] == 3) {
            printf("* %d)Sherlock Holmes:                                                                                                           *\n",i+1);
            printf("* Move 1 to 3 houses                                                                                                           *\n");
            printf("* After making his move, he picks up a card from the suspects cards and looks it                                               *\n");
        } else if (cards[i] == 4) {
            printf("* %d)Jeremy Bert:                                                                                                               *\n",i+1);
            printf("* Move 1 to 3 houses                                                                                                           *\n");
            printf("* Before or after moving,He picks up one of the well caps and places it on the other well                                      *\n");
        } else if (cards[i]==5) {
            printf("* %d)John Watson:                                                                                                               *\n",i+1);
            printf("* Move 1 to 3 houses                                                                                                           *\n");
            printf("* After moving, it chooses a direction and turns its light in that direction, and all the houses along the light are turned on *\n");
        } else if (cards[i] == 6) {
            printf("* %d)Miss Stealthy:                                                                                                             *\n",i+1);
            printf("* Move 1 to 4 houses                                                                                                           *\n");
            printf("* She can pass through unempty houses on her move, but her final destination must be empty house                               *\n");
        } else if (cards[i] == 7) {
            printf("* %d)John Smith:                                                                                                                *\n",i+1);
            printf("* Move 1 to 3 hoses                                                                                                            *\n");
            printf("* Before or after moving, it selects one light, turns it off, and turns on another light                                       *\n");
        }
        else
            printf("* %d)Used                                                                                                                       *\n",i+1);
        printf("*                                                                                                                              *\n");
    }
    printf("********************************************************************************************************************************\n");
    printf("Which card do you want?");
    scanf("%d",&answer);
    while(1) {
        if(cards[answer-1]==-1 || (4<answer || answer<1)){
            Beep(900,690);
            printf("This card was used or your input is invalid.Please try again : ");
            scanf("%d",&answer);
        }
        else {
            int temp=cards[answer-1];
            cards[answer-1]=-1;
            return temp;
        }
    }
}

