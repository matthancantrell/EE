#pragma once
#include "Framework/Actor.h"

class Player : public Engine::Actor
{
public:

	Player() = default;
	Player(const Engine::Model& model, const Engine::Transform& transform) : Actor(model, transform) {}

	void Update() override;
	void OnCollision(Actor* other) override;

	float GetHealth() { return health_; }

private:
	
	float health_{ 10 };

	float speed_{ 0 };
	float maxSpeed_{ 500 };
};
