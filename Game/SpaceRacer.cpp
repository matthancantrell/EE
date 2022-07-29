#include "SpaceRacer.h"
#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "Engine.h"
#include <memory>
#include <iostream>

void SpaceRacer::Initialize()
{
	// Create Scene
	scene_ = std::make_unique<Engine::Scene>();

	// Create Assets For Scene

	Engine::audioSystem_g.AddAudio("laser", "laser.wav");
	Engine::audioSystem_g.AddAudio("music", "music.mp3");
	Engine::audioSystem_g.AddAudio("explosion", "explosion.mp3");
	Engine::audioSystem_g.PlayAudio("music");

	font_ = std::make_unique<Engine::Font>("Fonts/shovel-knight-extended.ttf", 24);
	titleText_ = std::make_unique<Engine::Text>(font_.get());
	titleText_->Create(Engine::renderer_g, "Space Racer", { 0, 255 ,255, 255 });
	scoreText_ = std::make_unique<Engine::Text>(font_.get());
	scoreText_->Create(Engine::renderer_g, "000000", { 255, 255, 255, 255 });

	// Create PLayer & Transform

	Engine::Transform transform;
	transform.position = { 400, 300 };
	transform.rotation = 0;
	transform.scale = 5;

	std::unique_ptr<Player> player = std::make_unique<Player>(Engine::Model{ "Player.txt" }, transform);
	scene_->Add(std::move(player));

	// Spawn First Set of Enemies

	for (size_t i = 0; i < 1; i++)
	{
		transform.position.x = Engine::RandomFloat(800);
		transform.position.y = Engine::RandomFloat(600);
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(Engine::Model{ "Enemy.txt" }, transform);
		scene_->Add(std::move(enemy));
	}
}

void SpaceRacer::Shutdown()
{
	
}

void SpaceRacer::Update()
{
	powerUpTimer_ -= Engine::timer_g.deltaTime;
	if (powerUpTimer_ <= 0)
	{
		powerUpTimer_ = Engine::RandomFloat(30);

		Engine::Transform transform;
		transform.position.x = Engine::RandomFloat(800);
		transform.position.y = Engine::RandomFloat(600);
		transform.rotation = Engine::RandomFloat(Math::TWO_PI);
		transform.scale = 3;

		std::unique_ptr<PowerUp> powerUp = std::make_unique<PowerUp>(Engine::Model{ "BiggerUpper.txt" }, transform);
		scene_->Add(std::move(powerUp));
		std::cout << "Spawned!";
	}

	PowerUp* power = scene_->GetActor<PowerUp>();
	if (power)
	{
		Player* player = scene_->GetActor<Player>();
		if (power->destroy_ == true)
		{
			AddPoints(500);
			player->transform_.scale += 2;
		}
	}

	// Spawn Enemies Continuously
	spawnTimer_ -= Engine::timer_g.deltaTime;
	if (spawnTimer_ <= 0)
	{
		spawnTimer_ = 5;

		Engine::Transform transform;
		transform.position.x = Engine::RandomFloat(800);
		transform.position.y = Engine::RandomFloat(600);
		transform.rotation = Engine::RandomFloat(Math::TWO_PI);
		transform.scale = 3;

		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(Engine::Model{ "Enemy.txt" }, transform);
		scene_->Add(std::move(enemy));
	}

	//Update Game Objects
	scene_->Update();

	// Update Score
	Enemy* enemy = scene_->GetActor<Enemy>();
	if (enemy)
	{
		if (enemy->destroy_ == true)
		{
			AddPoints(200);
		}
	}
	scoreText_->Create(Engine::renderer_g, std::to_string(score_), { 255, 255, 255, 255 });
}

void SpaceRacer::Draw(Engine::Renderer& renderer)
{
	// Render Game Objects

	scene_->Draw(Engine::renderer_g);
	titleText_->Draw(Engine::renderer_g, { 0, 0});
	scoreText_->Draw(Engine::renderer_g, { 600, 0 });
}
