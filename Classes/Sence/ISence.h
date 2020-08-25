#ifndef _ISence_h_
#define _ISence_h_

class ObjectBase;
class Camera;

class ISence
{
public:
	virtual void init() = 0;

	virtual void addToRenderingList(ObjectBase* object);
	virtual void removeObjectOfTarget(int tag);

	virtual void registerCamera(Camera* object);
	virtual void registerMainCamera(Camera* object);
	virtual void unregisterCamera(Camera* object);
};

#endif // !_Sence_h_

