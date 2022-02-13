# CppProject

Small project created in an Actor-Component SDL-engine made in class, in order to better understand how it works

Branch Additions
=

Design patterns exploration:
- Flyweight:
	- Its own project + implementation test regarding the tiles
		- Didn't worked because of the way the Tiles were created (as new) and then changed
		- Tried to work with simpler classes (LevelFW & Tree) but ran into an issue regarding the "delete_scalar.cpp" when trying to close the game
		- We can also only see 3 different trees, but not their copies
- Spatial Partition:
	- Didn't really work on it while knowing it was a design pattern, this was just a common way to implement tiles in a grid [here in the Level class]

Controls
=

You can move using the ZQSD keys

Files to look at
=

Modifications made in:
  - Game.cpp (in "Game specifics" section)
  - Game.h
  - MoveComponent class
  - InputComponent class
  - Tile class
  - PlayableTile class
  - Level class


Current state
=

Launchable
Level creation fully operationnal 
Playable tiles read inputs

Movements don't work as expected

Collisions logic removed (created code errors)

Post mortem
=

- (+) understood the engine, and the principle behind the Actor-Component architecture
- (+) understood how I should approach programming classes 
     - quickly following the document while trying to understand as much things as possible in a short amount of time
     - finishing the project
     - reading the whole document again, taking as much time as needed to understand everything while having the "big picture" in mind, create new documents to assimilate the difficult stuff 
 
- (-) even if it was necessary, I lost almost one week going through the engine in details to understand it  
- (-) ran through multiple difficulties I had trouble to overcome (regarding symbols or things like "vector subscript out of range" for example)
      huge thanks to Ma6icm4n for his precious help
- (-) not quite satisfied with the delivery itself (seems small)
