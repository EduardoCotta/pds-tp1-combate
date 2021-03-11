//
// Created by Dell on 10/03/2021.
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "draw.h"


void drawTank(Tank tank, GameVariables variables){
    al_draw_circle(tank.center.x, tank.center.y, variables.FORCEFIELDRADIUS, tank.color, 1);
    al_draw_filled_triangle(tank.A.x + tank.center.x, tank.A.y + tank.center.y,
                            tank.B.x + tank.center.x, tank.B.y + tank.center.y,
                            tank.C.x + tank.center.x, tank.C.y + tank.center.y,
                            tank.color);
}

void drawPlayers(Players players, GameVariables variables){
    drawTank(players.tank1, variables);
    drawTank(players.tank2, variables);
};

void drawScenario(){
    al_clear_to_color(al_map_rgb(255, 255, 255));
};
