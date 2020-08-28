#include "AudioManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<sstream>

map<string, Sound> AudioManager::sounds;

AudioManager::AudioManager(string bgMusicPath)
{
	// Set up and play background music
	bgMusic.openFromFile(bgMusicPath);
	bgMusic.setVolume(65);
	bgMusic.setLoop(true);
	bgMusic.play();

	// Set up sound effects
	buffer[0].loadFromFile("Audio/Hit_Bat.wav");
	sounds["Hit_Bat"].setBuffer(buffer[0]);

	buffer[1].loadFromFile("Audio/Hit_Wall.wav");
	sounds["Hit_Wall"].setBuffer(buffer[1]);

	buffer[2].loadFromFile("Audio/Begin_Game.wav");
	sounds["Begin_Game"].setBuffer(buffer[2]);

	buffer[3].loadFromFile("Audio/Fail.wav");
	sounds["Fail"].setBuffer(buffer[3]);

	buffer[4].loadFromFile("Audio/Win.wav");
	sounds["Fail"].setBuffer(buffer[4]);

	// Setup Break Sound effects
	// Loads an array of sounds for when a block is broken
	for (int i = 0; i < 7; i++ )
	{
		std::stringstream ss;
		ss << "Audio/Block_Break_" << i << ".wav";
		breakSoundBuffers[i].loadFromFile(ss.str());
		sounds[ss.str()].setBuffer(breakSoundBuffers[i]);
	}
}

// Any class can access this to play a sound, by simply passing the correct string
void AudioManager::playSound(string soundName)
{
	sounds[soundName].play();
}

// Plays back a random block break sound
void AudioManager::playRandomBlockBreak()
{
	int sound = rand() % 7;

	std::stringstream ss;
	ss << "Audio/Block_Break_" << sound << ".wav";

	playSound(ss.str());
}