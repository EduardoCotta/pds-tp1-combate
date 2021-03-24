//
// Created by Dell on 10/03/2021.
//

#include "../gameProps/gameProps.h"
#include "../generalConfigs/gameVariables.h"
#include "../generalConfigs/allegroControls.h"

#ifndef PDS_TP1_COMBATE_DRAW_H
#define PDS_TP1_COMBATE_DRAW_H

void drawPlayers(Players players, GameVariables variables);
void drawScenery();
void drawGameOver(Players players, GameVariables variables, AllegroControls controls);

#endif //PDS_TP1_COMBATE_DRAW_H
