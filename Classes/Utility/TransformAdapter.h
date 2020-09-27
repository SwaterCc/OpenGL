#ifndef _TransformAdapter_h_
#define _TransformAdapter_h_
#include "../Include/data.h"
#include "../Object/Node/ObjectBase.h"

#define tav3(x,y,z) (glmath::vec3(x,y,z))
#define _SOP(target,pos) (TransformAdapter::getInstance()->setPosition(target,pos))
#define _SOS(target,pos) (TransformAdapter::getInstance()->setScale(target,pos))
#define _SOR(target,pos) (TransformAdapter::getInstance()->setRotate(target,pos))

class TransformAdapter
{
public:
	static TransformAdapter * getInstance();
public:
	void setPosition(ObjectBase * target, glmath::vec3 pos);
	void setScale(ObjectBase * target, glmath::vec3 scale);
	void setScale(ObjectBase * target, float scale);
	void setRotate(ObjectBase * target, glmath::vec3 rotate);
private:
	TransformAdapter() = default;
	static TransformAdapter * m_pInstance;
};


#endif // 
