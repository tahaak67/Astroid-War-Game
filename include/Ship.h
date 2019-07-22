#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include "InGameMenu.h"
#include "GameMusic.h"

using namespace std;
using namespace sf;

class Ship
{
  public:
    Ship();
    void ShipDraw(RenderWindow &Window);
    void ShipControl(Event event,bool &DisplayInGameMenu,bool &DisplayGame);
    void Logics();
    void RestartShip();

    Sprite Ship1_Sprite;
    RectangleShape Laser_Shape;

    //States!
    bool Upbutton;
    bool Downbutton;
    bool Rightbutton;
    bool Leftbutton;
    bool SpeedUp;
    bool Laser;

  private:
    //Variables!
    int WinW;
    int WinH;
    float diffualtSpeed;
    float xVelocity;
    float yVelocity;
    float IncreaseSpeed;
    float MaxSpeed;
    float Laser_Timer=0;


    //Textures
    Texture Ship1_Texture;
    Texture Laser_Texture;
    Texture Turbo_Texture;

    //Shapes!
    Sprite Turbo1_Sprite;
    Sprite Turbo2_Sprite;

    //Objects!
    InGameMenu InGameMenu_Object;
    GameMusic GameMusic_Object;

};
#endif
