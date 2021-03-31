//
// Created by Dell on 09/03/2021.
//

#ifndef PDS_TP1_COMBATE_INITALLEGRO_H
#define PDS_TP1_COMBATE_INITALLEGRO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "../generalConfigs/gameVariables.h"

int init();
int initTimer(ALLEGRO_TIMER** timer, float FPS);
int initDisplay(ALLEGRO_DISPLAY** display, ALLEGRO_TIMER** timer, int SCREEN_W, int SCREEN_H);
int initEventQueue(ALLEGRO_EVENT_QUEUE** eventQueue, ALLEGRO_DISPLAY** display, ALLEGRO_TIMER** timer);
int initFonts(ALLEGRO_FONT** font_size32);
int starTimer(ALLEGRO_TIMER** timer);
int destroy(ALLEGRO_EVENT_QUEUE** eventQueue, ALLEGRO_DISPLAY** display, ALLEGRO_TIMER** timer, GameVariables* variables);

#endif //PDS_TP1_COMBATE_INITALLEGRO_H
