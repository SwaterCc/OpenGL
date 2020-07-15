#ifndef _Cube_h_
#define _Cube_h_

#include"ObjectBase.h"
#include"Texture.h"
OBJECT_BEGIN
class Cube : public ObjectBase
{
public:
	static Cube* create();

	virtual void draw();

	virtual void addTexture();
protected:
	virtual void init();

	Cube();
	~Cube();
private:
	Triangle_Vertex m_CubeVexData[12];
	std::vector<Texture> m_TextureCatch;
};
OBJECT_END

#endif // !_Cube_h_
