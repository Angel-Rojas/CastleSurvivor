#include "BulletAsteroidZombie.h"

Asteroid::Asteroid() {
    prev = NULL;
    next = NULL;
}

Game::~Game() {
    delete [] barr;
}

