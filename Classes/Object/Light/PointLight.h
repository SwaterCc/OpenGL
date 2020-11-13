#ifndef _PointLight_h_
#define _PointLight_h_

#include"Light.h"

class PointLight : public Light
{
public:
	static PointLight* create();
	static PointLight* create(glmath::vec3 lightColor);
	PointLight();
	PointLight(glmath::vec3 lightColor);

	virtual void draw();
	virtual void update();
protected:
	virtual void init();
	virtual void add() override;
	virtual void remove() override;
private:
	glmath::vec3 position;
	float constant;
	float linear;
	float quadratic;
};


#endif // !_PointLight_h_