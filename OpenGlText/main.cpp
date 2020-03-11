//2020.2.23 练习创建三角形
//2020.2.23 增加索引绘画正方形
#include<iostream>

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"../Classes/Shader.h"
#include"../Classes/data.h"
#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>

using namespace std;

float vertexArr[] = {
	 0.5f, 0.5f,0.0f, 1.0f,0.0f,0.0f, 1.0f,1.0f,
	-0.5f, 0.5f,0.0f, 0.0f,1.0f,0.0f, 0.0f,1.0f,		//top
	-0.5f,-0.5f,0.0f, 0.5f,0.5f,0.0f, 0.0f,0.0f,	    //left
	 0.5f,-0.5f,0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f		//right
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

	stbi_set_flip_vertically_on_load(true);

	
	

	
	//加入纹理
	int height, width, nrChannels;
	unsigned char* TextureData = stbi_load("../Resources/1.jpg", &width, &height, &nrChannels, 0);

	//创建纹理对象
	unsigned int Texture;
	glGenTextures(1, &Texture);

	//激活纹理单元
	glActiveTexture(GL_TEXTURE0);
	//绑定纹理
	glBindTexture(GL_TEXTURE_2D, Texture);

	//设置纹理环绕方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	//设置纹理过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//纹理放大不可以使用多级渐远来设置纹理过滤

	//传入纹理数据
	if (TextureData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureData);
		//第一个是纹理类型，第二个为多级渐远纹理的级别，0则为手动设置，第三个参数是希望opengl将图片以什么格式存储，第四个第五个是长宽，第六个固定为0
		//第七第八为原图片格式的固定类型，最后是利用库取出的图片的真正数据
		glGenerateMipmap(GL_TEXTURE_2D);
		//为当前绑定的图片自动创建多级渐远纹理
		stbi_image_free(TextureData);
		//数据传入后可以释放图片内存了
	}
	else
	{
		std::cerr << "loading image failed !" << endl;
	}
	int h, w, c;
	uchar* TextureData2 = stbi_load("../Resources/bg.jpg", &w, &h, &c, 0);

	uint TexBg;
	glGenTextures(1, &TexBg);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, TexBg);
	//设置纹理环绕方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	//设置纹理过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//纹理放大不可以使用多级渐远来设置纹理过滤
	if (TextureData2)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureData2);
		//第一个是纹理类型，第二个为多级渐远纹理的级别，0则为手动设置，第三个参数是希望opengl将图片以什么格式存储，第四个第五个是长宽，第六个固定为0
		//第七第八为原图片格式的固定类型，最后是利用库取出的图片的真正数据
		glGenerateMipmap(GL_TEXTURE_2D);
		//为当前绑定的图片自动创建多级渐远纹理
		stbi_image_free(TextureData2);
		//数据传入后可以释放图片内存了
	}
	else
	{
		std::cerr << "loading image failed !" << endl;
	}


	//创建VAO
	//GLuint VAOID;
	//glGenVertexArrays(1, &VAOID);
	//glBindVertexArray(VAOID);
	//VAO的创建不能够在VEO之后

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	//glBindVertexArray(VAOID); 放在这里是错误的，必须先绑定再设置属性指针
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	//创建着色器
	Shader shaderManager;

	shaderManager.createShader("test_1.txt", GL_VERTEX_SHADER);
	shaderManager.createShader("test_1.txt", GL_FRAGMENT_SHADER);

	shaderManager.createProgram();
	
	shaderManager.useShaderProgream();
	
	//glUniform1i(glGetUniformLocation(shaderManager.getShaderProgram(), "ourTexture1"), 0);
	//glUniform1i(glGetUniformLocation(shaderManager.getShaderProgram(), "ourTexture2"), 1);

	shaderManager.setUniformOneInt("ourTexture1", 0);
	shaderManager.setUniformOneInt("ourTexture2", 1);

	while (!glfwWindowShouldClose(windows))
	{
		glClearColor(0.2f, 0.3f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		
		//glUseProgram(shaderProgream);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(windows);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}