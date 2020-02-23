#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
using namespace std;


int main()
{
	//2020.2.23 练习创建三角形
	//初始化glfw环境
	glfwInit();
	//初始化glfw库
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//设置大版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//设置小版本号
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//设置核心渲染模式

	auto* windows = glfwCreateWindow(800, 600, "LearnOpenGL",NULL,NULL);
	//创建窗口
	
	glfwMakeContextCurrent(windows);//关联上下文，主义：这条语句必须在glad初始化之前，否则glad初始化会出错
	
	//初始化GLAD 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cerr << "init glad Error" << endl;
		return -1;
	}

	

	while (!glfwWindowShouldClose(windows))
	{




		glfwSwapBuffers(windows);
		glfwPollEvents();
	}


	return 0;
}