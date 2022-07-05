// ".." goes back one dir, "../Engine/Math/MathUtils.h"
#include "Math/MathUtils.h"
#include "Renderer/Renderer.h"
#include "Core/Memory.h"
#include <iostream>
using namespace std;
// DEPENDENCIES 

int main()
{
   //printf("C: Hello world!\n");
   //cout << "C++: Hello World!\n";
   //cout << Math::sqr(9) << "\n";
   //cout << Math::half(6);

	Engine::InitializeMemory(); //Memory Init

	Engine::Renderer renderer; // Creates a Renderer Object
	renderer.Initialize(); // Initializes the window
	renderer.CreateWindow("Engine", 800, 600); // Creates the window with parameters

	getchar(); // Pause?

	renderer.ShutDown(); // 
}
