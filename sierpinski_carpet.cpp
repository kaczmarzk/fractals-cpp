#include "sierpinski_carpet.h"

int drawSquare(point2d v0, float width, bool empty) {
    
    if (empty) {
     glColor3f(1.0f, 1.0f, 1.0f);   
    }
    else {
     glColor3f(0.0f, 0.0f, 0.0f);
    }
    
    // left top, right top, right bottom
    point2d v1 = {v0[0], v0[1] + width};
    point2d v2 = {v0[0] + width, v0[1] + width};
    point2d v3 = {v0[0] + width, v0[1]};
 
    // draw
    glBegin(GL_QUADS);
    glVertex2f(v0[0], v0[1]);
    glVertex2f(v1[0], v1[1]);
    glVertex2f(v2[0], v2[1]);
    glVertex2f(v3[0], v3[1]);
    glEnd();
    return 0;
}

// left top, left bottom, width
int drawCarpet(point2d v0, float width) {
    
    drawSquare(v0, width, false);
    
    // empty mid
    float new_a = width / 3;
    point2d empty_v0 = {v0[0] + new_a, v0[1] + new_a};
    drawSquare(empty_v0, new_a, true);

    return 0;
}

int drawSierpinskiCarpet(point2d v0, float width, int n){ 
    if (n <= 1) {
        drawCarpet(v0, width);
        }
        else {
            float new_a = width / 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    point2d new_v0 = {v0[0] + (new_a * i), v0[1] + (new_a * j)}; 
                    if (i != 1 || j != 1) {
                        drawSierpinskiCarpet(new_v0, new_a, n - 1);
                    }
                    else {
                        drawSquare(new_v0, new_a, true);
                    }
                }
            }
        }
    return 0;
}



int buildSierpinskiCarpet(int n)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Sierpinski Carpet", NULL, NULL);
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
        
        // background color  
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

        // draw
        point2d initial_v0 = {-0.5f, -0.5f};
        drawSierpinskiCarpet(initial_v0, 1.0f, n);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}