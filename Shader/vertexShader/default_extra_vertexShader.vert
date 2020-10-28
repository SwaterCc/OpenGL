#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texcoord;
layout (location = 3) in vec3 normal;

out vec4 Color;
out vec2 Texcoord;
out vec3 Normal;
out vec4 FragPos;

uniform mat4 model;
uniform mat4 mvp_mat;
uniform vec4 _uniformColor;
uniform mat4 normalMatrix;

void main(){
	gl_Position = mvp_mat * vec4(position,1.0f);
	Color = _uniformColor * color;
	Texcoord = texcoord;
	
	FragPos = model * vec4(position,1.0f);
	//vec4 tmp = normalMatrix*vec4(normal,1.0f);
	vec3 tmp = mat3(transpose(inverse(model))) * normal;
	Normal = tmp;
}