#version 330 core
struct Material{
	float ambientStrenght;
	float diffuseStrenght;
	float specularStrength;
	float shininess;
};

struct Light{
	vec4 lightPos; 
	vec4 lightColor;
	vec4 viewPos;
};

in vec4 Color;
in vec2 Texcoord;
in vec3 Normal;
in vec4 FragPos;

uniform int useLight = 1;
uniform Light light;
uniform Material material; 

uniform int useTexture = 0;
uniform sampler2D image;

out vec4 fragColor;

vec4 ambientCalc();
vec4 diffuseCalc();
vec4 specularCalc();
vec4 CalculationLight();
vec4 CalculationTexture();

void main(){
	vec4 CalcValue = vec4(1.0);
	if(useTexture == 1)
	{
		CalcValue *= CalculationTexture();
	}
	if(useLight == 1)
	{
		CalcValue *= CalculationLight();
	}
	fragColor = CalcValue * Color;
}

vec4 ambientCalc()
{
	vec4 ambient = light.lightColor * material.ambientStrenght;
	return ambient;
}

vec4 diffuseCalc()
{
	vec3 normal = normalize(Normal);
	vec4 fragToLightDir = normalize(light.lightPos - FragPos);
	float diff = max(dot(vec4(normal,1.0),fragToLightDir),0.0f);
	vec4 diffuse = (diff * material.diffuseStrenght) * light.lightColor;
	return diffuse;
}

vec4 specularCalc()
{
	vec3 normal = normalize(Normal);
	vec3 fragToViewDir = vec3(normalize(light.viewPos - FragPos));
	vec4 lightToFragDir = normalize(FragPos - light.lightPos);
	vec3 reflectDir = reflect(lightToFragDir.xyz,normal);
	float spec = pow(max(dot(fragToViewDir,reflectDir),0.0f),material.shininess);
	vec4 specualar = material.specularStrength * spec * light.lightColor;
	return specualar;
}

vec4 CalculationLight()
{
	vec4 res = ambientCalc() + diffuseCalc() + specularCalc();
	return res;
}

vec4 CalculationTexture()
{
	vec4 res = texture(image,Texcoord);
	return res;
}