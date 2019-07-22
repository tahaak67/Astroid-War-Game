#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "GameMusic.h"
#include "OptionsMenu.h"
#include "HowToPlay.h"
#include "Credits.h"

using namespace std;
using namespace sf;

//The Base MainMenu
class MainMenu
{
  public:
     MainMenu();
     void setShapes();
     void draw(RenderWindow &Window);
     void Menu_Control(Event MainEvent,RenderWindow &Window,bool &DisplayMenu,bool &DisplayGame,Clock &c1);
     void MoveUp();
     void MoveDown();
     void setMusicState();
     void setScreenMode(RenderWindow &Window);
     void ExitMenu(RenderWindow &Window);
     void PlayMode(bool &DisplayMenu);

  private:

     //States!
     bool DisplayMainMenu;
     bool DisplayOptions;
     bool DisplayHowToPlay;
     bool DisplayCredits;

     //Data Members!
     float WinW;
     float WinH;
     int Line_xOffset;
     int Line_yOffset;
     int SelectedElementIndex;
     int MusicStateCount;
     int ScreenModeCount;

     //Textures!
     Texture MenuBackground_Texture;

     //Fonts!
     Font font;
     Font vivaldi_Font;

     //Text!
     Text Menu_Text[5];

     //Shapes!
     RectangleShape MenuBackground_Shape;
     RectangleShape Line[6];

     //Objects
     OptionsMenu optionsMenu;
     HowToPlay howToPlay;
     Credits credits;
     GameMusic GameMusic_Object;

};
#endif
