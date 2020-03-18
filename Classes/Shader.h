#ifndef _Shader_H_
#define _Shader_H_
#include<iostream>
#include<vector>
#include<queue>
#include<glad/glad.h>
#include"data.h"
using namespace std;

class Shader{
public:
	Shader();
public:
	void createShader(std::string ShaderFile , unsigned int shaderType);
	void createProgram();
	void useShaderProgream();

	GLuint getShaderProgram() { return m_nShaderProgram; }


	void setUniformOneInt(string valName,int value);
	void setUniformOneUInt(string valName, uint value);
	void setUniformOneFloat(string valName, float value);
	void setUniform4F(string valName, uniform_fv fv);

private:
	string readFile(std::string path);
	void ShaderCompiledLog(GLuint shaderID);
	void releseShader();
	
private:

	std::vector<GLuint> m_VertexShader;
	uint m_uVertexShaderCount;
	std::vector<GLuint> m_FragmentShader;
	uint m_uFragmentShaderCount;

	GLuint m_nShaderProgram;

	//uniform÷µ¥Ê¥¢
	bool m_bIsShaderProgramUsed;//shaderProgram ±ªuse

};


#endif // _ShaderManager_H_
