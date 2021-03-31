#ifndef PDS_TP1_COMBATE_GAMEPROPS_H
#define PDS_TP1_COMBATE_GAMEPROPS_H

#include <allegro5/color.h>

struct Point {
    float x, y;
};

typedef struct Point Point;

struct MobileCircle {
    Point center;
    float radius;
    float speed;
    float angleAxisX;
    float cosineAxisX;
    float sineAxisY;
    float angularSpeed;
};

typedef struct MobileCircle MobileCircle;

struct TankMissile {
    MobileCircle mobileCircle;
    ALLEGRO_COLOR color;
    int isMoving;
};

typedef struct TankMissile TankMissile;

struct Tank {
    MobileCircle mobileCircle;
    Point A, B , C;
    ALLEGRO_COLOR color;
    float isColliding;
    TankMissile missile;
    int healthPoints;
    int points;
};

typedef struct Tank Tank;

struct Players {
    Tank tank1;
    Tank tank2;
};

typedef struct Players Players;

struct Rectangle{
    Point A, B, C, D;
    ALLEGRO_COLOR color;
};

typedef struct Rectangle RectangularObstacle;

struct GeneratedObstacles {
    RectangularObstacle rectangularObstacles[3];
    int numberOfObstacles;
};

typedef struct GeneratedObstacles GeneratedObstacles;

struct PreDefinedGeneratedObstacles {
    GeneratedObstacles generatedObstacles[10];
};

typedef struct PreDefinedGeneratedObstacles PreDefinedGeneratedObstacles;

struct Obstacles {
    GeneratedObstacles generatedObstacles;
};

typedef struct Obstacles Obstacles;

struct Scenery{
    Obstacles obstacles;
};

typedef struct Scenery Scenery;

#endif //PDS_TP1_COMBATE_GAMEPROPS_H
