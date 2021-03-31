//
// Created by Dell on 10/03/2021.
//

#include <allegro5/display.h>
#include <allegro5/timer.h>
#include <stdio.h>
#include <math.h>
#include "event.h"
#include "../draw//draw.h"
#include "collision.h"
#include "../sound/sound.h"

void draw(Players players, GameVariables variables, Scenery scenery, AllegroControls controls) {
    drawScenery(scenery);
    drawPlayers(players, variables);
    drawScore(players, variables, controls);
}

void rotatePoint(Point *point, float angle) {
    float x = point->x;
    float y = point->y;

    point->x = (x * cos(angle)) - (y * sin(angle));
    point->y = (y * cos(angle)) + (x * sin(angle));
}

void rotateTank(Tank *tank) {

    if (tank->mobileCircle.angularSpeed != 0) {

        rotatePoint(&tank->A, tank->mobileCircle.angularSpeed);
        rotatePoint(&tank->B, tank->mobileCircle.angularSpeed);
        rotatePoint(&tank->C, tank->mobileCircle.angularSpeed);

        tank->mobileCircle.angleAxisX += tank->mobileCircle.angularSpeed;
        tank->mobileCircle.cosineAxisX = cos(tank->mobileCircle.angleAxisX);
        tank->mobileCircle.sineAxisY = sin(tank->mobileCircle.angleAxisX);

        if (!(tank->missile.isMoving)) {
            rotatePoint(&tank->missile.mobileCircle.center, tank->mobileCircle.angularSpeed);
            tank->missile.mobileCircle.cosineAxisX = cos(tank->mobileCircle.angleAxisX);
            tank->missile.mobileCircle.sineAxisY = sin(tank->mobileCircle.angleAxisX);
        }
    }

}

void moveTank(Tank *tank) {
    tank->mobileCircle.center.y += tank->mobileCircle.speed * (tank->mobileCircle.sineAxisY);
    tank->mobileCircle.center.x += tank->mobileCircle.speed * (tank->mobileCircle.cosineAxisX);
}

void moveBackwardTank(Tank *tank) {
    tank->mobileCircle.center.y -= tank->mobileCircle.speed * (tank->mobileCircle.sineAxisY);
    tank->mobileCircle.center.x -= tank->mobileCircle.speed * (tank->mobileCircle.cosineAxisX);
}

void handleTankMovement(Tank *tank, GameVariables variables, Scenery scenery, Tank otherTank) {
    rotateTank(tank);

    if (!(hasScreenCollision(variables, tank->mobileCircle)) &&
        !(hasObstacleCollision(variables, scenery, tank->mobileCircle))) {
        if (tank->isColliding) {
            moveTank(tank);
            if ((!hasTankCollision(tank->mobileCircle, otherTank.mobileCircle)) &&
                (!hasObstacleDiagonalCollision(variables, scenery, tank->mobileCircle))) {
                tank->isColliding = 0;
            } else {
                moveBackwardTank(tank);
            }
        } else if (!hasTankCollision(tank->mobileCircle, otherTank.mobileCircle) &&
                   !hasObstacleDiagonalCollision(variables, scenery, tank->mobileCircle)) {
            moveTank(tank);
        } else {
            tank->isColliding = 1;
        }
    }
}

void moveMissile(Tank *tank) {
    tank->missile.mobileCircle.center.y -= tank->missile.mobileCircle.speed * (tank->missile.mobileCircle.sineAxisY);
    tank->missile.mobileCircle.center.x -= tank->missile.mobileCircle.speed * (tank->missile.mobileCircle.cosineAxisX);

}

void resetMissile(Tank *tank) {
    tank->missile.mobileCircle.center = tank->A;
    tank->missile.isMoving = 0;
    tank->missile.mobileCircle.speed = 0;
}

void handleMissileMovement(Tank *tank, GameVariables variables, Scenery scenery, Tank *otherTank) {
    if (tank->missile.isMoving) {
        int screenCollision = (hasScreenCollision(variables, tank->missile.mobileCircle));
        int obstacleCollision = (hasObstacleCollision(variables, scenery, tank->missile.mobileCircle));
        int obstacleDiagonalCollision = (hasObstacleDiagonalCollision(variables, scenery, tank->missile.mobileCircle));

        if (screenCollision || obstacleCollision || obstacleDiagonalCollision) {
            playSample(variables.gameSoundSamples.explosion);
            resetMissile(tank);
        } else if (hasTankCollision(tank->missile.mobileCircle, otherTank->mobileCircle)) {
            tank->points++;
            otherTank->healthPoints--;
            playSample(variables.gameSoundSamples.explosion);
            resetMissile(tank);
        } else {
            moveMissile(tank);
        }
    }
}

void refreshTank(Tank *tank, GameVariables variables, Scenery scenery, Tank *otherTank) {
    handleTankMovement(tank, variables, scenery, *otherTank);
    handleMissileMovement(tank, variables, scenery, otherTank);
}

void refreshTanks(Players *players, GameVariables variables, Scenery scenery) {
    refreshTank(&players->tank1, variables, scenery, &players->tank2);
    refreshTank(&players->tank2, variables, scenery, &players->tank1);
}

void verifyGameOver(Players players, GameVariables *variables, AllegroControls controls) {
    if (players.tank1.healthPoints <= 0 || players.tank2.healthPoints <= 0) {
        variables->playing = 0;
        variables->history.firstPlayerWins += (players.tank1.healthPoints > 0);
        variables->history.secondPlayerWins += (players.tank2.healthPoints > 0);
        drawGameOver(players, *variables, controls);
        al_flip_display();
        al_rest(3);
    }
}

