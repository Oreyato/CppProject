#include "MoveComponent.h"
#include "Maths.h"
#include "Actor.h"
#include "Window.h"

MoveComponent::MoveComponent(Actor* ownerP, int updateOrderP) :
	Component(ownerP, updateOrderP),
	moveX(0.0f),
	moveY(0.0f)
{
}

void MoveComponent::setMoveX(float moveXP)
{
	moveX = moveXP;
}

void MoveComponent::setMoveY(float moveYP)
{
	moveY = moveYP;
}

void MoveComponent::update(float dt)
{
	if (!(Maths::nearZero(moveX) && Maths::nearZero(moveY))) {
		Vector2 moveVector = { moveX * owner.getScale(), moveY * owner.getScale() };
		Vector2 newPosition = owner.getPosition() + moveVector;

		owner.setPosition(newPosition);
	}
}
