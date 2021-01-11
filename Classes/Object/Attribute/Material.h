#ifndef _Material_h_
#define _Material_h_

#include "../../Include/Include.h"
#include "AttributeModule.h"
#include "../Texture/Texture2D.h"

class Material :public AttributeModule
{
public:
	Material();
	virtual void update() override;
public:
	//������ɫ
	glmath::vec4 color;
	//������ǿ��ϵ��
	float ambientStrenght;
	//������ǿ��ϵ��
	float diffuseStrenght;
	//���淴��ǿ��ϵ��
	float specularStrength;
	//�����
	float shininess;
	//��������ͼ�����ʱ����ͼ��
	Texture2D* diffuseTex;
	//���淴����ͼ
	Texture2D* specularTex;
	
};



#endif
