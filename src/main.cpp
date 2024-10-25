#include "config.h"

int main() 
{
	GLFWwindow* window;

	if (!glfwInit()) 
	{
		return -1;
	}
	
	window = glfwCreateWindow(640, 480, "window", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		cout << "Couldn't load opengl" << endl;
		glfwTerminate();
		return -1;
	}

	glClearColor(0, 0, 0, 1);

	while (!glfwWindowShouldClose(window)) 
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}                                                                                              