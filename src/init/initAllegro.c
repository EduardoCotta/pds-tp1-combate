#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include "initAllegro.h"



int init() {
    //inicializa o Allegro
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return 0;
    }

    //inicializa o módulo de primitivas do Allegro
    if (!al_init_primitives_addon()) {
        fprintf(stderr, "failed to initialize primitives!\n");
        return 0;
    }

    //inicializa o modulo que permite carregar imagens no jogo
    if (!al_init_image_addon()) {
        fprintf(stderr, "failed to initialize image module!\n");
        return 0;
    }

    //instala o teclado
    if (!al_install_keyboard()) {
        fprintf(stderr, "failed to install keyboard!\n");
        return 0;
    }

    //inicializa o modulo allegro que carrega as fontes
    al_init_font_addon();

    //inicializa o modulo allegro que entende arquivos tff de fontes
    if (!al_init_ttf_addon()) {
        fprintf(stderr, "failed to load tff font module!\n");
        return 0;
    }

    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "assets");
    al_change_directory(al_path_cstr(path, '/'));
    al_destroy_path(path);

    return 1;

}

int initTimer(ALLEGRO_TIMER **timer, float FPS) {
    //cria um temporizador que incrementa uma unidade a cada 1.0/FPS segundos
    *timer = al_create_timer(1.0 / FPS);
    if (!*timer) {
        fprintf(stderr, "failed to create timer!\n");
        return 0;
    }
    return 1;
}

int initDisplay(ALLEGRO_DISPLAY **display, ALLEGRO_TIMER **timer, int SCREEN_W, int SCREEN_H) {
    //cria uma tela com dimensoes de SCREEN_W, SCREEN_H pixels
    *display = al_create_display(SCREEN_W, SCREEN_H);
    if (!*display) {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(*timer);
        return 0;
    }

    return 1;
}

int initEventQueue(ALLEGRO_EVENT_QUEUE **eventQueue, ALLEGRO_DISPLAY **display, ALLEGRO_TIMER **timer) {
    *eventQueue = al_create_event_queue();
    if (!*eventQueue) {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_display(*display);
        al_destroy_timer(*timer);
        return 0;
    }
    //registra na fila os eventos de tela (ex: clicar no X na janela)
    al_register_event_source(*eventQueue, al_get_display_event_source(*display));
    //registra na fila os eventos de tempo: quando o tempo altera de t para t+1
    al_register_event_source(*eventQueue, al_get_timer_event_source(*timer));
    //registra na fila os eventos de teclado (ex: pressionar uma tecla)
    al_register_event_source(*eventQueue, al_get_keyboard_event_source());

    return 1;
}

int initFonts(ALLEGRO_FONT **font_size32) {
    *font_size32 = al_load_font("fonts/arial.ttf", 32, 1);
    if (*font_size32 == NULL) {
        fprintf(stderr, "font file does not exist or cannot be accessed!\n");
    }

    return 1;
}

int starTimer(ALLEGRO_TIMER **timer) {
    al_start_timer(*timer);
}

int destroy(ALLEGRO_EVENT_QUEUE **eventQueue, ALLEGRO_DISPLAY **display, ALLEGRO_TIMER **timer) {
    al_destroy_timer(*timer);
    al_destroy_display(*display);
    al_destroy_event_queue(*eventQueue);
}