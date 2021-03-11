//
// Created by Dell on 10/03/2021.
//

#include <allegro5/display.h>
#include <allegro5/timer.h>
#include <stdio.h>
#include "event.h"
#include "../draw//draw.h"

void draw(Players players, GameVariables variables){
    drawScenario();
    drawPlayers(players, variables);
}

void handleTimer(Players* players, ALLEGRO_EVENT event, AllegroControls controls, GameVariables variables){
    draw(*players, variables);
    al_flip_display();
    if(al_get_timer_count(controls.timer)%(int)variables.FPS == 0)
        printf("\n%d segundos se passaram...", (int)(al_get_timer_count(controls.timer)/variables.FPS));
}

void handleKeyUp(Players* players, ALLEGRO_EVENT event, AllegroControls controls, GameVariables variables) {

}

void handlePressW(Tank* tank) {
    tank->center.y -= 2.5;
}

void handlePressS(Tank* tank) {
    tank->center.y += 2.5;
}

void handleKeyDown(Players* players, ALLEGRO_EVENT event, AllegroControls controls, GameVariables variables) {
    switch(event.keyboard.keycode){
        case ALLEGRO_KEY_W:
            handlePressW(&players->tank1);
            break;
        case ALLEGRO_KEY_S:
            handlePressS(&players->tank1);
            break;
    };
}

void handleEvent(Players* players, ALLEGRO_EVENT event, AllegroControls controls, GameVariables* variables){
    switch (event.type) {
        case ALLEGRO_EVENT_TIMER:
            handleTimer(players, event, controls, *variables);
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            variables->playing = 0;
            break;
        case ALLEGRO_EVENT_KEY_UP:
            handleKeyUp(players, event, controls, *variables);
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            handleKeyDown(players, event, controls, *variables);
            break;
    };
}