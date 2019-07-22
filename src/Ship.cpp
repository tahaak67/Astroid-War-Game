#include "Ship.h"

using namespace sf;

Ship::Ship()
{
 //Screen Width & Height!
 WinW = 1366;
 WinH = 768;

 //Variables
 diffualtSpeed=4;
 xVelocity=diffualtSpeed;
 yVelocity=diffualtSpeed;
 IncreaseSpeed=6.0;
 MaxSpeed=3.0;

 //States
 Upbutton=false;
 Downbutton=false;
 Rightbutton=false;
 Leftbutton=false;
 SpeedUp=false;
 Laser=false;

 //Textures
 Ship1_Texture.loadFromFile("Data/Pictures/SpaceShips/ship.png");
 Laser_Texture.loadFromFile("Data/Pictures/Laser/laser5.png");
 Turbo_Texture.loadFromFile("Data/Pictures/turbo/turbo210.png");

 //Shapes
 Ship1_Sprite.setPosition(WinW/2,WinH-Ship1_Texture.getSize().y);
 Ship1_Sprite.move(0,0);
 Ship1_Sprite.setTexture(Ship1_Texture);
 Ship1_Sprite.setOrigin(Ship1_Sprite.getLocalBounds().height/2,Ship1_Sprite.getLocalBounds().width/2);

 Laser_Shape.setPosition(Ship1_Sprite.getPosition().x-11.8,6.5);
 Laser_Shape.setSize(Vector2f(15,(WinH-Ship1_Sprite.getGlobalBounds().height/1.128)));
 Laser_Shape.setTexture(&Laser_Texture);
 Laser_Shape.setScale(Vector2f(0.8,Laser_Shape.getScale().y));
 Laser_Shape.setFillColor(Color::Cyan);

 Turbo1_Sprite.setTexture(Turbo_Texture);
 Turbo2_Sprite.setTexture(Turbo_Texture);

}


void Ship::ShipControl(Event event,bool &DisplayInGameMenu,bool &DisplayGame)
{
 //KeyPressed
 if(event.type == Event::KeyPressed)
 {
  if(Keyboard::isKeyPressed(Keyboard::Up))
  {
   Upbutton=true;
  }
  if(Keyboard::isKeyPressed(Keyboard::Down))
  {
   Downbutton=true;
  }
  if(Keyboard::isKeyPressed(Keyboard::Right))
  {
   Rightbutton=true;
  }
  if( Keyboard::isKeyPressed(Keyboard::Left))
  {
   Leftbutton=true;
  }
  if(event.key.code==Keyboard::Space)
  {
   Laser_Timer+=0.01;
   if(Laser_Timer<0.01){Laser=true;}
   if(Laser_Timer>0.01){Laser=false;}
  }

  if(event.key.code == Keyboard::LShift || event.key.code == Keyboard::RShift)
  {
   SpeedUp = true;
   if(SpeedUp==true)
   {
    xVelocity=diffualtSpeed+IncreaseSpeed;
    yVelocity=diffualtSpeed+IncreaseSpeed;
    GameMusic_Object.setTurbo_Sound();
   }
  }
 }

 //KeyReleased!
 if(event.type == Event::KeyReleased)
 {
  if(event.key.code==Keyboard::Escape)
  {
   DisplayInGameMenu=true;
   DisplayGame=false;
  }
  if(event.key.code==Keyboard::Up)
  {
   Upbutton=false;
  }
  if(event.key.code==Keyboard::Down)
  {
   Downbutton=false;
  }
  if(event.key.code==Keyboard::Right)
  {
   Rightbutton=false;
  }
  if(event.key.code==Keyboard::Left)
  {
   Leftbutton=false;
  }
  if(event.key.code == Keyboard::Space)
  {
   Laser=false;
   Laser_Timer=0;
  }
  if(event.key.code == Keyboard::LShift || event.key.code == Keyboard::RShift)
  {
   SpeedUp = false;
   if(SpeedUp == false)
   {
    xVelocity=diffualtSpeed;
    yVelocity=diffualtSpeed;
   }
  }
 }
}


