#include "GlMainWindow.h"
#include "RenderPipelineManager.h"
#include "GLShaderProgreamCatch.h"
GLMainWindow* GLMainWindow::m_pInstance = nullptr;
using std::cerr;
using std::endl;
GLMainWindow* GLMainWindow::getInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new GLMainWindow();
	}
	return m_pInstance;
}

void GLMainWindow::start()
{
	if (m_pGLFWwindow == nullptr)
		m_pGLFWwindow = glfwCreateWindow(_VIEW_WIDTH_, _VIEW_HEIGHT_, _VIEW_TITLE_, NULL, NULL);
	glfwMakeContextCurrent(m_pGLFWwindow);
#if defined(GLAD_SETUP)
	initGLAD();
#elif defined(GL3W_SETUP)
	initGL3W();
#endif

	//������ʼ��
	RenderPiplineManager::getInstance()->setWinSize(SizeMake(_VIEW_WIDTH_, _VIEW_HEIGHT_));
	RenderPiplineManager::getInstance()->createSence(SenceType_LightTest);//����//Ĭ��
	//ģʽ����
	glEnable(GL_DEPTH_TEST);
	
	//��ѭ��

	while (!glfwWindowShouldClose(m_pGLFWwindow))
	{
		//���̴���ģʽ����
		//��괦��ģʽ����
		
		//������
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		//����ѭ��
		RenderPiplineManager::getInstance()->mainLoop();

		glfwSwapBuffers(m_pGLFWwindow);
		glfwPollEvents();
	}


	glfwTerminate();
}


GLMainWindow::GLMainWindow()
{
	m_pGLFWwindow = nullptr;
	//��ʼ��GLFW����
	//��ʼ��GLFW��
	glfwInit();
	//���ô�汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//����С�汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//���ú�����Ⱦ��ʽ
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLMainWindow::~GLMainWindow()
{
	
}

void GLMainWindow::initGLAD()
{
#if defined(GLAD_SETUP)
	//��ʼ��GLAD 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cerr << "init glad Error" << endl;
		return ;
	}
#endif
}

void GLMainWindow::initGL3W()
{
#if defined(GL3W_SETUP)
	//��ʼ��GL3W 
	if (gl3wInit()) {
		fprintf(stderr, "failed to initialize OpenGL\n");
		
	}
	if (!gl3wIsSupported(4, 5)) {
		fprintf(stderr, "OpenGL 4.5 not supported\n");
		
	}
	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
		glGetString(GL_SHADING_LANGUAGE_VERSION));
#endif
}
