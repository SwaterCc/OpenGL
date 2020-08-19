#include "Camera.h"

Camera* Camera::create()
{
	Camera* p = new Camera();
	if (p)
	{
		p->init();
	}
	return p;
}

Camera* Camera::create(glmath::vec3 cameraPos, glmath::point3 target, Projection_Type type)
{
	Camera* p = new Camera(cameraPos,target,type);
	if (p)
	{
		p->init();
	}
	return p;
}
