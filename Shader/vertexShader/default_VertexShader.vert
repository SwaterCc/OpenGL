#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoord;
out vec4 uColor;
uniform mat4 mvp_mat;
void main()
{
	//gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);
	gl_Position = mvp_mat * vec4(aPos.x,aPos.y,aPos.z,1.0);
	uColor = vec4(aColor.r,aColor.g,aColor.b,1.0);
	TexCoord = aTexCoord;
}