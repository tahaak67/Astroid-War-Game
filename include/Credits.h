#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>

using namespace std;
using namespace sf;

class Credits
{
  public:
    Credits();
    void setCredits_Text();
    void setCreditsBackGround();
    void setShapes();
    void ShowCredits(RenderWindow &Window);
    void MoveCredits();
    void Credits_Control(Event MainEvent, RenderWindow &Window,bool &DisplayMainMenu,bool &DisplayCredits);
    void ResetCredits();

  private:
    //Variables
    int WinW , WinH;

    //Fonts!
    Font font;
    Font calibri_Font;
    Font vivaldi_Font;

    //Textures!
    Texture CreditsBackGround[2];

    //Shapes!
    RectangleShape backGround_Shape[2];

    //Text!
    Text GameDevelopment;
    Text GameDevelopment_Text[4];

    Text BetaTesters;
    Text BetaTesters_Text[5];

    Text SpecialThanks;
    Text SpecialThanks_Text[18];

    Text ProductionTeam;
    Text CopyRight;

    Text End_Credit;

};
