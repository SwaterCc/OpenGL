#include "GlfWwindow.h"
#include "../Classes/RenderPipelineManager.h"
#include "../Classes/GLShaderProgreamCatch.h"
GLFWwindow* GLFWwindow::m_pInstance = nullptr;

GLFWwindow* GLFWwindow::getInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new GLFWwindow();
	}
	return m_pInstance;
}

void GLFWwindow::start()
{
	if (m_pGLFWwindow == nullptr)
		m_pGLFWwindow = glfwCreateWindow(_VIEW_WIDTH_, _VIEW_HEIGHT_, _VIEW_TITLE_, NULL, NULL);
	glfwMakeContextCurrent(m_pGLFWwindow);

	initGLAD();
	//场景初始化
	RenderPiplineManager::getInstance()->createSence(SenceType_Default);//默认
	//模式设置
	glEnable(GL_DEPTH_TEST);
	//主循环

	while (!glfwWindowShouldClose(m_pGLFWwindow))
	{
		//键盘处理模式函数
		//鼠标处理模式函数

		//清理缓存
		glClearColor(0.0f, 0.2f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		//绘制循环
		RenderPiplineManager::getInstance()->mainLoop();

		glfwSwapBuffers(m_pGLFWwindow);
		glfwPollEvents();
	}


	glfwTerminate();
}


GLFWwindow::GLFWwindow()
{
	m_pGLFWwindow = nullptr;
	//初始化GLFW环境
	//初始化GLFW库
	glfwInit();
	//设置大版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//设置小版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//设置核心渲染方式
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow::~GLFWwindow()
{
	
}

void GLFWwindow::initGLAD()
{
	//初始化GLAD 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cerr << "init glad Error" << endl;
		return ;
	}
}
