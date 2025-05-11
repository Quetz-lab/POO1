/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/
#include <iostream>
#include <string>
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "GameObject.h"
#include "Player.h"
#include "Sidekick.h"	
#include <vector>

using namespace std;


int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	cout << "Inicializando sistema de juego" << endl;

	// Create the window and OpenGL context
	InitWindow(1280, 800, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	vector<GameObject*> gameObjects;

	GameObject* myObj = new GameObject({ 0,0 }, "myObj", LoadTexture("wabbit_alpha.png"));
	myObj->displayName = true;
	
	gameObjects.push_back(myObj);

	Player* playerCharacter = new Player({ 0,0 }, "Player", LoadTexture("wabbit_alpha.png"));
	playerCharacter->speed = 200.0f;
	gameObjects.push_back(static_cast<GameObject*>(playerCharacter));

	Sidekick* sideKick = new Sidekick({ 500,0 }, "Jorge", LoadTexture("LuigiMalo.png"));
	sideKick->owner = playerCharacter;
	sideKick->name = true;
	sideKick->speed = 199.9f;
	gameObjects.push_back(sideKick);

	Sidekick* sideKick2 = new Sidekick({ 800,600 }, "Antonio", LoadTexture("LuigiMalo.png"));
	sideKick2->speed = 199.0f;
	sideKick2->owner = playerCharacter;
	sideKick2->name = true;
	gameObjects.push_back(sideKick2);

	for (GameObject* obj : gameObjects)
	{
		Player* p = dynamic_cast<Player*>(obj);
		if (p)
		{
			p->attack();
		}
	}
	// Load a texture from the resources directory
	//Texture wabbit = LoadTexture("wabbit_alpha.png");
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{

		for (GameObject* obj : gameObjects)
		{
			obj->update();
		}
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(SKYBLUE);

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);


		for (GameObject* obj : gameObjects)
		{
			obj->draw();
		}
		/*DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() / 2, 50, 30, RED);
		DrawCircle(GetScreenWidth() * 0.25f, GetScreenHeight() * 0.25f, 50, BLUE);*/

		// draw our texture to the screen
		for (size_t i = 0; i < 20; i++)
		{
			/*DrawTexture(wabbit, 20+(i), 200, WHITE);*/
		}
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	//UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
