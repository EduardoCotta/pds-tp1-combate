#include <stdio.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <math.h>
#include "init/initAllegro.h"
#include "generalConfigsStructs/allegroControls.h"
#include "generalConfigsStructs/gameVariables.h"
#include "play/playGame.h"

const float FPS = 100;
const int SCREEN_W = 960;
const int SCREEN_H = 540;

Players initPlayers(GameVariables variables){
    float alpha = M_PI_2 - variables.THETA;
    float internTriangleHeight = variables.FORCEFIELDRADIUS * sin(alpha);
    float internTriangleHalfBase = variables.FORCEFIELDRADIUS * sin(variables.THETA);

    Players players = {
            .tank1 = {
                    .center = {
                            .x = variables.SCREEN_W / 4,
                            .y = variables.SCREEN_H / 2
                    },
                    .A = {
                            .x = 0,
                            .y = -variables.FORCEFIELDRADIUS
                    },
                    .B = {
                        .x = - internTriangleHalfBase,
                        .y = internTriangleHeight
                    },
                    .C = {
                            .x = internTriangleHalfBase,
                            .y = internTriangleHeight
                    },
                    .color = al_map_rgb(0, 0, 255),
                    .speed = 0.0
            },
            .tank2 = {
                    .center = {
                            .x = 3 * (variables.SCREEN_W / 4),
                            .y = variables.SCREEN_H / 2
                    },
                    .A = {
                            .x = 0,
                            .y = -variables.FORCEFIELDRADIUS
                    },
                    .B = {
                            .x = - internTriangleHalfBase,
                            .y = internTriangleHeight
                    },
                    .C = {
                            .x = internTriangleHalfBase,
                            .y = internTriangleHeight
                    },
                    .color = al_map_rgb(255, 0, 0),
                    .speed = 0.0
            },
    };

    return players;
}

int main(int argc, char **argv){
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *size_32;

    if(!init() ||
       !initTimer(&timer, FPS) ||
       !initDisplay(&display, &timer, SCREEN_W, SCREEN_H) ||
       !initEventQueue(&eventQueue, &display, &timer)||
       !initFonts(&size_32)
    ){
        return -1;
    }

    starTimer(&timer);

    AllegroControls controls = {
            .eventQueue = eventQueue,
            .display = display,
            .size_32 = size_32,
            .timer = timer
    };

    GameVariables variables = {
            .FPS = FPS,
            .SCREEN_H = SCREEN_H,
            .SCREEN_W = SCREEN_W,
            .THETA = M_PI_4,
            .FORCEFIELDRADIUS = 50.0,
            .playing = 1,
            .tankSpeed = 2.5
    };

    Players players = initPlayers(variables);

    play(controls, &variables, &players);

    destroy(&eventQueue, &display, &timer);

    return 0;
}
