#ifndef PDS_TP1_COMBATE_GAMEPROPS_H
#define PDS_TP1_COMBATE_GAMEPROPS_H

#include <allegro5/color.h>

struct Point {
    float x, y;
};

typedef struct Point Point;

struct Tank {
    Point center;
    Point A, B , C;
    ALLEGRO_COLOR color;
    float speed;
};

typedef struct Tank Tank;

struct Players {
    Tank tank1;
    Tank tank2;
};

typedef struct Players Players;

#endif //PDS_TP1_COMBATE_GAMEPROPS_H
