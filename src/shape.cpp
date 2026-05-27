
#include "../include/shape.h"


CircleShape::CircleShape(double x, double y, sf::Vector2<double> velocity, double radius) : Entity(x, y), v_(velocity)
{
	shape_.setRadius(static_cast<float>(radius));
	shape_.setPosition({ static_cast<float>(x), static_cast<float>(y) });
	shape_.setOrigin({ static_cast<float>(radius), static_cast<float>(radius) });
	shape_.setFillColor(sf::Color::White);
}

void CircleShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape_, states);
}

void CircleShape::update()
{
	v_ = borderCollision();
	this->set_position(this->x() + v_.x, this->y() + v_.y);
	shape_.setPosition({ static_cast<float>(this->x()), static_cast<float>(this->y()) });
}

void CircleShape::render(const double residual_frame, sf::RenderWindow& window)
{
	shape_.setPosition({ static_cast<float>(this->x() + v_.x * residual_frame), static_cast<float>(this->y() + v_.y * residual_frame) });
	window.draw(shape_);
}

sf::Vector2<double> CircleShape::borderCollision()
{
	double x = this->x();
	double y = this->y();

	if ((1600 - x) <= shape_.getRadius() || x <= shape_.getRadius())
	{
		return { -v_.x, v_.y };
	}

	if ((900 - y) <= shape_.getRadius() || y <= shape_.getRadius())
	{
		return { v_.x, -v_.y };
	}

	return { v_.x, v_.y };
}

