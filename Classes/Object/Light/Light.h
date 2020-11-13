#ifndef _Light_h_
#define _Light_h_

#include "../../Utility/glmath/glmathlib.h"

class Light
{
public:
	static Light* create();
	static Light* create(glmath::vec3 lightColor);
	
	virtual void draw();
	virtual void update();

	virtual void add() {}
	virtual void remove() {}
protected:
	Light();
	Light(glmath::vec3 lightColor);

	int getTag() { return tag; }
	void setTag(int t) { this->tag = t; }
private:
	glmath::vec3 m_lightColor;
	int tag;
};


#endif // !_Light_h_

