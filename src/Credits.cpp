#include "Credits.h"

using namespace sf;

Credits::Credits()
{
  WinW=1366;
  WinH=768;

  //Font!
  font.loadFromFile("Data/Fonts/Leander.ttf");
  calibri_Font.loadFromFile("Data/Fonts/calibri.ttf");
  vivaldi_Font.loadFromFile("Data/Fonts/vivaldi.ttf");

  //Textures!
  CreditsBackGround[0].loadFromFile("Data/Pictures/Credits/backGround0.png");
  CreditsBackGround[1].loadFromFile("Data/Pictures/Credits/backGround1.png");

  //Shapes
  setShapes();

  //Text!
  setCredits_Text();

}


void Credits::setShapes()
{
 for(int i=0;i<2;i++)
 {
  backGround_Shape[i].setSize(Vector2f(WinW,WinH));
  backGround_Shape[i].setPosition(WinW*i,0);
  backGround_Shape[i].setTexture(&CreditsBackGround[i]);
 }
}


void Credits::setCredits_Text()
{
 //GameDevelopment
 GameDevelopment.setString("Game Development");
 GameDevelopment.setFont(font);
 GameDevelopment.setCharacterSize(40);
 GameDevelopment.setPosition((WinW/2)-(GameDevelopment.getGlobalBounds().width/2) ,WinH+10);

 GameDevelopment_Text[0].setString("Abdulmagid almgbub");
 GameDevelopment_Text[1].setString("Osama Tantush");
 GameDevelopment_Text[2].setString("Taha ben achour");
 GameDevelopment_Text[3].setString("Abdulmoneim izmaim");

 int yOffset=30;
 for(int i=0;i<4;i++)
 {
  GameDevelopment_Text[i].setFont(font);
  GameDevelopment_Text[i].setCharacterSize(20);
  GameDevelopment_Text[i].setPosition((WinW/2)-(GameDevelopment_Text[i].getGlobalBounds().width/2) , GameDevelopment.getPosition().y+30+yOffset);
  yOffset+=30;
 }

 //Beta testers
 BetaTesters.setString("BetaEditions Testers");
 BetaTesters.setFont(font);
 BetaTesters.setCharacterSize(40);
 BetaTesters.setPosition((WinW/2)-(BetaTesters.getGlobalBounds().width/2) ,GameDevelopment_Text[3].getPosition().y+300);

 BetaTesters_Text[0].setString("Hussien alwalid");
 BetaTesters_Text[1].setString("Mohammad Gzema");
 BetaTesters_Text[2].setString("Ali Alzendate");
 BetaTesters_Text[3].setString("AbdAlfatah Alhadi");
 BetaTesters_Text[4].setString("Sami Mohammad");

 yOffset=30;
 for(int i=0;i<5;i++)
 {
  BetaTesters_Text[i].setFont(font);
  BetaTesters_Text[i].setCharacterSize(20);
  BetaTesters_Text[i].setPosition((WinW/2)-(BetaTesters_Text[i].getGlobalBounds().width/2) ,BetaTesters.getPosition().y+30+yOffset);
  yOffset+=30;
 }

 //SpecialThanks
 SpecialThanks.setString("Special Thanks to");
 SpecialThanks.setFont(font);
 SpecialThanks.setCharacterSize(40);
 SpecialThanks.setPosition((WinW/2)-(SpecialThanks.getGlobalBounds().width/2) , BetaTesters_Text[4].getPosition().y+300);

 //EC252 Teachers!
 SpecialThanks_Text[0].setString("EC252 Teachers:");
 SpecialThanks_Text[1].setString("Dr.Youssef Gdura");
 SpecialThanks_Text[2].setString("Eng.Hajer Alhamrouny");
 //Spring 2016 Students!
 SpecialThanks_Text[3].setString("EC252 Students:");
 SpecialThanks_Text[4].setString("Abdulhadi Alhasumi");
 SpecialThanks_Text[5].setString("Akrem Bahloul");
 SpecialThanks_Text[6].setString("Arwa Abushagor");
 SpecialThanks_Text[7].setString("Asma Alwerfali");
 SpecialThanks_Text[8].setString("Enass Altarhuni");
 SpecialThanks_Text[9].setString("Ghofran Alelwani");
 SpecialThanks_Text[10].setString("Hana Abusalam");
 SpecialThanks_Text[11].setString("Huda Amer Alsager");
 SpecialThanks_Text[12].setString("Lugain Shaban");
 SpecialThanks_Text[13].setString("Mohammed Turki");
 SpecialThanks_Text[14].setString("Rawan Mansour");
 SpecialThanks_Text[15].setString("Ritaj Alsharif");
 SpecialThanks_Text[16].setString("Shaima Mohammed");
 SpecialThanks_Text[17].setString("Ziyad Abeid");

 yOffset=30;
 for(int i=0;i<18;i++)
 {
  if(i==0)
  {
   SpecialThanks_Text[i].setFont(calibri_Font);
   SpecialThanks_Text[i].setStyle(Text::Bold);
   SpecialThanks_Text[i].setCharacterSize(32);
   SpecialThanks_Text[i].setPosition((WinW/2)-(SpecialThanks_Text[i].getGlobalBounds().width/2) , SpecialThanks.getPosition().y+30+yOffset);
   yOffset+=30;
  }
  else if(i!=0 || i!=3)
  {
   SpecialThanks_Text[i].setFont(font);
   SpecialThanks_Text[i].setCharacterSize(20);
   if(i<3)
   {
    SpecialThanks_Text[i].setPosition((WinW/2)-(SpecialThanks_Text[i].getGlobalBounds().width/2) , SpecialThanks.getPosition().y+40+yOffset);
   }
   if(i>3)
   {
    SpecialThanks_Text[i].setPosition((WinW/2)-(SpecialThanks_Text[i].getGlobalBounds().width/2) , SpecialThanks.getPosition().y+30+yOffset);
   }
   yOffset+=30;
  }
  if(i==3)
  {
   SpecialThanks_Text[i].setFont(calibri_Font);
   SpecialThanks_Text[i].setStyle(Text::Bold);
   SpecialThanks_Text[i].setCharacterSize(32);
   SpecialThanks_Text[i].setPosition((WinW/2)-(SpecialThanks_Text[i].getGlobalBounds().width/2) , SpecialThanks.getPosition().y+20+yOffset);
   yOffset+=30;
  }
 }


 //Producers!
 ProductionTeam.setString("Produced by AlphaCrew");
 ProductionTeam.setFont(font);
 ProductionTeam.setCharacterSize(40);
 ProductionTeam.setPosition((WinW/2)-(ProductionTeam.getGlobalBounds().width/2), SpecialThanks_Text[17].getPosition().y+300);

 //CopyRights
 CopyRight.setString("all rights are reserved 2016");
 CopyRight.setFont(font);
 CopyRight.setCharacterSize(20);
 CopyRight.setPosition((WinW/2)-(CopyRight.getGlobalBounds().width/2),ProductionTeam.getPosition().y+50);

 //EndCredits
 End_Credit.setString("Press [ESC] to back to MainMenu");
 End_Credit.setFont(font);
 End_Credit.setCharacterSize(28);
 End_Credit.setPosition((WinW/2)-(End_Credit.getGlobalBounds().width/2),WinH/2);
}


