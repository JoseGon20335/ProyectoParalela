#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle {
    float velocityX;
    float velocityY;
    float posX;
    float posY;
    float redColor;
    float greenColor;
    float blueColor;
    float colorChange;
    float radius;

    Particle(float vx, float vy, float x, float y, float r, float g, float b, float ch, float rad);
};

#endif // PARTICLE_H
