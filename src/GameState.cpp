#include "GameState.h"

using namespace std;
using namespace sf;

GameState::GameState()
{
 DisplayMenu=true;
 DisplayGame=false;
 DisplayInGameMenu=false;
 DisplayEndGame=false;
 RestartGame=false;

 //Timers
 timer1=0;
 timer2=0;

}

void GameState::setControlState(Event MainEvent,RenderWindow &Window)
{
 if(DisplayMenu==true)
 {
  MainMenu_Object.Menu_Control(MainEvent,Window,DisplayMenu,DisplayGame,c1);
 }
 if(DisplayGame==true)
 {
  Ship_Object.ShipControl(MainEvent,DisplayInGameMenu,DisplayGame);
 }
 if(DisplayInGameMenu==true)
 {
  InGameMenu_Object.InGameMenu_Control(MainEvent,Window,DisplayMenu,DisplayGame,DisplayInGameMenu,RestartGame,c1,timer1,timer2);
 }
 if(DisplayEndGame==true)
 {
  EndGame_Object.EndGame_Control(MainEvent,DisplayMenu,DisplayGame,DisplayEndGame,RestartGame,&c1,timer1,timer2);
  Ship_Object.Upbutton=false;
  Ship_Object.Downbutton=false;
  Ship_Object.Rightbutton=false;
  Ship_Object.Leftbutton=false;
  Ship_Object.Laser=false;
  Ship_Object.SpeedUp=false;
 }
}


void GameState::setGameOn(RenderWindow &Window)
{
 Collision_Object.Check_RockCrash(Window,Ship_Object.Laser,Ship_Object.Laser_Shape,Meteors_Object.RockDrop_Shape,Meteors_Object.RockRaise_Shape,Score_Object.Bonus10,Score_Object.Bonus15);
 if(DisplayGame==true)
 {
  GameTimer=c1.getElapsedTime();
  timer1+=0.01;
  timer2+=0.005;
  Ship_Object.Logics();
  Score_Object.SetScore(DisplayGame,RestartGame,GameTimer);

  if(GameTimer>seconds(0.1))
  {
   GameBackGround_Object.MovingBackGround();
   //Meteors_Object.MoveMeteors(timer1,timer2);
   //Collision_Object.Check_LifeState(Ship_Object.Ship1_Sprite ,Meteors_Object.RockDrop_Shape ,Meteors_Object.RockRaise_Shape,DisplayGame,DisplayEndGame);
  }
  if(RestartGame==true)
  {
   if(GameTimer<seconds(0.1))
   {
    GameBackGround_Object.RestartBackGround();
    Ship_Object.RestartShip();
    Meteors_Object.RestartMeteors();
    Meteors_Object.RestartMeteorType();
    Score_Object.RestartColor();
   }
  }
 }
}

void GameState::setDrawState(RenderWindow &Window)
{
 if(DisplayMenu==true)
 {
  MainMenu_Object.draw(Window);
 }
 if(DisplayGame==true)
 {
  GameBackGround_Object.Draw(Window);
  Ship_Object.ShipDraw(Window);
  Meteors_Object.MeteorsDraw(Window,timer1,timer2);
  Score_Object.DrawScore(Window);
  Collision_Object.DrawRockCrash(Window,Meteors_Object.Meteors1_MoveY);
 }
 if(DisplayInGameMenu==true)
 {
  InGameMenu_Object.InGameMenu_Draw(Window);
 }
 if(DisplayEndGame==true)
 {
  GameBackGround_Object.Draw(Window);
  Collision_Object.DrawShipCrash(Window);
  EndGame_Object.Draw_EndGame(Window);
 }
}
