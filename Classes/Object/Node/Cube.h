#ifndef _Cube_h_
#define _Cube_h_

#include"ObjectBase.h"
#include"../Texture/Texture2D.h"
OBJECT_BEGIN
class Cube : public ObjectBase
{
public:
	static Cube* create();

	virtual void update() override;
	virtual void updateUniform() override;
	virtual void draw();

	virtual void addTexture();

	virtual void setWidth(float w) { m_fWidth = w; }
	virtual void setHeight(float h){ m_fHeight = h;}
	virtual void setDepth(float d) { m_fDepth = d; }
	virtual void setColor(glmath::vec4 color) { m_objColor = color; }
protected:
	virtual void init();
	virtual void InputVertexData();
	virtual void updateColorUniform();
	virtual void updateCamera();
	Cube();
	~Cube();
private:
	Triangle_Vertex m_CubeVexData[12];
	std::vector<Texture2D> m_TextureCatch;

	float m_fWidth;
	float m_fHeight;
	float m_fDepth;

	bool m_bIsFirstUpDate;
	glmath::vec4 m_objColor;
};
OBJECT_END

#endif // !_Cube_h_
