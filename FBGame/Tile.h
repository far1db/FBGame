#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

/**
	
*/

enum TileType {
	WALL = 0,
	PLAYER,
	WOOD_BLOCK,
	COIN,
	LOCK_YELLOW,
	GREEN_BONUS,
	RED_MALUS,

	PLAYER_RIGHT,
	PLAYER_LEFT,
	PLAYER_UP,
	PLAYER_DOWN,
	TOTAL
};

ref class Tile
{
public:
	Tile();
	Tile(String ^ imagePath); // Initilize a Tile with a background image
	~Tile();

	void show(Form ^); // Add the picture box to the form
	void loadFromImage(String ^);
	void setLocation(int, int);
	void setSprite(TileType);
	void setWalkable(bool);
	TileType getType();
	bool isWalkable();
	PictureBox ^ getPictureBox();

	const static int TILE_SIZE = 64; // Size in pixels of a single tile image

private:
	PictureBox ^ pictureBox = gcnew PictureBox;
	static array<String^>^ sprites = gcnew array<String^>(TileType::TOTAL);
	const static Color DEFAULT_TILE_COLOR = Color::FromArgb(89, 96, 108);

	TileType type;
	bool walkable;

	void initSprites();
};
