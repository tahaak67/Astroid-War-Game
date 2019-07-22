#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class HowToPlay
{
  public:
    HowToPlay();
    void draw(RenderWindow &Window);
    void Menu_Control(Event MainEvent,RenderWindow &Window, bool &DisplayMainMenu,bool &DisplayHowToPlay);

  private:
    //Data
    float WinW;
    float WinH;

    //Textures!
    Texture HowToPlay_Texture;

    //Shapes!
    RectangleShape HowToPlay_Shape;
};

#endif
