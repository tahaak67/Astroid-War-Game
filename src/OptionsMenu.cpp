#include "OptionsMenu.h"

using namespace sf;

OptionsMenu::OptionsMenu()
{
  WinW=1366;
  WinH=768;

  //Variables
  SelectedElementIndex = 0;
  MusicStateCount=0;
  ScreenModeCount=0;

  //Textures!
  OptionsScreen_Texture[0].loadFromFile("Data/Pictures/MainMenu/Options-Menu/OptionsMenu0.png");
  OptionsScreen_Texture[1].loadFromFile("Data/Pictures/MainMenu/Options-Menu/OptionsMenu1.png");
  OptionsScreen_Texture[2].loadFromFile("Data/Pictures/MainMenu/Options-Menu/OptionsMenu2.png");

  //Shapes!
  setShapes();

  //Fonts!
  font.loadFromFile("Data/Fonts/Leander.ttf");
  vivaldi_Font.loadFromFile("Data/Fonts/vivaldi.ttf");

  //Sound Buffers!
  MenuSelect_buffer.loadFromFile("Data/Sounds/MenuSelect.wav");

  //Sounds!
  MenuSelect_Sound.setBuffer(MenuSelect_buffer);

}

void OptionsMenu::setShapes()
{
  OptionsScreen_Shape.setSize(Vector2f(WinW,WinH));
  OptionsScreen_Shape.setPosition(0,0);
  OptionsScreen_Shape.setTexture(&OptionsScreen_Texture[0]);
}


void OptionsMenu::Menu_Control(Event MainEvent,RenderWindow &Window,bool &DisplayMainMenu,bool &DisplayOptions)
{
 if(MainEvent.type == Event::KeyPressed)
 {
  if(MainEvent.key.code == Keyboard::Right)
  {
   MoveRight();
  }
  if(MainEvent.key.code == Keyboard::Left)
  {
   MoveLeft();
  }
 if(MainEvent.key.code==Keyboard::Escape)
  {
   DisplayMainMenu=true;
   DisplayOptions=false;
  }
 }
}


void OptionsMenu::MoveRight()
{
 if(SelectedElementIndex+1<3)
 {
  MenuSelect_Sound.play();
  SelectedElementIndex++;
  OptionsScreen_Shape.setTexture(&OptionsScreen_Texture[SelectedElementIndex]);
 }
}


void OptionsMenu::MoveLeft()
{
 if(SelectedElementIndex-1>=0)
 {
  MenuSelect_Sound.play();
  SelectedElementIndex--;
  OptionsScreen_Shape.setTexture(&OptionsScreen_Texture[SelectedElementIndex]);
 }

}


void OptionsMenu::draw(RenderWindow &Window)
{
  Window.draw(OptionsScreen_Shape);
}
