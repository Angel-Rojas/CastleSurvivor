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
        Asteroid() {
                prev = NULL;
                next = NULL;
        }
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
        Game() {
                ahead = NULL;
                barr = new Bullet[MAX_BULLETS];
                nasteroids = ZERO;
                nbullets = ZERO;
                nastdestroyed = ZERO;
                mouseThrustOn = false;
                //build 15 asteroids...
                for (int j=0; j<15; j++) {
                        Asteroid *a = new Asteroid;
                        a->nverts = 4;
                        //a->radius = 80.0 + 40.0;
                        //Flt r2 = a->radius / 2.0;
                        //Flt angle = 90.0f;
                        //Flt inc = (PI * 2.0) / (Flt)a->nverts;
                       /*for (int i=0; i<a->nverts; i++) {
                                a->vert[i][0] = sin(angle) * (r2 + rnd() * a->radius);
                                a->vert[i][1] = cos(angle) * (r2 + rnd() * a->radius);
                                angle += inc;
                        }*/
                        //zombies are 30 wide x 70 high
                        a->vert[0][0] = 0;
                        a->vert[0][1] = 0;
                        a->vert[1][0] = 30;
                        a->vert[1][1] = 0;
                        a->vert[2][0] = 30;
                        a->vert[2][1] = 70;
                        a->vert[3][0] = 0;
                        a->vert[3][1] = 70;
                        //initializing zombie postion-----------------------
                        initZombiePosition(gl.xres,zombie_pos);
                        a->pos[ZERO] = zombie_pos;
                        a->pos[1] = (Flt)(rand() % gl.yres - 145);
                        a->pos[2] = 0.0f;
                        a->angle = 0.0;
                        a->rotate = rnd() * 4.0 - 2.0;
                        a->color[ZERO] = rnd() + 0.4;
                        a->color[1] = rnd() + 0.3;
                        a->color[2] = rnd() + 0.2;
                        a->vel[0] = -1;//(Flt)(rnd()*2.0-1.0);
                        a->vel[1] = (Flt)(rnd()*2.0-1.0);
                        //std::cout << "asteroid" << std::endl;
                        //add to front of linked list
                        a->next = ahead;
                        if (ahead != NULL)
                                ahead->prev = a;
                        ahead = a;
                        ++nasteroids;
                }
                clock_gettime(CLOCK_REALTIME, &bulletTimer);
        }
        ~Game() {
                delete [] barr;
        }
} g;

