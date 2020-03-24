#include "Shader.h"
#include<fstream>
#include<string>
#include<sstream>

Shader::Shader()
{
	m_VertexShader.clear();
	m_FragmentShader.clear();

	m_uVertexShaderCount = 0;
	m_uFragmentShaderCount = 0;
	
	m_nShaderProgram = 0;
	m_bIsShaderProgramUsed = false;
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
		GLuint shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &shaderC, NULL);
		glCompileShader(shader);
		ShaderCompiledLog(shader);
		m_VertexShader.push_back(shader);
		m_uVertexShaderCount++;
	}
	else if (shaderType == GL_FRAGMENT_SHADER)
	{
		GLuint shader = glCreateShader(shaderType);
		
		glShaderSource(shader, 1, &shaderC, NULL);
		glCompileShader(shader);
		ShaderCompiledLog(shader);
		m_FragmentShader.push_back(shader);
		m_uFragmentShaderCount++;
	}	
}

void Shader::createProgram()
{
	m_nShaderProgram = glCreateProgram();
	if (m_VertexShader.size())
	{
		for (size_t i = 0; i < m_uVertexShaderCount; i++)
		{
			glAttachShader(m_nShaderProgram, m_VertexShader[i]);
		}
		
	}
	if (m_FragmentShader.size())
	{
		for (size_t i = 0; i < m_uFragmentShaderCount; i++)
		{
			glAttachShader(m_nShaderProgram, m_FragmentShader[i]);
		}
	}
	glLinkProgram(m_nShaderProgram);

	releseShader();
}

void Shader::useShaderProgream()
{
	glUseProgram(m_nShaderProgram);
	m_bIsShaderProgramUsed = true;
}


void Shader::setUniformOneInt(string valName, int value)
{
	if (m_nShaderProgram)
	{
		uint localUniform = glGetUniformLocation(m_nShaderProgram, valName.c_str());
		if (m_bIsShaderProgramUsed)
		{
			glUniform1i(localUniform,value);
		}
	}
	else
	{
		std::cout << "error shaderProgram is NULL" << endl;
	}
}

void Shader::setUniformOneUInt(string valName, uint value)
{
	if (m_nShaderProgram)
	{
		uint localUniform = glGetUniformLocation(m_nShaderProgram, valName.c_str());
		if (m_bIsShaderProgramUsed)
		{
			glUniform1i(localUniform, value);
		}
		else
		{
			std::cout << "error shaderProgram is NULL" << endl;
		}
	}
	else
	{
		std::cout << "error shaderProgram is NULL" << endl;
	}
}

void Shader::setUniformOneFloat(string valName, float value)
{
	if (m_nShaderProgram)
	{
		uint localUniform = glGetUniformLocation(m_nShaderProgram, valName.c_str());
		if (m_bIsShaderProgramUsed)
		{
			glUniform1i(localUniform, value);
		}
		else
		{
			std::cout << "error shaderProgram is NULL" << endl;
		
		}
	}
	else
	{
		std::cout << "error shaderProgram is NULL" << endl;
	
	}
}

void Shader::setUniform4F(string valName, uniform_fv fv)
{
	if (m_nShaderProgram)
	{
		uint localUniform = glGetUniformLocation(m_nShaderProgram, valName.c_str());
		if (m_bIsShaderProgramUsed)
		{
			glUniform4f(localUniform, fv.v1, fv.v2, fv.v3, fv.v4);
		}
		else
		{
			std::cout << "error shaderProgram is NULL" << endl;
		}
	}
	else
	{
		std::cout << "error shaderProgram is NULL" << endl;
	}
}

void Shader::setUniform4MatrixFV(string valName, mat4 matrix)
{
	if (m_nShaderProgram)
	{
		uint localUniform = glGetUniformLocation(m_nShaderProgram, valName.c_str());
		if (m_bIsShaderProgramUsed)
		{
			glUniformMatrix4fv(localUniform,1/*矩阵数量*/,GL_FALSE/*是否行列相反*/,glm::value_ptr(matrix));
		}
		else
		{
			std::cout << "error shaderProgram is NULL" << endl;
		}
	}
	else
	{
		std::cout << "error shaderProgram is NULL" << endl;
	}
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

void Shader::releseShader()
{
	for (size_t i = 0; i < m_uVertexShaderCount; i++)
	{
		glDeleteShader(m_VertexShader[i]);
	}
	for (size_t i = 0; i < m_uFragmentShaderCount; i++)
	{
		glDeleteShader(m_FragmentShader[i]);
	}
}
