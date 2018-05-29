#include "stdafx.h"
#include "Boulder.h"
#include "Grid.h"
#include "GridSprite.h"

// Constructor
Boulder::Boulder(sf::Texture& _texture, GridObject::Type _type /* = GridObject::BOULDER*/)
	: GridSprite(_texture, _type)
{

}

void Boulder::update(const float& _dtAsSeconds)
{

}