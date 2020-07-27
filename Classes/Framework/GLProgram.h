#ifndef _GLProgram_H_
#define _GLProgram_H_

#include<vector>
#include<queue>
#define NOT_USE_CUSTOM_MATRIX
#include "../Include/Include.h"

#if defined(NOT_USE_CUSTOM_MATRIX)
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;
#endif

class GLProgram{
public:
	GLProgram();
public:
	void createShader(std::string ShaderFile , unsigned int shaderType);
	void createProgram();
	void useShaderProgream();

	GLuint getShaderProgram() { return m_nShaderProgram; }


	void setUniformOneInt(string valName,int value);
	void setUniformOneUInt(string valName, uint value);
	void setUniformOneFloat(string valName, float value);
	void setUniform4F(string valName, uniform_fv fv);

	void setUniform4MatrixFV(string valName, mat4 matrix);
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

	//uniformֵ�洢
	bool m_bIsShaderProgramUsed;//shaderProgram ��use
};


#endif // _GLProgram_H_
