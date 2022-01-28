#include "Level.h"
#include "PlayableTile.h"

Level::Level(int screenWidthP, int screenHeightP) :
	screenWidth(screenWidthP),
	screenHeight(screenHeightP)
{
	row = 0;
	column = 0;
	scale = 1;
	baseWidthHeight = 32;
}

void Level::createLevel(int currentLevelP)
{
	switch (currentLevelP)
	{
	case 1: {
		Log::info("GENERATE LEVEL 01");

		// Initialisations
		row = 9;
		column = 14;

		setStartingPos();
		float newSize = baseWidthHeight * scale;

		// Resize tiles to the right dimensions
		tiles.resize(row);
		for (size_t i = 0; i < tiles.size(); i++)
		{
			tiles[i].resize(column);
		}

		//v Create border ================================================
		// Top
		size_t i = 0;
		for (size_t j = 0; j < column; j++) {
			tiles[i][j] = new Tile();

			tiles[i][j]->setType(Tile::TileType::LIMIT);
			tiles[i][j]->setPosition(Vector2(startingPos.x + j * newSize, startingPos.y + i * newSize));
			tiles[i][j]->setScale(scale);
		}
		// Left
		size_t j = 0;
		for (size_t i = 1; i < row - 1; i++) {
			tiles[i][j] = new Tile();

			tiles[i][j]->setType(Tile::TileType::LIMIT);
			tiles[i][j]->setPosition(Vector2(startingPos.x + j * newSize, startingPos.y + i * newSize));
			tiles[i][j]->setScale(scale);
		}
		// Bottom
		i = row - 1;
		for (size_t j = 0; j < column; j++) {
			tiles[i][j] = new Tile();

			tiles[i][j]->setType(Tile::TileType::LIMIT);
			tiles[i][j]->setPosition(Vector2(startingPos.x + j * newSize, startingPos.y + i * newSize));
			tiles[i][j]->setScale(scale);
		}
		// Right
		j = column - 1;
		for (size_t i = 1; i < row - 1; i++) {
			tiles[i][j] = new Tile();

			tiles[i][j]->setType(Tile::TileType::LIMIT);
			tiles[i][j]->setPosition(Vector2(startingPos.x + j * newSize, startingPos.y + i * newSize));
			tiles[i][j]->setScale(scale);
		}
		//^ Create border ================================================
		// Create background
		for (size_t i = 1; i < row - 1; i++) {
			for (size_t j = 1; j < column - 1; j++) {
				tiles[i][j] = new Tile();

				tiles[i][j]->setType(Tile::TileType::BACKGROUND);
				tiles[i][j]->setPosition(Vector2(startingPos.x + j * newSize, startingPos.y + i * newSize));
				tiles[i][j]->setScale(scale);
			}
		}
		// Create obstacles
		tiles[1][1]->setType(Tile::TileType::OBSTACLE);
		tiles[1][2]->setType(Tile::TileType::OBSTACLE);
		tiles[1][3]->setType(Tile::TileType::OBSTACLE);
		tiles[1][4]->setType(Tile::TileType::OBSTACLE);
		tiles[2][4]->setType(Tile::TileType::OBSTACLE);
		tiles[3][4]->setType(Tile::TileType::OBSTACLE);
		tiles[4][5]->setType(Tile::TileType::OBSTACLE);
		tiles[5][5]->setType(Tile::TileType::OBSTACLE);
		tiles[5][1]->setType(Tile::TileType::OBSTACLE);
		tiles[4][9]->setType(Tile::TileType::OBSTACLE);
		tiles[4][10]->setType(Tile::TileType::OBSTACLE);
		tiles[4][11]->setType(Tile::TileType::OBSTACLE);
		tiles[4][12]->setType(Tile::TileType::OBSTACLE);
		tiles[1][9]->setType(Tile::TileType::OBSTACLE);
		// Create special tiles
		tiles[7][6]->setType(Tile::TileType::AEND);
		tiles[4][8]->setType(Tile::TileType::BEND);

		//Add playable tiles
		addPlayableTiles();
	}
	default:
		break;
	}
}

void Level::addPlayableTiles() {
	PlayableTile* playerA = new PlayableTile();
	PlayableTile* playerB = new PlayableTile();
	playerA->setType(Tile::TileType::APLAYER);
	playerB->setType(Tile::TileType::BPLAYER);
	playerA->setScale(1);
	playerB->setScale(1);
	playerA->setPosition(tiles[2][1]->getPosition());
	playerB->setPosition(tiles[1][10]->getPosition());
}

void Level::setStartingPos()
{
	float xPos = 0.0f;
	float yPos = 0.0f;

	xPos = (screenWidth - baseWidthHeight * scale * column) / 2.0f;
	yPos = (screenHeight - baseWidthHeight * scale * row) / 2.0f;

	// Scale up / -down the tiles so that the board fits better in the screen
	setScale(xPos, yPos);

	// Update the positions with the new scale
	xPos = (screenWidth - baseWidthHeight * scale * column) / 2.0f;
	yPos = (screenHeight - baseWidthHeight * scale * row) / 2.0f;

	startingPos = { xPos, yPos };
}

void Level::setScale(int xPosP, int yPosP)
{
	int halfScreenW = screenWidth / 2;
	int halfScreenH = screenHeight / 2;

	if (xPosP - yPosP <= 0) {
		scale = (halfScreenH - 75) / (halfScreenH - xPosP);
	}
	else {
		scale = (halfScreenW - 75) / (halfScreenW - yPosP);
	}
}
