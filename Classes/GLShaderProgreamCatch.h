#ifndef _GLShaderProgreamCatch_H_
#define _GLShaderProgreamCatch_H_
#include"Include.h"
#include<map>

enum GLShaderProgramType{
	ShaderProgramType_Default,



	ShaderProgramType_MaxNum,
};

class GLProgram;

class GLShaderProgreamCatch {
public:
	static GLShaderProgreamCatch* getInstance();

	GLProgram* getGLProgream(GLShaderProgramType type);
private:
	//string load
	GLShaderProgreamCatch();
	~GLShaderProgreamCatch();

	void init();

	void loadShaderFile(GLProgram * p, std::string vertexShaderFile, std::string fragmentShaderFile);
private:
	static GLShaderProgreamCatch* m_pInstance;
	std::map<GLShaderProgramType, GLProgram*> m_ProgramList;
};



#endif // !_GLShaderCatch_H_

