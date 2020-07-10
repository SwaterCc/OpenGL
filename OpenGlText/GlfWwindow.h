#ifndef _GLFWwindow_h_
#define _GLFWwindow_h_

/***************************************************/
/*************用于控制GLFW窗口初始化****************/
/***************************************************/
#include"../Classes/Include.h"

class GLFWwindow
{
	const int _VIEW_HEIGHT_ = 600;
	const int _VIEW_WIDTH_ = 800;
	const char* _VIEW_TITLE_ = "OpenGL";
public:
	static GLFWwindow* getInstance();

	void start();
protected:

private:
	GLFWwindow();
	~GLFWwindow();
	
	GLFWwindow* m_pGLFWwindow;

	void initGLAD();
	
	static GLFWwindow* m_pInstance;
};





#endif // !_GLFWwindow_h_

