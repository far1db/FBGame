#pragma once

enum Directions {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

ref struct Player {
	// Position of the player relatively to the Map
	int mapX;
	int mapY;
};
