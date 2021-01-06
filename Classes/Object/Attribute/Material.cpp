#include "Material.h"
#include "color_define.h"
Material::Material():
	color(COLOR_RGB_WHITE),ambientStrenght(0.1f),diffuseStrenght(1.0f),specularStrength(1.0f),shininess(32),
	diffuseTex(nullptr),specularTex(nullptr)
{
}

void Material::update()
{
}
