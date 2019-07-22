#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <fstream>

using namespace sf;

class Score
{
  public:
    Score();
    void DrawScore(RenderWindow &Window);
    void SetScore(bool &DisplayGame,bool &RestartGame,Time &GameTimer);
    void setFile(float PlayerScore);
    void setBonus(RenderWindow &Window);
    void setHighScore();
    void ChangeColor();
    void RestartColor();


    bool Bonus10;
    bool Bonus15;

  private:
    //Variables
    int WinW;
    int WinH;
    float ScorePoints;
    int PlayerScore;
    int newScore;
    int HighScore;
    int x;
    int temp;
    int OldScore;
    int randNum;

    //Textures!
    Texture Bonus10_Texture;
    Texture Bonus15_Texture;

    //Shapes
    Sprite Bonus10_Sprite;
    Sprite Bonus15_Sprite;

    //Fonts
    Font Score_Font;
    Font font;
    Font vivaldi_Font;

    //Text
    Text Score_Text;
    Text Score_Number;
    Text HighScore_Text;
    Text HighScore_Number;

};
#endif
