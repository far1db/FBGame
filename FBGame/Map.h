#pragma once
#include <fstream>
#include "Tile.h"
#include "Player.h"

/**
	Handles a map of images through an array of Tile objects

	Stores information about each level such as the position of the safe and the number of steps

	Contains methods handling the game play such as moving the player
*/

ref class Map
{
public:
	Map();
	~Map();

	void setTileAt(int, int, TileType);
	void show(Form^); // Displays the map inside the form passed as a parameter
	void movePlayer(Directions);
	void setScore(int);
	bool loadFromFile(char*); // Load a map from a file
	int getCoinsTotal();
	int getGatheredCoins();
	int getScore();
	int getStepsTotal();
	int getStepsWalked();
	bool hasWon();
	bool hasLost();
	
	const static int MAP_WIDTH = 10; // Default number of tiles in the x axis
	const static int MAP_HEIGHT = 9; // Default number of tiles in the y axis

private:
	array<Tile^, 2> ^ tilesMap = gcnew array<Tile^, 2>(MAP_WIDTH, MAP_HEIGHT);
	Player player;

	int coinsTotal;
	int gatheredCoins;

	int score; // Total score

	// Position of the safe on the map
	int lockX;
	int lockY;

	bool won; // Set to true when the player wins
	bool lost; // Set to true when the player looses (stepsWalked > stepsTotal)

	int stepsTotal;
	int stepsWalked;

	System::Media::SoundPlayer ^ coinSound;
	System::Media::SoundPlayer ^ bonusSound;
	System::Media::SoundPlayer ^ malusSound;
	System::Media::SoundPlayer ^ wonSound;
	System::Media::SoundPlayer ^ lostSound;
};
