#pragma once
#include "GameObject.h"
#include "Player.h"
#include "raymath.h"
namespace AQ_QuetzLab {
    class Sidekick :
        public GameObject
    {

    public:
        float speed = 100;
        GameObject* owner;

        Sidekick(Vector2 pos, string _name, Texture tex) :
            GameObject(pos, _name, tex) {
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
    };
}

