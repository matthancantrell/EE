#include "Player.h"
#include "Engine.h"

void Player::Update()
{

	// Rotate Left/Right
	if (Engine::inputSystem_g.GetKeyState(Engine::key_left) == Engine::InputSystem::KeyState::Held)
	{
		transform_.rotation -= 0.05f;
	}

	if (Engine::inputSystem_g.GetKeyState(Engine::key_right) == Engine::InputSystem::KeyState::Held)
	{
		transform_.rotation += 0.05f;
	}

	// Move Forward
	float thrust = 0;
	if (Engine::inputSystem_g.GetKeyState(Engine::key_up) == Engine::InputSystem::KeyState::Held)
	{
		speed_ = maxSpeed_;
	}

	// Mouse

	//if (Engine::inputSystem_g.GetButtonState(Engine::button_left) == Engine::InputSystem::KeyState::Pressed)
	//{
	//	std::cout << "Left Mouse Click!" << endl;
	//}

	//if (Engine::inputSystem_g.GetButtonState(Engine::button_right) == Engine::InputSystem::KeyState::Pressed)
	//{
	//	std::cout << "Mouse Position: (" << Engine::inputSystem_g.GetMousePosition().x << ", " << inputSystem.GetMousePosition().y << ")" << endl;
	//}

	// Face Target
	Engine::Vector2 target = Engine::inputSystem_g.GetMousePosition();
	target = target - transform_.position; // Direction Vector Towards
	transform_.rotation = target.GetAngle();

	// Thrust Code
	Engine::Vector2 direction{ 1,0 };
	direction = Engine::Vector2::Rotate(direction, transform_.rotation);

	Engine::Vector2 velocity = direction * speed_;

	transform_.position += velocity;
}
