#include "Bullet.h"
#include "Engine.h"

void Bullet::Update()
{
	// Lifespan
	lifespan_ -= Engine::timer_g.deltaTime;
	if (lifespan_ <= 0) destroy_ = true;

	// Calculate Velocity
	Engine::Vector2 direction{ 1,0 };
	direction = Engine::Vector2::Rotate(direction, transform_.rotation);

	velocity_ = direction * (speed_ * Engine::timer_g.deltaTime);
	transform_.position += velocity_;

	// Wrap
	if (transform_.position.x > Engine::renderer_g.GetWidth_()) transform_.position.x = 0;
	if (transform_.position.x < 0) transform_.position.x = (float)Engine::renderer_g.GetWidth_();

	if (transform_.position.y > Engine::renderer_g.GetHeight_()) transform_.position.y = 0;
	if (transform_.position.y < 0) transform_.position.y = (float)Engine::renderer_g.GetHeight_();
}
