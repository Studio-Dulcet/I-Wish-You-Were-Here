//
// Created by kenzie on 16/10/2021.
//


#include "raylib.h"
#include "screens.h"

static int finishScreen=0;


void InitGameScreen(void){
    finishScreen = 0;
}

void UpdateGameScreen(void){
    finishScreen = 0;
}

void DrawGameScreen(void){
    ClearBackground(WHITE);
    DrawText("congrats the gameplay screen works", GetScreenWidth()/2, GetScreenHeight()/2, 60, PINK);
}

void UnloadGameScreen(void){

}

int FinishGameScreen(void){
    return finishScreen;
}