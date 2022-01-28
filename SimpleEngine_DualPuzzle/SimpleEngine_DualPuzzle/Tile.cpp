#include "Tile.h"
#include "Assets.h"

Tile::Tile() :
	Actor(),
	baseWidthHeight(32),
	type(Tile::TileType::BACKGROUND)
{
	vector<Texture*> tempTex{
		&Assets::getTexture("Background")
	};

	sprite = new SpriteComponent(this, Assets::getTexture(""));
	animSprite = new AnimSpriteComponent(this, tempTex);
	collision = new CircleCollisionComponent(this);
	collision->setRadius(baseWidthHeight / 2);
}

void Tile::setType(TileType typeP)
{
	type = typeP;
	updateTexture();
}

void Tile::setScale(float scaleP)
{
	scale = scaleP;
	collision->setRadius((baseWidthHeight / 2) * scale);
}

void Tile::updateTexture()
{
	vector<Texture*> textures;
	std::string text;

	// Get the [animated or not] textures depending of the type of tile
	switch (type)
	{
	case Tile::TileType::APLAYER:
		textures = {
			&Assets::getTexture("APlayer1"),
			&Assets::getTexture("APlayer2"),
			&Assets::getTexture("APlayer3"),
		};
		break;
	case Tile::TileType::BPLAYER:
		textures = {
			&Assets::getTexture("BPlayer1"),
			&Assets::getTexture("BPlayer2"),
			&Assets::getTexture("BPlayer3")
		};
		break;
	case Tile::TileType::AEND:
		textures = {
			&Assets::getTexture("AEnd1"),
			&Assets::getTexture("AEnd2"),
			&Assets::getTexture("AEnd3")
		};
		break;
	case Tile::TileType::BEND:
		textures = {
			&Assets::getTexture("BEnd1"),
			&Assets::getTexture("BEnd2"),
			&Assets::getTexture("BEnd3")
		};
		break;
	case Tile::TileType::OBSTACLE:
		textures = {
			&Assets::getTexture("Obstacle1"),
			&Assets::getTexture("Obstacle2"),
			&Assets::getTexture("Obstacle3")
		};
		break;
	case Tile::TileType::LIMIT:
		textures = {
			&Assets::getTexture("Limit1"),
			&Assets::getTexture("Limit2"),
			&Assets::getTexture("Limit3")
		};
		break;
	case Tile::TileType::BACKGROUND:
		text = "Background";
		break;
	default:
		break;
	}

	if (type != Tile::TileType::BACKGROUND) {
		animSprite->setAnimTextures(textures);
	}
	else {
		sprite->setTexture(Assets::getTexture(text));
	}
}
