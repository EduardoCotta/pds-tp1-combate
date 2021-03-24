//
// Created by Dell on 11/03/2021.
//

#include "colors.h"

Colors getColors(){
    Colors colors = {
            .BLUE = al_map_rgb(0, 0 , 255),
            .GREEN = al_map_rgb(0, 255, 0),
            .RED = al_map_rgb(255, 0, 0),
            .YELLOW = al_map_rgb(255, 255, 0),
            .ORANGE = al_map_rgb(255, 165, 0),
            .PINK = al_map_rgb(237, 109, 220),
            .PURPLE = al_map_rgb(82, 5, 71)
    };

    return colors;
}