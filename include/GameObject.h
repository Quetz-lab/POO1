#pragma once
#include "raylib.h"
#include "string"
using namespace std;
class GameObject
{

public:
	Vector2 position;
	string name;

	Texture texture;
	bool displayName = false;

	GameObject( Vector2 pos, string _name, Texture tex  ):
		position(pos), name(_name), texture(tex) { }

	virtual void update();
	void draw();

};

