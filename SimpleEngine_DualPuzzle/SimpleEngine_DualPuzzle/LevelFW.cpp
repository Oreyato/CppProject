#include "LevelFW.h"
#include "Tree.h"
#include "Random.h"

LevelFW::LevelFW() :
	WIDTH(8),
	HEIGHT(4),
	treeA("TreeA"),
	treeB("TreeB"),
	treeC("TreeC")
{
}

void LevelFW::generateLevelFW()
{
    Random random;

	// Resizing trees to fit the dimensions
	trees.resize(WIDTH);
	for (size_t i = 0; i < trees.size(); i++)
	{
		trees[i].resize(HEIGHT);
	}

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            // Add random trees
            if (random.getIntRange(0, 3) == 0)
            {
                trees[i][j] = &treeB;
            }
            else
            {
                trees[i][j] = &treeC;
            }
        }
    }

    // Add some more
    int i = random.getIntRange(0, WIDTH);
    for (int j = 0; j < HEIGHT; j++) {
        trees[i][j] = &treeA;
    }

    setPos();
}

void LevelFW::setPos() {
    int treeDimension = treeA.getBaseWidthHeight();

    for (size_t i = 0; i < WIDTH; i++)
    {
        for (size_t j = 0; j < HEIGHT; j++) {
            trees[i][j]->setPosition(Vector2(25.0f + i * treeDimension, 25.0f + j * treeDimension));
        }
    }
}