#ifndef _Texture_h_
#define _Texture_h_

#include"AttributeModule.h"
#include"../../Include/Include.h"

using std::endl;

class Texture2D :public AttributeModule
{
public:
	static Texture2D* create(std::string textureFile,GLuint textureUnit = GL_TEXTURE0);
	Texture2D(std::string textureFile, GLuint textureUnit);

	int getTexWidth() { return m_nWidth; }
	int getTexHeight() { return m_nHeight; }
	int getTexChanners() { return m_nNRChanners; }
	GLuint getTex() { return m_Texture; }
public:
	virtual void update() override;
protected:
	virtual bool initWithTexture();

private:
	GLuint m_Texture;
	GLuint m_TextureUnit;

	int m_nWidth;
	int m_nHeight;
	int m_nNRChanners;
	std::string m_pTexFile;
};

#endif // !_Texture_h_

