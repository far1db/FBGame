#pragma once
#include <iostream>
#include <fstream>

/*
	Handles reading and writing the highest score
*/

namespace HighScore
{
	int getHighScore();
	void setHighScore(int);

	const std::string HS_FILE = "highscore.fb"; // File stocking the highest score
};

