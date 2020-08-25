#include "GLProgram.h"
#include<fstream>
#include<string>
#include<sstream>

GLProgram::GLProgram()
{
	m_nShaderProgram = 0;
	m_glVertexShader = 0;
	m_glFragmentShader = 0;
	m_bIsShaderProgramUsed = false;
}

void GLProgram::createShader(std::string ShaderFile, unsigned int shaderType)
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
		m_glVertexShader = glCreateShader(shaderType);
		glShaderSource(m_glVertexShader, 1, &shaderC, NULL);
		glCompileShader(m_glVertexShader);
		ShaderCompiledLog(m_glVertexShader);
	}
	else if (shaderType == GL_FRAGMENT_SHADER)
	{
		m_glFragmentShader = glCreateShader(shaderType);
		
		glShaderSource(m_glFragmentShader, 1, &shaderC, NULL);
		glCompileShader(m_glFragmentShader);
		ShaderCompiledLog(m_glFragmentShader);
	}	
}

void GLProgram::createProgram()
{
	m_nShaderProgram = glCreateProgram();
	
	glAttachShader(m_nShaderProgram, m_glVertexShader);
	glAttachShader(m_nShaderProgram, m_glFragmentShader);
	
	glLinkProgram(m_nShaderProgram);
	int success = 0;
	char infoLog[512];
	memset(infoLog, 0, 512);
	glGetProgramiv(m_nShaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_nShaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	releseShader();
}

void GLProgram::useShaderProgream()
{
	glUseProgram(m_nShaderProgram);
	m_bIsShaderProgramUsed = true;
}


void GLProgram::setUniformOneInt(string valName, int value)
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

void GLProgram::setUniformOneUInt(string valName, uint value)
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

void GLProgram::setUniformOneFloat(string valName, float value)
{
	if (m_nShaderProgram)
	{
		uint localUniform = glGetUniformLocation(m_nShaderProgram, valName.c_str());
		if (m_bIsShaderProgramUsed)
		{
			glUniform1f(localUniform, value);
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

void GLProgram::setUniform4F(string valName, uniform_fv fv)
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

void GLProgram::setUniform4MatrixFV(string valName, glm::mat4 matrix)
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

void GLProgram::setUniform4MatrixFV(string valName, glmath::mat4 matrix)
{
	if (m_nShaderProgram)
	{
		uint localUniform = glGetUniformLocation(m_nShaderProgram, valName.c_str());
		if (m_bIsShaderProgramUsed)
		{
			glUniformMatrix4fv(localUniform, 1/*矩阵数量*/, GL_TRUE/*是否行列相反*/, &(matrix[0].x));
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

string GLProgram::readFile(std::string path)
{
	using std::fstream;
	std::ifstream ins;
	std::stringstream stros;
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

void GLProgram::ShaderCompiledLog(GLuint shaderID)
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

void GLProgram::releseShader()
{
	glDeleteShader(m_glVertexShader);
	glDeleteShader(m_glFragmentShader);
}
