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
	// TODO: only do this every x seconds
	
	{
		int targetX = m_gridX;
		int targetY = m_gridY + 1;

		GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);

		if (targetCellObject == nullptr)
		{
			// fall
			m_grid->MoveObject(m_gridX, m_gridY++, targetX, targetY, true);
		}
		else if (targetCellObject->GetType() == GridObject::PLAYER)
		{
			// CRUSH
		}
	}
}