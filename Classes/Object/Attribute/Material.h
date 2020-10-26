#ifndef _Material_h_
#define _Material_h_

#include "../../Include/Include.h"
#include "AttributeModule.h"

class Material :public AttributeModule
{
public:
	Material();
	virtual void update() override;
public:
	////������ɫ
	//glmath::vec4 color;
	//������ǿ��ϵ��
	float ambientStrenght;
	//������ǿ��ϵ��
	float diffuseStrenght;
	//���淴��ǿ��ϵ��
	float specularStrength;
	//�����
	float shininess;
};



#endif
