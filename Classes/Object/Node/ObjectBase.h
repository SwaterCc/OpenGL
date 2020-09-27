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

class ObjectBase
{
public:
	static ObjectBase* create();
	ObjectBase();
	virtual ~ObjectBase();

	virtual void setVertexConfig(VertexConfig* config);

	virtual void addToRenderingList();
	virtual void removeToRenderingList();

	virtual void draw();
	virtual void update();
	int& getRenderTag();

	virtual Transform & getTransform();
	virtual void setProgram(GLProgram* GLProgram);

protected:
	virtual void init();
	virtual void updateUniformOfShader();
protected:
	GLuint m_uVAO;
	Point m_AnchorPoint;
	GLuint m_uProgramTarget;
	VertexConfig * m_VertexConfig;
	GLProgram * m_ShaderProgram;
	
	Transform transform;
private:
	
	bool isDrity;
	int _nRenderTag;
};



#endif // !_ObjectBase_h_
