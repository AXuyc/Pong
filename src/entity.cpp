
#include "../include/entity.h"

Entity::Entity(double x, double y): x_(x), y_(y), remove_(false){}

Entity::~Entity()
{
	std::cout << "Entity destroyed" << std::endl;
}

double Entity::x() const { return x_; }
double Entity::y() const { return y_; }

void Entity::set_position(double x, double y)
{
	x_ = x;
	y_ = y;
}
