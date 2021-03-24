#ifndef PDS_TP1_COMBATE_GAMEVARIABLES_H
#define PDS_TP1_COMBATE_GAMEVARIABLES_H

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
    float angleVariation;
} GameVariables;


#endif //PDS_TP1_COMBATE_GAMEVARIABLES_H
