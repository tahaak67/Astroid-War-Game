#include "InGameMenu.h"

using namespace sf;

InGameMenu::InGameMenu()
{
 WinW=1366;
 WinH=768;

 //variables
 SelectedElementIndex=0;
 MusicCounter=0;
 EscapeCounter=0;
 ScreenModeCount=0;

 //Fonts!
 font.loadFromFile("Data/Fonts/Leander.ttf");

 //Textures!
 BackGround_Texture.loadFromFile("Data/Pictures/Game BackGround/backGround0.png");

 //Shapes
 BackGround_Shape.setSize(Vector2f(WinW,WinH));
 BackGround_Shape.setPosition(0,0);
 BackGround_Shape.setTexture(&BackGround_Texture);

 //Lines
 Line_xOffset=150;
 Line_yOffset=0;
 for(int i=0;i<7;i++)
 {
  Line[i].setSize(Vector2f(200,2));
  Line[i].setFillColor(Color(230,230,230));
  Line[i].setPosition(WinW/2-Line_xOffset,WinH/2+Line_yOffset);
  Line_yOffset+=34;
 }
 Line[0].setFillColor(Color::Cyan);
 Line[1].setFillColor(Color::Cyan);

 //Text!
 for(int i=0;i<6;i++)
 {
  InGameMenu_Text[i].setFont(font);
  InGameMenu_Text[i].setColor(Color(230,230,230));
  InGameMenu_Text[i].setCharacterSize(21);
 }
 InGameMenu_Text[0].setString("Resume");
 InGameMenu_Text[0].setPosition(Line[0].getPosition().x+InGameMenu_Text[0].getCharacterSize()*3,Line[0].getPosition().y+4);
 InGameMenu_Text[0].setColor(Color::Cyan);  //Selected By Default!

 InGameMenu_Text[1].setString("Start NewGame");
 InGameMenu_Text[1].setPosition(Line[1].getPosition().x+InGameMenu_Text[1].getCharacterSize()*1,Line[1].getPosition().y+4);

 InGameMenu_Text[2].setString("Full Screen Mode");
 InGameMenu_Text[2].setPosition(Line[2].getPosition().x+InGameMenu_Text[2].getCharacterSize()*0.8,Line[2].getPosition().y+4);

 InGameMenu_Text[3].setString("Music ON");
 InGameMenu_Text[3].setPosition(Line[3].getPosition().x+InGameMenu_Text[3].getCharacterSize()*2.5,Line[3].getPosition().y+4);

 InGameMenu_Text[4].setString("Exit to MainMenu");
 InGameMenu_Text[4].setPosition(Line[4].getPosition().x+InGameMenu_Text[4].getCharacterSize()*0.6,Line[4].getPosition().y+4);

 InGameMenu_Text[5].setString("Exit to Desktop");
 InGameMenu_Text[5].setPosition(Line[5].getPosition().x+InGameMenu_Text[5].getCharacterSize()*1.1,Line[5].getPosition().y+4);

}


void InGameMenu::InGameMenu_Control(Event event,RenderWindow &Window,bool &DisplayMenu,bool &DisplayGame,bool &DisplayInGameMenu,bool &RestartGame,Clock &c1,float &timer1,float &timer2)
{
 if(event.type == Event::KeyPressed)
 {
  if(event.key.code == Keyboard::Up)
  {
   MoveUp();
  }
  if(event.key.code == Keyboard::Down)
  {
   MoveDown();
  }
  if(event.key.code == Keyboard::Return)
  {
   if(SelectedElementIndex==0)
   {
    DisplayInGameMenu=false;
    DisplayGame=true;
   }
   if(SelectedElementIndex==1)
   {
    DisplayGame=true;
    RestartGame=true;
    DisplayInGameMenu=false;
    c1.restart();
    timer1=0;
    timer2=0;
   }
   if(SelectedElementIndex==2)
   {

   }
   if(SelectedElementIndex==3)
   {

   }
   if(SelectedElementIndex==4)
   {
    DisplayInGameMenu=false;
    DisplayMenu=true;
   }
   if(SelectedElementIndex==5)
   {
    Window.close();
   }
  }
 }
 if(event.type==Event::KeyReleased)
 {
  if(event.key.code==Keyboard::Return)
  {
   if(SelectedElementIndex==1)
   {

   }
  }
 }
}


void InGameMenu::MoveUp()
{
 if(SelectedElementIndex-1>=0)
 {
  InGameMenu_Text[SelectedElementIndex].setColor(Color(230,230,230));
  Line[SelectedElementIndex+1].setFillColor(Color(230,230,230));
  SelectedElementIndex--;
  InGameMenu_Text[SelectedElementIndex].setColor(Color::Cyan);
  Line[SelectedElementIndex].setFillColor(Color::Cyan);
  GameMusic_Object.setMenuSelect_Sound();
  }
}


void InGameMenu::MoveDown()
{
 if(SelectedElementIndex+1 < 6)
 {
  InGameMenu_Text[SelectedElementIndex].setColor(Color(230,230,230));
  Line[SelectedElementIndex].setFillColor(Color(230,230,230));
  Line[SelectedElementIndex-1].setFillColor(Color(230,230,230));
  SelectedElementIndex++;
  InGameMenu_Text[SelectedElementIndex].setColor(Color::Cyan);
  Line[SelectedElementIndex].setFillColor(Color::Cyan);
  Line[SelectedElementIndex+1].setFillColor(Color::Cyan);
  GameMusic_Object.setMenuSelect_Sound();
 }
}


void InGameMenu::setScreenMode(RenderWindow &Window)
{
 if(SelectedElementIndex==2)
 {
  ScreenModeCount++;
  if(ScreenModeCount%2==0)
  {
   InGameMenu_Text[2].setString("Full Screen Mode");
   InGameMenu_Text[2].setPosition(Line[2].getPosition().x+InGameMenu_Text[2].getCharacterSize()*0.8,Line[2].getPosition().y+4);
   Window.create(VideoMode(WinW,WinH),"Ship!" ,Style::Default);
   Window.setFramerateLimit(60);
  }
  else
  {
   InGameMenu_Text[2].setString("Window Mode");
   InGameMenu_Text[2].setPosition(Line[2].getPosition().x+InGameMenu_Text[2].getCharacterSize()*1.3,Line[2].getPosition().y+4);
   Window.create(VideoMode(WinW,WinH) ,"Ship!", Style::Fullscreen);
   Window.setFramerateLimit(60);
   Window.setMouseCursorVisible(false);
   Window.setKeyRepeatEnabled(false);
  }
 }
}


void InGameMenu::setMusicState()
{
 MusicCounter++;
 if(MusicCounter%2==0)
 {
  InGameMenu_Text[3].setString("Music ON");
  InGameMenu_Text[3].setPosition(Line[3].getPosition().x+InGameMenu_Text[3].getCharacterSize()*2.5,Line[3].getPosition().y+4);
 }
 else
 {
  InGameMenu_Text[3].setString("Music OFF");
  InGameMenu_Text[3].setPosition(Line[3].getPosition().x+InGameMenu_Text[3].getCharacterSize()*2.4,Line[3].getPosition().y+4);
 }
}


void InGameMenu::InGameMenu_Draw(RenderWindow &Window)
{
 //BackGround!
 Window.draw(BackGround_Shape);

 //Lines!
 for(int i=0;i<7;i++)
 {
  Window.draw(Line[i]);
 }
 //Text!
 for(int i=0;i<6;i++)
 {
  Window.draw(InGameMenu_Text[i]);
 }
}
