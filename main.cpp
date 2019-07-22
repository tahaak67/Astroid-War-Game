
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "GameState.h"
#include "time.h"

using namespace std;
using namespace sf;

int main()
{
 //Screen width & height
 int WinW=1366;
 int WinH=768;

 //Create the Window
 RenderWindow Window(VideoMode(WinW,WinH) ,"Asteroid War");
 Window.setMouseCursorVisible(false);
 Window.setFramerateLimit(60);
 Window.setKeyRepeatEnabled(true);

 GameState GameState_Object;

 while(Window.isOpen())
 {
  Event MainEvent;
  while(Window.pollEvent(MainEvent))
  {
   if(MainEvent.type == Event::Closed)
   {
    Window.close();
   }
   GameState_Object.setControlState(MainEvent,Window);
  }

  GameState_Object.setGameOn(Window);

  Window.clear();
  GameState_Object.setDrawState(Window);
  Window.display();
 }
}
