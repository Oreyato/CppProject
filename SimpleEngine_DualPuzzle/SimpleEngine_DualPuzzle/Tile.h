#pragma once
#include "Actor.h"
#include "AnimSpriteComponent.h"
#include "CircleCollisionComponent.h"
#include <vector>

class Tile :
    public Actor
{
public:
    // We need a friend class here for Level so that Level.h and Tile.h don't include each other
    friend class Level;

    enum TileType {
        APLAYER,
        BPLAYER,
        AEND,
        BEND,
        OBSTACLE,
        LIMIT,
        BACKGROUND
    };

    Tile();

    Tile::TileType getType() { return type; }
    int getWidthHeight() { return baseWidthHeight; }
    CircleCollisionComponent& getCollision() { return *collision; }

    void setType(TileType typeP);
    void setScale(float scaleP);

protected: 
    void updateTexture();
    SpriteComponent* sprite;
    AnimSpriteComponent* animSprite;
    CircleCollisionComponent* collision;

    TileType type;
    int baseWidthHeight;
    float scale;
};

