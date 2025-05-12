#include "Player.h"
#include "IAttacker.h"

namespace AQ_QuetzLab
{

	using namespace std;

	void Fire() override
	{
		cout << "fuego!" << endl;
	}

	void Player::update()
	{
		if (IsKeyDown(KEY_A))
		{
			position.x -= speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_W))
		{
			position.y -= speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_D))
		{
			position.x += speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_S))
		{
			position.y += speed * GetFrameTime();
		}
	}
}