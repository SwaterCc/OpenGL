#include "Sprite.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

OBJECT_BEGIN
Sprite* Sprite::create()
{
	auto* p = new Sprite();
	
	return p;
}

Sprite* Sprite::create(const char* TextureFile)
{
	auto* p = new Sprite(TextureFile);
	if (p)
	{
		p->init();
	}
	return p;
}

void Sprite::draw()
{
	m_ShaderProgram->useShaderProgream();

	glBindVertexArray(m_uVAO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Sprite::Sprite():ObjectBase()
{
	
}

Sprite::Sprite(const char* TextureFile):ObjectBase(),m_sTextureFile(TextureFile)
{
	
}

Sprite::~Sprite()
{
	delete this;
}

void Sprite::init()
{
	initTexture();

	m_VertexData.lb.color = c3(1, 1, 1);
	m_VertexData.rb.color = c3(1, 1, 1);
	m_VertexData.lt.color = c3(1, 1, 1);
	m_VertexData.rt.color = c3(1, 1, 1);

	//VAO
	glGenVertexArrays(1, &m_uVAO);
	glBindVertexArray(m_uVAO);

	//坐标变换
	Size winSize = RenderPiplineManager::getInstance()->getWinSize();
	float _width = (float)m_nTexture_width / (float)winSize.width * 2;
	float _height = (float)m_nTexture_height / (float)winSize.height * 2;
	//float _width = (float)m_nTexture_width / (float)m_nTexture_width;
	//float _height = (float)m_nTexture_height / (float)m_nTexture_width;

	m_VertexData.rt.vertex = Vec3(_width * m_AnchorPoint.X, _height * m_AnchorPoint.Y, 0);
	m_VertexData.rb.vertex = Vec3(_width * m_AnchorPoint.X, -_height * m_AnchorPoint.Y, 0);
	m_VertexData.lt.vertex = Vec3(-_width * m_AnchorPoint.X, _height * m_AnchorPoint.Y, 0);
	m_VertexData.lb.vertex = Vec3(-_width * m_AnchorPoint.X, -_height * m_AnchorPoint.Y, 0);

	//VBO
	glGenBuffers(1, &m_uVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_VertexData), &m_VertexData, GL_STATIC_DRAW);

	//VEO
	///索引的值必须是uint类型，否则会无法识别
	uint veoId;
	uVec3 elements[2] = { uv3(0,1,2),uv3(0,2,3) };
	glGenBuffers(1, &veoId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, veoId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	//顶点属性
	glVertexAttribPointer(VertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_POSITION);
	glVertexAttribPointer(VertexAttrib_Color, 4, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_COLOR);
	glVertexAttribPointer(VertexAttrib_Texture, 2, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_TEXTURE);

	//属性激活
	for (int i = 0; i < VertexAttrib_MaxNum; i++)
	{
		glEnableVertexAttribArray(i);
	}

	//着色器
	GLProgram* program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_PositionColorTexture);
	setProgram(program);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
void Sprite::initTexture()
{
	stbi_set_flip_vertically_on_load(true);

	string path = "../Resources/";
	path.append(m_sTextureFile);
	unsigned char* data = stbi_load(path.c_str(),&m_nTexture_width, &m_nTexture_height,&m_nTexture_nrChanners,0);

	//创建纹理
	glGenTextures(1, &m_uTexture);
	glBindTexture(GL_TEXTURE_2D, m_uTexture);
	//激活纹理单元
	glActiveTexture(GL_TEXTURE0);

	//设置纹理环绕方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	//设置纹理过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//传入纹理数据
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_nTexture_width, m_nTexture_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);//创建多级渐远纹理
		stbi_image_free(data);
	}
	else
	{
		std::cerr << "loading image failed !" << endl;
	}

	m_VertexData.lb.texture = { 0,0 };
	m_VertexData.lt.texture = { 0,1 };
	m_VertexData.rt.texture = { 1,1 };
	m_VertexData.rb.texture = { 1,0 };
	
}
OBJECT_END