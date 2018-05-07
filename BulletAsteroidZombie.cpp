#include "BulletAsteroidZombie.h"
//int castleHealth = 10000;
//int actualHealth = 10000;;

Asteroid::Asteroid() {
    prev = NULL;
    next = NULL;
}

Game::~Game() {
    delete [] barr;
}

