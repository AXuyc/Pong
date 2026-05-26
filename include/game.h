#pragma once
#include "entity.h"
#include "shape.h"
#include <SFML/Graphics.hpp>
#include <chrono>

using namespace std::chrono_literals;
constexpr std::chrono::nanoseconds MS_STEP = 16ms;

class Game
{
public:
	Game(sf::RenderWindow* window);
	void gameLoop();
	void addEntity(Entity* entity);
	void removeEntities();

private:
	static constexpr int MAX_ENTITIES = 100;
	Entity* entities_[MAX_ENTITIES];
	sf::RenderWindow* game_window;
	int numEntities_;
	float width_ratio;
	float height_ratio;
};