void Credits::ResetCredits()
{
 //BackGround
 for(int i=0;i<2;i++)
 {
  backGround_Shape[i].setPosition(WinW*i,0);
 }

 //GameDevelopment
 GameDevelopment.setPosition((WinW/2)-(GameDevelopment.getGlobalBounds().width/2) ,WinH+20);
 int yOffset=30;
 for(int i=0;i<4;i++)
 {
  GameDevelopment_Text[i].setPosition((WinW/2)-(GameDevelopment_Text[i].getGlobalBounds().width/2) , GameDevelopment.getPosition().y+30+yOffset);
  yOffset+=30;
 }

 BetaTesters.setPosition((WinW/2)-(BetaTesters.getGlobalBounds().width/2) ,GameDevelopment_Text[3].getPosition().y+300);
 yOffset=30;
 for(int i=0;i<5;i++)
 {
  BetaTesters_Text[i].setPosition((WinW/2)-(BetaTesters_Text[i].getGlobalBounds().width/2) ,BetaTesters.getPosition().y+30+yOffset);
  yOffset+=30;
 }

 //SpecialThanks
 SpecialThanks.setPosition((WinW/2)-(SpecialThanks.getGlobalBounds().width/2) , BetaTesters_Text[4].getPosition().y+300);
 yOffset=30;
 for(int i=0;i<18;i++)
 {
  if(i==0)
  {
   SpecialThanks_Text[i].setPosition((WinW/2)-(SpecialThanks_Text[i].getGlobalBounds().width/2) , SpecialThanks.getPosition().y+30+yOffset);
   yOffset+=30;
  }
  else if(i!=0 || i!=3)
  {
   if(i<3){SpecialThanks_Text[i].setPosition((WinW/2)-(SpecialThanks_Text[i].getGlobalBounds().width/2) , SpecialThanks.getPosition().y+40+yOffset);}
   if(i>3){SpecialThanks_Text[i].setPosition((WinW/2)-(SpecialThanks_Text[i].getGlobalBounds().width/2) , SpecialThanks.getPosition().y+30+yOffset);}
   yOffset+=30;
  }
  if(i==3)
  {
   SpecialThanks_Text[i].setPosition((WinW/2)-(SpecialThanks_Text[i].getGlobalBounds().width/2) , SpecialThanks.getPosition().y+20+yOffset);
   yOffset+=30;
  }
 }
 ProductionTeam.setPosition((WinW/2)-(ProductionTeam.getGlobalBounds().width/2), SpecialThanks_Text[17].getPosition().y+300);
 CopyRight.setPosition((WinW/2)-(CopyRight.getGlobalBounds().width/2),ProductionTeam.getPosition().y+50);
 End_Credit.setPosition((WinW/2)-(End_Credit.getGlobalBounds().width/2),WinH/2);
}


