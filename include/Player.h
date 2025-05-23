#pragma once
#include "GameObject.h"
#include "IAttacker.h"
#include "Weapon.h"
#include "Sidekick.h"
#include <iostream>
namespace AQ_QuetzLab
{
    using namespace AQ_QuetzLab;
    enum EAnimDirection
    {
        ANIM_DOWN,
        ANIM_UP,
        ANIM_LEFT,
        ANIM_RIGHT
    };

    struct SAnimData
    {
        int currFrame;
        int maxFrame;
        int frameSpeed = 10;
        int frameCount;
        float spriteWidth;
        float spriteHeight;
        EAnimDirection dir;
    };

    using namespace std;

    class Player :
        public GameObject, public IAttacker
    {
    public:
        float speed = 10.0f;
        Player(Vector2 pos, string _name, Texture tex) :
            weapon(nullptr)
        {
            texture = LoadTexture("PlayerF.png");
            animData = { 0,4,66,100 };
            animData.maxFrame = 4;
            animData.frameSpeed = 30;

            name = _name;
            position = pos;

        };

        void update() override;

        void draw() override;

        void attack()
        {
            cout << name << "Atacando" << endl;
        }

        void flee()
        {
            cout << name << "Huye como cobarde" << endl;
        }
        void Fire()
        {
            IAttacker* SetWeapon(IAttacker * newWeapon);
        }
        void SetSidekick(Sidekick* newSidekick, int index);
    private:
        //El Arma
        IAttacker* weapon;

        Sidekick sideKicks[3];
        SAnimData animData;
    };
}
