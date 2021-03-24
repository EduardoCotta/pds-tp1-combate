#include <math.h>
#include <stdio.h>
#include "collision.h"

float distanceBetweenTwoPoints(Point first, Point second){
    return sqrt(pow((second.x - first.x), 2) + pow((second.y - first.y), 2));
}

int hasScreenVerticalCollision(GameVariables variables, MobileCircle mobileCircle){
    float yTankProjectionLimitMax = (mobileCircle.center.y + mobileCircle.radius +
            (mobileCircle.speed * (mobileCircle.sineAxisY)));
    float yTankProjectionLimitMin = (mobileCircle.center.y - mobileCircle.radius +
            (mobileCircle.speed * (mobileCircle.sineAxisY)));

    return (yTankProjectionLimitMax >= variables.SCREEN_H) ||
           (yTankProjectionLimitMin <= 0);
}

int hasScreenHorizontalCollision(GameVariables variables, MobileCircle mobileCircle){
    float xTankProjectionLimitMax = (mobileCircle.center.x + mobileCircle.radius +
            (mobileCircle.speed * (mobileCircle.cosineAxisX)));
    float xTankProjectionLimitMin = (mobileCircle.center.x - mobileCircle.radius +
            (mobileCircle.speed * (mobileCircle.cosineAxisX)));


    return (xTankProjectionLimitMax >= variables.SCREEN_W) ||
           (xTankProjectionLimitMin <= 0);
}

int hasScreenLimitCollision(GameVariables variables, MobileCircle mobileCircle) {
    int screenHorizontalCollision = hasScreenHorizontalCollision(variables, mobileCircle);
    int screenVerticalCollision = hasScreenVerticalCollision(variables, mobileCircle);

    return  screenHorizontalCollision || screenVerticalCollision;

}

int hasCollisionWithVertex(Point vertex, MobileCircle mobileCircle){
    float distanceCenterVertex = distanceBetweenTwoPoints(vertex, mobileCircle.center);

    return distanceCenterVertex <= (mobileCircle.radius + 1);
}

int hasCollisionWithRectangularObstacleVertex(RectangularObstacle rectangle, MobileCircle mobileCircle){
    return hasCollisionWithVertex(rectangle.A, mobileCircle) ||
           hasCollisionWithVertex(rectangle.B, mobileCircle) ||
           hasCollisionWithVertex(rectangle.C, mobileCircle) ||
           hasCollisionWithVertex(rectangle.D, mobileCircle);
}

int hasCollisionWithRectangularObstacleVerticalLimit(RectangularObstacle rectangle, MobileCircle mobileCircle){
    float xTankProjectionLimitMax = (mobileCircle.center.x + mobileCircle.radius +
            (mobileCircle.speed * (mobileCircle.cosineAxisX)));
    float xTankProjectionLimitMin = (mobileCircle.center.x - mobileCircle.radius +
            (mobileCircle.speed * (mobileCircle.cosineAxisX)));

    if( rectangle.A.y <= mobileCircle.center.y && rectangle.C.y >= mobileCircle.center.y){
        if(rectangle.A.x <= xTankProjectionLimitMax && rectangle.C.x >= xTankProjectionLimitMin){
            return 1;
        }
    }

    return 0;
}

int hasCollisionWithRectangularObstacleHorizontalLimit(RectangularObstacle rectangle, MobileCircle mobileCircle){
    float yTankProjectionLimitMax = (mobileCircle.center.y + mobileCircle.radius +
            (mobileCircle.speed * (mobileCircle.sineAxisY)));
    float yTankProjectionLimitMin = (mobileCircle.center.y - mobileCircle.radius +
            (mobileCircle.speed * (mobileCircle.sineAxisY)));

    if(rectangle.A.x <= mobileCircle.center.x && rectangle.C.x >= mobileCircle.center.x){
        if(rectangle.A.y <= yTankProjectionLimitMax && rectangle.C.y >= yTankProjectionLimitMin){
            return 1;
        }
    }
    return 0;
}

int hasCollisionWithRectangularObstacle(RectangularObstacle rectangle, MobileCircle mobileCircle){
    return hasCollisionWithRectangularObstacleHorizontalLimit(rectangle, mobileCircle) ||
           hasCollisionWithRectangularObstacleVerticalLimit(rectangle, mobileCircle);
}

int hasObstacleDiagonalCollision(GameVariables variables, Scenery scenery, MobileCircle mobileCircle) {
    return hasCollisionWithRectangularObstacleVertex(scenery.obstacles.rectangularObstacles, mobileCircle);
}

int hasObstacleCollision(GameVariables variables, Scenery scenery, MobileCircle mobileCircle) {
    return hasCollisionWithRectangularObstacle(scenery.obstacles.rectangularObstacles, mobileCircle);
}

int hasScreenCollision(GameVariables variables,  MobileCircle mobileCircle){
    return hasScreenLimitCollision(variables, mobileCircle);
}

int hasTankCollision(MobileCircle first, MobileCircle second){
    float distanceBetweenTanks = distanceBetweenTwoPoints(first.center, second.center);

    return (distanceBetweenTanks <= ((first.radius) + (second.radius)) + 1);
}




