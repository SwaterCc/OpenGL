#ifndef _Mesh_h_
#define _Mesh_h_

#include "AttributeModule.h"

class Mesh : public AttributeModule
{
public:
	virtual void update() override;
public:
	virtual void setIsPhotosensitive(int isPs);
	virtual int getIsPhotosensitive();
private:
	int m_bIsPhotosensitive;//�Ƿ�й�
};


#endif // !_Mesh_h_

