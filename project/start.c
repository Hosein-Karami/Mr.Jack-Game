#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void gotoxy(int x, int y){
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
int start(int computer){
    system("cls");
    FILE *information=fopen("info.txt","r");
    if(information==NULL){
        Beep(900,690);
        printf("Sorry.The information file can not open.");
        return -1;
    }
    char name[50],heart=3,smile=1;
    int gender;
    fscanf(information,"%d",&gender);
    fgets(name,50,information);
    fclose(information);
    printf("Date : %s\n",__DATE__);
    if(gender==1)
        printf("Hi Mr.%s,Welcome to Mr.Jack.",name);
    else if(gender==2)
        printf("Hi Ms.%s,welcome to Mr.jack.",name);
    else
        printf("Hi %s,welcome to Mr.jack.",name);
    printf("We wish you have a great game %c%c %c%c.\n",heart,heart,smile,smile);
    int answer;
    gotoxy(65,20);
    printf("******************************\n");
    gotoxy(65,21);
    printf("*    1)Edit information      *\n");
    gotoxy(65,22);
    printf("*    2)Start a new game      *\n");
    gotoxy(65,23);
    printf("*    3)Load game             *\n");
    gotoxy(65,24);
    printf("*    4)Customized map        *\n");
    gotoxy(65,25);
    printf("*    5)About us              *\n");
    gotoxy(65,26);
    printf("*    6)Delete all saves      *\n");
    gotoxy(65,27);
    printf("*    7)Guide                 *\n");
    gotoxy(65,28);
    printf("******************************\n");
    gotoxy(65,29);
    printf("Please enter your choice :");
    scanf("%d",&answer);
    getchar();
    if(answer==1){
        system("cls");
        FILE *edit=fopen("info.txt","w");
        if(edit==NULL){
            Beep(900,690);
            printf("Sorry.The about file can not open.");
        }
        else {
            char male=11,female=12;
            printf("********************************\n");
            printf("*1)Male-%c     2)Female-%c       *\n",male,female);
            printf("********************************\n");
            printf("Choose your gender :");
            int genderr;
            while(1){
                scanf("%d",&genderr);
                if(genderr==1 || genderr==2)
                    break;
                Beep(900,690);
                printf("Please inter a number beetwen 1 and 2 :");
            }
            getchar();
            fprintf(edit,"%d",genderr);
            printf("Enter your new name:");
            gets(name);
            fprintf(edit, "%s", name);
            fclose(edit);
        }
        system("cls");
    }
    else if(answer==2){
        return 0;
    }
    else if(answer==3){
        return 1;
    }
    else if(answer==4){
        system("cls");
        FILE *rahnama= fopen("Customize.txt","r");
        if(rahnama==NULL){
            Beep(900,690);
            printf("Sorry.We can not open the guide file.\n");
            Sleep(5000);
            return -1;
        }
        else{
            char temp[200];
            for(int i=1;i<=17;i++){
                fgets(temp,200,rahnama);
                printf("%s\n",temp);
            }
            fclose(rahnama);
            printf("If undrestand,press enter:");
            getchar();
            FILE *map=fopen("customized_map.txt","w");
            if(map==NULL){
                Beep(900,690);
                printf("Sorry.We can not open the map file.\n");
                Sleep(5000);
                return -1;
            }
            else{
                printf("\n");
                for(int i=1;i<=9;i++){
                    printf("Enter the %d row:",i);
                    gets(temp);
                    fprintf(map,"%s\n",temp);
                }
                fclose(map);
                printf("Do you want to customize the characters(1=YES,0=NO)?");
                int x;
                scanf("%d",&x);
                if(x){
                    FILE *rahnama_2=fopen("Customize_2.txt","r");
                    if(rahnama_2==NULL){
                        Beep(900,690);
                        printf("Sorry we can not open the guide file.");
                        Sleep(5000);
                        return -1;
                    }
                    else{
                        for(int i=1;i<=10;i++){
                            fgets(temp,200,rahnama_2);
                            printf("%s\n",temp);
                        }
                        fclose(rahnama_2);
                        printf("If undrestand,press enter:\n");
                        getchar();
                        getchar();
                        FILE *map_2=fopen("customized_map_2.txt","w");
                        if(map_2==NULL){
                            Beep(900,690);
                            printf("Sorry.We can not open the map file.\n");
                            Sleep(5000);
                            return -1;
                        }
                        else{
                            printf("Enter the character and cordinate according the above guide:\n");
                            int counter=1;
                            while(1){
                                printf("Enter the character_%d:\n",counter);
                                counter++;
                                getchar();
                                gets(temp);
                                fprintf(map_2,"%s\n",temp);
                                printf("Do you want to continue(1=YES,0=NO)?");
                                scanf("%d",&x);
                                if(x==0)
                                    break;
                            }
                            fclose(map_2);
                        }
                    }
                }
            }
        }
    }
    else if(answer==5){
        system("cls");
        FILE *info=fopen("about.txt","r");
        if(info==NULL){
            Beep(900,690);
            printf("Sorry.The information file can not open.");
        }
        else {
            char temp[200];
            for (int i = 1; i <= 9; i++) {
                fgets(temp, 200, info);
                printf("%s", temp);
            }
            fclose(info);
            printf("\nIf undrestand,please press enter :");
        }
    }
    else if(answer==6) {
        if (computer) {
            FILE *destroy = fopen("save_c.bin", "wb");
            fclose(destroy);
            FILE *delete = fopen("Current_Of_Saves_c.txt", "w");
            fprintf(delete, "%d", 0);
            fclose(delete);
        } else {
            FILE *destroy = fopen("save.bin", "wb");
            fclose(destroy);
            FILE *delete = fopen("Current_Of_Saves.txt", "w");
            fprintf(delete, "%d", 0);
            fclose(delete);
        }
    }
    else if(answer==7){
        system("cls");
        FILE *guide= fopen("guide_of_map.txt","r");
        if(guide==NULL){
            printf("sorry.we can not open the guide file.");
            Sleep(5000);
            return -1;
        }
        char temp[150];
        for(int i=1;i<=46;i++) {
            fgets(temp,150, guide);
            printf("%s",temp);
        }
        printf("\n\nIf undrestand the hints,please press enter:");
    }
    else{
        Beep(900,690);
        return -1;
    }
    printf("\n\n");
    getchar();
    return -1;
}
