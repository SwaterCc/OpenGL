#include "Camera.h"
using glmath::vec3;

Camera::Camera()
{
	m_objTarget = { 0,0,0 };
	m_objPos = { 0,0,0 };

	m_type = Projection_ortho;
	m_fViewWidth = 0;
	m_fViewHeight = 0;
	m_fNearPlane = 0;
	m_fFarPlane = 0;
	m_fFov = 0;


	m_objProjectionMat = glmath::mat4(1.0f);
	m_objLookAt = glmath::mat4(1.0f);
}

Camera::Camera(glmath::vec3 cameraPos, glmath::point3 target, Projection_Type type)
	:m_objPos(cameraPos),m_objTarget(target),m_type(type)
{
	m_fViewWidth = 0;
	m_fViewHeight = 0;
	m_fNearPlane = 0;
	m_fFarPlane = 0;
	m_fFov = 0;

	m_objProjectionMat = glmath::mat4(1.0f);
	m_objLookAt = glmath::mat4(1.0f);
}


Camera* Camera::create()
{
	Camera* p = new Camera();
	if (p)
	{
		p->init();
	}
	return p;
}
/************************************************************************/
/*			接受四个参数	  用来创建一个摄像机						*/
/*			@parame cameraPos 用于指定摄像机的坐标						*/
/*			@parame target    用于指定摄像机指向的位置					*/
/*			@parame upAxis    用于指定上方向							*/
/*			@parame type      用于指定是正交投影还是透视投影			*/
/************************************************************************/
Camera* Camera::create(glmath::vec3 cameraPos, glmath::point3 target, glmath::vec3 upAxis, Projection_Type type)
{
	Camera* p = new Camera(cameraPos,target,type);
	if (p)
	{
		p->init();
	}
	return p;
}


void Camera::init()
{
	//创建LookAt矩阵
	//1.获取摄像机指向方向的单位向量
	vec3 D = glmath::normalize(m_objPos - m_objTarget);
	D = -1.0f * D;//方向向量，也就是相机坐标系z在世界坐标系中的表示
	//2.获取右向量
	vec3 U = m_objUp;//上向量
	vec3 R = glmath::normalize(glmath::cross(U, D));//向量叉乘不满足交换律，交换后会得到右向量的负方向
	//3.获取平移变换矩阵
	glmath::mat4 Look_translate = {
		1.0f, 0.0f, 0.0f, -m_objPos.x,
		0.0f, 1.0f, 0.0f, -m_objPos.y,
		0.0f, 0.0f, 1.0f, -m_objPos.z,
		0.0f, 0.0f, 0.0f, 1.0f
	};
	//4.获取旋转变换矩阵
	glmath::mat4 Look_rotation = {
		glmath::vec4(R,0.0f),
		glmath::vec4(U,0.0f),
		glmath::vec4(D,0.0f),
		glmath::vec4(glmath::vec3(0.0f),1.0f)
	};
}

