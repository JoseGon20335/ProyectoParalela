// Particle.cpp
#include "Particle.h"

Particle::Particle(float vx, float vy, float x, float y, float r, float g, float b, float ch, float rad)
    : velocityX(vx), velocityY(vy), posX(x), posY(y), redColor(r), greenColor(g), blueColor(b), colorChange(ch), radius(rad) {}
