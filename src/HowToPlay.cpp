#include "HowToPlay.h"

using namespace sf;

HowToPlay::HowToPlay()
{
  WinW=1366;
  WinH=768;

  //Textures!
  HowToPlay_Texture.loadFromFile("Data/Pictures/MainMenu/How to Play-Menu/HowToPlay PopUp-Menu2.png");

  //Shapes!
  HowToPlay_Shape.setSize(Vector2f(WinW,WinH));
  HowToPlay_Shape.setPosition(0,0);
  HowToPlay_Shape.setTexture(&HowToPlay_Texture);
}


void HowToPlay::Menu_Control(Event MainEvent,RenderWindow &Window,bool &DisplayMainMenu,bool &DisplayHowToPlay)
{
 if(MainEvent.type == Event::KeyPressed)
 {
  if(MainEvent.key.code==Keyboard::Escape)
  {
   DisplayMainMenu=true;
   DisplayHowToPlay=false;
  }
 }
}


void HowToPlay::draw(RenderWindow &Window)
{
  Window.draw(HowToPlay_Shape);
}
