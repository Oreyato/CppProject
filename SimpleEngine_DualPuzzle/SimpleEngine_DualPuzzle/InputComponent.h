#pragma once
#include "MoveComponent.h"
#include <SDL_stdinc.h>

class InputComponent :
    public MoveComponent
{
public:
    InputComponent(Actor* ownerP);
    InputComponent() = delete;
    InputComponent(const InputComponent&) = delete;
    InputComponent& operator=(const InputComponent&) = delete;

    void processInput(const Uint8* keyState);

    void setForwardKey(int key);
    void setBackKey(int key);
    void setRightKey(int key);
    void setLeftKey(int key);

private:
    int forwardKey;
    int backKey;
    int rightKey;
    int leftKey;

    float moveX;
    float moveY;

    // Was added in an attempt to create a keyDown-like behaviour,
    // but I didn't manage to do it, nor in the .cpp nor in the Game.cpp
    bool isKeyLocked;
};