void Ship::Logics()
{
 if(Upbutton==true)
 {
  Ship1_Sprite.move(0,-yVelocity);
  Laser_Shape.setSize(Vector2f(Laser_Shape.getSize().x,Ship1_Sprite.getPosition().y+15));
 }
 if(Downbutton==true)
 {
  Ship1_Sprite.move(0,yVelocity);
  Laser_Shape.setSize(Vector2f(Laser_Shape.getSize().x,Ship1_Sprite.getPosition().y+15));
 }
 if(Rightbutton==true)
 {
  Ship1_Sprite.move(xVelocity,0);
  Laser_Shape.setPosition(Ship1_Sprite.getPosition().x-11.8,Laser_Shape.getPosition().y);
 }
 if(Leftbutton==true)
 {
  Ship1_Sprite.move(-xVelocity, 0);
  Laser_Shape.setPosition(Ship1_Sprite.getPosition().x-11.8,Laser_Shape.getPosition().y);
 }
 if(Upbutton==true||Downbutton==true||Rightbutton==true||Leftbutton==true)
 {
  Turbo1_Sprite.setPosition(Ship1_Sprite.getPosition().x-Turbo_Texture.getSize().x+22,Ship1_Sprite.getPosition().y+Turbo_Texture.getSize().y+24);
  Turbo2_Sprite.setPosition(Turbo1_Sprite.getPosition().x-28,Turbo1_Sprite.getPosition().y-0.5);
 }
 if(Laser==true)
 {
  GameMusic_Object.setLaser_Sound();
 }

 //Out of Screen bounds Check!
 if(Ship1_Sprite.getPosition().y < 100)
 {
  Ship1_Sprite.setPosition(Ship1_Sprite.getPosition().x,100);
  Laser_Shape.setSize(Vector2f(Laser_Shape.getSize().x,Ship1_Sprite.getPosition().y+15));
  Laser_Shape.setScale(Vector2f(0.79,Laser_Shape.getScale().y));
  Turbo1_Sprite.setPosition(Ship1_Sprite.getPosition().x-Turbo_Texture.getSize().x+22,Ship1_Sprite.getPosition().y+Turbo_Texture.getSize().y+24);
  Turbo2_Sprite.setPosition(Turbo1_Sprite.getPosition().x-28,Turbo1_Sprite.getPosition().y-0.5);
 }

 if(Ship1_Sprite.getPosition().y > WinH-110)
 {
  Ship1_Sprite.setPosition(Ship1_Sprite.getPosition().x,WinH-110);
  Laser_Shape.setSize(Vector2f(Laser_Shape.getSize().x,Ship1_Sprite.getPosition().y+15));
  Turbo1_Sprite.setPosition(Ship1_Sprite.getPosition().x-Turbo_Texture.getSize().x+22,Ship1_Sprite.getPosition().y+Turbo_Texture.getSize().y+24);
  Turbo2_Sprite.setPosition(Turbo1_Sprite.getPosition().x-28,Turbo1_Sprite.getPosition().y-0.5);
 }

 if((Ship1_Sprite.getPosition().x) < 100)
 {
  Ship1_Sprite.setPosition(100,Ship1_Sprite.getPosition().y);
  Laser_Shape.setPosition(Laser_Shape.getPosition().x+3.25,Laser_Shape.getPosition().y);
  if(Leftbutton==true && SpeedUp==true)
  {
   Laser_Shape.setPosition(Laser_Shape.getPosition().x+6,Laser_Shape.getPosition().y);
  }
  Turbo1_Sprite.setPosition(Ship1_Sprite.getPosition().x-Turbo_Texture.getSize().x+22,Ship1_Sprite.getPosition().y+Turbo_Texture.getSize().y+24);
  Turbo2_Sprite.setPosition(Turbo1_Sprite.getPosition().x-28,Turbo1_Sprite.getPosition().y-0.5);
 }

 if(Ship1_Sprite.getPosition().x>WinW-100)
 {
  Ship1_Sprite.setPosition(WinW-100,Ship1_Sprite.getPosition().y);
  Laser_Shape.setPosition(Laser_Shape.getPosition().x-3.25,Laser_Shape.getPosition().y);
  if(Rightbutton==true && SpeedUp==true)
  {
   Laser_Shape.setPosition(Laser_Shape.getPosition().x-6,Laser_Shape.getPosition().y);
  }
  Turbo1_Sprite.setPosition(Ship1_Sprite.getPosition().x-Turbo_Texture.getSize().x+22,Ship1_Sprite.getPosition().y+Turbo_Texture.getSize().y+24);
  Turbo2_Sprite.setPosition(Turbo1_Sprite.getPosition().x-28,Turbo1_Sprite.getPosition().y-0.5);
 }
}

void Ship::RestartShip()
{
 Ship1_Sprite.move(0,0);
 Ship1_Sprite.setPosition(WinW/2,WinH-Ship1_Texture.getSize().y);
 Ship1_Sprite.setOrigin(Ship1_Sprite.getLocalBounds().height/2,Ship1_Sprite.getLocalBounds().width/2);
 Laser_Shape.setPosition(Ship1_Sprite.getPosition().x-13,6.5);
}

void Ship::ShipDraw(RenderWindow &Window)
{
 //Ship
 Window.draw(Ship1_Sprite);

 //turbo
 if(Upbutton==true || Downbutton==true || Rightbutton==true || Leftbutton==true)
 {
  Window.draw(Turbo1_Sprite);
  Window.draw(Turbo2_Sprite);
 }

 //Laser
 if(Laser == true)
 {
  Window.draw(Laser_Shape);
 }
}
