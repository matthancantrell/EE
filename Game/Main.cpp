#include "Renderer/Model.h"
#include "Player.h"
#include "Engine.h"
#include <iostream>
#include <vector>

using namespace std;
// DEPENDENCIES

int main()
{
	//Memory Init
	Engine::InitializeMemory();

	// Set File Path to Pull Models
	Engine::SetFilePath("../Assets");

	array<int, 3> anumbers = { 4, 5, 6 }; // on the stack {4,5,6}
	anumbers[0] = 5;

	vector<int> numbers = { 3, 5, 6 }; // new = on the heap

	Engine::Scene scene;

	// Create Actor
	// Transform
	Engine::Transform transform;
	transform.position = { 400, 300 };
	transform.rotation = 0;
	transform.scale = 5;

	// Model
	vector<Engine::Vector2> points
	{
		{ 7.00f, 0.00f },
		{ -3.00f, -5.00f },
		{ 0.00f, 0.00f },
		{ -3.00f, 5.00f },
		{ 7.00f, 0.00f }

	};
	//Engine::Model model(points, Engine::Color{ 255, 255, 255, 255 });

	Engine::Model model;
	model.Load("Model.txt");

	for (size_t i = 0; i < 20; i++)
	{
		transform.position.x = Engine::RandomFloat(800);
		transform.position.y = Engine::RandomFloat(600);
		std::unique_ptr<Player> player = std::make_unique<Player>(model, transform);
		scene.Add(std::move(player));

	}

	// Player player{ model, transform };


	// Initialize Our Major Systems
	Engine::renderer_g.Initialize();
	Engine::inputSystem_g.Initialize();

	// Create A Window And Set Background Color
	Engine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	Engine::renderer_g.SetClearColor(Engine::Color{ 50, 50, 50, 255 });

	bool quit = false;
	while (!quit)
	{
		// Update
		Engine::inputSystem_g.Update();
		Engine::timer_g.Tick();

		std::cout << Engine::timer_g.deltaTime << std::endl;

		//Keys
		if (Engine::inputSystem_g.GetKeyState(Engine::key_esc) == Engine::InputSystem::KeyState::Pressed)
		{
			quit = true;
		}

		//Update Game Objects
		scene.Update();

		// Render
		Engine::renderer_g.BeginFrame();

		scene.Draw(Engine::renderer_g);
		//player.Draw(Engine::renderer_g);

		Engine::renderer_g.EndFrame();
	}

	Engine::renderer_g.ShutDown();
}
