#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#define GAMES 1000000
#define SECOND 1000

int gameOutcome(){
    int notlost = 1;
    int victory_counter = 0;
    while(notlost){
        int outcome = rand() % 2;
        if(outcome == 1){
            victory_counter++;
        }
        else{
            notlost = 0;
        }
    }
    return victory_counter++;
}

int export_data(int* data){
    FILE* file = fopen("shroots_data.txt", "w");
    char buff[4];
    for(int i = 0; i < GAMES; i++){
        itoa(*(data+i), buff, 10);
        strcat(buff, "\n");
        fprintf(file, buff);
    }
    fclose(file);
    return 0;
}

int main(){
    int* GAME_STORAGE = (int*) malloc(sizeof(int)*GAMES);
    printf("%d of memory has been allocated for the game.", sizeof(int)*GAMES);
    for(int i = 0; i < GAMES; i++){
        *(GAME_STORAGE+i) = gameOutcome();
    }
    printf("All game outcomes have been collected.\n");
    export_data(GAME_STORAGE);
    printf("Game data saved in shroots_data.txt\n");
    free(GAME_STORAGE);
    printf("Memory has been returned to the heap... Goodbye!\n");
    Sleep(SECOND);
    return 0;
}