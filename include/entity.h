#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	Entity(double x, double y);
	~Entity() override;
	bool remove_;

	double x() const;
	double y() const;
	void set_position(double x, double y);
	virtual void update() = 0;
	virtual void render(const double lag, sf::RenderWindow& window) = 0;

private:

	double x_;
	double y_;
	
};
