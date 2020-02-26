//2020.2.23 练习创建三角形
//2020.2.23 增加索引绘画正方形
#include<iostream>

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"../Classes/Shader.h"
using namespace std;

float vertexArr[] = {
	 0.5f, 0.5f,0.0f, 1.0f,0.0f,0.0f,
	-0.5f, 0.5f,0.0f, 0.0f,1.0f,0.0f,		//top
	-0.5f,-0.5f,0.0f, 0.5f,0.5f,0.0f,	    //left
	 0.5f,-0.5f,0.0f, 0.0f,0.0f,1.0f		//right
};

GLuint elements[] = {
	0,1,2,
	0,2,3
};

int main()
{
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
	
	
	GLuint VAOID;
	glGenVertexArrays(1, &VAOID);
	glBindVertexArray(VAOID);

	//创建VBO
	GLuint VBOID;
	glGenBuffers(1, &VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, VBOID);//一定注意先绑定后设置属性

	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexArr),vertexArr,GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, VBOID);放在这里是错误的
	
	//创建EBO（必须是在处于vao绑定状态时才可以绑定EBO，否则绑不上会报错）
	GLuint EBOID;
	glGenBuffers(1, &EBOID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);


	//创建VAO
	//GLuint VAOID;
	//glGenVertexArrays(1, &VAOID);
	//glBindVertexArray(VAOID);
	//VAO的创建不能够在VEO之后

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	
	//glBindVertexArray(VAOID); 放在这里是错误的，必须先绑定再设置属性指针
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//创建着色器
	Shader shaderManager;

	shaderManager.createShader("test_1.txt", GL_VERTEX_SHADER);
	shaderManager.createShader("test_1.txt", GL_FRAGMENT_SHADER);

	shaderManager.createProgram();
	while (!glfwWindowShouldClose(windows))
	{
		glClearColor(0.2f, 0.3f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderManager.useShaderProgream();
		//glUseProgram(shaderProgream);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(windows);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}