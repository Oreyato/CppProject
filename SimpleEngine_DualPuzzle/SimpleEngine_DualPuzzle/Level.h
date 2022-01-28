#pragma once
#include "Actor.h"
#include "Log.h"
#include <vector>

class Level :
	public Actor
{
public:
	Level(int screenWidthP, int screenHeightP);

	void createLevel(int currentLevelP);
	void addPlayableTiles();
	void setStartingPos();
	void setScale(int xPosP, int yPosP);

	Vector2 getStartingPos() { return startingPos; }
	float getScale() { return scale; }
	std::vector<std::vector<class Tile*>> getTiles() { return tiles; }

private:
	int screenHeight;
	int screenWidth;

	int row;
	int column;

	Vector2 startingPos;
	float scale;
	float baseWidthHeight;

	std::vector<std::vector<class Tile*>> tiles;
};

