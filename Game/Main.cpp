#include "Player.h"
#include "Enemy.h"
#include "Engine.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

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


	std::unique_ptr<Player> player = std::make_unique<Player>(Engine::Model{ "Player.txt" }, transform);
	scene.Add(std::move(player));

	for (size_t i = 0; i < 5; i++)
	{
		transform.position.x = Engine::RandomFloat(800);
		transform.position.y = Engine::RandomFloat(600);
		std::unique_ptr<Enemy> player = std::make_unique<Enemy>(Engine::Model { "Enemy.txt" }, transform);
		scene.Add(std::move(player));

	}

	// Player player{ model, transform };


	// Initialize Our Major Systems
	Engine::renderer_g.Initialize();
	Engine::inputSystem_g.Initialize();

	// Create A Window And Set Background Color
	Engine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	Engine::renderer_g.SetClearColor(Engine::Color{ 50, 50, 50, 255 });

	std::string word = "{ Color.r, Color.b, Color.g }";
	cout << word << endl;

	std::string sub;
	sub = word.substr(word.find("{") + 1, word.find(",") - (word.find("{") + 1));

	cout << "Substring:" << sub << endl;

	word = word.substr(word.find(",") + 1);
	cout << word << endl;

	word = word.substr(word.find(",") + 1);
	cout << word << endl;

	bool quit = false;
	while (!quit)
	{
		// Update
		Engine::inputSystem_g.Update();
		Engine::timer_g.Tick();

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
