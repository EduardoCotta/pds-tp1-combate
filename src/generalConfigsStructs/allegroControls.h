//
// Created by Dell on 10/03/2021.
//

#ifndef PDS_TP1_COMBATE_ALLEGROCONTROLS_H
#define PDS_TP1_COMBATE_ALLEGROCONTROLS_H

#include <allegro5/display.h>
#include <allegro5/allegro_font.h>

typedef struct AllegroControls {
    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE* eventQueue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_FONT *size_32;
} AllegroControls;

#endif //PDS_TP1_COMBATE_ALLEGROCONTROLS_H
