#ifndef _GLFWwindow_h_
#define _GLFWwindow_h_

/***************************************************/
/*************用于控制GLFW窗口初始化****************/
/***************************************************/
#include"../Include/Include.h"

class GLMainWindow
{
	float _VIEW_HEIGHT_ = 720;
	float _VIEW_WIDTH_ = 1080;
	const char* _VIEW_TITLE_ = "OpenGL";
public:
	static GLMainWindow* getInstance();

	void start();
protected:

private:
	GLMainWindow();
	~GLMainWindow();
	
	GLFWwindow* m_pGLFWwindow;

	void initGLAD();
	
	static GLMainWindow* m_pInstance;
};





#endif // !_GLFWwindow_h_

