#include "EndGame.h"

using namespace sf;

EndGame::EndGame()
{
 WinW=1366;
 WinH=768;

 //Fonts
 font.loadFromFile("Data/Fonts/Leander.ttf");

 setEndGameText();
}


void EndGame::setEndGameText()
{
 BacktoMainMenu_Text.setFont(font);
 BacktoMainMenu_Text.setString("Press [ESC] to back to MainMenu");
 BacktoMainMenu_Text.setCharacterSize(15);
 BacktoMainMenu_Text.setPosition(WinW/2-(BacktoMainMenu_Text.getGlobalBounds().width/2)-10,WinH/2-350);

 StartNewGame_Text.setFont(font);
 StartNewGame_Text.setString("Press [Enter] to start a new Game");
 StartNewGame_Text.setCharacterSize(22);
 StartNewGame_Text.setPosition(WinW/2-(StartNewGame_Text.getGlobalBounds().width/2)-10,WinH/2-100);
}


void EndGame::EndGame_Control(Event MainEvent,bool &DisplayMenu,bool &DisplayGame,bool &DisplayEndGame,bool &RestartGame,Clock *c1,float &timer1,float &timer2)
{
 if(MainEvent.type == Event::KeyPressed)
 {
  if(MainEvent.key.code == Keyboard::Escape)
  {
   DisplayEndGame=false;
   DisplayMenu=true;
  }
  if(MainEvent.key.code == Keyboard::Return)
  {
   DisplayEndGame=false;
   DisplayGame=true;
   RestartGame=true;
   c1->restart();
   timer1=0;
   timer2=0;
  }
 }
}


void EndGame::Draw_EndGame(RenderWindow &Window)
{
 Window.draw(BacktoMainMenu_Text);
 Window.draw(StartNewGame_Text);
}
