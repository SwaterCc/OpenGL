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
/*			�����ĸ�����	  ��������һ�������						*/
/*			@parame cameraPos ����ָ�������������						*/
/*			@parame target    ����ָ�������ָ���λ��					*/
/*			@parame upAxis    ����ָ���Ϸ���							*/
/*			@parame type      ����ָ��������ͶӰ����͸��ͶӰ			*/
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
	glmath::mat4 mvp = (m_objProjectionMat * (m_objLookAt * model));//ע��˳��
	obj->setMVPMatrix(mvp);
}


void Camera::init()
{
	//����LookAt����
	createLookAt();
	//����projection����
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
	//1.��ȡ�����ָ����ĵ�λ����
	vec3 D = glmath::normalize(m_objTarget - m_objPos);
	//D = -1.0f * D;//����������Ҳ�����������ϵz����������ϵ�еı�ʾ
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

	m_objLookAt = Look_rotation * Look_translate; //��������ˣ���˳����ƽ�ƺ���ת
}

void Camera::createPerspectiveMat()
{

}

void Camera::createOrthogonalMat()
{
	//��ʱʹ�ã�ԭ����Ҫ6������������Ĭ����ƽ����0��������0����ʱ����ļ����ͼӷ���һ����
	//����ͶӰ�任
	//�ڿռ�������һ�������壬ת��Ϊ[-1,1]��Χ��������
	//1.����������е�ƽ��������ռ��ԭ�㴦��Ĭ��ԭ��Ϊ��0��0��0��
	glmath::mat4 trans = {
		1.0f,0.0f,0.0f,-(0+m_fViewWidth ) / 2,
		0.0f,1.0f,0.0f,-(0+m_fViewHeight) / 2,
		0.0f,0.0f,1.0f,-(m_fNearPlane + m_fFarPlane) / 2,
		0.0f,0.0f,0.0f,1.0f
	};
	//2.��������ĳ�������ų�[-1,1]�ķ�Χ��
	glmath::mat4 scale = {
		2 / (m_fViewWidth), 0.0f, 0.0f, 0.0f,
		0.0f, 2 / (m_fViewHeight), 0.0f, 0.0f, 
		0.0f, 0.0f, 2 / (- m_fNearPlane + m_fFarPlane),0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	//���
	m_objProjectionMat = scale * trans;
}

