#include "stdafx.h"
#include "Diamond.h"
#include "Boulder.h"
#include "Grid.h"
#include "GridSprite.h"


// Constructor
Diamond::Diamond(sf::Texture& _texture)
	: Boulder(_texture, GridObject::DIAMOND)
{

}

