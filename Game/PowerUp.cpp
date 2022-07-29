#include "PowerUp.h"
#include "Player.h"
#include "Bullet.h"
#include "Engine.h"

void PowerUp::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other) && other->GetTag() == "Player")
	{
		destroy_ = true;
	}
}
