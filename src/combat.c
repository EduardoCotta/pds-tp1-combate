#include <stdio.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <math.h>
#include "init/initAllegro.h"
#include "generalConfigs/allegroControls.h"
#include "generalConfigs/gameVariables.h"
#include "play/playGame.h"
#include "gameProps/generatedProps.h"
#include "utils/utils.h"
#include "draw/colors.h"
#include "sound/sound.h"

const float FPS = 100;
const int SCREEN_W = 960;
const int SCREEN_H = 540;
char scoreFileName [20] = "scores.dat";

GameHistory getGameHistory(){
    GameHistory history = {
            .firstPlayerWins = 0,
            .secondPlayerWins = 0
    };
    FILE* file = openFile(scoreFileName, "r");

    if(file){
        history = readGameHistory(file);
    }

    closeFile(file);

    return history;
}

void updateGameHistory(GameHistory history){
    FILE* file = openFile(scoreFileName, "w+");

    writeGameHistory(file, history);

    closeFile(file);
}

Scenery initScenery(GameVariables variables) {
    PreDefinedGeneratedObstacles generated = getPreDefinedObstacles(variables);

    Scenery scenery;

    scenery.obstacles.generatedObstacles = generated.generatedObstacles[generateRandomInt(0, 4)];

    return scenery;
}

Players initPlayers(GameVariables variables) {
    float alpha = M_PI_2 - variables.THETA;
    float internTriangleHeight = variables.FORCEFIELDRADIUS * sin(alpha);
    float internTriangleHalfBase = variables.FORCEFIELDRADIUS * sin(variables.THETA);
    Colors colors = getColors();

    Players players = {
            .tank1 = {
                    .mobileCircle = {
                            .center = {
                                    .x = 0.5 * (variables.SCREEN_HORIZONTAL_FRACTION),
                                    .y = (variables.SCREEN_VERTICAL_FRACTION) * 2
                            },
                            .speed = 0.0,
                            .angleAxisX = M_PI_2,
                            .angularSpeed = 0.0,
                            .radius = variables.FORCEFIELDRADIUS,
                    },
                    .A = {
                            .x = 0,
                            .y = -variables.FORCEFIELDRADIUS
                    },
                    .B = {
                            .x = -internTriangleHalfBase,
                            .y = internTriangleHeight
                    },
                    .C = {
                            .x = internTriangleHalfBase,
                            .y = internTriangleHeight
                    },
                    .color = colors.RED,
                    .isColliding = 0,
                    .healthPoints = 5,
                    .points = 0,
            },
            .tank2 = {
                    .mobileCircle = {
                            .center = {
                                    .x = 5.5 * (variables.SCREEN_HORIZONTAL_FRACTION),
                                    .y = (variables.SCREEN_VERTICAL_FRACTION) * 2
                            },
                            .speed = 0.0,
                            .cosineAxisX = 0.0,
                            .sineAxisY = 0.0,
                            .angleAxisX = M_PI_2,
                            .angularSpeed = 0.0,
                            .radius = variables.FORCEFIELDRADIUS,
                    },
                    .A = {
                            .x = 0,
                            .y = -variables.FORCEFIELDRADIUS
                    },
                    .B = {
                            .x = -internTriangleHalfBase,
                            .y = internTriangleHeight
                    },
                    .C = {
                            .x = internTriangleHalfBase,
                            .y = internTriangleHeight
                    },
                    .color = colors.BLUE,
                    .isColliding = 0,
                    .healthPoints = 5,
                    .points = 0,
            },
    };

    TankMissile firstMissile = {
            .color = colors.GREEN,
            .mobileCircle = {
                    .center = players.tank1.A,
                    .radius = 7.0,
                    .angleAxisX = players.tank1.mobileCircle.angleAxisX
            },
            .isMoving = 0,

    };

    TankMissile secondMissile = {
            .color = colors.PURPLE,
            .mobileCircle = {
                    .center = players.tank2.A,
                    .radius = 7.0,
                    .angleAxisX = players.tank2.mobileCircle.angleAxisX
            },
            .isMoving = 0,
    };

    players.tank1.mobileCircle.cosineAxisX = cos(players.tank1.mobileCircle.angleAxisX);
    players.tank1.mobileCircle.sineAxisY = sin(players.tank1.mobileCircle.angleAxisX);
    firstMissile.mobileCircle.cosineAxisX = players.tank1.mobileCircle.cosineAxisX;
    firstMissile.mobileCircle.sineAxisY = players.tank1.mobileCircle.sineAxisY;
    players.tank1.missile = firstMissile;
    players.tank2.mobileCircle.cosineAxisX = cos(players.tank2.mobileCircle.angleAxisX);
    players.tank2.mobileCircle.sineAxisY = sin(players.tank2.mobileCircle.angleAxisX);

    secondMissile.mobileCircle.cosineAxisX = players.tank2.mobileCircle.cosineAxisX;
    secondMissile.mobileCircle.sineAxisY = players.tank2.mobileCircle.sineAxisY;
    players.tank2.missile = secondMissile;

    return players;
}

int main(int argc, char **argv) {
    srand(time(NULL));
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *size_32;

    if (!init() ||
        !initTimer(&timer, FPS) ||
        !initDisplay(&display, &timer, SCREEN_W, SCREEN_H) ||
        !initEventQueue(&eventQueue, &display, &timer) ||
        !initFonts(&size_32)
            ) {
        return -1;
    }

    starTimer(&timer);

    AllegroControls controls = {
            .eventQueue = eventQueue,
            .display = display,
            .size_32 = size_32,
            .timer = timer
    };

    GameHistory history = getGameHistory();
    GameSoundSamples gameSoundSamples;

    GameVariables variables = {
            .FPS = FPS,
            .SCREEN_H = SCREEN_H,
            .SCREEN_W = SCREEN_W,
            .SCREEN_HORIZONTAL_FRACTION = (SCREEN_W / 6),
            .SCREEN_VERTICAL_FRACTION = (SCREEN_H / 4),
            .THETA = M_PI_4,
            .FORCEFIELDRADIUS = 30.0,
            .playing = 1,
            .tankSpeed = 2.5,
            .missileSpeed = 4,
            .angleVariation = M_PI_4 / 12,
            .history = history,
            .gameSoundSamples = gameSoundSamples
    };

    loadSamples(&variables.gameSoundSamples);

    Players players = initPlayers(variables);

    Scenery scenery = initScenery(variables);

    playSampleInstance(variables.gameSoundSamples.soundtrack_instance);

    play(controls, &variables, &players, scenery);

    updateGameHistory(variables.history);

    stopSampleInstance(variables.gameSoundSamples.soundtrack_instance);

    destroy(&eventQueue, &display, &timer, &variables);

    return 0;
}
