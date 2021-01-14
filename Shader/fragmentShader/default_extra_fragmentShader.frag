#version 330 core
struct Material{
	float ambientStrenght;
	float diffuseStrenght;
	float specularStrength;
	float shininess;
	sampler2D diffuseTex;
	sampler2D specularTex;
};

struct ParallelLight{
	vec4 lightDir; 
	vec4 lightColor;
};

struct PointLight{
	vec3 position;
	float constant;
	float linear;
	float quadratic;
	vec4 lightColor;
};

struct Spotlight{
	vec3 position;
	vec3 lightDir;
	float cutOff;
	vec4 lightColor;
};

in vec4 Color;
in vec2 Texcoord;
in vec3 Normal;
in vec4 FragPos;

uniform int useLight = 0;
uniform Material material; 
uniform vec3 cameraPos;

uniform ParallelLight parallelLight;
uniform PointLight pointLight;
uniform Spotlight spotlight;

out vec4 fragColor;

vec4 CalculationLight();


void main(){
	vec4 CalcValue = vec4(1.0);

	if(useLight == 1)
	{
		CalcValue *= CalculationLight();
	}
	fragColor = CalcValue * Color;
}

vec4 ParallelLightCalc()
{
	vec4 paralleLightValue;
	//环境光
	vec4 ambient = parallelLight.lightColor * material.ambientStrenght;
	ambient *= vec4(texture(material.diffuseTex,Texcoord).rgb,1);
	
	//漫反射
	vec3 normal = normalize(Normal);
	vec4 fragToLightDir = normalize(-parallelLight.lightDir);
	float diff = max(dot(vec4(normal,1.0),fragToLightDir),0.0f);
	vec4 diffuse = (diff * material.diffuseStrenght) * parallelLight.lightColor;
	diffuse *= vec4(texture(material.diffuseTex,Texcoord).rgb,1);
	//镜面反射
	vec4 lightDir = normalize(parallelLight.lightDir);
	vec3 fragToViewDir = vec3(normalize(vec4(cameraPos,1) - FragPos));
	vec3 reflectDir = reflect(lightDir.xyz,normal);
	float spec = pow(max(dot(fragToViewDir,reflectDir),0.0f),material.shininess);
	vec4 specualar = material.specularStrength * spec * parallelLight.lightColor;
	specualar *= vec4(texture(material.specularTex,Texcoord).rgb,1);
	
	paralleLightValue = ambient + diffuse + specualar;
	return paralleLightValue;
}

vec4 PointLightCalc()
{
	vec4 lightDir = normalize(FragPos-vec4(pointLight.position,1));
	vec3 normal = normalize(Normal);
	float diff = max(dot(-lightDir.xyz,normal),0.0f);
	vec4 diffuse = diff * pointLight.lightColor * material.diffuseStrenght * vec4(texture(material.diffuseTex,Texcoord).rgb,1);
	//镜面反射
	vec3 fragToViewDir = vec3(normalize(vec4(cameraPos,1) - FragPos));
	vec3 reflectDir = reflect(lightDir.xyz,normal);
	float spec = pow(max(dot(fragToViewDir,reflectDir),0.0f),material.shininess);
	vec4 specualar = material.specularStrength * spec * pointLight.lightColor * vec4(texture(material.specularTex,Texcoord).rgb,1);
	//环境光
	 vec4 ambient = material.ambientStrenght * pointLight.lightColor * vec4(texture(material.diffuseTex,Texcoord).rgb,1);
	//衰减	
	float distance = length(FragPos-vec4(pointLight.position,1));
	float attenuation = 1.0f / (pointLight.constant + pointLight.linear * distance +pointLight.quadratic * distance * distance);

	return (ambient+diffuse+specualar)*attenuation;
	//return pointLight.lightColor;
}

vec4 SpotlightCalc()
{
	vec4 lightToFragDir = normalize(FragPos-vec4(spotlight.position,1));
	float theta = dot(-lightToFragDir,normalize(vec4(-spotlight.lightDir,0)));
	if (theta > spotlight.cutOff )
	{//漫反射
		vec3 normal = normalize(Normal);
		float diff = max(dot(-lightToFragDir.xyz,normal),0);
		vec4 diffuse = diff * spotlight.lightColor * material.diffuseStrenght * texture(material.diffuseTex,Texcoord);
	//镜面反射
		vec4 fragToViewDir = normalize(vec4(cameraPos,1)-FragPos);
		vec3 reflectDir = reflect(lightToFragDir.xyz,normal);
		float spec = max(dot(fragToViewDir.xyz,reflectDir),0);
		vec4 specualar = spec * material.specularStrength*spotlight.lightColor*texture(material.specularTex,Texcoord);
		return diffuse + specualar ;
	}	
	else
		return vec4(0);
}


vec4 CalculationLight()
{
	vec4 res = PointLightCalc()+ParallelLightCalc()+SpotlightCalc();
	//vec4 res = SpotlightCalc();
	return res;
}