void Credits::Credits_Control(Event MainEvent, RenderWindow &Window,bool &DisplayMainMenu,bool &DisplayCredits)
{
 if(MainEvent.type == Event::KeyPressed)
 {
  if(MainEvent.key.code == Keyboard::Escape)
  {
   DisplayMainMenu=true;
   DisplayCredits=false;
   ResetCredits();
  }
 }
}


void Credits::MoveCredits()
{
 //BackGround
 for(int i=0;i<2;i++){backGround_Shape[i].move(-0.24,0);}
 if(backGround_Shape[1].getPosition().x<0){backGround_Shape[1].move(0.24,0);}

 ///Text

 //GameDevelopment
 GameDevelopment.move(0,-0.48);
 for(int i=0;i<4;i++){GameDevelopment_Text[i].move(0,-0.48);}
 //BetaTesters
 BetaTesters.move(0,-0.48);
 for(int i=0;i<5;i++){BetaTesters_Text[i].move(0,-0.48);}
 //SpecialThanks
 SpecialThanks.move(0,-0.48);
 for(int i=0;i<18;i++){SpecialThanks_Text[i].move(0,-0.48);}
 //Production && CopyRights
 ProductionTeam.move(0,-0.48);
 CopyRight.move(0,-0.48);
}


void Credits::ShowCredits(RenderWindow &Window)
{
 MoveCredits();
 //BackGround
 for(int i=0;i<2;i++){Window.draw(backGround_Shape[i]);}
 //GameDevelopment
 Window.draw(GameDevelopment);
 for(int i=0;i<4;i++){Window.draw(GameDevelopment_Text[i]);}
 //BetaTesters
 Window.draw(BetaTesters);
 for(int i=0;i<5;i++){Window.draw(BetaTesters_Text[i]);}
 //SpecialThanks
 Window.draw(SpecialThanks);
 for(int i=0;i<18;i++){Window.draw(SpecialThanks_Text[i]);}
 //ProductionTeam
 Window.draw(ProductionTeam);
 //CopyRight
 Window.draw(CopyRight);
 //EndCredits
 if(CopyRight.getPosition().y<-100){Window.draw(End_Credit);}
}
