#include "Shader.h"
#include<fstream>
#include<string>
#include<sstream>

Shader::Shader()
{
	m_uVertexShader = 0;
	m_uFragmentShader = 0;
	m_nShaderProgram = 0;
}

void Shader::createShader(std::string ShaderFile, unsigned int shaderType)
{
	string path = "";
	if (shaderType == GL_VERTEX_SHADER)
	{
		path = "../Shader/vertexShader/";
	}
	else if (shaderType == GL_FRAGMENT_SHADER)
	{
		path = "../Shader/fragmentShader/";
	}
	
	path.append(ShaderFile);

	string shaderScore = readFile(path).c_str();

	const char * shaderC = shaderScore.c_str();

	if (shaderType == GL_VERTEX_SHADER)
	{
		m_uVertexShader = glCreateShader(shaderType);
		glShaderSource(m_uVertexShader, 1, &shaderC, NULL);
		glCompileShader(m_uVertexShader);
		ShaderCompiledLog(m_uVertexShader);
	}
	else if (shaderType == GL_FRAGMENT_SHADER)
	{
		m_uFragmentShader = glCreateShader(shaderType);
		glShaderSource(m_uFragmentShader, 1, &shaderC, NULL);
		glCompileShader(m_uFragmentShader);
		ShaderCompiledLog(m_uFragmentShader);
	}	
}

void Shader::createProgram()
{
	m_nShaderProgram = glCreateProgram();
	if (m_uVertexShader)
	{
		glAttachShader(m_nShaderProgram, m_uVertexShader);
	}
	if (m_uFragmentShader)
	{
		glAttachShader(m_nShaderProgram, m_uFragmentShader);
	}
	glLinkProgram(m_nShaderProgram);
}

void Shader::useShaderProgream()
{
	glUseProgram(m_nShaderProgram);
}

string Shader::readFile(std::string path)
{
	ifstream ins;
	stringstream stros;
	string res;
	ins.exceptions(fstream::failbit | fstream::badbit);
	try
	{
		ins.open(path);

		stros << ins.rdbuf();
		res = stros.str();
		cout << "file : \n" << res << endl;
		ins.close();
	}
	catch (std::ifstream::failure e)
	{
		 std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	return res;
}

void Shader::ShaderCompiledLog(GLuint shaderID)
{
	int success;
	char log[512];
	memset(log, 0, sizeof(log));

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderID, sizeof(log), NULL, log);
		cout << log << endl;
	}
}
