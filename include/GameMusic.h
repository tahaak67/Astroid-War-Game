#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "OptionsMenu.h"

using namespace std;
using namespace sf;

class GameMusic
{
 public:
    GameMusic();
    void setMainMenu_Music();
    void setInGame_Music();
    void setCredits_Music();
    void setMenuSelect_Sound();
    void setLaser_Sound();
    void setTurbo_Sound();
    void setShipCrash_Sound();
    void setRockCrash_Sound();
    void setActivateShield_Sound();



 private:
    //Music
    Music MainMenu_Music;
    Music InGame_Music;
    Music Credits_Music;

    //Sound Buffers!
    SoundBuffer MenuSelect_Buffer;
    SoundBuffer laser_buffer;
    SoundBuffer turbo_buffer;
    SoundBuffer ShipCrash_buffer;
    SoundBuffer RockCrash_buffer;
    SoundBuffer ActivateShield_buffer;

    //Sounds!
    Sound MenuSelect_Sound;
    Sound laser_Sound;
    Sound turbo_Sound;
    Sound ShipCrash_Sound;
    Sound RockCrash_Sound;
    Sound ActivateShield_Sound;

};
#endif
