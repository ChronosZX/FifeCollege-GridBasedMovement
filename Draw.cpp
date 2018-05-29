#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::Black);

	// switch to main view
	m_Window.setView(m_MainView);

	//background
	m_background.draw(m_Window);

	// draw the grid
	m_Grid.draw(m_Window);

	// Show everything we have just drawn
	m_Window.display();
}