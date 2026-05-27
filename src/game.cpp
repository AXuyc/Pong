#include "../include/game.h"

#include <iostream>

Game::Game(sf::RenderWindow* window)
{
	numEntities_ = 0;
	width_ratio = 1;
	height_ratio = 1;
	game_window = window;
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		entities_[i] = nullptr;
	}
}

void Game::addEntity(Entity* entity)
{
	if (numEntities_ < MAX_ENTITIES)
	{
		entities_[numEntities_] = entity;
		numEntities_++;
	} else
	{
		std::cout << "Max entities reached. Cannot add more.\n";
	}
}

void Game::removeEntities()
{
	int curr_Entities = numEntities_;
	for (int i = 0; i < numEntities_; ++i)
	{
		if (entities_[i]->remove_)
		{
			delete entities_[i];
			numEntities_--;
			entities_[i] = nullptr;
		}
	}

	int firstEmptyIndex = -1;

	for (int i = 0; i < curr_Entities; ++i)
	{
		if (entities_[i] == nullptr && firstEmptyIndex == -1)
		{
			firstEmptyIndex = i;
		}
		else if (entities_[i] != nullptr && firstEmptyIndex != -1)
		{
			entities_[firstEmptyIndex] = entities_[i];
			entities_[i] = nullptr;
			firstEmptyIndex++;
		}


	}
}

void Game::gameLoop()
{
	using clock = std::chrono::high_resolution_clock;
	std::chrono::nanoseconds lag(0ns);

	auto prev_time = clock::now();
	while (game_window->isOpen())
	{
		while (const std::optional event = game_window->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				game_window->close();

			if (const auto* resized = event->getIf<sf::Event::Resized>())
			{
				width_ratio = static_cast<float>(resized->size.x) / 1600;
				height_ratio = static_cast<float>(resized->size.y) / 900;
			}
		}
		auto delta_time = clock::now() - prev_time;
		prev_time = clock::now();

		lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

		while (lag >= MS_STEP)
		{
			lag -= MS_STEP;
			for (int i = 0; i < numEntities_; ++i)
			{
				entities_[i]->update();
			}

		}
		

		game_window->clear();
		
		
		for (int i = 0; i < numEntities_; ++i)
		{
			entities_[i]->render(std::chrono::duration<double>(lag / MS_STEP).count(), *game_window);
		}
		


		game_window->display();
	}
}