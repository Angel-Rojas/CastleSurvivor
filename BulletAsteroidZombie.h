#include "Common.h"
#include "defs.h"
//#include "timers.cpp"
#include <ctime>

class Ship {
public:
        Vec dir;
        Vec pos;
        Vec vel;
        float angle;
        float color[3];
public:
        Ship();
};


class Bullet {
public:
        Vec pos;
        Vec vel;
        float color[3];
        struct timespec time;
public:
        Bullet() { }
};

class Asteroid {
public:
        Vec pos;
        Vec vel;
        int nverts;
        Flt radius;
        Vec vert[8];
        float angle;
        float rotate;
        float color[3];
        // Fixed Warning: Asteroid was already declared
        // struct Asteroid *prev;
        Asteroid *prev;
        Asteroid *next;
public:
        Asteroid();
};

class Game {
public:
        Ship ship;
        Asteroid *ahead;
        Bullet *barr;
        int nasteroids;
        int nastdestroyed;
        int nbullets;
        struct timespec bulletTimer;
        struct timespec mouseThrustTimer;
        bool mouseThrustOn;
public:
        Game();
        ~Game();
};

