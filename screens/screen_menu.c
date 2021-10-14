//
// Created by kenzie on 14/10/2021.
//

#include "raylib.h"
#include "screens.h"

static int framesCounter=0;
static int finishScreen=0;
Music menuMusic = {0};

void InitMenuScreen(void){
    framesCounter=0;
    finishScreen=0;

    PlayMusicStream(menuMusic);

    InitAudioDevice();

    //audio
    menuMusic = LoadMusicStream(""); //add music
    SetMusicVolume (menuMusic, 1.0f);
    PlayMusicStream(menuMusic); //TODO fuck w audio see if it needs to be declared globally or locally
}

void UpdateMenuScreen(void){
    if (IsKeyPressed(KEY_ENTER)){ //currently you just press enter and it concludes the screen; need to make actual gui later
        //add finish screen logic here l8r
    }
}

void DrawMenuScreen(void){
    ClearBackground(PINK);
}

void UnloadMenuScreen(void){

}

int FinishMenuScreen(void){
    return finishScreen;
}