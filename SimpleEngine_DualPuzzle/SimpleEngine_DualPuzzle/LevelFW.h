#pragma once
#include "Tree.h"

class LevelFW {
public:
	Tree* trees[8][8];

private:
	const int WIDTH;
	const int HEIGHT;
};