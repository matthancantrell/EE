#pragma once
#include "Framework/Game.h"

namespace Engine
{
	class Font;
	class Text;
}

class SpaceRacer : public Engine::Game
{
public:

	SpaceRacer() = default;
	~SpaceRacer() = default;

	// Inherited via Game
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(Engine::Renderer& renderer) override;

private:
	
	float spawnTimer_ = 0;
	float powerUpTimer_ = 0;
	std::unique_ptr<Engine::Font> font_;
	std::unique_ptr<Engine::Text> titleText_;
	std::unique_ptr<Engine::Text> scoreText_;
};