#pragma once
#include "Component.h"

class MoveComponent :
    public Component
{
public:
    MoveComponent(Actor* ownerP, int updateOrderP = 10); // By default, update before other components
    MoveComponent() = delete;
    MoveComponent(const MoveComponent&) = delete;
    MoveComponent& operator=(const MoveComponent&) = delete;

    float getMoveX() const { return moveX; } 
    float getMoveY() const { return moveY; } 

    void setMoveX(float moveXP);
    void setMoveY(float moveYP);

    void update(float dt) override;

private:
    float moveX;
    float moveY;
};