void handleTimer(Players *players, ALLEGRO_EVENT event, AllegroControls controls,
                 GameVariables *variables, Scenery scenery) {
    refreshTanks(players, *variables, scenery);
    draw(*players, *variables, scenery, controls);
    verifyGameOver(*players, variables, controls);
    al_flip_display();
//    if (al_get_timer_count(controls.timer) % (int) variables.FPS == 0)
//        printf("\n%d segundos se passaram...", (int) (al_get_timer_count(controls.timer) / variables.FPS));
}

void handleReleaseUp(Tank *tank, float defaultSpeed) {
    tank->mobileCircle.speed += defaultSpeed;
}

void handleReleaseDown(Tank *tank, float defaultSpeed) {
    tank->mobileCircle.speed -= defaultSpeed;
}

void handleReleaseRotateRight(Tank *tank, float defaultAngle) {
    tank->mobileCircle.angularSpeed -= defaultAngle;
}

void handleReleaseRotateLeft(Tank *tank, float defaultAngle) {
    tank->mobileCircle.angularSpeed += defaultAngle;
}

void handleKeyUp(Players *players, ALLEGRO_EVENT event, AllegroControls controls, GameVariables variables) {
    switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_W:
            handleReleaseUp(&players->tank1, variables.tankSpeed);
            break;
        case ALLEGRO_KEY_S:
            handleReleaseDown(&players->tank1, variables.tankSpeed);
            break;
        case ALLEGRO_KEY_D:
            handleReleaseRotateRight(&players->tank1, variables.angleVariation);
            break;
        case ALLEGRO_KEY_A:
            handleReleaseRotateLeft(&players->tank1, variables.angleVariation);
            break;
        case ALLEGRO_KEY_UP:
            handleReleaseUp(&players->tank2, variables.tankSpeed);
            break;
        case ALLEGRO_KEY_DOWN:
            handleReleaseDown(&players->tank2, variables.tankSpeed);
            break;
        case ALLEGRO_KEY_RIGHT:
            handleReleaseRotateRight(&players->tank2, variables.angleVariation);
            break;
        case ALLEGRO_KEY_LEFT:
            handleReleaseRotateLeft(&players->tank2, variables.angleVariation);
            break;
    };
}

void handlePressUp(Tank *tank, float defaultSpeed) {
    tank->mobileCircle.speed -= defaultSpeed;
}

void handlePressDown(Tank *tank, float defaultSpeed) {
    tank->mobileCircle.speed += defaultSpeed;
}

void handlePressRotateRight(Tank *tank, float defaultAngle) {
    tank->mobileCircle.angularSpeed += defaultAngle;
}

void handlePressRotateLeft(Tank *tank, float defaultAngle) {
    tank->mobileCircle.angularSpeed -= defaultAngle;
}

void handlePressShoot(Tank *tank, float missileDefaultSpeed, GameVariables variables) {
    if (!tank->missile.isMoving) {
        tank->missile.mobileCircle.speed += missileDefaultSpeed;
        tank->missile.mobileCircle.cosineAxisX = tank->mobileCircle.cosineAxisX;
        tank->missile.mobileCircle.sineAxisY = tank->mobileCircle.sineAxisY;
        tank->missile.mobileCircle.center.x = tank->mobileCircle.center.x +
                                              (tank->mobileCircle.radius * (-tank->mobileCircle.cosineAxisX));
        tank->missile.mobileCircle.center.y = tank->mobileCircle.center.y +
                                              (tank->mobileCircle.radius * (-tank->mobileCircle.sineAxisY));
        tank->missile.isMoving = 1;
        playSample(variables.gameSoundSamples.shot);
    }
}

void handleKeyDown(Players *players, ALLEGRO_EVENT event, AllegroControls controls, GameVariables variables) {
    switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_W:
            handlePressUp(&players->tank1, variables.tankSpeed);
            break;
        case ALLEGRO_KEY_S:
            handlePressDown(&players->tank1, variables.tankSpeed);
            break;
        case ALLEGRO_KEY_D:
            handlePressRotateRight(&players->tank1, variables.angleVariation);
            break;
        case ALLEGRO_KEY_A:
            handlePressRotateLeft(&players->tank1, variables.angleVariation);
            break;
        case ALLEGRO_KEY_Q:
            handlePressShoot(&players->tank1, variables.missileSpeed, variables);
            break;
        case ALLEGRO_KEY_UP:
            handlePressUp(&players->tank2, variables.tankSpeed);
            break;
        case ALLEGRO_KEY_DOWN:
            handlePressDown(&players->tank2, variables.tankSpeed);
            break;
        case ALLEGRO_KEY_RIGHT:
            handlePressRotateRight(&players->tank2, variables.angleVariation);
            break;
        case ALLEGRO_KEY_LEFT:
            handlePressRotateLeft(&players->tank2, variables.angleVariation);
            break;
        case ALLEGRO_KEY_ENTER:
            handlePressShoot(&players->tank2, variables.missileSpeed, variables);
            break;
    };
}

void handleEvent(Players *players, ALLEGRO_EVENT event, AllegroControls controls,
                 GameVariables *variables, Scenery scenery) {
    switch (event.type) {
        case ALLEGRO_EVENT_TIMER:
            handleTimer(players, event, controls, variables, scenery);
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