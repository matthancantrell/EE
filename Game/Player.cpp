#include "Player.h"
#include "Engine.h"
#include "Bullet.h"

void Player::Update()
{

	// Rotate Left/Right
	if (Engine::inputSystem_g.GetKeyState(Engine::key_left) == Engine::InputSystem::KeyState::Held)
	{
		transform_.rotation -= (3.0f * Engine::timer_g.deltaTime);
	}

	if (Engine::inputSystem_g.GetKeyState(Engine::key_right) == Engine::InputSystem::KeyState::Held)
	{
		transform_.rotation += (3.0f * Engine::timer_g.deltaTime);
	}

	// Move Forward
	float thrust = 0;
	if (Engine::inputSystem_g.GetKeyState(Engine::key_up) == Engine::InputSystem::KeyState::Held)
	{
		speed_ = maxSpeed_;
	}

	// Fire Bullet
	if (Engine::inputSystem_g.GetKeyState(Engine::key_space) == Engine::InputSystem::KeyState::Held)
	{
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(model_, transform_);
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

	// Thrust Code
	Engine::Vector2 direction{ 1,0 };
	direction = Engine::Vector2::Rotate(direction, transform_.rotation);

	Engine::Vector2 velocity = direction * (speed_ * Engine::timer_g.deltaTime);

	transform_.position += velocity;


}
