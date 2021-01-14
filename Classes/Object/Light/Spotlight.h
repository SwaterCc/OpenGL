#ifndef _Spotlight_h_
#define _Spotlight_h_

#include"Light.h"

class Spotlight : public Light
{
public:
	static Spotlight* create();
	static Spotlight* create(glmath::vec3 pos, glmath::vec3 dir, float height, float radius, glmath::vec3 lightColor = glmath::vec3(1));
	
	Spotlight();
	Spotlight(glmath::vec3 pos, glmath::vec3 dir, float height, float radius, glmath::vec3 lightColor = glmath::vec3(1));

	virtual void draw();
	virtual void update(GLProgram* program)override;
protected:
	virtual void init();
	virtual void add() override;
	virtual void remove() override;
private:
	glmath::vec3 position;
	glmath::vec3 direction;
	float cutOff;
};

#endif // !_Spotlight_h_

