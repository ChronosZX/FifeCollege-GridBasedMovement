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

	int targetX = m_gridX;
	int targetY = m_gridY + 1;

	GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);


	if (targetCellObject == nullptr)
	{
		counter += _dtAsSeconds;
		if (counter >= 0.5f)
		{
			// fall
			m_grid->MoveObject(m_gridX, m_gridY++, targetX, targetY, true);
			counter = 0;
		}
	}
	else if (targetCellObject->GetType() == GridObject::PLAYER)
	{
		counter += _dtAsSeconds;
		if (counter >= 0.5f)
		{
			// fall
			m_grid->MoveObject(m_gridX, m_gridY++, targetX, targetY, true);
			counter = 0;

		}

	}



	else if (targetCellObject->GetType() == GridObject::BOULDER || targetCellObject->GetType() == GridObject::DIAMOND)//checks right of below object if there is a diamond or boulder underneath
	{
		targetX = m_gridX + 1;
		targetY = m_gridY;
		GridObject* sideCellObjectRight = m_grid->GetOjbect(targetX, targetY);

		
		if (sideCellObjectRight == nullptr)
		{
			targetX = m_gridX + 1;
			targetY = m_gridY + 1;

			GridObject* diagonalCellRight = m_grid->GetOjbect(targetX, targetY);

			if (diagonalCellRight == nullptr || targetCellObject->GetType() == GridObject::PLAYER)
			{
				counter += _dtAsSeconds;
				if (counter >= 0.5f)
				{
					// fall
					m_grid->MoveObject(m_gridX, m_gridY++, targetX, targetY, true);
					counter = 0;

				}
			}
		}

		targetX = m_gridX - 1;
		targetY = m_gridY;

		GridObject* sideCellObjectLeft = m_grid->GetOjbect(targetX, targetY);

		//if the object to the left is clear but the right isn't
		if (sideCellObjectLeft == nullptr)
		{
			targetX = m_gridX - 1;
			targetY = m_gridY + 1;
			GridObject* diagonalCellLeft = m_grid->GetOjbect(targetX, targetY);

			if (diagonalCellLeft == nullptr || targetCellObject->GetType() == GridObject::PLAYER)
			{
				counter += _dtAsSeconds;
				if (counter >= 0.5f)
				{
					// fall
					m_grid->MoveObject(m_gridX, m_gridY++, targetX, targetY, true);
					counter = 0;

				}
			}
		}
	}


}