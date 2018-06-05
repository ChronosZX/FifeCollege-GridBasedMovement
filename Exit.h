#pragma once
#include "Grid.h"
#include "GridSprite.h"
#include "Player.h"

class Exit : public GridSprite
{
public:


	// Constructor
	Exit(sf::Texture& _texture, GridObject::Type _type = GridObject::EXIT);

	// Game Object Function
	//void update(const float& _dtAsSeconds) override;
};
