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

GeneratedObstacles getFirstPreDefinedSetOfObstacles(GameVariables variables, Colors colors){
    GeneratedObstacles obstacles;

    Point A = {
            .x = 1.875 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 0.74 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    Point B = {
            .x = 4.375 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 2.96 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    obstacles.rectangularObstacles[0] = getPreDefinedRectangular(A, B, colors.ORANGE);
    obstacles.numberOfObstacles = 1;

    return obstacles;
}

GeneratedObstacles getSecondPreDefinedSetOfObstacles(GameVariables variables, Colors colors){
    GeneratedObstacles obstacles;

    Point A = {
            .x = 1.875 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 0.74 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    Point B = {
            .x = 4.375 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 1.48 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    obstacles.rectangularObstacles[0] = getPreDefinedRectangular(A, B, colors.ORANGE);

    A.y = 2.22 * (variables.SCREEN_VERTICAL_FRACTION);
    B.y = 2.96 * (variables.SCREEN_VERTICAL_FRACTION);

    obstacles.rectangularObstacles[1] = getPreDefinedRectangular(A, B, colors.CYAN);

    obstacles.numberOfObstacles = 2;

    return obstacles;
}

GeneratedObstacles getThirdPreDefinedSetOfObstacles(GameVariables variables, Colors colors){
    GeneratedObstacles obstacles;

    Point A = {
            .x = 2.5 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 0.44 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    Point B = {
            .x = 3.75 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 1.03 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    obstacles.rectangularObstacles[0] = getPreDefinedRectangular(A, B, colors.CORN_FLOWER_BLUE);

    A.y = 2.66 * (variables.SCREEN_VERTICAL_FRACTION);
    B.y = 3.25 * (variables.SCREEN_VERTICAL_FRACTION);

    obstacles.rectangularObstacles[1] = getPreDefinedRectangular(A, B, colors.YELLOW);

    obstacles.numberOfObstacles = 2;

    return obstacles;
}

GeneratedObstacles getFourthPreDefinedSetOfObstacles(GameVariables variables, Colors colors){
    GeneratedObstacles obstacles;

    Point A = {
            .x = 1.875 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 0.74 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    Point B = {
            .x = 2.5 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 2.96 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    obstacles.rectangularObstacles[0] = getPreDefinedRectangular(A, B, colors.MAROON);

    A.x = 3.75 * (variables.SCREEN_HORIZONTAL_FRACTION);
    B.x = 4.375 * (variables.SCREEN_HORIZONTAL_FRACTION);

    obstacles.rectangularObstacles[1] = getPreDefinedRectangular(A, B, colors.INDIGO);

    obstacles.numberOfObstacles = 2;

    return obstacles;
}

GeneratedObstacles getFifthPreDefinedSetOfObstacles(GameVariables variables, Colors colors){
    GeneratedObstacles obstacles;

    Point A = {
            .x = 1.875 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 0.74 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    Point B = {
            .x = 2.5 * (variables.SCREEN_HORIZONTAL_FRACTION),
            .y = 1.48 * (variables.SCREEN_VERTICAL_FRACTION)
    };

    obstacles.rectangularObstacles[0] = getPreDefinedRectangular(A, B, colors.CORN_FLOWER_BLUE);

    A.x = 2.75 * (variables.SCREEN_HORIZONTAL_FRACTION);
    A.y = 1.77 * (variables.SCREEN_VERTICAL_FRACTION);
    B.x = 3.375 * (variables.SCREEN_HORIZONTAL_FRACTION);
    B.y = 2.51 * (variables.SCREEN_VERTICAL_FRACTION);

    obstacles.rectangularObstacles[1] = getPreDefinedRectangular(A, B, colors.CYAN);

    A.x = 3.625 * (variables.SCREEN_HORIZONTAL_FRACTION);
    A.y = 2.81 * (variables.SCREEN_VERTICAL_FRACTION);
    B.x = 4.25 * (variables.SCREEN_HORIZONTAL_FRACTION);
    B.y = 3.55 * (variables.SCREEN_VERTICAL_FRACTION);

    obstacles.rectangularObstacles[2] = getPreDefinedRectangular(A, B, colors.NAVY);

    obstacles.numberOfObstacles = 3;

    return obstacles;
}

PreDefinedGeneratedObstacles getPreDefinedObstacles(GameVariables variables){
    Colors colors = getColors();
    PreDefinedGeneratedObstacles obstacles;

    obstacles.generatedObstacles[0] = getFirstPreDefinedSetOfObstacles(variables, colors);
    obstacles.generatedObstacles[1] = getSecondPreDefinedSetOfObstacles(variables, colors);
    obstacles.generatedObstacles[2] = getThirdPreDefinedSetOfObstacles(variables, colors);
    obstacles.generatedObstacles[3] = getFourthPreDefinedSetOfObstacles(variables, colors);
    obstacles.generatedObstacles[4] = getFifthPreDefinedSetOfObstacles(variables, colors);

    return obstacles;
}

