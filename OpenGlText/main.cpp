#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
using namespace std;

float vertexArr[] = {
	 0.0f, 0.5f,0.0f,		//top
	-0.5f,-0.5f,0.0f,	//left
	 0.5f,-0.5f,0.0f		//right
};

void makeShaderCompiledLog(GLuint shaderID)
{
	int success;
	char log[512];
	memset(log, 0, sizeof(log));

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderID, sizeof(log), NULL, log);
		cout << log << endl;
	}
}

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
	
	//创建VBO
	GLuint VBOID;
	glGenBuffers(1, &VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, VBOID);//一定注意先绑定后设置属性

	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexArr),vertexArr,GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, VBOID);放在这里是错误的

	//创建VAO
	GLuint VAOID;
	glGenVertexArrays(1, &VAOID);
	glBindVertexArray(VAOID);	

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glBindVertexArray(VAOID); 放在这里是错误的，必须先绑定再设置属性指针
	glEnableVertexAttribArray(0);

	//创建着色器
	//1.顶点着色器
	 const GLchar* vertexShaderCore =
	"#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	//"out vec3 outVex;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
	"}\0";

	auto vertexShader = glCreateShader(GL_VERTEX_SHADER);		//创建着色器
	glShaderSource(vertexShader, 1, &vertexShaderCore, NULL);	//将代码拷贝至着色器上
	glCompileShader(vertexShader);								//编译源码
	makeShaderCompiledLog(vertexShader);
	//2.片段着手器

	const GLchar* fragmentShaderCore =
	"#version 330 core\n"
	"out vec4 aColor;\n"
	"void main()\n"
	"{\n"
	"	aColor = vec4(0.3f,0.5f,0.0f,0.0f);\n"
	"}\0";

	auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderCore, NULL);
	glCompileShader(fragmentShader);
	makeShaderCompiledLog(fragmentShader);

	//创建着色器程序

	auto shaderProgream = glCreateProgram();

	glAttachShader(shaderProgream, vertexShader);
	glAttachShader(shaderProgream, fragmentShader);
	glLinkProgram(shaderProgream);

	while (!glfwWindowShouldClose(windows))
	{
		glClearColor(0.2f, 0.3f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		
		glUseProgram(shaderProgream);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		

		glfwSwapBuffers(windows);
		glfwPollEvents();
	}


	return 0;
}