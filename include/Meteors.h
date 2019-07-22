#ifndef METEORS_H
#define METEORS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>

using namespace std;
using namespace sf;

class Meteors
{
  public:
    Meteors();
    void MeteorsDraw(RenderWindow &Window,float timer1,float timer2);
    void MoveMeteors(float timer1,float timer2);
    void RestartMeteors();
    void RestartMeteorType();

    int Meteors0_MoveY;
    int Meteors1_MoveY;

    //Shapes!
    RectangleShape RockDrop_Shape[30];
    RectangleShape RockRaise_Shape[30];

  private:
    //Variables!
    int WinW;
    int WinH;
    float RocksMoveY;
    float RockMoveY1;
    int MeteorDropType1;
    int MeteorRaiseType1;
    //int x,y;

    //Randoms!
    int randomNumber[30];
    int randomPositions1[30];
    int randomPositions2[30];
    float randomSize0[30];
    float randomSize1[30];
    int randomDegrees[30];
    int randomMoveX[30];
    int randomRockCrashSize[30];
    float randomScale[30];

    //Textures
    Texture Rock_texture1;
    Texture Rock_texture2;

};
#endif
