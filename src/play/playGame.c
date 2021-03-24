#include <stdio.h>
#include "playGame.h"
#include "../events/event.h"

void play(AllegroControls controls, GameVariables* variables, Players* players, Scenery scenery){

    while(variables->playing) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(controls.eventQueue, &ev);
        handleEvent(players, ev, controls, variables, scenery);
    }
}