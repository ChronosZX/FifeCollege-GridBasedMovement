#pragma once

#include "GridSprite.h"
#include "Grid.h"

// Player class
// A GridSprite which can move around
class Player : public GridSprite
{
public:
	// Constructor
	Player(sf::Texture& _texture);

	// Game Object Functions
	bool input(const sf::Event& _event) override;
	
	int diamondsCollected;
};

