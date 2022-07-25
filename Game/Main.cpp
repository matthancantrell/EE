#include "Player.h"
#include "Enemy.h"
#include "Engine.h"

using namespace std;
// DEPENDENCIES

int main()
{
	//Memory Init
	Engine::InitializeMemory();

	// Set File Path to Pull Models
	Engine::SetFilePath("../Assets");
	
	Engine::Scene scene;

	// Create Actor
	// Transform
	Engine::Transform transform;
	transform.position = { 400, 300 };
	transform.rotation = 0;
	transform.scale = 5;

	std::unique_ptr<Player> player = std::make_unique<Player>(Engine::Model{ "Player.txt" }, transform);
	scene.Add(std::move(player));

	for (size_t i = 0; i < 5; i++)
	{
		transform.position.x = Engine::RandomFloat(800);
		transform.position.y = Engine::RandomFloat(600);
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(Engine::Model { "Enemy.txt" }, transform);
		scene.Add(std::move(enemy));
	}

	// Initialize Our Major Systems
	Engine::renderer_g.Initialize();
	Engine::inputSystem_g.Initialize();
	Engine::audioSystem_g.Initialize();

	Engine::audioSystem_g.AddAudio("laser", "jump.wav");

	// Create A Window And Set Background Color
	Engine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	Engine::renderer_g.SetClearColor(Engine::Color{ 50, 50, 50, 255 });

	bool quit = false;
	while (!quit)
	{
		//Engine::audioSystem_g.PlayAudio("laser");

		// Update
		Engine::inputSystem_g.Update();
		Engine::audioSystem_g.Update();
		Engine::timer_g.Tick();

		//Keys
		if (Engine::inputSystem_g.onKeyEsc(Engine::InputSystem::KeyState::Pressed))
		{
			quit = true;
		}

		//Update Game Objects
		scene.Update();

		// Render
		Engine::renderer_g.BeginFrame();

		scene.Draw(Engine::renderer_g);

		Engine::renderer_g.EndFrame();
	}
	Engine::audioSystem_g.ShutDown();
	Engine::renderer_g.ShutDown();
}
