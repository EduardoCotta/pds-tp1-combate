#ifndef PDS_TP1_COMBATE_GAMEVARIABLES_H
#define PDS_TP1_COMBATE_GAMEVARIABLES_H

#include <allegro5/allegro_audio.h>

typedef struct GameHistory {
    int firstPlayerWins;
    int secondPlayerWins;
} GameHistory;

typedef struct GameSoundSamples {
    ALLEGRO_SAMPLE *shot;
    ALLEGRO_SAMPLE *explosion;
    ALLEGRO_SAMPLE *soundtrack;
    ALLEGRO_SAMPLE_INSTANCE *soundtrack_instance;
} GameSoundSamples;

typedef struct GameVariables {
    float FPS;
    int SCREEN_W;
    int SCREEN_H;
    float SCREEN_HORIZONTAL_FRACTION;
    float SCREEN_VERTICAL_FRACTION;
    float FORCEFIELDRADIUS;
    float THETA;
    int playing;
    float tankSpeed;
    float missileSpeed;
    float angleVariation;
    GameHistory history;
    GameSoundSamples gameSoundSamples;
} GameVariables;


#endif //PDS_TP1_COMBATE_GAMEVARIABLES_H
