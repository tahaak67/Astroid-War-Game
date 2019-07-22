#include "GameBackGround.h"
using namespace sf;

GameBackGround::GameBackGround()
{
  WinW=1366;
  WinH=768;

  //Textures!

  //BackGround
  for(int i=0;i<20;i+=2)
  {
   backGround[i].loadFromFile("Data/Pictures/Game BackGround/backGround0.png");
  }
  for(int i=1;i<20;i+=2)
  {
   backGround[i].loadFromFile("Data/Pictures/Game BackGround/backGround1.png");
  }

  //Planets!
  Earth.loadFromFile("Data/Pictures/Game BackGround/Earth.png");
  Mars.loadFromFile("Data/Pictures/Game BackGround/Mars.png");
  jupiter.loadFromFile("Data/Pictures/Game BackGround/jupiter.png");
  Saturn.loadFromFile("Data/Pictures/Game BackGround/Saturn.png");
  Uranus.loadFromFile("Data/Pictures/Game BackGround/uranus.png");
  Neptune.loadFromFile("Data/Pictures/Game BackGround/Neptune.png");
  Pluto.loadFromFile("Data/Pictures/Game BackGround/Pluto.png");

  //EndGame!
  BlackHole.loadFromFile("Data/Pictures/Game BackGround/backGround10.png");

  setShapes();

}


void GameBackGround::setShapes()
{
 //background
 for(int i=0;i<20;i++)
 {
  backGround_Shape[i].setSize(Vector2f(WinW,WinH));
  backGround_Shape[i].setPosition(0,-WinH*i);
  backGround_Shape[i].setTexture(&backGround[i]);
 }
 //Planets
 earth_sprite.setPosition(WinW-WinW/2-Earth.getSize().x, WinH-Earth.getSize().y);
 earth_sprite.setTexture(Earth);

 mars_sprite.setPosition(WinW-WinW/2-Mars.getSize().x-250,-WinH*2);
 mars_sprite.setTexture(Mars);

 jupiter_sprite.setPosition(WinW-WinW/2-jupiter.getSize().x,-WinH*4);
 jupiter_sprite.setTexture(jupiter);

 Saturn_sprite.setPosition(WinW-WinW/2-750,-WinH*6);
 Saturn_sprite.setTexture(Saturn);

 Uranus_sprite.setPosition(WinW-WinW/2,-WinH*8);
 Uranus_sprite.setTexture(Uranus);

 Neptune_sprite.setPosition(WinW-WinW/2-Neptune.getSize().x,-WinH*10);
 Neptune_sprite.setTexture(Neptune);

 Pluto_sprite.setPosition(WinW-WinW/2-Pluto.getSize().x+300,-WinH*12);
 Pluto_sprite.setTexture(Pluto);

 //EndGame
 BlackHole_Shape.setPosition(0,-WinH*20);
 BlackHole_Shape.setSize(Vector2f(WinW,WinH));
 BlackHole_Shape.setTexture(&BlackHole);
}


void GameBackGround::MovingBackGround()
{
 //BackGround
 for(int i=0;i<20;i++)
 {
  if(BlackHole_Shape.getPosition().y<0)
  {
   backGround_Shape[i].move(0,1.0);
  }
 }

 //Planets!
 earth_sprite.move(0,1.0);
 mars_sprite.move(0,1.0);
 jupiter_sprite.move(0,1.0);
 Saturn_sprite.move(0,1.0);
 Uranus_sprite.move(0,1.0);
 Neptune_sprite.move(0,1.0);
 Pluto_sprite.move(0,1.0);

 //EndGame
 if(BlackHole_Shape.getPosition().y<0)
 {
  BlackHole_Shape.move(0,1.0);
 }
}


void GameBackGround::UpdateScreen(float W,float H)
{
 WinW=W;
 WinH=H;
}


void GameBackGround::Draw(RenderWindow &Window)
{
  //Background!
  for(int i=0;i<20;i++)
  {
    Window.draw(backGround_Shape[i]);
  }

  //Planets!
  Window.draw(earth_sprite);
  Window.draw(mars_sprite);
  Window.draw(jupiter_sprite);
  Window.draw(Saturn_sprite);
  Window.draw(Uranus_sprite);
  Window.draw(Neptune_sprite);
  Window.draw(Pluto_sprite);

  //EngGame
  Window.draw(BlackHole_Shape);
}


void GameBackGround::RestartBackGround()
{
 //background
 for(int i=0;i<20;i++)
 {
  backGround_Shape[i].setPosition(0,-WinH*i);
 }

 //Planets
 earth_sprite.setPosition(WinW-WinW/2-Earth.getSize().x, WinH-Earth.getSize().y);
 mars_sprite.setPosition(WinW-WinW/2-Mars.getSize().x-250,-WinH*2);
 jupiter_sprite.setPosition(WinW-WinW/2-jupiter.getSize().x,-WinH*4);
 Saturn_sprite.setPosition(WinW-WinW/2-750,-WinH*6);
 Uranus_sprite.setPosition(WinW-WinW/2,-WinH*8);
 Neptune_sprite.setPosition(WinW-WinW/2-Neptune.getSize().x,-WinH*10);
 Pluto_sprite.setPosition(WinW-WinW/2-Pluto.getSize().x+300,-WinH*12);

 //EndGame
 BlackHole_Shape.setPosition(0,-WinH*20);
}
