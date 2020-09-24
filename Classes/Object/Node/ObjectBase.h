#ifndef _ObjectBase_h_
#define _ObjectBase_h_
#include<iostream>
#include "../Attribute/VertexConfig.h"
#include "../Attribute/AttributeModule.h"
#include "../Attribute/Transform.h"
#include "../../Framework/RenderPipelineManager.h"
#include "../../Framework/GLProgram.h"
#include "../../Include/makeFileInclude.h"
#include "../../Framework/GLShaderProgreamCatch.h"
#include "../../Utility/glmath/glmathlib.h"
#include "../../Camera/Camera.h"
#define AnchorPoint_Center Point(0.5f,0.5f)

class ObjectBase : public CameraTransfomationInterface
{
public:
	static ObjectBase* create();
	ObjectBase();
	virtual ~ObjectBase();

	virtual void setVertexConfig(VertexConfig* config);

	virtual void addToRenderingList()
	{
		RenderPiplineManager::getInstance()->addObjectToList(this, _nRenderTag);
	}
	

	virtual void removeToRenderingList()
	{
		RenderPiplineManager::getInstance()->removeObjectAtIndex(getRenderTag());
	}

	virtual void draw();
	virtual void update();
	int& getRenderTag() { return _nRenderTag; }

	//model±ä»»
	virtual Transform & getTransform() 
	{
		return transform; 
	}

	virtual void setProgram(GLProgram* GLProgram) {
		m_ShaderProgram = GLProgram;
		m_uProgramTarget = m_ShaderProgram->getShaderProgram();
	}

protected:
	virtual void init() {}
	virtual void setMVPMatrix(glmath::mat4 mvp) { m_ObjMVPMatrix = mvp; }
	virtual void updateUniformOfShader();
protected:
	int _nRenderTag;

	GLuint m_uVAO;
	VertexConfig * m_VertexConfig;
	GLProgram * m_ShaderProgram;
	GLuint m_uProgramTarget;
	Point m_AnchorPoint;

	glmath::mat4 m_ObjMVPMatrix;
	Transform transform;
private:
	bool isDrity;
};



#endif // !_ObjectBase_h_
