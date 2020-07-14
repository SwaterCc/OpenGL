#ifndef _ObjectBase_h_
#define _ObjectBase_h_
#include<iostream>
#include "../Framework/RenderPipelineManager.h"
#include "../Framework/GLProgram.h"
#include "../Include/makeFileInclude.h"
#include "../Framework/GLShaderProgreamCatch.h"
enum {
	VertexAttrib_Position = 0,
	VertexAttrib_Color = 1,
	VertexAttrib_Texture = 2,
	VertexAttrib_MaxNum,
};

class ObjectBase
{
public:
	static ObjectBase* create();
	ObjectBase();
	virtual ~ObjectBase();



	virtual void addToRenderingList() 
	{
		RenderPiplineManager::getInstance()->addObjectToList(this,_nRenderTag);
	}

	virtual void removeToRenderingList()
	{
		RenderPiplineManager::getInstance()->removeObjectAtIndex(getRenderTag());
	}

	virtual void draw() {}
	
	int& getRenderTag() { return _nRenderTag; }
protected:
	virtual void setProgram(GLProgram * GLProgram) { 
		m_ShaderProgram = GLProgram; 
		m_uProgramTarget = m_ShaderProgram->getShaderProgram();
	}
protected:

	virtual void init() {}

	
	int _nRenderTag;

	GLuint m_uVBO, m_uVAO;
	GLProgram * m_ShaderProgram;
	GLuint m_uProgramTarget;

	Point m_AnchorPoint;
};



#endif // !_ObjectBase_h_
