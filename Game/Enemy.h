#pragma once
#include "Framework/Actor.h"

class Enemy : public Engine::Actor
{
public:
	Enemy() = default;
	Enemy(const Engine::Model& model, const Engine::Transform& transform, float health = 2) : Actor{ model, transform }, health_{ health }
	{
		Initialize();
	}

	void Initialize();
	void Update() override;

	void OnCollision(Actor* other) override;

private:
	float health_ = 2;
	float speed_ = 50;
	float fireTimer_ = 10;

};