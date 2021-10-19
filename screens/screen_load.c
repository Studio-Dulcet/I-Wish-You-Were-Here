//
// Created by kenzie on 18/10/2021.
//

#include "raylib.h"
#include "screens.h"

static int finishScreen=0;
static Rectangle backButton;

static bool mouseOverBackButton = false;

void InitLoadScreen(void){
    finishScreen = 0;
    backButton=(Rectangle){500, 500, MeasureText("meow", 160) + 40, 160};
}

void UpdateLoadScreen(void){
    finishScreen = 0;
    Vector2 mousePos=GetMousePosition();

    if(CheckCollisionPointRec(mousePos, backButton)){
        mouseOverBackButton=true;
        if (mouseOverBackButton=true && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            finishScreen=2;
        }
        else mouseOverBackButton = false;
    }
}

void DrawLoadScreen(void){
    ClearBackground(WHITE);
    DrawText("back", backButton.x, backButton.y, 60, PINK);
    DrawText("congrats the load screen works", GetScreenWidth()/2, GetScreenHeight()/2, 60, PINK);
}

void UnloadLoadScreen(void){

}

int FinishLoadScreen(void){
    return finishScreen;
}