#include "Sprite.h"

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

void Sprite::updateUniformOfShader()
{
	m_ShaderProgram->setUniform4MatrixFV(MVP_MAT, m_ObjMVPMatrix);
}

void Sprite::draw()
{
	m_ShaderProgram->useShaderProgream();
	glBindVertexArray(m_uVAO);


	updateUniformOfShader();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Sprite::Sprite():ObjectBase()
{
	m_pTex = nullptr;
}

Sprite::Sprite(const char* TextureFile):ObjectBase(),m_sTextureFile(TextureFile)
{
	m_pTex = nullptr;
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

	//坐标变换
	Size winSize = RenderPiplineManager::getInstance()->getWinSize();
	float _width = (float)m_pTex->getTexWidth();
	float _height = (float)m_pTex->getTexHeight();
	//float _width = (float)m_nTexture_width / (float)m_nTexture_width;
	//float _height = (float)m_nTexture_height / (float)m_nTexture_width;

	m_VertexData.rt.vertex = Vec3(_width * m_AnchorPoint.X, _height * m_AnchorPoint.Y, 0);
	m_VertexData.rb.vertex = Vec3(_width * m_AnchorPoint.X, -_height * m_AnchorPoint.Y, 0);
	m_VertexData.lt.vertex = Vec3(-_width * m_AnchorPoint.X, _height * m_AnchorPoint.Y, 0);
	m_VertexData.lb.vertex = Vec3(-_width * m_AnchorPoint.X, -_height * m_AnchorPoint.Y, 0);

	m_VertexConfig->setVBO(&m_VertexData, 1);
	//VEO
	///索引的值必须是uint类型，否则会无法识别
	uVec3 elements[2] = { uv3(0,1,2),uv3(0,2,3) };
	m_VertexConfig->setVEO(elements, 2);

	//顶点属性
	m_VertexConfig->setup(VERTEX_ATTRIB_POSITION | VERTEX_ATTRIB_COLOR | VERTEX_ATTRIB_TEXTURE);
	//着色器
	GLProgram* program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_PositionColorTexture);
	setProgram(program);
}
void Sprite::initTexture()
{
	m_pTex = Texture2D::create(m_sTextureFile);
	m_VertexData.lb.texture = { 0,0 };
	m_VertexData.lt.texture = { 0,1 };
	m_VertexData.rt.texture = { 1,1 };
	m_VertexData.rb.texture = { 1,0 };
	
}
OBJECT_END