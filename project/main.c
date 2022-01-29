#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include "computer.h"
#include "start.h"
#include "print_board.h"
#include "guide_of_cards.h"
#include "save_and_load.h"
#include "save_and_load_2.h"
#include "save_for_video.h"
#include "load_for_video.h"
#include "card.h"
#include "move.h"
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
int temp_for_sherlock[8],current_of_saves,temp_of_load,type_of_map,temp_innocent_save[8];
char obj[11][3],character[8][20];
object *newnode(int a){
    object *output=(object *) malloc(sizeof(object));
    output->next=NULL;
    output->pervious=NULL;
    output->value=a;
    return output;
}
void finish(){
     printf("****************************************************************************************************************\n");
     printf("*Please follow and contact us in Linked_in and Github :                                                        *\n");
     printf("*Linked_in : www.linkedin.com/in/hosein-karami                                                                 *\n");
     printf("*Github : Hosein_Karami                                                                                        *\n");
     char money=36,heart=3;
     printf("*If you want to buy the source code of this game chat with @hosein_karami in telegram and %c=5000 Tooman.       *\n",money);
     printf("*Have a nice day %c%c%c.Goodbye.                                                                                  *\n",heart,heart,heart);
     printf("****************************************************************************************************************");

    Sleep(10000);
}
void read_map(int a){
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
void read_first_objects_on_homes(int a){
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
         home[temp_2-1][temp_3-1].objects= newnode(temp_1);
     }
    fclose(map);
}
void temp_board(){
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
void give_number_to_each_character(){
    strcpy(character[0],"Sergent Goodley");
    strcpy(character[1],"Inspecteur Lestrade");
    strcpy(character[2],"William Gull");
    strcpy(character[3],"Sherlock Holmes");
    strcpy(character[4],"Jeremy Bert");
    strcpy(character[5],"John H.Watson");
    strcpy(character[6],"Miss Stealthy");
    strcpy(character[7],"John Smith");
}
int who_is_Jack(char characters[8][20]){
    printf("\n");
    time_t t = time(NULL);
    srand(t);
    int index=(rand()%8);
    printf("Jack is : %s\n",characters[index]);
    printf("if you undrestand who is jack,please press enter:");
    getchar();
    system("cls");
    temp_for_sherlock[index]=-1;
    return index;
}
int player(){
    printf("Which player is jack(1 or 2)?");
    int jack;
    while(1) {
        scanf("%d", &jack);
        if(jack==1 || jack==2)
            break;
        Beep(900, 690);
        printf("Choose between 1 and 2 : ");
    }
    getchar();
    return jack;
}
void first_make(int *player_jack,int *round,int *player_detective,int *jack){
    *player_jack = player();
    *round = 1;
    *jack = who_is_Jack(character);
    if (*player_jack == 1)
        *player_detective = 2;
    else
        *player_detective = 1;
}
bool search(object *temp,int card){
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
bool save_func(int round,int player_jack,int jack,int *temp_card,int turn){
         int save;
         printf("\n\nDo you want to save this game(1=YES,0=NO)?");
         while(1) {
             scanf("%d", &save);
             if(save==1 || save==0)
                 break;
             Beep(900, 690);
             printf("Choose between 0 and 1 : ");
         }
         if(save) {
             save_and_load(round, player_jack,jack,temp_card,temp_for_sherlock,turn,type_of_map,temp_innocent_save);
             current_of_saves++;
         }
    int answer;
    printf("Do you want to exit(1=YES,0=NO)?");
    while(1) {
        scanf("%d", &answer);
        if(answer==1 || answer==0)
            break;
        Beep(900, 690);
        printf("Choose between 0 and 1 : ");
    }
    if(answer)
        return true;
    return false;
}
void win(){
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
void game(int load){
    int player_jack,player_detective,round=0,jack,end;
    char flag=20,smile=1;
    bool exit;
    if(load==0) {
        first_make(&player_jack,&round,&player_detective,&jack);
        print_board(obj);
    }
    int cards[8],turn=1,choose,*temp_card,row,coloumn,visible=0;
    temp_card=(int *) malloc(8*sizeof(int));
    while((round<=8)){
        for(int i=0;i<9;i++){
            for(int j=0;j<13;j++)
                home[i][j].on=0;
        }
        printf("\n");
        turn=1;
        if(load){
            int *temp_for_loads=(int *) malloc(8*sizeof(int));
            save_and_load_2(&round,&player_jack,&jack,temp_for_loads,temp_for_sherlock,&turn,temp_of_load,&type_of_map,temp_innocent_save);
            read_map(type_of_map);
            if(turn==5){
                round++;
                if(round%2==1){
                    card(cards);
                    free(temp_for_loads);
                    temp_card=cards;
                }
                else
                    temp_card=temp_for_loads+4;
                turn=1;
            }
            else
                temp_card=temp_for_loads;
            if(player_jack==1)
                player_detective=2;
            else
                player_detective=1;
            print_board(obj);
            load=0;
            if(round%2)
                printf("the player_%d(detective) should start.\n\n",player_detective);
            else
                printf("the player_%d(Mr.Jack) should start.\n\n",player_jack);
        }
        else if(round%2==0){
            printf("the player_%d(Mr.Jack) should start.\n\n",player_jack);
            temp_card+=4;
        }
        else{
            printf("the player_%d(detective) should start.\n\n",player_detective);
            card(cards);
            temp_card=cards;
        }
        while(turn<=4){
            printf("%cround = %d   %cturn = %d",flag,round,flag,turn);
            choose= guide_of_cards(temp_card);
            printf("Please enter the cordinate of the selected character:\n");
            printf("row : ");
            scanf("%d",&row);
            printf("coloumn : ");
            scanf("%d",&coloumn);
            while(1) {
                if (search(home[row - 1][coloumn - 1].objects, choose + 1)){
                    end = move(row - 1, coloumn - 1, round, turn, visible, choose, jack, character, temp_for_sherlock);
                    getchar();
                    break;
                }
                else{
                    Beep(900,690);
                    printf("Your wish character does not exist in the house with your cordinate.tyr again.\n");
                    printf("Row : ");
                    scanf("%d",&row);
                    printf("Coloumn : ");
                    scanf("%d",&coloumn);
                }
            }
            print_board(obj);
            if(end==1 || end==-1){
                printf("Jack wins %c.",smile);
                save_for_video(round,turn,0);
                Sleep(4000);
                win();
                return;
            }
            else if(end==2){
                printf("Detective wins %c.",smile);
                save_for_video(round,turn,0);
                Sleep(4000);
                win();
                return;
            }
            turn++;
            save_for_video(round,turn-1,0);
            exit=save_func(round,player_jack,jack,temp_card,turn);
            if(exit)
                return;
        }
        visible=Visible_Invisible(jack,character,temp_innocent_save);
        round++;
    }
    printf("Jack wins %c.\n",smile);
    Sleep(4000);
    win();
}
int main() {
    for(int i=0;i<9;i++){
        for(int j=0;j<13;j++){
            home[i][j].objects=(object *)malloc(sizeof(object));
            home[i][j].objects->next=NULL;
            home[i][j].objects=NULL;
        }
    }
    temp_board();
    give_number_to_each_character();
    system("color 60");
    Beep(523,500);
    Beep(587,500);
    Beep(659,500);
    Beep(698,500);
    Beep(783,500);
    Sleep(1400);
    int x;
    printf("Do you want to play with computer(1=YES,0=NO)?");
    while(1){
        scanf("%d",&x);
        if(x==1 || x==0)
            break;
        Beep(900, 690);
        printf("Choose between 0 and 1 : ");
    }
    if(x)
         computer(obj,character);
    else
    {
        int load;
        while(1) {
            load = start(0);
            if(load==1 || load==0)
                break;
        }
        system("cls");
        FILE *counter_of_saves = fopen("Current_Of_Saves.txt", "r");
        fscanf(counter_of_saves, "%d", &current_of_saves);
        fclose(counter_of_saves);
        if (load == 0) {
            printf("\nDo you want to use your customized map or defualt map(1=Customized_map 2=Default_map)?");
            while(1) {
                scanf("%d", &type_of_map);
                if(type_of_map==1 || type_of_map==2)
                    break;
                Beep(900, 690);
                printf("Choose between 1 and 2 : ");
            }
            read_map(type_of_map);
            read_first_objects_on_homes(type_of_map);
        } else {
            if (current_of_saves == 0) {
                printf("You do not have a saved game.\n");
                Sleep(2000);
                load = 0;
                printf("\nDo you want to use your customized map or defualt map(1=Customized_map 2=Default_map)?");
                scanf("%d", &type_of_map);
                read_map(type_of_map);
                read_first_objects_on_homes(type_of_map);
            } else {
                printf("Which your saves do you want to game(between 1 to %d)?", current_of_saves);
                while (1) {
                    scanf("%d", &temp_of_load);
                    if (1 <= temp_of_load && temp_of_load <= current_of_saves)
                        break;
                    Beep(900, 690);
                    printf("Please enter a correct input. ⚠\n");
                }
            }
        }
        system("cls");
        game(load);
        system("cls");
        FILE *edit = fopen("Current_Of_Saves.txt", "w");
        fprintf(edit, "%d", current_of_saves);
        fclose(edit);
        int video;
        printf("Do you want to see your video game from first(1=YES,0=NO)?");
        while(1) {
            scanf("%d", &video);
            if(video==0 || video==1)
                break;
            Beep(900, 690);
            printf("Choose between 0 and 1 : ");
        }
        getchar();
        if(video)
            load_for_video(obj,0);
    }
    system("cls");
    atexit(finish);
    return 0;
}