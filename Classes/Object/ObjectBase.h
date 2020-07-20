#ifndef _ObjectBase_h_
#define _ObjectBase_h_
#include<iostream>
#include "../Framework/RenderPipelineManager.h"
#include "../Framework/GLProgram.h"
#include "../Include/makeFileInclude.h"
#include "../Framework/GLShaderProgreamCatch.h"
#include "VertexConfig.h"


class ObjectBase
{
public:
	static ObjectBase* create();
	ObjectBase();
	virtual ~ObjectBase();

	virtual void setVertexConfig(VertexConfig * config) { m_VertexConfig = config; }

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

	GLuint m_uVAO;
	VertexConfig * m_VertexConfig;
	GLProgram * m_ShaderProgram;
	GLuint m_uProgramTarget;
	Point m_AnchorPoint;
};



#endif // !_ObjectBase_h_
