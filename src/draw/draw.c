//
// Created by Dell on 10/03/2021.
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
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

    for (int i = 0; i < scenery.obstacles.generatedObstacles.numberOfObstacles; ++i) {
        drawRectangularObstacle(scenery.obstacles.generatedObstacles.rectangularObstacles[i]);
    }
};

void drawScore(Players players, GameVariables variables, AllegroControls controls){
    char scorePlayerOne[20];
    char scorePlayerTwo[20];

    sprintf(scorePlayerOne, "Player 1: %d", players.tank1.points);
    sprintf(scorePlayerTwo, "Player 2: %d", players.tank2.points);

    al_draw_text(controls.size_32, players.tank1.color,
                 (0.5 * variables.SCREEN_W/8), variables.SCREEN_H/10, 0, scorePlayerOne);
    al_draw_text(controls.size_32, players.tank2.color,
                 (4.5 * variables.SCREEN_W/6), variables.SCREEN_H/10, 0, scorePlayerTwo);
}

void drawGameOver(Players players, GameVariables variables, AllegroControls controls){
    char score[20];
    char playerOneWins[35];
    char playerTwoWins[35];
    al_clear_to_color(al_map_rgb(0, 0, 0));
    sprintf(score, "Score: %d x %d", players.tank1.points, players.tank2.points);
    sprintf(playerOneWins, "Player 1 won: %d times", variables.history.firstPlayerWins);
    sprintf(playerTwoWins, "Player 2 won: %d times", variables.history.secondPlayerWins);

    al_draw_text(controls.size_32, al_map_rgb(0, 200, 30),
                 (2.25 * variables.SCREEN_W/6), variables.SCREEN_H/3, 0, score);

    al_draw_text(controls.size_32, al_map_rgb(0, 200, 30),
                 (2.1 * variables.SCREEN_W/6), 1.5 * variables.SCREEN_H/3, 0, playerOneWins);

    al_draw_text(controls.size_32, al_map_rgb(0, 200, 30),
                 (2.1 * variables.SCREEN_W/6), 2 * variables.SCREEN_H/3, 0, playerTwoWins);

}
