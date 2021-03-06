#ifndef _ISence_h_
#define _ISence_h_

#include "../Utility/TransformAdapter.h"
#include "../Framework/LightManager.h"

class Camera;

class ISence
{
public:
	ISence();
	virtual void init() = 0;

	virtual void addToRenderingList(ObjectBase* object);
	virtual void removeObjectOfTarget(int tag);

	virtual void addToRenderingList(Light * object);
	virtual void removeObjectOfTarget(Light* object);
	
	virtual void registerCamera(Camera* object);
	virtual void registerMainCamera(Camera* object);
	virtual void unregisterCamera(Camera* object);

	virtual void setSenceBackgroundColor(glmath::vec4 color) { m_objSenceColor = color; }
	virtual glmath::vec4 getSenceBackgroundColor() { return m_objSenceColor; }
protected:
	glmath::vec4 m_objSenceColor;
};

#endif // !_Sence_h_

