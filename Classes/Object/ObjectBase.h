#ifndef _ObjectBase_h_
#define _ObjectBase_h_
#include<iostream>
#include "../Framework/RenderPipelineManager.h"
#include "../Framework/GLProgram.h"
#include "../Include/makeFileInclude.h"
#include "../Framework/GLShaderProgreamCatch.h"
#include "VertexConfig.h"
#include "../Utility/glmath/glmathlib.h"
#include "../Camera/Camera.h"

class ObjectBase : public CameraTransfomationInterface
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

	virtual void draw();
	virtual void update();
	int& getRenderTag() { return _nRenderTag; }

	//model±ä»»

	virtual void setScale(float s) 
	{
		m_fScale = s; 
	}
	virtual float getScale() 
	{
		return m_fScale; 
	}
	virtual void setRotate(float r, glmath::vec3 axle) 
	{
		m_fRadio = r;
		m_objRotateAxle = axle; 
	}
	virtual float getRotateAngle()
	{
		return m_fRadio;
	}
	virtual glmath::vec3 getRotateAxle()
	{
		return m_objRotateAxle;
	}
	virtual void setPosition(glmath::vec3 pos)
	{
		m_objPosition = pos;
	}
	virtual glmath::vec3 getPosition()
	{
		return m_objPosition;
	}
	virtual float getPosX()
	{
		return m_objPosition.x;
	}
	virtual float getPosY()
	{
		return m_objPosition.y;
	}
	virtual float getPosZ()
	{
		return m_objPosition.z;
	}
protected:
	virtual void init() {}
	virtual void setProgram(GLProgram * GLProgram) { 
		m_ShaderProgram = GLProgram; 
		m_uProgramTarget = m_ShaderProgram->getShaderProgram();
	}

	virtual glmath::mat4 getModel() { return m_pObjModelMatrix; }
	virtual void setMVPMatrix(glmath::mat4 mvp) { m_ObjMVPMatrix = mvp; }
	virtual void updateUniformOfShader();
protected:
	int _nRenderTag;

	GLuint m_uVAO;
	VertexConfig * m_VertexConfig;
	GLProgram * m_ShaderProgram;
	GLuint m_uProgramTarget;
	Point m_AnchorPoint;
private:
	glmath::mat4 m_pObjModelMatrix;
	glmath::mat4 m_ObjMVPMatrix;
	float m_fScale;
	float m_fRadio;
	glmath::vec3 m_objRotateAxle;
	glmath::vec3 m_objPosition;
	bool isDrity;
};



#endif // !_ObjectBase_h_
