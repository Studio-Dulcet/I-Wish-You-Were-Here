//
// Created by kenzie on 14/10/2021.
//

#ifndef YUYUKO_SCREENS_H
#define YUYUKO_SCREENS_H

typedef enum GameScreen{LOGO=0, MENU, LOAD, GAME, CREDITS} GameScreen;

extern GameScreen currentScreen;
#endif
//global
extern Music logoMusic;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//raylib logo
void InitLogoScreen(void);
void UpdateLogoScreen(void);
void DrawLogoScreen(void);
void UnloadLogoScreen(void);
int FinishLogoScreen(void);

//menu
void InitMenuScreen(void);
void UpdateMenuScreen(void);
void DrawMenuScreen(void);
void UnloadMenuScreen(void);
int FinishMenuScreen(void);

//load
void InitLoadScreen(void);
void UpdateLoadScreen(void);
void DrawLoadScreen(void);
void UnloadLoadScreen(void);
int FinishLoadScreen(void);

//gameplay
void InitGameScreen(void);
void UpdateGameScreen(void);
void DrawGameScreen(void);
void UnloadGameScreen(void);
int FinishGameScreen(void);

//credits
void InitCreditScreen(void);
void UpdateCreditScreen(void);
void DrawCreditScreen(void);
void UnloadCreditScreen(void);
int FinishCreditScreen(void);

#ifdef __cplusplus
}
#endif
