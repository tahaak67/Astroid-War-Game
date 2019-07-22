#ifndef INGAMEMENU_H
#define INGAMEMENU_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "GameMusic.h"

using namespace std;
using namespace sf;

class InGameMenu
{
    public:
     InGameMenu();
     void InGameMenu_Draw(RenderWindow &Window);
     void InGameMenu_Control(Event event,RenderWindow &Window,bool &DisplayMenu,bool &DisplayGame,bool &DisplayInGameMenu,bool &RestartGame,Clock &c1,float &timer1,float &timer2);
     void MoveUp();
     void MoveDown();
     void setScreenMode(RenderWindow &Window);
     void setMusicState();

    private:
     //Data Members!
     float WinW;
     float WinH;
     int Line_xOffset;
     int Line_yOffset;
     int SelectedElementIndex;
     int MusicCounter;
     int ScreenModeCount;
     int EscapeCounter;

     //Textures!
     Texture BackGround_Texture;

     //Shapes!
     RectangleShape BackGround_Shape;
     RectangleShape Line[7];

     //Fonts!
     Font font;

     //Text
     Text InGameMenu_Text[6];

     //Object
     GameMusic GameMusic_Object;

};

#endif
