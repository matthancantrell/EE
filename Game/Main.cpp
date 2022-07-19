#include "Renderer/Model.h"
#include "Player.h"
#include "Engine.h"
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
// DEPENDENCIES

int main()
{
	// Time


	Engine::SetFilePath("../Assets");

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

	Player player{ model, transform };

	//Memory Init
	Engine::InitializeMemory();

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
		player.Update();

		// Render
		Engine::renderer_g.BeginFrame();

		player.Draw(Engine::renderer_g);

		Engine::renderer_g.EndFrame();
	}

	Engine::renderer_g.ShutDown();
}
