#ifndef GAMEBACKGROUND_H
#define GAMEBACKGROUND_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class GameBackGround
{
  public:
    GameBackGround();
    void UpdateScreen(float W,float H);
    void setShapes();
    void MovingBackGround();
    void Draw(RenderWindow &Window);
    void RestartBackGround();

  private:
    //Data Members!
    float WinW;
    float WinH;

    //Textures
    Texture backGround[20];
    Texture Earth;
    Texture Mars;
    Texture jupiter;
    Texture Saturn;
    Texture Uranus;
    Texture Neptune;
    Texture Pluto;
    Texture BlackHole;

    //background
    RectangleShape backGround_Shape[20];
    RectangleShape BlackHole_Shape;

    //Planets!
    Sprite earth_sprite;
    Sprite mars_sprite;
    Sprite jupiter_sprite;
    Sprite Saturn_sprite;
    Sprite Uranus_sprite;
    Sprite Neptune_sprite;
    Sprite Pluto_sprite;

};
#endif
