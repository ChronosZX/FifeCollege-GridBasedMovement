#include "stdafx.h"
#include "Engine.h"
#include "GridSprite.h"
#include "Player.h"
#include "Diamond.h"
#include "Boulder.h"
#include "GridObject.h"

using namespace sf;

Engine::Engine()
	: m_Grid(9,10,64.0f,64.0f) // Set your grid size here!
	,m_background(9, 10, 64.0f, 64.0f)
{
	// Get the game screen resolution
	// and creste an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"BoulderDash",
		Style::Titlebar);

	// Initialise the fullscreen view
	m_MainView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	// Set the grid position so grid is centered
	sf::Vector2f gridPosition(0,0);
	gridPosition.x = 0.5f*resolution.x -m_Grid.CELL_WIDTH  * 0.5f *(float)m_Grid.GRID_SIZE_X;
	gridPosition.y = 0.5f*resolution.y -m_Grid.CELL_HEIGHT * 0.5f *(float)m_Grid.GRID_SIZE_Y;
	m_Grid.SetPosition(gridPosition);

	// Set up the grid contents
	// NOTE: This could be done based on a file
	// similar to how Thomas Was Late levels were loaded!
	
	// create player
	m_player = new Player(TextureHolder::GetTexture("graphics/player_down_01.png"));
	m_Grid.SetObject(0, 0, m_player);

	
	
	
	// create exit
	m_Grid.SetObject(8, 9, new GridSprite(TextureHolder::GetTexture("graphics/exit_locked.png"), GridObject::EXIT));

	// create diamonds
	m_Grid.SetObject(1, 4, new Diamond(TextureHolder::GetTexture("graphics/diamond.png")));
	m_Grid.SetObject(1, 6, new Diamond(TextureHolder::GetTexture("graphics/diamond.png")));
	m_Grid.SetObject(3, 2, new Diamond(TextureHolder::GetTexture("graphics/diamond.png")));

	// create boulders
	m_Grid.SetObject(1, 3, new Boulder(TextureHolder::GetTexture("graphics/boulder.png")));
	m_Grid.SetObject(7, 7, new Boulder(TextureHolder::GetTexture("graphics/boulder.png")));

	// Fill the rest of our grid with dirt
	for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
	{
		for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
		{
			if (m_Grid.GetOjbect(x, y) == nullptr)
				m_Grid.SetObject(x, y, new GridSprite(TextureHolder::GetTexture("graphics/dirt.png"), GridObject::DIRT));
		}
	}

	m_background.SetPosition(gridPosition);
	for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
	{
		for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
		{
			m_background.SetObject(x, y, new GridSprite(TextureHolder::GetTexture("graphics/background_dirt.png"), GridObject::DIRT));
		}
	}
}





void Engine::run()
{
	// Timing
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();

		// Make a float from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}

}