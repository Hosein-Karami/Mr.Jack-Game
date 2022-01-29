#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "start.h"
#include "print_board.h"
#include "card.h"
#include "move.h"
#include "guide_of_cards.h"
#include "guide_of_cards_c.h"
#include "cordinate.h"
#include "move_c.h"
#include "save_c.h"
#include "load_c.h"
#include "undo_save.h"
#include "undo_load.h"
#include "save_for_video.h"
#include "Visible_Invisible.h"
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
int temp_for_sherlock_c[8],current_of_saves_c,temp_of_load_c,type_of_map_c,computer_role,innocents[8];
object *newnode_c(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void read_map_c(int a){
    FILE *naghshe;
    if(a==1)
        naghshe=fopen("customized_map.txt","r");
    else
        naghshe=fopen("map.txt","r");
    for(int i=0;i<9;i++){
        for(int j=0;j<13;j++)
            fscanf(naghshe,"%d", &(home[i][j].type_of_home));
    }
    fclose(naghshe);
}
void read_first_objects_on_homes_c(int a){
    int temp_1,temp_2,temp_3;
    FILE *map;
    if(a==1)
        map=fopen("customized_map_2.txt","r");
    else
        map= fopen("map_2.txt","r");
    while(1){
        if(feof(map))
            break;
        fscanf(map,"%d %d %d",&temp_1,&temp_2,&temp_3);
        home[temp_2-1][temp_3-1].objects= newnode_c(temp_1);
    }
    fclose(map);
}
int who_is_Jack_c(char characters[8][20]){
    printf("\n");
    time_t t = time(NULL);
    srand(t);
    int index=(rand()%8);
    if(computer_role==2) {
        printf("Jack is : %s\n", characters[index]);
        printf("if you undrestand who is jack,please press enter:");
        getchar();
        getchar();
        system("cls");
    }
    temp_for_sherlock_c[index]=-1;
    return index;
}
void first_make_c(int *round,int *jack,char character_c[8][20]){
    *round = 1;
    *jack = who_is_Jack_c(character_c);
}
int diagnose_turn(int turn,int round){
    if(computer_role==1 &&((round%2==1)&&((turn==2)||(turn==3))))
        return 0;
    if(computer_role==1 &&((round%2==0)&&((turn==1)||(turn==4))))
        return 0;
    if(computer_role==2 &&((round%2==1)&&((turn==1)||(turn==4))))
        return 0;
    if(computer_role==2 &&((round%2==0)&&((turn==2)||(turn==3))))
        return 0;
    return 1;
}
bool search_c(object *temp,int card){
    if(temp==NULL )
        return false;
    if(temp->value==9 || temp->value==11)
        return false;
    while(temp!=NULL){
        if(temp->value==card)
            return true;
        temp=temp->next;
    }
    return false;
}
bool save_func_c(int round,int jack,int *temp_card,int turn){
    int save;
    printf("\n\nDo you want to save this game(1=YES,0=NO)?");
    while(1) {
        scanf("%d", &save);
        if(save==0 || save==1)
            break;
        Beep(900, 690);
        printf("Choose between 0 and 1 : ");
    }
    if(save) {
        save_c(round,jack,temp_card,temp_for_sherlock_c,turn,type_of_map_c,computer_role,innocents);
        current_of_saves_c++;
    }
    int answer;
    printf("Do you want to exit(1=YES,0=NO)?");
    while(1) {
        scanf("%d", &answer);
        if(answer==0 || answer==1)
            break;
        Beep(900, 690);
        printf("Choose between 0 and 1 : ");
    }
    if(answer)
        return true;
    return false;
}
void undo(int *turn,int *cards){
        if(*turn==5)
            *turn=4;
        else
            (*turn)--;
        undo_load(cards,temp_for_sherlock_c);
}
void win_c(){
    FILE *win= fopen("Win.txt","r");
    if(win==NULL)
        return;
    system("cls");
    char temp[100];
    for(int i=1;i<=17;i++){
        fgets(temp,100,win);
        printf("%s\n",temp);
    }
    fclose(win);
    Beep(523, 200);
    Beep(523, 200);
    Beep(578, 400);
    Beep(523, 400);
    Beep(698, 400);
    Beep(659, 800);
    Beep(523, 200);
    Beep(523, 200);
    Beep(578, 400);
    Beep(523, 400);
    Beep(784, 400);
    Beep(698, 800);
    Beep(523, 200);
    Beep(523, 200);
    Beep(1046, 400);
    Beep(880, 400);
    Beep(698, 400);
    Beep(659, 400);
    Beep(578, 400);
    Beep(932, 200);
    Beep(932, 200);
    Beep(880, 400);
    Beep(698, 400);
    Beep(784, 400);
    Beep(698, 800);
    Sleep(7500);
}
void game_c(int load,char obj_c[11][3],char character_c[8][20]){
    char flag=20,smile=1;
    int round_c=0,jack,end,reverse;
    bool exit=false;
    if(load==0) {
        first_make_c(&round_c,&jack,character_c);
        print_board(obj_c);
    }
    int cards_c[8],turn_c=1,choose_c,*temp_card_c,row_c,coloumn_c,visible_c=0;
    temp_card_c=(int *) malloc(8*sizeof(int));
    while(round_c<=8){
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++)
                home[i][j].on=0;
        }
        printf("\n");
        turn_c=1;
        if(load){
            int *temp_for_loads=(int *) malloc(8*sizeof(int));
            load_c(&round_c,&jack,temp_for_loads,temp_for_sherlock_c,&turn_c,temp_of_load_c,&type_of_map_c,&computer_role,innocents);
            read_map_c(type_of_map_c);
            if(turn_c==5){
                round_c++;
                if(round_c%2==1){
                    card(cards_c);
                    free(temp_for_loads);
                    temp_card_c=cards_c;
                }
                else
                    temp_card_c=temp_for_loads+4;
                turn_c=1;
            }
            else
                temp_card_c=temp_for_loads;
            print_board(obj_c);
            load=0;
            if(round_c%2)
                printf("the detective should start.\n\n");
            else
                printf("the Mr.Jack should start.\n\n");
        }
        else if(round_c%2==0){
            printf("the Mr.Jack should start.\n\n");
            temp_card_c+=4;
        }
        else{
            printf("the detective should start.\n\n");
            card(cards_c);
            temp_card_c=cards_c;
        }
        while(turn_c<=4) {
            undo_save(cards_c, temp_for_sherlock_c);
            printf("\n%cround = %d   %cturn = %d",flag, round_c,flag, turn_c);
            if (diagnose_turn(turn_c, round_c)) {
                choose_c = guide_of_cards(temp_card_c);
                printf("Please enter the cordinate of the selected character:\n");
                printf("row : ");
                scanf("%d", &row_c);
                printf("coloumn : ");
                scanf("%d", &coloumn_c);
                while (1) {
                    if (search_c(home[row_c - 1][coloumn_c - 1].objects, choose_c + 1)) {
                        end = move(row_c - 1, coloumn_c - 1, round_c, turn_c, visible_c, choose_c, jack, character_c,
                                   temp_for_sherlock_c);
                        getchar();
                        print_board(obj_c);
                        break;
                    } else {
                        Beep(900, 690);
                        printf("Your wish character does not exist in the house with your cordinate.tyr again.\n");
                        printf("Row : ");
                        scanf("%d", &row_c);
                        printf("Coloumn : ");
                        scanf("%d", &coloumn_c);
                    }
                }
            } else {
                choose_c = guide_of_cards_c(temp_card_c);
                cordinate(&row_c, &coloumn_c, choose_c + 1);
                end = move_c(row_c, coloumn_c, round_c, turn_c, visible_c, choose_c, jack,temp_for_sherlock_c);
                print_board(obj_c);
            }
            if (end == 1 || end == -1) {
                printf("Jack wins %c.",smile);
                save_for_video(round_c, turn_c, 1);
                Sleep(4000);
                win_c();
                return;
            } else if (end == 2) {
                printf("Detective wins %c.",smile);
                save_for_video(round_c, turn_c, 1);
                Sleep(4000);
                win_c();
                return;
            }
            turn_c++;
            printf("Do you want to undo(1=YES,0=NO)?");
            while(1) {
                scanf("%d", &reverse);
                if(reverse==0 || reverse==1)
                    break;
                Beep(900, 690);
                printf("Choose between 0 and 1 : ");
            }
            if(reverse) {
                undo(&turn_c, cards_c);
                print_board(obj_c);
            }
            else {
                save_for_video(round_c, turn_c - 1, 1);
                exit = save_func_c(round_c, jack, temp_card_c, turn_c);
            }
            if (exit) {
                FILE *edit = fopen("Current_Of_Saves_c.txt", "w");
                fprintf(edit, "%d", current_of_saves_c);
                fclose(edit);
                return;
            }
        }
        visible_c = Visible_Invisible(jack, character_c,innocents);
        round_c++;
    }
    FILE *edit = fopen("Current_Of_Saves_c.txt", "w");
    fprintf(edit, "%d", current_of_saves_c);
    fclose(edit);
    printf("Jack wins %c.\n",smile);
    Sleep(4000);
    win_c();
}
void computer(char obj_c[11][3],char character_c[8][20]){
    int load;
    while(1) {
        load = start(1);
        if(load==1 || load==0)
            break;
    }
    system("cls");
    FILE *counter_of_saves = fopen("Current_Of_Saves_c.txt", "r");
    fscanf(counter_of_saves, "%d", &current_of_saves_c);
    fclose(counter_of_saves);
    if (load == 0) {
        printf("Who is jack(1=Computer,2=Person)?");
        while(1){
            scanf("%d",&computer_role);
            if(computer_role==1 || computer_role==2)
                break;
            Beep(900, 690);
            printf("Choose between 1 and 2 : ");
        }
        printf("\nDo you want to use your customized map or defualt map(1=Customized_map 2=Default_map)?");
        while(1){
            scanf("%d",&type_of_map_c);
            if(type_of_map_c==1 || type_of_map_c==2)
                break;
            Beep(900, 690);
            printf("Choose between 1 and 2 : ");
        }
        read_map_c(type_of_map_c);
        read_first_objects_on_homes_c(type_of_map_c);
    }
    else {
        if (current_of_saves_c == 0) {
            printf("You do not have a saved game\n");
            Sleep(2000);
            load = 0;
            printf("Who is jack(1=Computer,2=Person)?");
            while(1){
                scanf("%d",&computer_role);
                if(computer_role==1 || computer_role==2)
                    break;
                Beep(900, 690);
                printf("Please enter a valid number.\n");
            }
            printf("\nDo you want to use your customized map or defualt map(1=Customized_map 2=Default_map)?");
            while(1){
                scanf("%d",&type_of_map_c);
                if(type_of_map_c==1 || type_of_map_c==2)
                    break;
                Beep(900, 690);
                printf("Choose between 1 and 2 : ");
            }
            read_map_c(type_of_map_c);
            read_first_objects_on_homes_c(type_of_map_c);
        } else {
            printf("Which your saves do you want to game(between 1 to %d)?", current_of_saves_c);
            while (1) {
                scanf("%d", &temp_of_load_c);
                if (1 <= temp_of_load_c && temp_of_load_c <= current_of_saves_c)
                    break;
                Beep(900, 690);
                printf("Please enter a correct input.\n");
            }
        }
    }
    system("cls");
    game_c(load,obj_c,character_c);
}
