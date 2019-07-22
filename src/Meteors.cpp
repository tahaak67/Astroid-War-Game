#include "Meteors.h"

using namespace sf;

Meteors::Meteors()
{
 //Screen Width & Height!
 WinW=1366;
 WinH=768;

 //Variables!
 Meteors0_MoveY=3;
 Meteors1_MoveY=5;

 //Randoms!
 for(int i=0;i<30;i++)
 {
  randomNumber[i]=rand()%WinW-WinW/2;
  randomSize0[i]=rand()%70+40;
  randomSize1[i]=rand()%70+40;
  randomScale[i]=rand()%2;
  randomPositions1[i]=rand()%WinW+randomSize0[i]*2;
  randomPositions2[i]=rand()%WinW+randomSize0[i]*2;
  randomDegrees[i]=rand()%360+1;
  randomMoveX[i]=rand()%4+(1)-4; //Range(3,-3)!
 }

 //Textures
 Rock_texture1.loadFromFile("Data/Pictures/Asteroids/asteroid.png");
 Rock_texture2.loadFromFile("Data/Pictures/Asteroids/asteroid02.png");

 //Shapes
 for(int i=0;i<30;i++)
 {
  if(i%5==0)
  {
   //Dropped Rocks type 1!
   RockDrop_Shape[i].setSize(Vector2f(randomSize1[i],randomSize1[i]));
   RockDrop_Shape[i].setTexture(&Rock_texture2);
   RockDrop_Shape[i].setPosition(randomPositions1[i],-400);
   RockDrop_Shape[i].setOrigin(Vector2f(RockDrop_Shape[i].getGlobalBounds().width/2,RockDrop_Shape[i].getGlobalBounds().height/2));
   RockDrop_Shape[i].setRotation(randomDegrees[i]);

   //RaisedRocks type 1!
   RockRaise_Shape[i].setSize(Vector2f(randomSize1[i],randomSize1[i]));
   RockRaise_Shape[i].setTexture(&Rock_texture2);
   RockRaise_Shape[i].setPosition(randomPositions2[i],WinH+400);
   RockRaise_Shape[i].setOrigin(Vector2f(RockRaise_Shape[i].getGlobalBounds().width/2,RockRaise_Shape[i].getGlobalBounds().height/2));
   RockRaise_Shape[i].setRotation(randomDegrees[i]);
   RockRaise_Shape[i].setFillColor(Color(140,140,150));
   }
   else
   {
    //Dropped Rocks!
    RockDrop_Shape[i].setSize(Vector2f(randomSize0[i],randomSize0[i]));
    RockDrop_Shape[i].setTexture(&Rock_texture1);
    RockDrop_Shape[i].setPosition(randomPositions1[i],-400);
    RockDrop_Shape[i].setOrigin(Vector2f(RockDrop_Shape[i].getGlobalBounds().width/2,RockDrop_Shape[i].getGlobalBounds().height/2));
    RockDrop_Shape[i].setRotation(randomDegrees[i]);
    RockDrop_Shape[i].setFillColor(Color(140,140,125));

    //RaisedRocks!
    RockRaise_Shape[i].setSize(Vector2f(randomSize0[i],randomSize0[i]));
    RockRaise_Shape[i].setTexture(&Rock_texture1);
    RockRaise_Shape[i].setPosition(randomPositions2[i],WinH+400);
    RockRaise_Shape[i].setOrigin(Vector2f(RockRaise_Shape[i].getGlobalBounds().width/2,RockRaise_Shape[i].getGlobalBounds().height/2));
    RockRaise_Shape[i].setRotation(randomDegrees[i]);
    RockRaise_Shape[i].setFillColor(Color(130,140,150));
   }
  }
}

void Meteors::RestartMeteorType()
{
 MeteorDropType1=0;
 MeteorRaiseType1=0;
}

void Meteors::RestartMeteors()
{
 for(int i=0;i<30;i++)
 {
  if(i%5==0)
  {
   RockDrop_Shape[i].setPosition(randomPositions1[i],-400);
   RockRaise_Shape[i].setPosition(randomPositions2[i],WinH+400);
  }
  else
  {
   RockDrop_Shape[i].setPosition(randomPositions1[i],-400);
   RockRaise_Shape[i].setPosition(randomPositions2[i],WinH+400);
  }
 }
}


void Meteors::MoveMeteors(float timer1,float timer2)
{
 for(int i=0;i<30;i++)
 {
  if(timer1>i)
  {
   if(i%5==0)
   {
    //Dropped Rocks type 1!
    RockDrop_Shape[i].move(randomMoveX[i],Meteors1_MoveY);
    if(RockDrop_Shape[i].getPosition().y > WinH)
    {
     randomPositions1[i]=rand()%WinW+randomSize0[i]*2;
     RockDrop_Shape[i].setPosition(randomPositions1[i],-400);
     RockDrop_Shape[i].setSize(Vector2f(randomSize1[i],randomSize1[i]));
    }
   }
   else
   {
    //Dropped Rocks!
    RockDrop_Shape[i].move(randomMoveX[i],Meteors0_MoveY);
    if(RockDrop_Shape[i].getPosition().y > WinH)
    {
     randomPositions1[i]=rand()%WinW+randomSize0[i]*2;
     RockDrop_Shape[i].setPosition(randomPositions1[i],-400);
     RockDrop_Shape[i].setSize(Vector2f(randomSize0[i],randomSize0[i]));
    }
   }
  }
  if(timer2>i)
  {
   if(i%5==0)
   {
    //RaisedRocks type 1!
    RockRaise_Shape[i].move(randomMoveX[i],-Meteors1_MoveY);
    if(RockRaise_Shape[i].getPosition().y < -100)
    {
     randomPositions2[i]=rand()%WinW+randomSize0[i]*2;
     RockRaise_Shape[i].setSize(Vector2f(randomSize1[i],randomSize1[i]));
     RockRaise_Shape[i].setPosition(randomPositions2[i],WinH+400);
    }
   }
   else
   {
    //RaisedRocks!
    RockRaise_Shape[i].move(randomMoveX[i],-Meteors0_MoveY);
    if(RockRaise_Shape[i].getPosition().y < -100)
    {
     randomPositions2[i]=rand()%WinW+randomSize0[i]*2;
     RockRaise_Shape[i].setSize(Vector2f(randomSize0[i],randomSize0[i]));
     RockRaise_Shape[i].setPosition(randomPositions2[i],WinH+400);
    }
   }
  }
 }
}


void Meteors::MeteorsDraw(RenderWindow &Window,float timer1,float timer2)
{
 //Drawing Rocks!
 for(int i=0;i<30;i++)
 {
  if(timer1>i)
  {
   Window.draw(RockDrop_Shape[i]);
  }
  if(timer2>i)
  {
   Window.draw(RockRaise_Shape[i]);
  }
 }
}
