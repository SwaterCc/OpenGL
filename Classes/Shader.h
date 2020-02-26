#ifndef _Shader_H_
#define _Shader_H_
#include<iostream>
#include<glad/glad.h>
using namespace std;

class Shader{
public:
	Shader();
public:
	void createShader(std::string ShaderFile , unsigned int shaderType);
	void createProgram();
	void useShaderProgream();
private:
	string readFile(std::string path);
	void ShaderCompiledLog(GLuint shaderID);
private:
	GLuint m_uVertexShader;
	GLuint m_uFragmentShader;
	GLuint m_nShaderProgram;
};


#endif // _ShaderManager_H_
