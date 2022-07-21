#include "Enemy.h"
#include "Engine.h"
#include "Bullet.h"
#include "Player.h"

void Enemy::Initialize()
{
	fireTimer_ = Engine::RandomFloat(2, 6);
	speed_ = Engine::RandomFloat(20, 100);
}

void Enemy::Update()
{

	// Fire Weapon

	fireTimer_ -= Engine::timer_g.deltaTime;
	if (fireTimer_ <= 0)
	{
		fireTimer_ = Engine::RandomFloat(2, 6);
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(Engine::Model{ "Bullet.txt" }, transform_);
		scene_->Add(std::move(bullet));
	}

	// Set Rotation Towards Player
	Player* player = scene_->GetActor<Player>();
	if (player)
	{
		Engine::Vector2 direction = player->transform_.position - transform_.position;
		transform_.rotation = direction.GetAngle();
	}

	// Calculate Velocity

	Engine::Vector2 direction{ 1,0 };
	direction = Engine::Vector2::Rotate(direction, transform_.rotation);

	Engine::Vector2 velocity = direction * (speed_ * Engine::timer_g.deltaTime);

	transform_.position += velocity;

	// Screen Wrapping
	if (transform_.position.x > Engine::renderer_g.GetWidth_()) transform_.position.x = 0;
	if (transform_.position.x < 0) transform_.position.x = (float)Engine::renderer_g.GetWidth_();

	if (transform_.position.y > Engine::renderer_g.GetHeight_()) transform_.position.y = 0;
	if (transform_.position.y < 0) transform_.position.y = (float)Engine::renderer_g.GetHeight_();
}
