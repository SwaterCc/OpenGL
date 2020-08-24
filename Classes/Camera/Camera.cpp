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
/*			�����ĸ�����	  ��������һ�������						*/
/*			@parame cameraPos ����ָ�������������						*/
/*			@parame target    ����ָ�������ָ���λ��					*/
/*			@parame upAxis    ����ָ���Ϸ���							*/
/*			@parame type      ����ָ��������ͶӰ����͸��ͶӰ			*/
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
	//����LookAt����
	//1.��ȡ�����ָ����ĵ�λ����
	vec3 D = glmath::normalize(m_objPos - m_objTarget);
	D = -1.0f * D;//����������Ҳ�����������ϵz����������ϵ�еı�ʾ
	//2.��ȡ������
	vec3 U = m_objUp;//������
	vec3 R = glmath::normalize(glmath::cross(U, D));//������˲����㽻���ɣ��������õ��������ĸ�����
	//3.��ȡƽ�Ʊ任����
	glmath::mat4 Look_translate = {
		1.0f, 0.0f, 0.0f, -m_objPos.x,
		0.0f, 1.0f, 0.0f, -m_objPos.y,
		0.0f, 0.0f, 1.0f, -m_objPos.z,
		0.0f, 0.0f, 0.0f, 1.0f
	};
	//4.��ȡ��ת�任����
	glmath::mat4 Look_rotation = {
		glmath::vec4(R,0.0f),
		glmath::vec4(U,0.0f),
		glmath::vec4(D,0.0f),
		glmath::vec4(glmath::vec3(0.0f),1.0f)
	};
}

