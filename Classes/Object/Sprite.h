#ifndef _Sprite_h_
#define _Sprite_h_

#include"ObjectBase.h"
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
	int m_nTexture_height;
	int m_nTexture_width;
	int m_nTexture_nrChanners;

	GLuint m_uTexture;

	Quad_Vertex m_VertexData;
};
OBJECT_END
#endif // !_Sprite_h
