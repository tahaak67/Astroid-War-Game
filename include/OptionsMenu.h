#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class OptionsMenu
{
  public:
    OptionsMenu();
    void setShapes();
    void Menu_Control(Event MainEvent,RenderWindow &Window, bool &DisplayMainMenu,bool &DisplayOptions);
    void draw(RenderWindow &Window);
    void MoveRight();
    void MoveLeft();

  private:
    //Data
    float WinW;
    float WinH;
    int SelectedElementIndex;
    int MusicStateCount;
    int ScreenModeCount;

    //Textures!
    Texture OptionsScreen_Texture[3];

    //Fonts!
    Font font;
    Font vivaldi_Font;

    //Shapes!
    RectangleShape OptionsScreen_Shape;

    //Sound buffers!
    SoundBuffer MenuSelect_buffer;

    //Sounds!
    Sound MenuSelect_Sound;

};

#endif
