#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Menu.h"
#include "GameBackGround.h"
#include "GameMusic.h"
#include "Ship.h"
#include "InGameMenu.h"
#include "Meteors.h"
#include "time.h"
#include "Collision.h"
#include "EndGame.h"
#include "Score.h"

using namespace sf;

class GameState
{
  public:
    GameState();
    void setControlState(Event MainEvent,RenderWindow &Window);
    void setGameOn(RenderWindow &Window);                       //Move things .-.
    void setDrawState(RenderWindow &Window);

  private:
    //States
    bool DisplayMenu;
    bool DisplayGame;
    bool DisplayInGameMenu;
    bool DisplayEndGame;
    bool RestartGame;

    ///Timers
    Clock c1;
    Time GameTimer;

    float timer1;
    float timer2;
    float ScorePoints;

    //Objects
    MainMenu MainMenu_Object;
    GameBackGround GameBackGround_Object;
    GameMusic GameMusic_Object;
    Ship Ship_Object;
    InGameMenu InGameMenu_Object;
    Meteors Meteors_Object;
    Collision Collision_Object;
    EndGame EndGame_Object;
    Score Score_Object;


};
#endif
