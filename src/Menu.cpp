#include "Menu.h"

using namespace sf;

MainMenu::MainMenu()
{
  WinW=1366;
  WinH=768;

  //States!
  DisplayMainMenu=true;
  DisplayOptions=false;
  DisplayHowToPlay=false;
  DisplayCredits=false;

  //Music
  GameMusic_Object.setMainMenu_Music();

  //Textures!
  MenuBackground_Texture.loadFromFile("Data/Pictures/MainMenu/BackGround/MainMenuBackGround.jpg");

  //Shapes
  setShapes();

  //Fonts!
  font.loadFromFile("Data/Fonts/Leander.ttf");
  vivaldi_Font.loadFromFile("Data/Fonts/vivaldi.ttf");

  //MainMenu Text!
  for(int i=0;i<5;i++)
  {
   Menu_Text[i].setFont(font);
   Menu_Text[i].setColor(Color(230,230,230));
   Menu_Text[i].setCharacterSize(21);
  }
   Menu_Text[0].setString("New Game");
   Menu_Text[0].setPosition(Line[0].getPosition().x+Menu_Text[0].getCharacterSize()*2.1,Line[0].getPosition().y+4);
   Menu_Text[0].setColor(Color::Cyan);

   Menu_Text[1].setString("Options");
   Menu_Text[1].setPosition(Line[1].getPosition().x+Menu_Text[1].getCharacterSize()*2.9,Line[1].getPosition().y+4);

   Menu_Text[2].setString("How to play");
   Menu_Text[2].setPosition(Line[2].getPosition().x+Menu_Text[2].getCharacterSize()*1.8,Line[2].getPosition().y+4);

   Menu_Text[3].setString("Credits");
   Menu_Text[3].setPosition(Line[3].getPosition().x+Menu_Text[3].getCharacterSize()*3.2,Line[3].getPosition().y+4);

   Menu_Text[4].setString("Exit to Desktop");
   Menu_Text[4].setPosition(Line[4].getPosition().x+Menu_Text[4].getCharacterSize()*1.1,Line[4].getPosition().y+4);

  //Variables
  SelectedElementIndex = 0;
  MusicStateCount=0;
  ScreenModeCount=0;

}


void MainMenu::setShapes()
{
  //BackGround!
  MenuBackground_Shape.setSize(Vector2f(WinW,WinH));
  MenuBackground_Shape.setPosition(0,0);
  MenuBackground_Shape.setTexture(&MenuBackground_Texture);

  //Lines!
  Line_xOffset=150;
  Line_yOffset=170;

  for(int i=0;i<6;i++)
  {
   Line[i].setSize(Vector2f(200,2));
   Line[i].setFillColor(Color(230,230,230));
   Line[i].setPosition(WinW/2-Line_xOffset,WinH/2+Line_yOffset);
   Line_yOffset+=34;
  }
  Line[0].setFillColor(Color::Cyan);
  Line[1].setFillColor(Color::Cyan);

}

void MainMenu::MoveUp()
{
 if(SelectedElementIndex-1>=0)
 {
   Menu_Text[SelectedElementIndex].setColor(Color(230,230,230));
   Line[SelectedElementIndex+1].setFillColor(Color(230,230,230));
   SelectedElementIndex--;
   Menu_Text[SelectedElementIndex].setColor(Color::Cyan);
   Line[SelectedElementIndex].setFillColor(Color::Cyan);
   GameMusic_Object.setMenuSelect_Sound();
 }
}

void MainMenu::MoveDown()
{
 if(SelectedElementIndex+1<5)
 {
   Menu_Text[SelectedElementIndex].setColor(Color(230,230,230));
   Line[SelectedElementIndex].setFillColor(Color(230,230,230));
   Line[SelectedElementIndex-1].setFillColor(Color(230,230,230));
   SelectedElementIndex++;
   Menu_Text[SelectedElementIndex].setColor(Color::Cyan);
   Line[SelectedElementIndex].setFillColor(Color::Cyan);
   Line[SelectedElementIndex+1].setFillColor(Color::Cyan);
   GameMusic_Object.setMenuSelect_Sound();
 }
}

void MainMenu::setScreenMode(RenderWindow &Window)
{
 if(SelectedElementIndex==1)
 {
   if(ScreenModeCount%2==0)
    {
    }
    else
    {
    }
 }
}

void MainMenu::setMusicState()
{
 if(SelectedElementIndex==2)
 {
   if(MusicStateCount%2==0)
   {
   }
   else
   {
   }
 }
}

void MainMenu::ExitMenu(RenderWindow &Window)
{
 if(SelectedElementIndex==4)
 {
   Window.close();
 }
}

void MainMenu::Menu_Control(Event MainEvent,RenderWindow &Window,bool &DisplayMenu,bool &DisplayGame,Clock &c1)
{
 if(DisplayMainMenu==true)
 {
  if(MainEvent.type == Event::KeyPressed)
  {
   if(MainEvent.key.code == Keyboard::Up)
   {
     MoveUp();
   }
   if(MainEvent.key.code == Keyboard::Down)
   {
     MoveDown();
   }
   if(MainEvent.key.code == Keyboard::Return)
   {
    if(SelectedElementIndex==0)
    {
     DisplayGame=true;
     DisplayMenu=false;
     c1.restart();
     GameMusic_Object.setInGame_Music();
    }
    if(SelectedElementIndex==1)
    {
     DisplayMainMenu=false;
     DisplayOptions=true;
    }
    if(SelectedElementIndex==2)
    {
     DisplayMainMenu=false;
     DisplayHowToPlay=true;
    }
    if(SelectedElementIndex==3)
    {
     DisplayCredits=true;
     DisplayMainMenu=false;
    }

    PlayMode(DisplayMenu);
    //setScreenMode(Window);
    //setMusicState();
    ExitMenu(Window);
   }
  }
  if(MainEvent.type==Event::KeyReleased)
  {
   if(MainEvent.key.code==Keyboard::Return)
   {
    if(SelectedElementIndex==0)
    {
    }
   }
  }
 }

 if(DisplayMainMenu==false && DisplayOptions==true)
 {
  optionsMenu.Menu_Control(MainEvent,Window,DisplayMainMenu,DisplayOptions);
 }
 if(DisplayMainMenu==false && DisplayHowToPlay==true)
 {
  howToPlay.Menu_Control(MainEvent,Window,DisplayMainMenu,DisplayHowToPlay);
 }
 if(DisplayMainMenu==false && DisplayCredits==true)
 {
  credits.Credits_Control(MainEvent,Window,DisplayMainMenu,DisplayCredits);
 }


}


void MainMenu::PlayMode(bool &DisplayMenu)
{
 if(SelectedElementIndex == 0)
 {
 }
}


void MainMenu::draw(RenderWindow &Window)
{
 if(DisplayMainMenu==true)
 {
  //Drawing BackGround!
  Window.draw(MenuBackground_Shape);

  //Drawing Lines!
  for(int i=0;i<6;i++)
  {
    Window.draw(Line[i]);
  }
  //Drawing MainMenu Text!
  for(int i=0;i<5;i++)
  {
    Window.draw(Menu_Text[i]);
  }
 }
 if(DisplayMainMenu==false && DisplayOptions==true)
 {
   optionsMenu.draw(Window);
 }
 if(DisplayMainMenu==false && DisplayHowToPlay==true)
 {
   howToPlay.draw(Window);
 }
 if(DisplayMainMenu==false && DisplayCredits==true)
 {
   credits.ShowCredits(Window);
 }
}
