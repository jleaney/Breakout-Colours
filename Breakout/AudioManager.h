#pragma once
#include <SFML/Audio.hpp>
#include <map>

using namespace sf;
using namespace std;

class AudioManager
{
private:

	// Allows us to load sound files
	SoundBuffer buffer[10];
	SoundBuffer breakSoundBuffers[7];

public:

	AudioManager(string bgMusicPath);
	
	Music bgMusic;

	// A dictionary of all sounds so they can be easily called
	static map<string, Sound> sounds;
	static vector<Sound> breakSounds;

	static void playSound(string soundName);
	static void playRandomBlockBreak();
};

