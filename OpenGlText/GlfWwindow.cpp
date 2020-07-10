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
	//������ʼ��
	RenderPiplineManager::getInstance()->createSence(SenceType_Default);//Ĭ��
	//ģʽ����
	glEnable(GL_DEPTH_TEST);
	//��ѭ��

	while (!glfwWindowShouldClose(m_pGLFWwindow))
	{
		//���̴���ģʽ����
		//��괦��ģʽ����

		//������
		glClearColor(0.0f, 0.2f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		//����ѭ��
		RenderPiplineManager::getInstance()->mainLoop();

		glfwSwapBuffers(m_pGLFWwindow);
		glfwPollEvents();
	}


	glfwTerminate();
}


GLFWwindow::GLFWwindow()
{
	m_pGLFWwindow = nullptr;
	//��ʼ��GLFW����
	//��ʼ��GLFW��
	glfwInit();
	//���ô�汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//����С�汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//���ú�����Ⱦ��ʽ
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow::~GLFWwindow()
{
	
}

void GLFWwindow::initGLAD()
{
	//��ʼ��GLAD 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cerr << "init glad Error" << endl;
		return ;
	}
}
