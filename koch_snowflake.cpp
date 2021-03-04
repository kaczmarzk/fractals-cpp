#include "koch_snowflake.h"

float calcSize(int n) {
    
    switch (n)
    {
      case 1: 
        return 0.3;
        break;
      case 2:
        return 0.1;
        break;
      case 3: 
        return 0.05;
        break;
      case 4:
        return 0.015;
        break;
      case 5:
        return 0.005;
        break;
    default:
        return 0.001;
        break;
    }

}

point2d init_point = {-0.5f, 0.5f};

int drawkoch(float direction, float size, int n){
    double dir_rad = 0.017453292222222 * direction;
    point2d new_point = {init_point[0] + size * cos(dir_rad), init_point[1] + size * sin(dir_rad)}; 
    if (n == 0) {
        glVertex2f(init_point[0], init_point[1]);
        glVertex2f(new_point[0], new_point[1]);
        init_point[0] = new_point[0];       
        init_point[1] = new_point[1];
    }
    else {
        n--;
        drawkoch(direction, size, n);
        direction += 60.0f;
        drawkoch(direction, size, n);
        direction -= 120.0f;
        drawkoch(direction, size, n);
        direction += 60.0f;
        drawkoch(direction, size, n);
    }
    return 0;

}

int buildKochSnowflake(int n)
{ 
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(500, 500, "Koch Snowflake", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // start drawing
        glBegin(GL_LINES);

        float flake_size = calcSize(n);
        drawkoch(0.0, flake_size, n);
        drawkoch(-120.0, flake_size, n);
        drawkoch(120.0, flake_size, n);

        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}