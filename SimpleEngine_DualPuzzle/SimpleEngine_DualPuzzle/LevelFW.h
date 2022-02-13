#pragma once
#include "Tree.h"

class LevelFW {
public:
	LevelFW();
	void generateLevelFW();
	void setPos();

private:
	int WIDTH;
	int HEIGHT;

	std::vector<std::vector<Tree*>> trees;

	Tree treeA;
	Tree treeB;
	Tree treeC;
};