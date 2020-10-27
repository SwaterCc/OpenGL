#version 330 core
in vec4 uColor;
in vec2 TexCoord;

out vec4 gl_Color;

void main()
{
	gl_Color = uColor;
}