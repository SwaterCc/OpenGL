//2020.2.23 练习创建三角形
//2020.2.23 增加索引绘画正方形
/**
#include"../Classes/Include.h"
#include"../Classes/GLProgram.h"
#include"../Classes/data.h"
#include"../Classes/Vertexs_Data.h"

#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>


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

bool firstMoveCursor = true;

double YawN = -90.0f;
double Pitch = 0.0f;
//默认第一次为屏幕中心
float lastX = 400;
float lastY = 300;
float fov = 45.0f;
vec3 gload_cameraPos;

vec3 cameraFront = vec3(0,0,-1);

void processInput(GLFWwindow* window);

void mouse_callBack(GLFWwindow* window,double xpos,double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
int main_old()
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
	
	GLProgram shaderManager;

	shaderManager.createShader("test_1.vs", GL_VERTEX_SHADER);
	shaderManager.createShader("test_1.fs", GL_FRAGMENT_SHADER);

	shaderManager.createProgram();
	
	GLuint VAOID;
	glGenVertexArrays(1, &VAOID);
	glBindVertexArray(VAOID);

	//创建VBO
	GLuint VBOID;
	glGenBuffers(1, &VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, VBOID);//一定注意先绑定后设置属性

	//glBufferData(GL_ARRAY_BUFFER,sizeof(vertexArr),vertexArr,GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(six_rect_vertices),six_rect_vertices,GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, VBOID);放在这里是错误的
	
	//创建EBO（必须是在处于vao绑定状态时才可以绑定EBO，否则绑不上会报错）
	//2020.3.24 FIX
	//GLuint EBOID;
	//glGenBuffers(1, &EBOID);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOID);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

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

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * SIZE_FLOAT, (void*)(0));
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * SIZE_FLOAT, (void*)(3 * SIZE_FLOAT));

	//glBindVertexArray(VAOID); 放在这里是错误的，必须先绑定再设置属性指针
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//glEnableVertexAttribArray(2);
	//创建着色器
	
	
	shaderManager.useShaderProgream();
	
	//glUniform1i(glGetUniformLocation(shaderManager.getShaderProgram(), "ourTexture1"), 0);
	//glUniform1i(glGetUniformLocation(shaderManager.getShaderProgram(), "ourTexture2"), 1);

	shaderManager.setUniformOneInt("ourTexture1", 0);
	shaderManager.setUniformOneInt("ourTexture2", 1);

	//坐标系变换
	
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	
	mat4 view = mat4(1.0f);
	view = translate(view, vec3(0, 0, -3));

	mat4 projection = mat4(1.0f);
	
	

	//2020.5.6
	//创建摄像机

	vec3 cameraPos = glm::vec3(0, 0, 3.0f);	//摄像机位置
	gload_cameraPos = cameraPos;
	vec3 cameraTarget = glm::vec3(0, 0, 0);//世界坐标原点
	//vec3 cameraDirection = glm::vec3(cameraPos - cameraTarget); // 获得指向摄像机的方向向量（摄像机Z轴正方向）

	vec3 Up = glm::vec3(0.0, 1.0, 0.0);//上轴
	//vec3 cameraX = glm::normalize(glm::cross(Up, cameraDirection));//x轴
	//vec3 cameraY = glm::normalize(glm::cross(cameraX, cameraDirection));//Y轴


	//Look At 矩阵
	//mat4 view = mat4(1.0f);	
	//float radios = 10.0f;

	//创建FPS视角
	glfwSetInputMode(windows, GLFW_CURSOR, GLFW_CURSOR_DISABLED);//窗口关闭光标显示
	
	//注册鼠标回调函数
	glfwSetCursorPosCallback(windows, mouse_callBack);
	//注册滚轮回调函数
	glfwSetScrollCallback(windows, scroll_callback);
	glEnable(GL_DEPTH_TEST);
	
	while (!glfwWindowShouldClose(windows))
	{

		processInput(windows);


		glClearColor(0.2f, 0.35f, 0.5f, 1);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		

		//先将当前矩形旋转后缩放
		//glm::mat4 tran = glm::mat4(1.0f);
		//tran = glm::rotate(tran, (float)glfwGetTime()/*将角度转换为弧度制, glm::vec3(0.5, 1, 0)/*三个值分别对应xyz轴);	//绕Z轴旋转85°
		//tran = glm::scale(tran, glm::vec3(0.7, 0.7, 0.7)/*对每个轴乘一个系数);

		//uint transform = glGetUniformLocation(shaderManager.getShaderProgram(), "transform");
		//glUniformMatrix4fv(transform, 1, GL_FALSE, glm::value_ptr(tran));
		//shaderManager.setUniform4MatrixFV("transform", tran);
		
		//float glmX = sin(glfwGetTime()) * radios;
		//float glmZ = cos(glfwGetTime()) * radios;

		//vec3 cameraShow = vec3(glmX, 0, glmZ);
		//view = glm::lookAt(cameraShow, cameraTarget, Up);//需要三个参数，摄像机位置向量，目标原点向量，上向量
		
		projection = perspective(radians(fov), float(800.0 / 600.0), 1.0f, 100.0f);
		shaderManager.setUniform4MatrixFV("projection", projection);
		view = glm::lookAt(gload_cameraPos, cameraTarget + cameraFront, Up);
		
		shaderManager.setUniform4MatrixFV("view", view);

		for (int i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			

			model = translate(model, cubePositions[i]);
			model = rotate(model, float(glfwGetTime()*(i+2)), vec3(1.0, 1.0, 0.5));//绕x轴旋转
			//矩阵的顺序会影响结果

			shaderManager.setUniform4MatrixFV("model", model);
			//glUseProgram(shaderProgream);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
		glfwSwapBuffers(windows);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	float cameraSpeed = 0.5f;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		gload_cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		gload_cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		gload_cameraPos -= glm::normalize(glm::cross(cameraFront, vec3(0,1,0))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		gload_cameraPos += glm::normalize(glm::cross(cameraFront, vec3(0, 1, 0))) * cameraSpeed;
}

void mouse_callBack(GLFWwindow* window, double xpos, double ypos)
{

	if (firstMoveCursor)
	{
		lastX = xpos;
		lastY = ypos;
		firstMoveCursor = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	YawN += xoffset;
	Pitch += yoffset;

	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(YawN)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(YawN)) * cos(glm::radians(Pitch));
	cameraFront = glm::normalize(front);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	if (fov >= 1.0f && fov <= 45.0f)
		fov -= yoffset;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;
}
**/