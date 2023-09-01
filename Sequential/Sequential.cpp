#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <vector>
#include <random>
#include <chrono>
#include "../Particle/Particle.h"

int WINDOW_WIDTH = 1920;
int WINDOW_HEIGHT = 1080;
float PARTICLE_RADIUS = 60.0f;
int numParticlesToGenerate = 0;

std::vector<Particle> particleCollection;

std::chrono::high_resolution_clock::time_point previousFrameTime;
int frameCount = 0;
float framesPerSecond = 0.0f;

void GenerateParticle() {
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_real_distribution<float> randomRadius(20.0f, PARTICLE_RADIUS);
    std::uniform_real_distribution<float> randomFloatX(-WINDOW_WIDTH / 2 + PARTICLE_RADIUS, WINDOW_WIDTH / 2 - PARTICLE_RADIUS);
    std::uniform_real_distribution<float> randomFloatY(-WINDOW_HEIGHT / 2 + PARTICLE_RADIUS, WINDOW_HEIGHT / 2 - PARTICLE_RADIUS);
    std::uniform_real_distribution<float> randomVelocity(-10.0f, 10.0f);
    std::uniform_real_distribution<float> randomColor(0.0f, 1.0f);

    particleCollection.reserve(numParticlesToGenerate); // Reserve space for particles

    for (int i = 0; i < numParticlesToGenerate; i++) {
        float radius = randomRadius(generator);
        float vx = randomVelocity(generator);
        float vy = randomVelocity(generator);
        float x = randomFloatX(generator);
        float y = randomFloatY(generator);
        float r = randomColor(generator);
        float g = randomColor(generator);
        float b = randomColor(generator);

        particleCollection.emplace_back(vx, vy, x, y, r, g, b, 0.0f, radius); // Use emplace_back to avoid extra copies
    }

    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = endTime - startTime;
    std::cout << "Particle generation time: " << totalTime.count() << " seconds\n";
}

void RenderParticles() {
    glClear(GL_COLOR_BUFFER_BIT);

    frameCount++;
    std::chrono::high_resolution_clock::time_point currentFrameTime = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentFrameTime - previousFrameTime).count() / 1000.0f;
    if (deltaTime >= 1.0f) {
        framesPerSecond = static_cast<float>(frameCount) / deltaTime;
        frameCount = 0;
        previousFrameTime = currentFrameTime;
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-WINDOW_WIDTH / 2 + 10, -WINDOW_HEIGHT / 2 + 10);
    std::string fpsText = "FPS: " + std::to_string(static_cast<int>(framesPerSecond));
    for (char c : fpsText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    for (size_t i = 0; i < numParticlesToGenerate; i++) {
        // Draw the outer circle
        glColor3f(particleCollection[i].redColor, particleCollection[i].greenColor, particleCollection[i].blueColor);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(particleCollection[i].posX, particleCollection[i].posY);
        const int numSegments = 64;
        for (int j = 0; j <= numSegments; j++) {
            float angle = j * 2.0f * M_PI / numSegments;
            float dx = particleCollection[i].radius * std::cos(angle);
            float dy = particleCollection[i].radius * std::sin(angle);
            glVertex2f(particleCollection[i].posX + dx, particleCollection[i].posY + dy);
        }
        glEnd();
    }

    glutSwapBuffers();
}

void UpdateParticles(int value) {
    std::chrono::high_resolution_clock::time_point currentFrameTime = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentFrameTime - previousFrameTime).count() / 1000.0f;

    for (size_t i = 0; i < numParticlesToGenerate; i++) {
        particleCollection[i].posX += particleCollection[i].velocityX;
        particleCollection[i].posY += particleCollection[i].velocityY;

        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_real_distribution<float> randomColor(0.0f, 1.0f);
        std::uniform_int_distribution<int> randomInt(5, 10);

        if (particleCollection[i].posX < -WINDOW_WIDTH / 2 + particleCollection[i].radius || particleCollection[i].posX > WINDOW_WIDTH / 2 - particleCollection[i].radius) {
            particleCollection[i].velocityX = -particleCollection[i].velocityX;
        }
        if (particleCollection[i].posY < -WINDOW_HEIGHT / 2 + particleCollection[i].radius || particleCollection[i].posY > WINDOW_HEIGHT / 2 - particleCollection[i].radius) {
            particleCollection[i].velocityY = -particleCollection[i].velocityY;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, UpdateParticles, 0);
}

int main(int argc, char** argv) {
    if (argc != 5) {
        std::cout << "Usage: " << argv[0] << " <num_particles> <window_width> <window_height> <particle_radius>\n";
        return 1;
    }
    previousFrameTime = std::chrono::high_resolution_clock::now();

    // Validate that argv[1] is a number between 1 and 100
    if (std::atoi(argv[1]) < 1 || std::atoi(argv[1]) > 10000) {
        std::cout << "Error: <num_particles> must be between 1 and 100\n";
        return 1;
    }

    // Validate that argv[2] is a number between 1 and 1920
    if (std::atoi(argv[2]) < 1 || std::atoi(argv[2]) > 1920) {
        std::cout << "Error: <window_width> must be between 1 and 1920\n";
        return 1;
    }

    // Validate that argv[3] is a number between 1 and 1080
    if (std::atoi(argv[3]) < 1 || std::atoi(argv[3]) > 1080) {
        std::cout << "Error: <window_height> must be between 1 and 1080\n";
        return 1;
    }

    // Validate that argv[4] is a number between 1 and 100
    if (std::atoi(argv[4]) < 1 || std::atoi(argv[4]) > 100) {
        std::cout << "Error: <particle_radius> must be between 1 and 100\n";
        return 1;
    }

    numParticlesToGenerate = std::atoi(argv[1]);
    WINDOW_WIDTH = std::atoi(argv[2]);
    WINDOW_HEIGHT = std::atoi(argv[3]);
    PARTICLE_RADIUS = std::atoi(argv[4]);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Sequential Project");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WINDOW_WIDTH / 2, WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GenerateParticle();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(RenderParticles);
    glutTimerFunc(0, UpdateParticles, 0);
    glutMainLoop();

    return 0;
}
