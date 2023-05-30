#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, 800, 800);
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents(); // 창 등장, 크기 변경 등등 변경사항 처리. 이 명령어 없이 창 변형시킬시 창 멈춤.
	}

	glfwDestroyWindow(window);



	glfwTerminate();
	return 0;
}