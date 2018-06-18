#pragma once
#include "GridSprite.h"
#include "Grid.h"

// Boulder class
// A GridSprite which can fall and crush the player
class Boulder : public GridSprite
{
public:


	// Constructor
	Boulder(sf::Texture& _texture, GridObject::Type _type = GridObject::BOULDER);

	// Game Object Function
	void update(const float& _dtAsSeconds) override;



protected:
	float counter = 0;

};