#ifndef COLLISION_H
#define COLLISION_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "GameMusic.h"
#include <cstdlib>


using namespace sf;


class Collision
{
  public:
    Collision();
    void Check_LifeState(Sprite Shipsprite,RectangleShape RockDrop_Shape[30],RectangleShape RockRaise_Shape[30],bool &DisplayGame,bool &DisplayEndGame);
    void Check_RockCrash(RenderWindow &Window,bool &Laser,RectangleShape Laser_Shape,RectangleShape RockDrop_Shape[30],RectangleShape RockRaise_Shape[30],bool &Bonus10,bool &Bonus15);
    void DrawShipCrash(RenderWindow &Window);
    void DrawRockCrash(RenderWindow &Window,int &Meteors1_MoveY);


  private:
    bool RockCrash=false;
    int x=0,y=0;
    int randomRockCrashSize[10];

    float CollisionTime1;
    float CollisionTime2;

    //Textures
    Texture RockCrash_texture;

    //Shapes
    Sprite ShipeCrash_Sprite;
    RectangleShape RockCrash_Shape[30][10];

    //Textures
    Texture ShipCrash_Texture;

    //Objects!
    GameMusic GameMusic_Object;

    ///Shield!

    bool ActivateShield=false;
    Texture Shield_Texture;
    CircleShape Shield_Shape;
    float ActivateShield_Timer=0;
    float MiniShield_Radius=10;
    float ActivateShield_Radius=0;


};
#endif
