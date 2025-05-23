#pragma once
#include "raylib.h"
#include "string"
namespace AQ_QuetzLab
{
	using namespace std;
	class GameObject
	{

	public:
		Vector2 position;
		string name;

		Texture texture;
		bool displayName = false;

		GameObject() :
			position({0,0}),
			name("GameObject"),
			texture({0})
		{ }

		GameObject(Vector2 pos, string _name, Texture tex) :
			position(pos), name(_name), texture(tex) {
		}

		virtual void update();
		virtual void draw();

	};
}

