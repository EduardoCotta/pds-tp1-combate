//
// Created by Dell on 11/03/2021.
//

#include "../generalConfigs/gameVariables.h"
#include "../gameProps/gameProps.h"

#ifndef PDS_TP1_COMBATE_COLLISION_H
#define PDS_TP1_COMBATE_COLLISION_H

int hasScreenCollision(GameVariables variables, MobileCircle mobileCircle);
int hasObstacleCollision(GameVariables variables, Scenery scenery, MobileCircle mobileCircle);
int hasObstacleDiagonalCollision(GameVariables variables, Scenery scenery, MobileCircle mobileCircle);
int hasTankCollision(MobileCircle first, MobileCircle second);

#endif //PDS_TP1_COMBATE_COLLISION_H
