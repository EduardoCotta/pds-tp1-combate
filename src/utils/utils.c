#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <allegro5/path.h>
#include <allegro5/system.h>
#include <allegro5/fshook.h>


float generateRandomFloat(float min, float max){
    float number = rand() / (float) RAND_MAX;
    return min + number * ( max - min );
}

int generateRandomInt(int min, int max){
    int number = rand();
    return min + (number % ( max+1 - min ));
}

void changeDirectory(){
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "");
    al_change_directory(al_path_cstr(path, '/'));
}

FILE* openFile(char* name, char* mode){
    changeDirectory();
    FILE *fp;
    fp  = fopen(name, mode);

    return fp;
}

void closeFile(FILE* file){
    fclose(file);
}


GameHistory readGameHistory(FILE* file){
    int firstPlayerWins = 0;
    int secondPlayerWins = 0;

    char buffer[6];
    buffer[0] = '\0';

    fgets(buffer, 5, file);

    if(strlen(buffer) > 0){
        firstPlayerWins = atoi(strtok(buffer," "));
        secondPlayerWins = atoi(strtok(NULL ," "));
    }

    GameHistory history = {
            .firstPlayerWins = firstPlayerWins,
            .secondPlayerWins = secondPlayerWins
    };

    return history;
}

void writeGameHistory(FILE* file, GameHistory newHistory){
    char history[5];
    sprintf(history, "%d %d", newHistory.firstPlayerWins, newHistory.secondPlayerWins);
    fputs(history, file);
}

