//
// Created by Dell on 30/03/2021.
//

#ifndef PDS_TP1_COMBATE_SOUND_H
#define PDS_TP1_COMBATE_SOUND_H

#include "../generalConfigs/gameVariables.h"

void loadSamples(GameSoundSamples* gameSoundSamples);
void playSample(ALLEGRO_SAMPLE* sample);
void playSampleInstance(ALLEGRO_SAMPLE_INSTANCE* sampleInstance);
void stopSampleInstance(ALLEGRO_SAMPLE_INSTANCE* sampleInstance);

#endif //PDS_TP1_COMBATE_SOUND_H
