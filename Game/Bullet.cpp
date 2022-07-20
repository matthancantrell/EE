#include "Bullet.h"
#include "Engine.h"

void Bullet::Update()
{
	// Calculate Velocity

	Engine::Vector2 direction{ 1,0 };
	direction = Engine::Vector2::Rotate(direction, transform_.rotation);

	Engine::Vector2 velocity = direction * (speed_ * Engine::timer_g.deltaTime);

	transform_.position += velocity;

}
