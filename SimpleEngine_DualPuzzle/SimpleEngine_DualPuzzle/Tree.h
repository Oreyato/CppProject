#pragma once
#include "SpriteComponent.h"

class Tree {
public:
    enum TreeType {
        TREE_A,
        TREE_B,
        TREE_C
    };

    Tree(SpriteComponent* spriteP) : 
        sprite(spriteP),
        baseWidthHeight(32)
    {}

    const SpriteComponent* getSpriteComponent() const { return sprite; }

private:
    // TreeType type;
    SpriteComponent* sprite;
    int baseWidthHeight;

    // not the scale because we used to change it in the Level creation
    // and things inside the flyweight are supposed to be immutable
};