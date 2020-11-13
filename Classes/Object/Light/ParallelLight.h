#ifndef _ParallelLight_h_
#define _ParallelLight_h_

#include"Light.h"

class ParallelLight : public Light
{
public:
	static ParallelLight* create();
	static ParallelLight* create(glmath::vec3 lightColor);
	ParallelLight();
	ParallelLight(glmath::vec3 lightColor);

	virtual void draw();
	virtual void update();
protected:
	virtual void init();
	virtual void add() override;
	virtual void remove() override;
private:
	glmath::vec3 direction;
};


#endif // !_ParallelLight_h_
