#ifndef _Triangle_h_
#define _Triangle_h_

#include"ObjectBase.h"


OBJECT_BEGIN
class Triangle :public ObjectBase{
public:
	static Triangle* create();

	static Triangle* create(Triangle_Vertex vertex);

	virtual void draw();
protected:
	Triangle();
	Triangle(Triangle_Vertex vertex);
	virtual ~Triangle();

	void init();
private:
	Triangle_Vertex m_VertexData;
};
OBJECT_END






#endif // !_Trangle_h_
