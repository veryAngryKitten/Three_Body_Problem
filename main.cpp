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

    void update(double dt);
    void applyForce(const Vec2& force);

};

int main() {
    GLFWwindow* window;

    //librariy init
    if (!glfwInit()) {
        return -1;
    }

    //window creation
    window = glfwCreateWindow(640, 480, "Hello Window", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    // make window context current
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}