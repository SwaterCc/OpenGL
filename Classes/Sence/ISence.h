#ifndef _ISence_h_
#define _ISence_h_

class ObjectBase;


class ISence
{
public:
	virtual void init() = 0;

	virtual void addToRenderingList(ObjectBase* object);
	virtual void removeObjectOfTarget(int tag);

};

#endif // !_Sence_h_

