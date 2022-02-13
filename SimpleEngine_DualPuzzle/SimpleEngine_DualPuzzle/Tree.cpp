#include "Tree.h"

Tree::Tree() :
    baseWidthHeight(32)
{
    vector<Texture*> tempTex{
    &Assets::getTexture("Background")
    };

    sprite = new SpriteComponent(this, Assets::getTexture(""));
}

Tree::Tree(std::string textureP) :
    texture(textureP),
    baseWidthHeight(32)
{
    sprite = new SpriteComponent(this, Assets::getTexture(textureP));
}
