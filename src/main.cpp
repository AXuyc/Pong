#include <optional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/game.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 1600, 900 } ), "Pong_Engine", sf::Style::Default );
	
	Game game(&window);

	CircleShape circle(100, 100, { 0.1, 0.1 }, 20);
	game.addEntity(&circle);

	game.gameLoop();
}
