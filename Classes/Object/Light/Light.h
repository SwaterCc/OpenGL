#ifndef _Light_h_
#define _Light_h_

#include "../../Utility/glmath/glmathlib.h"
#include "../../Framework/GLProgram.h"

class Light
{
public:
	static Light* create();
	static Light* create(glmath::vec3 lightColor);
	
	virtual void draw();
	virtual void update(GLProgram * program);

	virtual void add() {}
	virtual void remove() {}
protected:
	Light();
	Light(glmath::vec3 lightColor);

	int getTag() { return tag; }
	void setTag(int t) { this->tag = t; }
	glmath::vec3 m_lightColor;
private:
	
	int tag;
};


#endif // !_Light_h_

