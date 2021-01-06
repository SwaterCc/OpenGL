#include "Texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture2D* Texture2D::create(std::string texture, GLuint textureUnit)
{
	auto* p = new Texture2D(texture,textureUnit);
	if (p&&p->initWithTexture())
	{
		return p;
	}
	return nullptr;
}

Texture2D::Texture2D(std::string texture, GLuint textureUnit):m_pTexFile(texture)
{
	m_TextureUnit = textureUnit;
}


void Texture2D::update()
{
	if (m_Texture)
	{
		glActiveTexture(m_TextureUnit);
		glBindTexture(GL_TEXTURE_2D, m_Texture);
	}
}

bool Texture2D::initWithTexture()
{
	stbi_set_flip_vertically_on_load(true);

	std::string path = "../Resources/";
	path.append(m_pTexFile);
	unsigned char* data = stbi_load(path.c_str(), &m_nWidth, &m_nHeight, &m_nNRChanners, 0);

	if (data)
	{
		glGenTextures(1, &m_Texture);
		glBindTexture(GL_TEXTURE_2D,m_Texture);
		
		GLenum format = GL_BLUE;
		if (m_nNRChanners == 1)
			format = GL_RED;
		else if (m_nNRChanners == 3)
			format = GL_RGB;
		else if (m_nNRChanners == 4)
			format = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, format, m_nWidth, m_nHeight, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		//���������Ʒ�ʽ
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		//����������˷�ʽ
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else 
	{
		std::cerr << "loading image failed !" << endl;
		return false;
	}
	
	return true;
}
