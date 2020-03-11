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
	runUniformQueue();
}

void Shader::setUniformInt(string valName, int value)
{
	if (m_nShaderProgram)
	{
		uint localUniform = glGetUniformLocation(m_nShaderProgram, valName.c_str());
		if (m_bIsShaderProgramUsed)
		{
			glUniform1i(localUniform,value);
		}
		else
		{
			std::cout << "Warning shaderProgram is not Used,But Uniform Value push in then queue!" << endl;
			name_uniform nu;
			nu.valName = valName;
			uniformValue u;
			u.tag = 'i';
			u.uu.ival = value;
			nu.u = u;
			m_uniformQueue.push(nu);
		}
	}
	else
	{
		std::cout << "Warning shaderProgram is NULL,But Uniform Value push in then queue!" << endl;
		name_uniform nu;
		nu.valName = valName;
		uniformValue u;
		u.tag = 'i';
		u.uu.ival = value;
		nu.u = u;
		m_uniformQueue.push(nu);
	}
}

void Shader::setUniformUInt(string valName, uint value)
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
			std::cout << "Warning shaderProgram is not Used,But Uniform Value push in then queue!" << endl;
			name_uniform nu;
			nu.valName = valName;
			uniformValue u;
			u.tag = 'u';
			u.uu.uval = value;
			nu.u = u;
			m_uniformQueue.push(nu);
		}
	}
	else
	{
		std::cout << "Warning shaderProgram is NULL,But Uniform Value push in then queue!" << endl;
		name_uniform nu;
		nu.valName = valName;
		uniformValue u;
		u.tag = 'u';
		u.uu.uval = value;
		nu.u = u;
		m_uniformQueue.push(nu);
	}
}

void Shader::setUniformFloat(string valName, float value)
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
			std::cout << "Warning shaderProgram is not Used,But Uniform Value push in then queue!" << endl;
			name_uniform nu;
			nu.valName = valName;
			uniformValue u;
			u.tag = 'f';
			u.uu.fval = value;
			nu.u = u;
			m_uniformQueue.push(nu);
		}
	}
	else
	{
		std::cout << "Warning shaderProgram is NULL,But Uniform Value push in then queue!" << endl;
		name_uniform nu;
		nu.valName = valName;
		uniformValue u;
		u.tag = 'f';
		u.uu.fval = value;
		nu.u = u;
		m_uniformQueue.push(nu);
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
			std::cout << "Warning shaderProgram is not Used,But Uniform Value push in then queue!" << endl;
			
			m_uniform4FQueue.push({ valName,fv });
		}
	}
	else
	{
		std::cout << "Warning shaderProgram is NULL,But Uniform Value push in then queue!" << endl;
		m_uniform4FQueue.push({ valName,fv });
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

void Shader::runUniformQueue()
{
	while (!m_uniformQueue.empty())
	{
		name_uniform nu = m_uniformQueue.front();
		m_uniformQueue.pop();

		
		switch (nu.u.tag)
		{
		case 'i':
			setUniformInt(nu.valName, nu.u.uu.ival);
		case 'u':
			setUniformInt(nu.valName, nu.u.uu.uval);
		case 'f':
			setUniformInt(nu.valName, nu.u.uu.fval);
		default:
			cout << "Tag ERROR!" << endl;
		}
	}

	while (!m_uniform4FQueue.empty())
	{
		name_uniformFV nfv = m_uniform4FQueue.front();
		m_uniform4FQueue.pop();

		setUniform4F(nfv.valName, nfv.u);
	}
}
