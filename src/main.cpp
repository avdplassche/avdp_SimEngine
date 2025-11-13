#include "pch.h"
#include "argument_handler.h"


int exitProgramm(const char *error_message, int return_value) {
	glfwTerminate();
	std::cerr << error_message << std::endl;
	return return_value;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		glfwSetWindowSize(window, WINDOW_WIDTH - 20, WINDOW_HEIGHT - 20);

	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main(int argc, char** argv)
{
	if (!glfwInit())
		return (exitProgramm("Failed to initialize GLFW", EXIT_FAILURE));

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pure OpenGL via GLFW", NULL, NULL);
	if (window == NULL)
		return (exitProgramm("Failed to create GLFW window", EXIT_FAILURE));

	if (argc == 2)
	{
		int return_value = handleArgument(argv[1], window);
		glfwTerminate();
		return return_value;
	}





	glfwMakeContextCurrent(window);

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.1f, 0.4f, 0.7f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_QUADS);
			glColor3f(1.0f, 1.0f, 1.0f); // White color
			glVertex2f(-0.5f,  0.5f); // Top-left vertex
			glVertex2f( 0.5f,  0.5f); // Top-right vertex
			glVertex2f( 0.5f, -0.5f); // Bottom-right vertex
			glVertex2f(-0.5f, -0.5f); // Bottom-left vertex
		glEnd();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}



