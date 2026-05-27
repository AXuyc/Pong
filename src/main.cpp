#include <optional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/game.h"

int main()
{
	//The velocity is the amount of pixels traversed per frame given 60 updates per seconds
	sf::RenderWindow window( sf::VideoMode( { 1600, 900 } ), "Pong_Engine", sf::Style::Default );
	
	Game game(&window);

	CircleShape circle1(100, 100, { 1, 0 }, 20);
	CircleShape circle2(300, 200, { -5, 3 }, 10);
	game.addEntity(&circle1);
	game.addEntity(&circle2);

	game.gameLoop();
}
