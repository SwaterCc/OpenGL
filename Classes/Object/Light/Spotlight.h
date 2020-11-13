#ifndef _Spotlight_h_
#define _Spotlight_h_

#include"Light.h"

class Spotlight : public Light
{
public:
	static Spotlight* create();
	static Spotlight* create(glmath::vec3 lightColor);
	
	Spotlight();
	Spotlight(glmath::vec3 lightColor);

	virtual void draw();
	virtual void update();
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

