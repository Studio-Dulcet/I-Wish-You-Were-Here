//
// Created by kenzie on 14/10/2021.
//
#include <stdio.h>
#include "include/raylib.h"
#include "screens/screens.h"

GameScreen currentScreen=LOGO;
Music logoMusic = {0};

static const int screenWidth = 1280;
static const int screenHeight = 720;


// for raylib logo transitions
static float transAlpha = 0.0f;
static bool onTransition = false;
static bool transFadeOut = false;
static int transFromScreen = -1;
static int transToScreen = -1;

//local funciton declaration
static void ChangeToScreen(int screen); //no transition

static void TransitionToScreen(int screen); //pending transition
static void UpdateTransition(void); //update transition effect
static void DrawTransition(void); //rectangle transition

static void UpdateFrame(void); //update + draw frame

//main
int main(void){
    InitWindow(screenWidth, screenHeight, "I Wish You Were Here Development Build");

    InitAudioDevice();

    //audio
    logoMusic = LoadMusicStream(""); //add music
    SetMusicVolume (logoMusic, 1.0f);
    PlayMusicStream(logoMusic);

    //init first screen
    currentScreen=LOGO;
    InitLogoScreen();

    SetTargetFPS(59);

    //game loop
    while (!WindowShouldClose()){
        UpdateFrame();
    }
    switch (currentScreen){
        case LOGO: UnloadLogoScreen(); break;
        case MENU: UnloadMenuScreen(); break;
        case GAME: UnloadGameScreen(); break;
        //unload future screens here as well
        default: break;
    }
    //global data unloading
    UnloadMusicStream(logoMusic);

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

//no screen transition
static void ChangeToScreen(int screen){
    switch (currentScreen){
        case LOGO: UnloadLogoScreen(); break;
        case MENU: UnloadMenuScreen(); break;
        case GAME: UnloadGameScreen(); break;
        //add
        default: break;
    }
    //next screen
    switch (screen){
        case LOGO: InitLogoScreen(); break;
        case MENU: InitMenuScreen(); break;
        case GAME: InitGameScreen(); break;
        //add
        default: break;
    }
    currentScreen=screen;
}

//pending transition to next screen
static void TransitionToScreen(int screen){
    onTransition=true;
    transFadeOut=false;
    transFromScreen=currentScreen;
    transToScreen=screen;
    transAlpha=0.0f;
}
//update transition
static void UpdateTransition(void) {
    if (!transFadeOut) {
        transAlpha += 0.02f;    //DUE TO FLOAT INTERNAL REPRESENTATION, CONDITION JUMPS ON 1.0F INSTEAD OF 1.0F; COMPARE AGAIN 1.01F TO AVOID LAST FRAME LOADING STOP.
        if (transAlpha > 1.0f) {
            transAlpha = 1.0f;
            //unload current screen
            switch (transFromScreen) {
                case LOGO:UnloadLogoScreen(); break;
                case MENU:UnloadMenuScreen(); break;
                case GAME:UnloadGameScreen(); break;
                //add
                default: break;
            }
            //load next
            switch (transToScreen) {
                case LOGO:InitLogoScreen(); break;
                case MENU:InitMenuScreen(); break;
                case GAME:InitGameScreen(); break;
                //add
                default: break;
            }
            currentScreen = transToScreen;
            transFadeOut = true;
        }
    }
    else{
        transAlpha-=0.02f;

        if (transAlpha<-0.01f){

            transAlpha = 0.0f;
            transFadeOut = false;
            onTransition = false;
            transFromScreen = -1;
            transToScreen = -1;
        }
    }
}

// rectangle transition
static void DrawTransition(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
}

static void UpdateFrame(void)
{

    UpdateMusicStream(logoMusic);

    if (!onTransition)
    {
        switch(currentScreen)
        {
            case LOGO:
            {
                UpdateLogoScreen();

                if (FinishLogoScreen()) TransitionToScreen(MENU);

            } break;
            case MENU:
            {
                UpdateMenuScreen();

                if (FinishMenuScreen()) TransitionToScreen(GAME);

            } break;
            case GAME:
            {
                UpdateGameScreen();
                //add
            } break;
            default: break;
        }
    }
    else UpdateTransition();

    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch(currentScreen)
    {
        case LOGO: DrawLogoScreen(); break;
        case MENU: DrawMenuScreen(); break;
        case GAME: DrawGameScreen(); break;
        //add
        default: break;
    }


    if (onTransition) DrawTransition();

    EndDrawing();

}
