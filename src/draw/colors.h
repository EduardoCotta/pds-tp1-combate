//
// Created by Dell on 11/03/2021.
//

#ifndef PDS_TP1_COMBATE_COLORS_H
#define PDS_TP1_COMBATE_COLORS_H

#include <allegro5/color.h>

struct Colors{
    ALLEGRO_COLOR RED;
    ALLEGRO_COLOR GREEN;
    ALLEGRO_COLOR BLUE;
    ALLEGRO_COLOR YELLOW;
    ALLEGRO_COLOR ORANGE;
    ALLEGRO_COLOR PINK;
    ALLEGRO_COLOR PURPLE;
};

typedef struct Colors Colors;

Colors getColors();


#endif //PDS_TP1_COMBATE_COLORS_H
