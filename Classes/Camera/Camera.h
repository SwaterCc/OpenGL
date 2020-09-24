#ifndef _Camera_H_
#define _Camera_H_

#include"../Include/Include.h"
#include"../Utility/glmath/glmathlib.h"
enum Projection_Type
{
	Projection_ortho = 10,
	Projection_Perspective = 12,
};

class ObjectBase;

class CameraTransfomationInterface
{
public:
	virtual void setMVPMatrix(glmath::mat4 mvp) = 0;
};

class Camera
{
public:
	static Camera* create();
	static Camera* create(glmath::vec3 cameraPos, glmath::point3 target = { 0,0,0 }, glmath::vec3 upAxis = {0,1,0}, Projection_Type type = Projection_ortho);
	// -- 视口投影变换 --

	//MVP矩阵创建
	void makeObjectTransfomation(CameraTransfomationInterface* obj);
	
	void setPosition(glmath::vec3 pos) { m_objPos = pos; }
	glmath::vec3 getPosition() { return m_objPos; }
	
	void setTarget(glmath::point3 point) { m_objTarget = point; }
	glmath::point3 getTarget() { return m_objTarget; }
	
	void setProjection(Projection_Type t) { m_type = t; }
	Projection_Type getProjection() { return m_type; }

	void setUpAxis(glmath::vec3 up) { m_objUp = up; }
	glmath::vec3 getUPAxis() { return m_objUp; }
	//-- 属性设置 --

	void setView(float width, float height) 
	{ 
		m_fViewWidth = width;
		m_fViewHeight = height;
	}
	Size getView()
	{
		return Size(m_fViewWidth, m_fViewHeight);
	}
	void setViewWidth(float width)
	{
		m_fViewWidth = width;
	}
	float getViewWidth()
	{
		return m_fViewWidth;
	}
	void setViewHeight(float height)
	{
		m_fViewHeight = height;
	}
	float getViewHeight()
	{
		return m_fViewHeight;
	}
	void setNearPlane(float nearplane)
	{
		m_fNearPlane = nearplane;
	}
	float getNearPlane()
	{
		return m_fNearPlane;
	}
	void setFarPlane(float farplane)
	{
		m_fFarPlane = farplane;
	}
	float getFarPlane()
	{
		return m_fFarPlane;
	}

	// -- 视角 --
	//仅透视模式需要
	void setViewAngle(float angle)
	{
		m_fFov = angle;
	}
	float getViewAngle()
	{
		return m_fFov;
	}

	// -- 额外属性 --

	void setTag(int tag) { m_nTag = tag; }
	int getTag() { return m_nTag; }

	void setActive(bool isActive) { m_bIsActive = isActive; }
	bool getActive() { return m_bIsActive; }
	void init();
protected:
	Camera();
	Camera(glmath::vec3 cameraPos, glmath::point3 target, glmath::vec3 upAxis, Projection_Type type);


	virtual void createLookAt();
	virtual void createPerspectiveMat();
	virtual void createOrthogonalMat();
private:
	glmath::point3 m_objTarget;
	glmath::vec3 m_objPos;
	glmath::vec3 m_objUp;

	Projection_Type m_type;
	float m_fViewWidth;
	float m_fViewHeight;
	float m_fNearPlane;
	float m_fFarPlane;
	float m_fFov;


	glmath::mat4 m_objProjectionMat;
	glmath::mat4 m_objLookAt;

	int m_nTag;
	bool m_bIsActive;
};



#endif // !_Camera_H_
