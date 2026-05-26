#pragma once

#include "entity.h"

class CircleShape : public Entity
{
public:
	CircleShape(double x, double y, sf::Vector2<double> velocity, double radius);
	void update(double delta_time) override;
	void render(const double lag, const double MS_STEP, sf::RenderWindow& window) override;

	sf::Vector2<double> borderCollision();
private:
	sf::Vector2<double> v_;
	sf::CircleShape shape_;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};