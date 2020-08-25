#ifndef _GLProgram_H_
#define _GLProgram_H_

#include<vector>
#include<queue>
#include"ShaderDefaultValue.h"
#define NOT_USE_CUSTOM_MATRIX
#include "../Include/Include.h"

#if defined(NOT_USE_CUSTOM_MATRIX)
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#endif

#include "../Utility/glmath/glmathlib.h"

using std::string;
using std::cout;
using std::endl;

class GLProgram{
public:
	GLProgram();
public:
	void createShader(string ShaderFile , unsigned int shaderType);
	void createProgram();
	void useShaderProgream();

	GLuint getShaderProgram() { return m_nShaderProgram; }

	void updateUniform();

	void setUniformOneInt(string valName,int value);
	void setUniformOneUInt(string valName, uint value);
	void setUniformOneFloat(string valName, float value);
	void setUniform4F(string valName, uniform_fv fv);
	void setUniform4MatrixFV(string valName, glm::mat4 matrix);
	void setUniform4MatrixFV(string valName, glmath::mat4 matrix);
private:
	string readFile(std::string path);
	void ShaderCompiledLog(GLuint shaderID);
	void releseShader();
private:
	GLuint m_glVertexShader;
	GLuint m_glFragmentShader;
	GLuint m_nShaderProgram;


	//uniform÷µ¥Ê¥¢
	bool m_bIsShaderProgramUsed;//shaderProgram ±ªuse
};


#endif // _GLProgram_H_
