#include "GameMusic.h"

using namespace sf;

GameMusic::GameMusic()
{
 ActivateShield_buffer.loadFromFile("Data/Sounds/bonusWave.wav");
 ActivateShield_Sound.setBuffer(ActivateShield_buffer);
}

void GameMusic::setMainMenu_Music()
{
  MainMenu_Music.openFromFile("Data/Music/CyaronsGate.ogg");
  MainMenu_Music.play();
  MainMenu_Music.setVolume(50);
  MainMenu_Music.setPlayingOffset(seconds(16.176));
}

void GameMusic::setInGame_Music()
{
 MainMenu_Music.stop();
 InGame_Music.openFromFile("Data/Music/InGame_Music.ogg");
 InGame_Music.play();
 InGame_Music.setVolume(50);
}

void GameMusic::setCredits_Music()
{
 MainMenu_Music.pause();
 Credits_Music.openFromFile("");
 Credits_Music.play();
 Credits_Music.setVolume(50);
}

void GameMusic::setMenuSelect_Sound()
{
 MenuSelect_Buffer.loadFromFile("Data/Sounds/MenuSelect.wav");
 MenuSelect_Sound.setBuffer(MenuSelect_Buffer);
 MenuSelect_Sound.play();
}

void GameMusic::setLaser_Sound()
{
 laser_buffer.loadFromFile("Data/Sounds/photon-torpedo.wav");
 laser_Sound.setBuffer(laser_buffer);
 laser_Sound.play();
}

void GameMusic::setTurbo_Sound()
{
 turbo_buffer.loadFromFile("Data/Sounds/ShipMove.wav");
 turbo_Sound.setBuffer(turbo_buffer);
 //turbo_Sound.play();
}

void GameMusic::setShipCrash_Sound()
{
 ShipCrash_buffer.loadFromFile("Data/Sounds/ShipCrash.wav");
 ShipCrash_Sound.setBuffer(ShipCrash_buffer);
 ShipCrash_Sound.play();
}

void GameMusic::setRockCrash_Sound()
{
 RockCrash_buffer.loadFromFile("Data/Sounds/laserhit1.wav");
 RockCrash_Sound.setBuffer(RockCrash_buffer);
 RockCrash_Sound.setVolume(40);
 RockCrash_Sound.play();
}

void GameMusic::setActivateShield_Sound()
{
 ActivateShield_Sound.play();
}
