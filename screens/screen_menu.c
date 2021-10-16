//
// Created by kenzie on 14/10/2021.
//

#include "raylib.h"
#include "screens.h"

static int framesCounter=0;
static int finishScreen=0;
Music menuMusic = {0};
static Rectangle playButton;
static bool mouseOverPlay = false;


void InitMenuScreen(void){
    framesCounter=0;
    finishScreen=0;
    playButton=(Rectangle){GetScreenWidth()/2, GetScreenHeight()/2, MeasureText("meow", 160) + 40, 160};
    PlayMusicStream(menuMusic);

    InitAudioDevice();

    //audio
    menuMusic = LoadMusicStream(""); //add music
    SetMusicVolume (menuMusic, 1.0f);
    PlayMusicStream(menuMusic); //TODO fuck w audio see if it needs to be declared globally or locally
}

void UpdateMenuScreen(void){
    Vector2 mousePos=GetMousePosition();

    if(CheckCollisionPointRec(mousePos, playButton)){
        mouseOverPlay=true;
        if (mouseOverPlay=true && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            finishScreen=1;
        }
    }
}

void DrawMenuScreen(void){
    DrawText("test", playButton.x, playButton.y, 160, WHITE);
    ClearBackground(PINK);
}

void UnloadMenuScreen(void){

}

int FinishMenuScreen(void){
    return finishScreen;
}