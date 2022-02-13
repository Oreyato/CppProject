#pragma once
#include "Actor.h"
#include "SpriteComponent.h"
#include "Assets.h"

class Tree :
    public Actor {
public:
    enum TreeType {
        TREE_A,
        TREE_B,
        TREE_C
    };

    Tree();
    Tree(std::string textureP);

    const SpriteComponent* getSpriteComponent() const { return sprite; }
    int getBaseWidthHeight() { return baseWidthHeight; }

private:
    // TreeType type;
    SpriteComponent* sprite;
    std::string texture;
    int baseWidthHeight;

    // not the scale because we used to change it in the Level creation
    // and things inside the flyweight are supposed to be immutable
};