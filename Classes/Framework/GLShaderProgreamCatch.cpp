#include "GLShaderProgreamCatch.h"

#include "GLProgram.h"

GLShaderProgreamCatch * GLShaderProgreamCatch::m_pInstance = nullptr;

GLShaderProgreamCatch* GLShaderProgreamCatch::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new GLShaderProgreamCatch;
		m_pInstance->init();
	}
	return m_pInstance;
}

GLProgram* GLShaderProgreamCatch::getGLProgream(GLShaderProgramType type)
{
	auto it = m_ProgramList.find(type);
	if (it!=m_ProgramList.end())
	{
		return it->second;
	}
	else
	{
		return m_ProgramList[ShaderProgramType_Default];
	}
}

GLShaderProgreamCatch::GLShaderProgreamCatch()
{
	m_ProgramList.clear();
}

GLShaderProgreamCatch::~GLShaderProgreamCatch()
{
	delete m_pInstance;
}

void GLShaderProgreamCatch::init()
{
	auto* p = new GLProgram;
	loadShaderFile(p, "default_VertexShader.vt", "default_FragmentShader.fg");
	p->createProgram();
	m_ProgramList.insert(make_pair(ShaderProgramType_Default, p));
}

void GLShaderProgreamCatch::loadShaderFile(GLProgram* p, std::string vertexShaderFile, std::string fragmentShaderFile)
{
	assert(vertexShaderFile != "" && fragmentShaderFile != "");
	p->createShader(vertexShaderFile, GL_VERTEX_SHADER);
	p->createShader(fragmentShaderFile, GL_FRAGMENT_SHADER);
}
