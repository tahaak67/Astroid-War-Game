#include "Collision.h"

using namespace sf;

Collision::Collision()
{
 CollisionTime1=0;
 CollisionTime2=0;

 //Textures
 ShipCrash_Texture.loadFromFile("Data/Pictures/ShipCrash/ShipCrash1.png");
 RockCrash_texture.loadFromFile("Data/Pictures/Asteroids/asteroid.png");
 Shield_Texture.loadFromFile("Data/Pictures/Shield/bubble2.png");

 //Shapes
 ShipeCrash_Sprite.setTexture(ShipCrash_Texture);
 ShipeCrash_Sprite.setOrigin(ShipeCrash_Sprite.getGlobalBounds().width/2,ShipeCrash_Sprite.getGlobalBounds().height/2);

 Shield_Shape.setTexture(&Shield_Texture);
 Shield_Shape.setRadius(MiniShield_Radius);
 Shield_Shape.setPosition(-500,-500);

 for(int i=0;i<30;i++)
 {
  for(int j=0;j<10;j++)
  {
   RockCrash_Shape[i][j].setTexture(&RockCrash_texture);
  }
 }
}

void Collision::Check_LifeState(Sprite Shipsprite,RectangleShape RockDrop_Shape[30],RectangleShape RockRaise_Shape[30],bool &DisplayGame,bool &DisplayEndGame)
{
 bool checkRockDropCollision=false;
 bool checkRockRaiseCollision=false;
 for(int i=0;i<30;i++)
 {
  if((Shipsprite.getGlobalBounds().intersects(RockDrop_Shape[i].getGlobalBounds()))&&(RockDrop_Shape[i].getPosition().x>Shipsprite.getGlobalBounds().left)&&(RockDrop_Shape[i].getPosition().x<(Shipsprite.getGlobalBounds().left+Shipsprite.getGlobalBounds().width))&&(RockDrop_Shape[i].getPosition().y>Shipsprite.getGlobalBounds().top)&&(RockDrop_Shape[i].getPosition().y<(Shipsprite.getGlobalBounds().top+Shipsprite.getGlobalBounds().height)))
  {
   if(ActivateShield==false)
   {
    checkRockDropCollision=true;
    CollisionTime1+=0.001;
    if(checkRockDropCollision==true)
    {
     if(CollisionTime1>0.006)
     {
      DisplayGame=false;
      DisplayEndGame=true;
      ShipeCrash_Sprite.setPosition(Shipsprite.getPosition().x , Shipsprite.getPosition().y);
      GameMusic_Object.setShipCrash_Sound();
     }
    }
   }
  }
  if((Shipsprite.getGlobalBounds().intersects(RockRaise_Shape[i].getGlobalBounds()))&&(RockRaise_Shape[i].getPosition().x>Shipsprite.getGlobalBounds().left)&&(RockRaise_Shape[i].getPosition().x<(Shipsprite.getGlobalBounds().left+Shipsprite.getGlobalBounds().width))&&(RockRaise_Shape[i].getPosition().y>Shipsprite.getGlobalBounds().height)&&(RockRaise_Shape[i].getPosition().y<(Shipsprite.getGlobalBounds().top+Shipsprite.getGlobalBounds().height)))
  {
   if(ActivateShield==false)
   {
    checkRockRaiseCollision=true;
    CollisionTime2+=0.001;
    if(checkRockRaiseCollision==true)
    {
     if(CollisionTime2>0.005)
     {
      ShipeCrash_Sprite.setPosition(Shipsprite.getPosition().x , Shipsprite.getPosition().y);
      GameMusic_Object.setShipCrash_Sound();
      DisplayEndGame=true;
      DisplayGame=false;
     }
    }
   }
  }
 }
 if(checkRockDropCollision==false)
 {
  CollisionTime1=0;
 }
 if(checkRockRaiseCollision==false)
 {
  CollisionTime2=0;
 }
 if(Shipsprite.getGlobalBounds().intersects(Shield_Shape.getGlobalBounds()))
 {
  ActivateShield_Timer+=0.01;
  if(ActivateShield_Timer<=5)
  {
   if(ActivateShield_Timer<=0.7){GameMusic_Object.setActivateShield_Sound();}
   ActivateShield_Radius+=2;
   if(ActivateShield_Radius==90){ActivateShield_Radius-=2;}
   ActivateShield=true;
   Shield_Shape.setPosition(Shipsprite.getPosition().x,Shipsprite.getPosition().y);
   Shield_Shape.setOrigin(Shield_Shape.getGlobalBounds().width/2,Shield_Shape.getGlobalBounds().height/2);
   Shield_Shape.setRadius(MiniShield_Radius+ActivateShield_Radius);
  }
  if(ActivateShield_Timer>5)
  {
   ActivateShield=false;
   Shield_Shape.setRadius(MiniShield_Radius);
   ActivateShield_Radius=0;
   ActivateShield_Timer=0;
   Shield_Shape.setPosition(-500,-500);
  }
 }
 if(DisplayEndGame==true)
 {
  ActivateShield_Radius=0;
  Shield_Shape.setRadius(MiniShield_Radius);
  Shield_Shape.setPosition(-500,-500);
 }
}

