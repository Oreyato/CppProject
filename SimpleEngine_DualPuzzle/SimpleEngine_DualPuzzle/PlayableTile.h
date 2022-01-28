#pragma once
#include "Tile.h"

#include "InputComponent.h"
#include "MoveComponent.h"

class PlayableTile :
    public Tile
{
public:
    PlayableTile();
    void updateActor(float dt) override;

private:
    InputComponent* input;
    MoveComponent* move;
};

