#ifndef _Square_h_
#define _Square_h_

#include "ObjectBase.h"

OBJECT_BEGIN

class Square : public ObjectBase
{
public:
	static Square* create();
	virtual void draw() override;
protected:
	Square();
	virtual ~Square();
private:
	void init();
private:
	GLuint m_uVEO;

	Quad_Vertex  m_pSquareVertexData;
	uVec3 m_pSquareVertexElement[2];
};

OBJECT_END

#endif // !_Square_h_

