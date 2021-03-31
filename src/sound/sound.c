//
// Created by Dell on 30/03/2021.
//

#include "sound.h"

void loadSamples(GameSoundSamples* gameSoundSamples){
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "assets");
    al_change_directory(al_path_cstr(path, '/'));

    al_reserve_samples(4);

    gameSoundSamples->shot = al_load_sample("sound/missile.wav");
    gameSoundSamples->explosion = al_load_sample("sound/explosion.wav");
    gameSoundSamples->soundtrack = al_load_sample("sound/game_song.ogg");
    gameSoundSamples->soundtrack_instance = al_create_sample_instance(gameSoundSamples->soundtrack);

    al_set_sample_instance_playmode(gameSoundSamples->soundtrack_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(gameSoundSamples->soundtrack_instance, al_get_default_mixer());

}
void playSample(ALLEGRO_SAMPLE* sample){
    al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
void playSampleInstance(ALLEGRO_SAMPLE_INSTANCE* sampleInstance){
    al_play_sample_instance(sampleInstance);
}

void stopSampleInstance(ALLEGRO_SAMPLE_INSTANCE* sampleInstance){
    al_stop_sample_instance(sampleInstance);
}