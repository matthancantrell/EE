#include "Renderer/Model.h"
#include "Player.h"
#include "Engine.h"
#include <iostream>
#include <vector>

using namespace std;
// DEPENDENCIES

int main()
{
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

	Engine::Renderer renderer;

	// Initialize Our Major Systems
	renderer.Initialize();
	Engine::inputSystem_g.Initialize();

	// Create A Window And Set Background Color
	renderer.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	renderer.SetClearColor(Engine::Color{ 50, 50, 50, 255 });

	bool quit = false;
	while (!quit)
	{
		// Update
		Engine::inputSystem_g.Update();

		//Keys
		if (Engine::inputSystem_g.GetKeyState(Engine::key_esc) == Engine::InputSystem::KeyState::Pressed)
		{
			quit = true;
		}

		//Update Game Objects
		player.Update();

		// Render
		renderer.BeginFrame();

		player.Draw(renderer);

		renderer.EndFrame();
	}

	renderer.ShutDown();
}
