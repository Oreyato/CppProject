#include "Game.h"
#include "AnimSpriteComponent.h"
#include "Timer.h"
#include "Log.h"
#include "Assets.h"
#include "BackgroundSpriteComponent.h"

#include "PlayableTile.h"

#include <iostream>

bool Game::initialize()
{
	bool isWindowInit = window.initialize();
	bool isRendererInit = renderer.initialize(window);

	int windowWidth = window.getWidth();
	int windowHeight = window.getHeight();

	Log::info("Game Initialized");

	return isWindowInit && isRendererInit; // Return bool && bool && bool ...to detect error
}

void Game::load()
{
	//v Load textures ================================================
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_Background.png", "Background");

	Assets::loadTexture(renderer, "..\\..\\Resources\\t_Obstacle1.png", "Obstacle1");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_Obstacle2.png", "Obstacle2");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_Obstacle3.png", "Obstacle3");

	Assets::loadTexture(renderer, "..\\..\\Resources\\t_Out1.png", "Limit1");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_Out2.png", "Limit2");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_Out3.png", "Limit3");

	Assets::loadTexture(renderer, "..\\..\\Resources\\t_EndB1.png", "BEnd1");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_EndB2.png", "BEnd2");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_EndB3.png", "BEnd3");

	Assets::loadTexture(renderer, "..\\..\\Resources\\t_EndA1.png", "AEnd1");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_EndA2.png", "AEnd2");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_EndA3.png", "AEnd3");

	Assets::loadTexture(renderer, "..\\..\\Resources\\t_PlayerA1.png", "APlayer1");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_PlayerA2.png", "APlayer2");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_PlayerA3.png", "APlayer3");

	Assets::loadTexture(renderer, "..\\..\\Resources\\t_PlayerB1.png", "BPlayer1");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_PlayerB2.png", "BPlayer2");
	Assets::loadTexture(renderer, "..\\..\\Resources\\t_PlayerB3.png", "BPlayer3");
	//^ Load textures ================================================
	//v Level creation ===============================================
	level = new Level(window.getWidth(), window.getHeight());
	level->createLevel(1);
	//^ Level creation ===============================================

	//v TESTS ========================================================



	//^ ==============================================================
}

void Game::loop()
{
	Timer timer;
	float dt = 0;
	while (isRunning)
	{
		float dt = timer.computeDeltaTime() / 1000.0f;
		processInput();
		update(dt);
		render();
		timer.delayTime();
	}
}

void Game::unload()
{
	// Delete actors
	// Because ~Actor calls RemoveActor, have to use a different type of loop
	while (!actors.empty()) {
		delete actors.back();
	}

	// Resources
	Assets::clear();
}

void Game::close()
{
	renderer.close();
	window.close();
	SDL_Quit();
}

// ===============================================================
// ===============================================================

void Game::processInput()
{
	// ==============================================================
	// I didn't manage to handle the SDL_KEYDOWN that works under the SDL_PollEvent,
	// and not under the keyboardState
	// 
	// As a consequence, the PlayableTiles are very difficult to move precisely because
	// they move accordingly to a keyboardPressed-like event, and not a keyDown
	// ==============================================================

	// SDL Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
	// Keyboard state
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	// Escape: quit game
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}
	//v Actor input ==================================================
	isUpdatingActors = true;

	for (auto actor : actors) {
		actor->processInput(keyboardState);
	}

	isUpdatingActors = false;
	//^ Actor input ==================================================
}

void Game::update(float dt)
{
	//v Actors =======================================================
	// Update actors 
	isUpdatingActors = true;

	for (auto actor : actors) {
		actor->update(dt);
	}

	isUpdatingActors = false;

	// Move pending actors to actors 
	for (auto pendingActor : pendingActors) {
		actors.emplace_back(pendingActor);
	}

	pendingActors.clear();

	// Delete dead actors
	vector<Actor*> deadActors;

	for (auto actor : actors) {
		if (actor->getState() == Actor::ActorState::Dead) {
			deadActors.emplace_back(actor);
		}
	}
	for (auto deadActor : deadActors) {
		delete deadActor;
	}

	//^ Actors =======================================================
}

void Game::render()
{
	renderer.beginDraw();
	renderer.draw();
	renderer.endDraw();
}

// ===============================================================
// ===============================================================

void Game::addActor(Actor* actor)
{
	if (isUpdatingActors) {
		pendingActors.emplace_back(actor);
	}
	else {
		actors.emplace_back(actor);
	}
}

void Game::removeActor(Actor* actor)
{
	// Erase actor from the two vectors
	auto iter = std::find(begin(pendingActors), end(pendingActors), actor);

	if (iter != end(pendingActors)) {
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, end(pendingActors) - 1);
		pendingActors.pop_back();
	}

	iter = std::find(begin(actors), end(actors), actor);

	if (iter != end(actors)) {
		std::iter_swap(iter, end(actors) - 1);
		actors.pop_back();
	}
}

// ==============================================================
// ==============================================================