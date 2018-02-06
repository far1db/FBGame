#include "HighScore.h"

int HighScore::getHighScore() {
	std::ifstream file;
	int highScore = 0;

	// Open file for input
	file.open(HighScore::HS_FILE, std::ios::in);

	if (file.is_open()) {
		file >> highScore;

		file.close();

		return highScore;
	}
	else {
		return 0;
	}

}

void HighScore::setHighScore(int newScore) {
	std::ofstream file;

	// Open file for output and discard previous file contents (trunc)
	file.open(HighScore::HS_FILE, std::ios::out | std::ios::trunc);
	if (file.is_open()) {
		file << newScore;

		file.close();
	}

}