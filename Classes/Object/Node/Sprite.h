#ifndef _Sprite_h_
#define _Sprite_h_

#include"ObjectBase.h"
#include"../Attribute/Texture.h"

OBJECT_BEGIN
class Sprite:public ObjectBase
{
public:
	static Sprite* create();
	static Sprite* create(const char* TextureFile);

	virtual void draw() ;
protected:
	Sprite();
	Sprite(const char* TextureFile);
	~Sprite();
private:
	void init();
	void initTexture();


	std::string m_sTextureFile;
	Texture2D* m_pTex;
	Quad_Vertex m_VertexData;
};
OBJECT_END
#endif // !_Sprite_h
