//
// Created by Dell on 10/03/2021.
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "draw.h"

void drawMissile(Tank tank, GameVariables variables){
    if(!tank.missile.isMoving){
        al_draw_filled_circle(tank.missile.mobileCircle.center.x + tank.mobileCircle.center.x,
                              tank.missile.mobileCircle.center.y + tank.mobileCircle.center.y,
                              tank.missile.mobileCircle.radius, tank.missile.color);
    }else{
        al_draw_filled_circle(tank.missile.mobileCircle.center.x,
                              tank.missile.mobileCircle.center.y,
                              tank.missile.mobileCircle.radius, tank.missile.color);
    }
}

void drawTank(Tank tank, GameVariables variables){
    al_draw_circle(tank.mobileCircle.center.x, tank.mobileCircle.center.y, variables.FORCEFIELDRADIUS, tank.color, 1);
    al_draw_filled_triangle(tank.A.x + tank.mobileCircle.center.x, tank.A.y + tank.mobileCircle.center.y,
                            tank.B.x + tank.mobileCircle.center.x, tank.B.y + tank.mobileCircle.center.y,
                            tank.C.x + tank.mobileCircle.center.x, tank.C.y + tank.mobileCircle.center.y,
                            tank.color);


    drawMissile(tank, variables);

}

void drawPlayers(Players players, GameVariables variables){
    drawTank(players.tank1, variables);
    drawTank(players.tank2, variables);
};

void drawRectangularObstacle(RectangularObstacle obstacle) {

    al_draw_filled_rectangle(obstacle.A.x, obstacle.A.y,
                             obstacle.C.x, obstacle.C.y, obstacle.color);
}

void drawScenery(Scenery scenery){
    al_clear_to_color(al_map_rgb(255, 255, 255));

    drawRectangularObstacle(scenery.obstacles.rectangularObstacles);
};
