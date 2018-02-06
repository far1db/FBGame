#include "Map.h"

Map::Map() {
	for (int y = 0; y < Map::MAP_HEIGHT; y++) {
		for (int x = 0; x < Map::MAP_WIDTH; x++) {
			tilesMap[x, y] = gcnew Tile;
			setTileAt(x, y, TileType::WALL);
		}
	}

	player.mapX = 0;
	player.mapY = 0;

	won = false;

	lockX = 0;
	lockY = 0;

	score = 0;

	stepsTotal = 0;
	stepsWalked = 0;

	coinSound = gcnew System::Media::SoundPlayer("sounds/coin.wav");
	bonusSound = gcnew System::Media::SoundPlayer("sounds/bonus.wav");
	malusSound = gcnew System::Media::SoundPlayer("sounds/malus.wav");
	wonSound = gcnew System::Media::SoundPlayer("sounds/won.wav");
	lostSound = gcnew System::Media::SoundPlayer("sounds/lost.wav");
}

Map::~Map() {
	delete tilesMap;
}

void Map::setTileAt(int x, int y, TileType type) {
	tilesMap[x, y]->setSprite(type);
	tilesMap[x, y]->setLocation(x * Tile::TILE_SIZE, y * Tile::TILE_SIZE);
}

void Map::show(Form ^ form) {
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			tilesMap[x, y]->show(form);
		}
	}
}

/**
	- Get the target tile according to the direction of movement
	- Check if the target tile is walkable
	- Check if the target tile is a coin, if so increment the gatheredCoins member variable
		if gatheredCoins = coinsTotal | trigger win()
*/
void Map::movePlayer(Directions direction) {
	int targetX = player.mapX, targetY = player.mapY; // Find the tile where the player would move to
	TileType newSprite = TileType::PLAYER;

	switch (direction)
	{
	case LEFT:
		if (player.mapX > 0) {
			targetX = player.mapX - 1;
		}
		newSprite = TileType::PLAYER_LEFT;
		break;
	case RIGHT:
		if (player.mapX < Map::MAP_WIDTH - 2) {
			targetX = player.mapX + 1;
		}
		newSprite = TileType::PLAYER_RIGHT;
		break;
	case UP:
		if (player.mapY > 0) {
			targetY = player.mapY - 1;
		}
		newSprite = TileType::PLAYER_UP;
		break;
	case DOWN:
		if (player.mapY < Map::MAP_HEIGHT - 2) {
			targetY = player.mapY + 1;
		}
		newSprite = TileType::PLAYER_DOWN;
		break;
	}
	
	// Move the player to the target tile if it is walkable
	if (tilesMap[targetX, targetY]->isWalkable()) {
		setTileAt(player.mapX, player.mapY, TileType::WALL); // Set the previous tile (where the player was) to WALL

		player.mapX = targetX;
		player.mapY = targetY;

		// Check if the target tile is a coin
		if (tilesMap[targetX, targetY]->getType() == TileType::COIN) {
			score += 10;
			// Increment the number of coins then check if it is equal to the coins total
			if (++gatheredCoins == coinsTotal)
			{
				tilesMap[lockX, lockY]->setWalkable(true); // Set the safe as walkable
			}

			coinSound->Play();
		}
		// Check if the target tile is a safe AND that the player gathered all the coins
		else if (targetX == lockX && targetY == lockY && gatheredCoins == coinsTotal) {
			won = true;

			wonSound->Play();
		}
		// Check if the target is a bonus or malus
		else if (tilesMap[targetX, targetY]->getType() == TileType::GREEN_BONUS) {
			stepsTotal++;

			bonusSound->Play();
		}
		else if (tilesMap[targetX, targetY]->getType() == TileType::RED_MALUS)
		{
			stepsTotal--;

			malusSound->Play();
		}

		setTileAt(player.mapX, player.mapY, newSprite); // Move the player to the target tile with the appropriate sprite
		
		// Increment the number of steps then check if it is greater than the number of steps allowed
		if (++stepsWalked > stepsTotal) {
			lost = true;

			lostSound->Play();
		}
	}	
}

/**
*	Load the tiles map from a file
*	The file uses number codes to determine the tile type:
	nm : n is a boolean refering to Tile::walkable and m is the tile type as stated in Tile::TileType enum

	return true if successful
*/

bool Map::loadFromFile(char* path) {

	// Reset all the game variables
	won = false; lost = false;
	gatheredCoins = 0;
	coinsTotal = 0;
	lockX = 0; lockY = 0;
	stepsTotal = 0; stepsWalked = 0;

	std::fstream mapFile;
	int tile = 0;
	int steps = 0;
	bool walkable = false;

	mapFile.open(path, std::ios::in); // Open file in "path" for input only

	if (mapFile.is_open()) {

		// Get the maximum number of steps
		mapFile >> steps;
		stepsTotal = steps;

		for (int y = 0; y < Map::MAP_HEIGHT; y++) {
			for (int x = 0; x < Map::MAP_WIDTH; x++) {
				mapFile >> tile; // Read the tile code number

				if (tile >= 10) { // When n = 1
					walkable = true;
					tile -= 10; // Set tile to m by removing n
				}
				else { // When n = 0
					walkable = false;
				}

				if (tile == TileType::PLAYER) {
					player.mapX = x;
					player.mapY = y;
				}
				else if (tile == TileType::COIN) {
					coinsTotal++;
				}
				else if (tile == TileType::LOCK_YELLOW) {
					lockX = x;
					lockY = y;
				}

				setTileAt(x, y, (TileType)tile);
				tilesMap[x, y]->setWalkable(walkable);

			}
		}

		mapFile.close(); // Close the file after reading it

		return true;
	}

	return false;
}

int Map::getCoinsTotal() {
	return coinsTotal;
}

int Map::getGatheredCoins() {
	return gatheredCoins;
}

bool Map::hasWon() {
	return won;
}

bool Map::hasLost() {
	return lost;
}

int Map::getScore() {
	return score;
}

void Map::setScore(int aScore) {
	score = aScore;
}

int Map::getStepsTotal() {
	return stepsTotal;
}

int Map::getStepsWalked() {
	return stepsWalked;
}