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
	////物体颜色
	//glmath::vec4 color;
	//环境光强度系数
	float ambientStrenght;
	//漫反射强度系数
	float diffuseStrenght;
	//镜面反射强度系数
	float specularStrength;
	//反光度
	float shininess;
};



#endif
