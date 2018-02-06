#include "Tile.h"

Tile::Tile()
{
	initSprites();
	
	pictureBox->BackColor = DEFAULT_TILE_COLOR;
	pictureBox->Width = TILE_SIZE;
	pictureBox->Height = TILE_SIZE;
}

Tile::Tile(String ^ path) {
	initSprites();

	loadFromImage(path);
}

Tile::~Tile()
{
	
}

void Tile::show(Form ^ form) {
	form->Controls->Add(pictureBox);
}

void Tile::loadFromImage(String ^ path) {
	pictureBox->Image = Image::FromFile(path);
	pictureBox->Size = pictureBox->Image->Size;
}

void Tile::setLocation(int x, int y) {
	pictureBox->Location = Point(x, y);
}

void Tile::setSprite(TileType sprite) {
	if (sprite == TileType::WALL) {
		pictureBox->Image = nullptr;
		pictureBox->BackColor = DEFAULT_TILE_COLOR;
	}
	else {
		loadFromImage(sprites[sprite]);
	}
	type = sprite;
}

void Tile::setWalkable(bool value) {
	walkable = value;
}

bool Tile::isWalkable() {
	return walkable;
}

PictureBox ^ Tile::getPictureBox() {
	return pictureBox;
}

TileType Tile::getType() {
	return type;
}

void Tile::initSprites() {
	sprites[TileType::PLAYER] = "assets/player_s.png";

	sprites[TileType::WALL] = "assets/ground_06.png";
	sprites[TileType::WOOD_BLOCK] = "assets/block_03.png";
	sprites[TileType::COIN] = "assets/coin.png";
	sprites[TileType::LOCK_YELLOW] = "assets/lockyellow.png";
	sprites[TileType::GREEN_BONUS] = "assets/green_bonus.png";
	sprites[TileType::RED_MALUS] = "assets/red_malus.png";

	sprites[TileType::PLAYER_RIGHT] = "assets/player_r.png";
	sprites[TileType::PLAYER_LEFT] = "assets/player_l.png";
	sprites[TileType::PLAYER_UP] = "assets/player_u.png";
	sprites[TileType::PLAYER_DOWN] = "assets/player_d.png";
}

