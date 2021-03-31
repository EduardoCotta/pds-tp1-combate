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
            .PURPLE = al_map_rgb(82, 5, 71),
            .CYAN = al_map_rgb(0,255,255),
            .NAVY = al_map_rgb(0,0,128),
            .MAROON = al_map_rgb(128,0,0),
            .CORN_FLOWER_BLUE = al_map_rgb(100,149,237),
            .INDIGO = al_map_rgb(75,0,130),
            .SADDLE_BROWN = al_map_rgb(139,69,19),
            .MEDIUM_VIOLET_RED = al_map_rgb(199,21,133)
    };

    return colors;
}