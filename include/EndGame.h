#ifndef ENDGAME_H
#define ENDGAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>

using namespace sf;

class EndGame
{
  public:
    EndGame();
    void setEndGameText();
    void EndGame_Control(Event MainEvent,bool &DisplayMenu,bool &DisplayGame,bool &DisplayEndGame,bool &RestartGame,Clock *c1,float &timer1,float &timer2);
    void Draw_EndGame(RenderWindow &Window);

  private:
    //Variables
    int WinW , WinH;

    //Fonts!
    Font font;

    //Text!
    Text BacktoMainMenu_Text;
    Text StartNewGame_Text;

};
#endif
