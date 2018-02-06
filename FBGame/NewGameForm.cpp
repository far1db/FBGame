#include "NewGameForm.h"

/*
	Load the map from the levels array according to the index passed
*/

bool FBGame::NewGameForm::loadLevel(int i)
{
	char* level = "";

	level = (char*)(void*)Marshal::StringToHGlobalAnsi(levels[i]); // Convert from String ^ to char*

	if (!map.loadFromFile(level)) {
		return false;
	}
	else {
		// Set the size of the client inside the form according to the map
		ClientSize = System::Drawing::Size((Map::MAP_WIDTH) * Tile::TILE_SIZE, (Map::MAP_HEIGHT) * Tile::TILE_SIZE + gameStatus->Height);
		updateStatus();

		return true;
	}
}

void FBGame::NewGameForm::updateStatus() {
	coinsLabel->Text = "Coins: " + map.getGatheredCoins() + "/" + map.getCoinsTotal();
	levelLabel->Text = "Level: " + (currentLevel + 1);
	scoreLabel->Text = "Score: " + map.getScore();
	highestScoreLabel->Text = "Highest Score: " + HighScore::getHighScore();
	stepsLabel->Text = "Steps: " + map.getStepsWalked() + "/" + map.getStepsTotal();
}
