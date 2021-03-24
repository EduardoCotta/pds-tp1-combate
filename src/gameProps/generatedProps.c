#include "generatedProps.h"
#include "../draw/colors.h"


RectangularObstacle getPreDefinedRectangular(Point superiorLeft, Point inferiorRight, struct ALLEGRO_COLOR color){
    RectangularObstacle rectangle = {
            .A = {
                    .x = superiorLeft.x,
                    .y = superiorLeft.y,
            },
            .B = {
                .x = inferiorRight.x,
                .y = superiorLeft.y,
            },
            .C = {
                    .x = inferiorRight.x,
                    .y = inferiorRight.y,
            },
            .D = {
                    .x = superiorLeft.x,
                    .y = inferiorRight.y,
            },
            .color = color
    };

    return rectangle;
}

GeneratedObstacles getPreDefinedObstacles(GameVariables variables){
    GeneratedObstacles obstacles;
    Colors colors = getColors();

    Point A = {
            .x = 2 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 0.9 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    Point B = {
            .x = 3 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 3 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    obstacles.rectangularObstacles[0] = getPreDefinedRectangular(A, B, colors.ORANGE);

    B.x =  3.5 * (variables.SCREEN_HORIZONTAL_FRACTION);

    obstacles.rectangularObstacles[1] = getPreDefinedRectangular(A, B, colors.YELLOW);

    B.x =  4 * (variables.SCREEN_HORIZONTAL_FRACTION);
    B.y =  3.10 * (variables.SCREEN_VERTICAL_FRACTION);

    obstacles.rectangularObstacles[2] = getPreDefinedRectangular(A, B, colors.PINK);

    return obstacles;
}

