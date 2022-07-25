#include "Player.h"
#include "Engine.h"
#include "Bullet.h"
#include <iostream>

void Player::Update()
{

	// Rotate Left/Right
	if (Engine::inputSystem_g.onKeyLeft(Engine::InputSystem::KeyState::Held))
	{
		transform_.rotation -= (3.0f * Engine::timer_g.deltaTime);
	}

	if (Engine::inputSystem_g.onKeyRight(Engine::InputSystem::KeyState::Held))
	{
		transform_.rotation += (3.0f * Engine::timer_g.deltaTime);
	}

	// Move Forward
	float speed_ = 0;
	if (Engine::inputSystem_g.onKeyUp(Engine::InputSystem::KeyState::Held))
	{
		speed_ = maxSpeed_;
	}

	// Fire Bullet
	if (Engine::inputSystem_g.onKeySpace(Engine::InputSystem::KeyState::Held))
	{
		Engine::audioSystem_g.PlayAudio("laser");

		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(Engine::Model { "Bullet.txt" }, transform_);
		scene_->Add(std::move(bullet));
	}

	// Mouse
/*
	if (Engine::inputSystem_g.GetButtonState(Engine::button_left) == Engine::InputSystem::KeyState::Pressed)
	{
		std::cout << "Left Mouse Click!" << endl;
	}

	if (Engine::inputSystem_g.GetButtonState(Engine::button_right) == Engine::InputSystem::KeyState::Pressed)
	{
		std::cout << "Mouse Position: (" << Engine::inputSystem_g.GetMousePosition().x << ", " << inputSystem.GetMousePosition().y << ")" << endl;
	}

	// Face Target
	Engine::Vector2 target = Engine::inputSystem_g.GetMousePosition();
	target = target - transform_.position; // Direction Vector Towards
	transform_.rotation = target.GetAngle();
*/

	// Calculate Force
	Engine::Vector2 direction{ 1,0 };
	direction = Engine::Vector2::Rotate(direction, transform_.rotation);
	Engine::Vector2 force = direction * speed_ * Engine::timer_g.deltaTime;

	// Apply Force To Velocity
	velocity_ += force;

	// Apply Drag
	velocity_ *= 1.0f / (1.0f + damping_ * Engine::timer_g.deltaTime);
	transform_.position += velocity_ *Engine::timer_g.deltaTime;

	// Wrap
	if (transform_.position.x > Engine::renderer_g.GetWidth_()) transform_.position.x = 0;
	if (transform_.position.x < 0) transform_.position.x = (float)Engine::renderer_g.GetWidth_();

	if (transform_.position.y > Engine::renderer_g.GetHeight_()) transform_.position.y = 0;
	if (transform_.position.y < 0) transform_.position.y = (float)Engine::renderer_g.GetHeight_();

}
