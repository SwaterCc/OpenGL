#ifndef _Light_h_
#define _Light_h_

#include "ObjectBase.h"

class Light : public ObjectBase
{
public:
	static Light* create();
	static Light* create(glmath::vec3 lightColor);
	Light();
	Light(glmath::vec3 lightColor);

	virtual void draw() override;
	virtual void update() override;
protected:

private:
	glmath::vec3 m_lightColor;
};


#endif // !_Light_h_