void Collision::DrawShipCrash(RenderWindow &Window)
{
 Window.draw(ShipeCrash_Sprite);
}

void Collision::Check_RockCrash(RenderWindow &Window, bool &Laser,RectangleShape Laser_Shape,RectangleShape RockDrop_Shape[30],RectangleShape RockRaise_Shape[30],bool &Bonus10,bool &Bonus15)
{
 for(int i=0;i<30;i++)
 {
  if(Laser==true)
  {
   if(Laser_Shape.getGlobalBounds().intersects(RockDrop_Shape[i].getGlobalBounds()))
   {
    RockCrash=true;
    RockDrop_Shape[i].setSize(Vector2f(0,0));
    GameMusic_Object.setRockCrash_Sound();
    if(i%5==0)
    {
     Bonus15=true;
    }
    if(i%5!=0)
    {
     Bonus10=true;
    }
    for(int j=0;j<10;j++)
    {
     RockCrash_Shape[i][j].setPosition(RockDrop_Shape[i].getPosition().x+x,RockDrop_Shape[i].getPosition().y+y);
     RockCrash_Shape[i][j].setSize(Vector2f(5,2.5));
     x=rand()%20+5;
     y=rand()%15+5;
    }

    if(i==4)
    {
     if(ActivateShield==false)
     {
      Shield_Shape.setPosition(RockDrop_Shape[i].getPosition().x,RockDrop_Shape[i].getPosition().y);
     }
    }

   }

   if(Laser_Shape.getGlobalBounds().intersects(RockRaise_Shape[i].getGlobalBounds()))
   {
    RockCrash=true;
    RockRaise_Shape[i].setSize(Vector2f(0,0));
    GameMusic_Object.setRockCrash_Sound();
    if(i%5==0)
    {
     Bonus15=true;
    }
    if(i%5!=0)
    {
     Bonus10=true;
    }
    for(int j=0;j<10;j++)
    {
      RockCrash_Shape[i][j].setPosition(RockRaise_Shape[i].getPosition().x+x,RockRaise_Shape[i].getPosition().y+y);
      RockCrash_Shape[i][j].setSize(Vector2f(5,2.5));
      x=rand()%20+5;
      y=rand()%15+5;
    }

    if(i==4)
    {
     if(ActivateShield==false)
     {
      Shield_Shape.setPosition(RockRaise_Shape[i].getPosition().x,RockRaise_Shape[i].getPosition().y);
     }
    }
   }
  }
 }
}

void Collision::DrawRockCrash(RenderWindow &Window,int &Meteors1_MoveY)
{
 if(RockCrash==true)
 {
  for(int i=0;i<30;i++)
  {
   for(int j=0;j<10;j++)
   {
    Window.draw(RockCrash_Shape[i][j]);
    RockCrash_Shape[i][j].move(0,Meteors1_MoveY);
   }
  }
  Window.draw(Shield_Shape);
  if(ActivateShield==false)
  {
   Shield_Shape.move(0,Meteors1_MoveY);
  }
 }
}
