#ifndef _PointLight_h_
#define _PointLight_h_

#include"Light.h"

class PointLight : public Light
{
public:
	static PointLight* create();
	static PointLight* create(glmath::vec3 pos, float constant, float linear, float quadratic, glmath::vec3 lightColor);
	PointLight();
	PointLight(glmath::vec3 pos, float constant, float linear, float quadratic, glmath::vec3 lightColor);

	virtual void draw();
	virtual void update(GLProgram* program) override;
	
	void setPos(glmath::vec3 pos);
	void setConstant(float c);
	void setLinear(float l);
	void setQuadratic(float q); 
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