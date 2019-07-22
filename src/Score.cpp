#include "Score.h"
#include <cstdlib>

using namespace std;
using namespace sf;

Score::Score()
{
 WinW=1366;
 WinH=768;

 ScorePoints=0;

 //Fonts!
 Score_Font.loadFromFile("Data/Fonts/Sansation-BoldItalic.ttf");
 font.loadFromFile("Data/Fonts/Leander.ttf");
 vivaldi_Font.loadFromFile("Data/Fonts/vivaldi.ttf");

 //Textures!
 Bonus10_Texture.loadFromFile("Data/Score/10.png");
 Bonus15_Texture.loadFromFile("Data/Score/15.png");

 //Shapes
 Bonus10_Sprite.setPosition(WinW-100,70);
 Bonus10_Sprite.setTexture(Bonus10_Texture);
 Bonus10_Sprite.setColor(Color::Cyan);

 Bonus15_Sprite.setPosition(WinW-100,70);
 Bonus15_Sprite.setTexture(Bonus15_Texture);

 //Text!
 Score_Text.setFont(Score_Font);
 Score_Text.setString("SCORE:");
 Score_Text.setCharacterSize(30);
 Score_Text.setPosition(WinW-200,30);
 Score_Text.setColor(Color::White);
 Score_Text.setStyle(Text::Bold);

 Score_Number.setFont(Score_Font);
 Score_Number.setCharacterSize(30);
 Score_Number.setPosition(Score_Text.getPosition().x+115,30);
 Score_Number.setColor(Color::White);
 Score_Number.setStyle(Text::Bold);


 HighScore_Text.setFont(Score_Font);
 HighScore_Text.setString("HighScore:");
 HighScore_Text.setCharacterSize(20);
 HighScore_Text.setPosition(WinW-196,10);
 HighScore_Text.setColor(Color::White);
 HighScore_Text.setStyle(Text::Bold);

 HighScore_Number.setFont(Score_Font);
 HighScore_Number.setCharacterSize(20);
 HighScore_Number.setPosition(HighScore_Text.getPosition().x+115,10);
 HighScore_Number.setColor(Color::White);
 HighScore_Number.setStyle(Text::Bold);

 setHighScore();

}


void Score::ChangeColor()
{
 randNum=rand()%3;
 if(randNum==0)
 {
  HighScore_Text.setColor(Color::White);
  HighScore_Number.setColor(Color::White);
 }
 if(randNum==1)
 {
  HighScore_Text.setColor(Color::Blue);
  HighScore_Number.setColor(Color::Blue);
  randNum=rand()%3;

 }
 if(randNum==2)
 {
  HighScore_Text.setColor(Color::Red);
  HighScore_Number.setColor(Color::Red);
  randNum=rand()%3;
 }
}


void Score::setHighScore()
{
 fstream HighScore_File;
 HighScore_File.open("HighScore.txt",ios::in);
 HighScore_File>>HighScore;
}


void Score::setFile(float PlayerScore)
{
 newScore=PlayerScore;
 if(PlayerScore>HighScore)
 {
  HighScore=PlayerScore;
  fstream HighScore_File;
  HighScore_File.open("HighScore.txt",ios::out);
  HighScore_File<<PlayerScore;
  HighScore_File.close();
  setHighScore();
  ChangeColor();
 }
}


void Score::RestartColor()
{
 HighScore_Text.setColor(Color::White);
 HighScore_Number.setColor(Color::White);
}


void Score::SetScore(bool &DisplayGame,bool &RestartGame,Time &GameTimer)
{
 ScorePoints+=0.015;
 if(RestartGame == true)
 {
  if(GameTimer<seconds(0.1))
  {
   ScorePoints=0;
  }
 }
}

void Score::setBonus(RenderWindow &Window)
{
 if(Bonus10==true)
 {
  Bonus10_Sprite.move(0,-0.90);
  ScorePoints+=0.25;
 }
 if(Bonus15==true)
 {
  Bonus15_Sprite.move(0,-0.90);
  ScorePoints+=0.5;
 }
 if(Bonus10_Sprite.getPosition().y<35)
 {
  Bonus10_Sprite.setPosition(WinW-100,70);
  Bonus10=false;
 }
 if(Bonus15_Sprite.getPosition().y<45)
 {
  Bonus15_Sprite.setPosition(WinW-100,70);
  Bonus15=false;
 }
}


void Score::DrawScore(RenderWindow &Window)
{
 PlayerScore = int (ScorePoints);
 setFile(PlayerScore);

 ostringstream buffer;
 buffer<<PlayerScore;
 Score_Number.setString(buffer.str());

 ostringstream HighScore_buffer;
 HighScore_buffer<<HighScore;
 HighScore_Number.setString(HighScore_buffer.str());


 Window.draw(Score_Text);
 Window.draw(Score_Number);
 Window.draw(HighScore_Text);
 Window.draw(HighScore_Number);

 if(Bonus10==true)
 {
  Window.draw(Bonus10_Sprite);
  setBonus(Window);
 }

 if(Bonus15==true)
 {
  Window.draw(Bonus15_Sprite);
  setBonus(Window);
 }
}
