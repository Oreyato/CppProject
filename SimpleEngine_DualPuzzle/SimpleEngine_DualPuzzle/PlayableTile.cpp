#include "PlayableTile.h"
#include "Game.h"
#include "Log.h"

PlayableTile::PlayableTile() : 
	Tile ()
{
	input = new InputComponent(this);
	move = new MoveComponent(this);
}

void PlayableTile::updateActor(float dt)
{
	// ==============================================================
	// Currently not working, returns a "vector subscript out of range"
	// 
	// Couldn't quite get the clues from the debug tool, but I had things 
	// like missing files (Log.h -when I was using it in the switch, 
	// or even Vector2.h for some reason)
	// ==============================================================
	
	//// Get the tiles in level from Game
	//auto tiles = getGame().getLevel()->getTiles();
	//// Browse tiles
	//for (size_t i = 0; i < tiles[0].size() - 1; i++) {
	//	for (size_t j = 0; j < tiles[1].size() - 1; j++) {
	//		// Check what intersects with our PlayableTile
	//		if (Intersect(*collision, tiles[i][j]->getCollision())) {
	//			// Get its type
	//			Tile::TileType targetType = tiles[i][j]->getType();

	//			switch (tiles[i][j]->getType())
	//			{
	//			case Tile::AEND:
	//				// A victory condition completed 

	//				break;
	//			case Tile::BEND:
	//				// B victory condition completed

	//				break;
	//			case Tile::OBSTACLE:
	//				// Playable tile cannot move

	//				break;
	//			case Tile::LIMIT:
	//				// Reload the level

	//				break;
	//			default:
	//				break;
	//			}
	//			//^ TEMP =========================================================
	//		}
	//	}
	//}

}
