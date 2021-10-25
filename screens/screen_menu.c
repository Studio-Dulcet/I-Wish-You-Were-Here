//
// Created by kenzie on 14/10/2021.
//

#include "raylib.h"
#include "screens.h"

static int framesCounter=0;
static int finishScreen=0;
Music menuMusic = {0};
static Rectangle playButton;
static Rectangle loadButton;
static Rectangle creditsButton;
static bool mouseOverPlay = false;
static bool mouseOverLoad = false;
static bool mouseOverCredits = false;


void InitMenuScreen(void){
    framesCounter=0;
    finishScreen=0;

    playButton=(Rectangle){500, 500, MeasureText("meow", 160) + 40, 160};
    loadButton=(Rectangle){500, 600, MeasureText("meow", 160) + 40, 160};
    creditsButton=(Rectangle){500, 700, MeasureText("meow", 160) + 40, 160};

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
        else mouseOverPlay = false;
    }
    if(CheckCollisionPointRec(mousePos, loadButton)){
        mouseOverLoad=true;
        if (mouseOverLoad=true && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            finishScreen=2;
        }
        else mouseOverLoad = false;
    }
    if(CheckCollisionPointRec(mousePos, creditsButton)){
        mouseOverCredits=true;
        if (mouseOverCredits=true && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            finishScreen=3;
        }
        else mouseOverCredits = false;
    }
}

void DrawMenuScreen(void){
    BeginDrawing();


    Texture2D BG = LoadTexture("resources/temp_menu1.png");

    DrawTexture(BG, 0, 0, RAYWHITE);


    DrawText("play", playButton.x, playButton.y, 160, WHITE);
    DrawText("load", loadButton.x, loadButton.y, 160, WHITE);
    DrawText("credits", creditsButton.x, creditsButton.y, 160, WHITE);

}



void UnloadMenuScreen(void){

}

int FinishMenuScreen(void){
    return finishScreen;
}