#ifndef PDS_TP1_COMBATE_UTILS_H
#define PDS_TP1_COMBATE_UTILS_H
#include "../generalConfigs/gameVariables.h"

float generateRandomFloat(float min, float max);
int generateRandomInt(int min, int max);
FILE* openFile(char* name, char* mode);
void closeFile(FILE* file);
GameHistory readGameHistory(FILE* file);
void writeGameHistory(FILE* file, GameHistory newHistory);
#endif //PDS_TP1_COMBATE_UTILS_H
