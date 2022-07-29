#pragma once
#include "Framework/Actor.h"

class Bullet : public Engine::Actor
{
public:
	Bullet() = default;
	Bullet(const Engine::Model& model, const Engine::Transform& transform, float damage = 1.0f) :
		Actor{ model, transform }, damage_ { damage } {}

	void Update() override;
	void OnCollision(Actor* other) override;

	float GetDamage() { return damage_; }

	float speed_ = 200;

private:
	std::string bulletType_;
	float damage_ = 1.0f;
	
	float lifespan_ = 5;
};