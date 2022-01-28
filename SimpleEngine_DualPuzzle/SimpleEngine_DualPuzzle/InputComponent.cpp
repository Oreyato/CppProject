#include "InputComponent.h"
#include <SDL_scancode.h>

InputComponent::InputComponent(Actor* ownerP) :
	MoveComponent(ownerP),
	forwardKey(SDL_SCANCODE_W),
	backKey(SDL_SCANCODE_S),
	rightKey(SDL_SCANCODE_D),
	leftKey(SDL_SCANCODE_A),
	moveX(0.0f),
	moveY(0.0f),
	isKeyLocked(false)
{
}

void InputComponent::processInput(const Uint8* keyState)
{
	moveX = .0f;
	moveY = .0f;
	float increment = 32.0f;

	if (keyState[forwardKey] && !isKeyLocked) {
		moveY = -increment;
	}
	if (keyState[backKey] && !isKeyLocked) {
		moveY = increment;
	}
	if (keyState[rightKey] && !isKeyLocked) {
		moveX = increment;
	}
	if (keyState[leftKey] && !isKeyLocked) {
		moveX = -increment;
	}
	
	setMoveX(moveX);
	setMoveY(moveY);

}

void InputComponent::setForwardKey(int key)
{
	forwardKey = key;
}

void InputComponent::setBackKey(int key)
{
	backKey = key;
}

void InputComponent::setRightKey(int key)
{
	rightKey = key;
}

void InputComponent::setLeftKey(int key)
{
	leftKey = key;
}
