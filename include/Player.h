#pragma once
#include "GameObject.h"
#include "IAttacker.h"
#include "Weapon.h"
#include "Sidekick.h"
#include <iostream>
namespace AQ_QuetzLab
{

    using namespace std;

    class Player :
        public GameObject, public IAttacker
    {
    public:
        float speed = 10.0f;
        Player(Vector2 pos, string _name, Texture tex) :
            GameObject(pos, _name, tex)
        {
        
        }

        void update() override;

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
    };
}
