#include "Player.h"
#include "IAttacker.h"

namespace AQ_QuetzLab
{
	using namespace AQ_QuetzLab;
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
			animData.dir = ANIM_LEFT;
		}

		if (IsKeyDown(KEY_W))
		{
			position.y -= speed * GetFrameTime();
			animData.dir = ANIM_UP;
		}

		if (IsKeyDown(KEY_D))
		{
			position.x += speed * GetFrameTime();
			animData.dir = ANIM_RIGHT;
		}

		if (IsKeyDown(KEY_S))
		{
			position.y += speed * GetFrameTime();
			animData.dir = ANIM_DOWN;
		}
		animData.frameCount++;
		if (animData.frameCount >= animData.maxFrame)
			animData.currFrame = 0;
		
	}
	void Player::draw()
	{
		Rectangle r = { 0,0, animData.spriteWidth, animData.spriteHeight };
		DrawTextureRec(texture, r, position, WHITE);
	}
	void Player::SetSidekick(Sidekick* newSidekick, int index)
	{
		if (index >= 0 && index < 3)
		{
			sideKicks[index] = newSidekick;
		}
		else
		{
			cout << "Indice de sidekick invalido" << endl;
		}
	}
	void Player::Fire()
	{

	}
	IAttacker* Player::SetWeapon(IAttacker* newWeapon)
	{
		if (newWeapon)
		{
			weapon = newWeapon;
			Weapon w = dynamic_cast <Weapon*>(weapon);
			if (w)
			{
				cout << "cambiando arma a " << w->name << endl;


				for (int i = 0; i < 3;i++)
				{
					if (sideKicks[i])
					{

					}
				}

				return weapon;
			}
			return nullptr;
		}
	}
}