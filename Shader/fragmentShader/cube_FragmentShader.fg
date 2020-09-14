#version 330 core
in vec4 uColor;
in vec2 TexCoord;
in vec3 uNormal;
in vec4 fragPos;

out vec4 gl_Color;

uniform vec4 lightPos; 
uniform vec4 lightColor;
uniform vec4 viewPos;
uniform sampler2D Texture1;


void main()
{
	//gl_Color =  uColor;
	//环境光
	float ambientStrength = 0.1;
	vec4 ambient = ambientStrength * uColor;

	//漫反射
	vec3 norm = normalize(uNormal);
	vec3 lightDir = normalize(lightPos.xyz - fragPos.xyz);
	float diff = max(dot(norm,lightDir),0.0);
	vec4 diffuse = diff * vec4(1.0,1.0,1.0,1.0);

	//镜面反射
	float specularStength = 0.5;
	vec3 viewDir = vec3(normalize(viewPos - fragPos));
	vec3 reflectDir = reflect(-lightDir,norm);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),32);
	vec4 specular = specularStength * spec * lightColor;

	vec4 result=(ambient + diffuse + specular) * uColor;
	gl_Color = vec4(result.rgb,1.0);
}