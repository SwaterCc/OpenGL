#ifndef _Shader_H_
#define _Shader_H_
#include<iostream>
#include<vector>
#include<queue>
#include<glad/glad.h>
#include"data.h"
using namespace std;

typedef struct name_uniformValue{
	string valName;
	uniformValue u;
}name_uniform;

typedef struct name_uniformFV {
	string valName;
	uniform_fv u;
};

class Shader{
public:
	Shader();
public:
	void createShader(std::string ShaderFile , unsigned int shaderType);
	void createProgram();
	void useShaderProgream();

	GLuint getShaderProgram() { return m_nShaderProgram; }

	void setUniformInt(string valName,int value);
	void setUniformUInt(string valName, uint value);
	void setUniformFloat(string valName, float value);
	void setUniform4F(string valName, uniform_fv fv);

private:
	string readFile(std::string path);
	void ShaderCompiledLog(GLuint shaderID);
	void releseShader();
	void runUniformQueue();
private:

	std::vector<GLuint> m_VertexShader;
	uint m_uVertexShaderCount;
	std::vector<GLuint> m_FragmentShader;
	uint m_uFragmentShaderCount;

	GLuint m_nShaderProgram;

	//uniform÷µ¥Ê¥¢
	bool m_bIsShaderProgramUsed;//shaderProgram ±ªuse
	std::queue<name_uniformValue> m_uniformQueue;
	std::queue<name_uniformFV> m_uniform4FQueue;
};


#endif // _ShaderManager_H_
