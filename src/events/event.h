//
// Created by Dell on 10/03/2021.
//

#include <allegro5/events.h>
#include "../generalConfigs/allegroControls.h"
#include "../generalConfigs/gameVariables.h"
#include "../gameProps/gameProps.h"

#ifndef PDS_TP1_COMBATE_EVENT_H
#define PDS_TP1_COMBATE_EVENT_H

void handleEvent(Players* players, ALLEGRO_EVENT event, AllegroControls controls,
                 GameVariables* variables, Scenery scenery);

#endif //PDS_TP1_COMBATE_EVENT_H
