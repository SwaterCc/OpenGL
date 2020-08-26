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

	m_bIsActive = false;
	m_nTag = -1;
}

Camera::Camera(glmath::vec3 cameraPos, glmath::point3 target, glmath::vec3 upAxis, Projection_Type type)
	:m_objPos(cameraPos),m_objTarget(target),m_objUp(upAxis),m_type(type)
{
	m_fViewWidth = 0;
	m_fViewHeight = 0;
	m_fNearPlane = 0;
	m_fFarPlane = 0;
	m_fFov = 0;

	m_objProjectionMat = glmath::mat4(1.0f);
	m_objLookAt = glmath::mat4(1.0f);

	m_bIsActive = false;
	m_nTag = -1;
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
	Camera* p = new Camera(cameraPos,target,upAxis,type);
	if (p)
	{
		//p->init();
	}
	return p;
}

void Camera::makeObjectTransfomation(CameraTransfomationInterface * obj)
{
	glmath::mat4 model = obj->getModel();
	glmath::mat4 mvp = (m_objProjectionMat * (m_objLookAt * model));//注意顺序
	obj->setMVPMatrix(mvp);
}


void Camera::init()
{
	//创建LookAt矩阵
	createLookAt();
	//创建projection矩阵
	switch (m_type)
	{
	case Projection_ortho:
		createOrthogonalMat();
		break;
	case Projection_Perspective:
		createPerspectiveMat();
		break;
	default:
		assert(false);
		break;
	}
}

void Camera::createLookAt()
{
	//1.获取摄像机指向方向的单位向量
	vec3 D = glmath::normalize(m_objTarget - m_objPos);
	//D = -1.0f * D;//方向向量，也就是相机坐标系z在世界坐标系中的表示
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

	m_objLookAt = Look_rotation * Look_translate; //矩阵是左乘，有顺序，先平移后旋转
}

void Camera::createPerspectiveMat()
{

}

void Camera::createOrthogonalMat()
{
	//临时使用，原本需要6个变量，现在默认左平面在0，底面在0，此时坐标的减法和加法是一样的
	//正交投影变换
	//在空间中任意一个立方体，转换为[-1,1]范围的正方体
	//1.将立方体的中点平移至坐标空间的原点处，默认原点为（0，0，0）
	glmath::mat4 trans = {
		1.0f,0.0f,0.0f,-(0+m_fViewWidth ) / 2,
		0.0f,1.0f,0.0f,-(0+m_fViewHeight) / 2,
		0.0f,0.0f,1.0f,-(m_fNearPlane + m_fFarPlane) / 2,
		0.0f,0.0f,0.0f,1.0f
	};
	//2.将立方体的长宽高缩放成[-1,1]的范围内
	glmath::mat4 scale = {
		2 / (m_fViewWidth), 0.0f, 0.0f, 0.0f,
		0.0f, 2 / (m_fViewHeight), 0.0f, 0.0f, 
		0.0f, 0.0f, 2 / (- m_fNearPlane + m_fFarPlane),0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	//相乘
	m_objProjectionMat = scale * trans;
}

