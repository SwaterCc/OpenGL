#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aNormal;

out vec2 TexCoord;
out vec4 uColor;
out vec3 uNormal;
out vec4 fragPos;

uniform mat4 model;
uniform mat4 mvp_mat;
uniform vec4 _uniformColor;

void main()
{
	gl_Position = mvp_mat * vec4(aPos.x,aPos.y,aPos.z,1.0);
	uColor = aColor * _uniformColor;
	TexCoord = aTexCoord;
	fragPos = model * vec4(aPos.x,aPos.y,aPos.z,1.0);
	uNormal = mat3(transpose(inverse(model))) * aNormal;
}