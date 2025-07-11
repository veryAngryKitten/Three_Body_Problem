#include <iostream>
#include <vector>
#include <cmath>
#include <GLFW/glfw3.h>
using namespace std;

struct Vec2 {
    double x, y;
};

class body {
    public:
    double mass;
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;

    body(double mass, Vec2 position, Vec2 velocity, Vec2 acceleration) {
        this->mass = mass;
        this->position = position;
        this->velocity = velocity;
        this->acceleration = acceleration;
    }

    void update(double dt) {
        velocity.x += acceleration.x * dt;
        velocity.y += acceleration.y * dt;
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
    }
    void applyForce(const Vec2& force) {
        acceleration.x = force.x / mass;
        acceleration.y = force.y / mass;
    }
    
};

// draw 
void drawCircle(float cx, float cy, float r, int num_segments) {

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // center
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
    
}

int main() {
    GLFWwindow* window;

    //librariy init
    if (!glfwInit()) {
        return -1;
    }

    //window creation
    window = glfwCreateWindow(800, 600, "Body", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    // make window context current
    glfwMakeContextCurrent(window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // body init
    body earth(
        5.972e24,
        {0.0, 0.0}, // Center
        {0.0, 0.0},
        {0.0, 0.0}

    );

    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);
        drawCircle(400.0f, 300.0f, 10.0f, 100);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}