#ifndef _Camera_H_
#define _Camera_H_

#include"../Include/Include.h"
#include"../Utility/glmath/glmathlib.h"
class ObjectBase;
class Camera
{
public:
	static Camera* create();
	static Camera* create(glmath::vec3 cameraPos, glmath::point3 target = { 0,0,0 }, Projection_Type type = Projection_Perspective);
	// -- 视口投影变换 --

	void makeObjectTransfomation(ObjectBase* obj);
	void setPosition(glmath::vec3 pos);
	glmath::vec3 getPosition();


	//-- 属性设置 --
	void setView(float width,float height);
	float getView();
	void setViewWidth(float width);
	float getViewWidth();
	void setViewHeight(float height);
	float getViewHeight();

	void setNearPlane(float nearplane);
	float getNearPlane();
	void setFarPlane(float farplane);
	float getFarPlane();

	// -- 视角 --
	//仅透视模式需要
	void setViewAngle(float angle);
	float getViewAngle();
protected:
	Camera();
	Camera(glmath::vec3 cameraPos, glmath::point3 target, Projection_Type type);
	void init();
private:
	glmath::point3 m_objTarget;
	glmath::vec3 m_objPos;

	Projection_Type m_type;
	float m_fViewWidth;
	float m_fViewHeight;
	float m_fNearPlane;
	float m_fFarPlane;
	float m_fFov;
};



#endif // !_Camera_H_
