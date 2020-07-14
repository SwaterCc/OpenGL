#version 330 core
in vec4 uColor;
in vec2 TexCoord;

out vec4 gl_Color;
uniform sampler2D Texture1;

void main()
{
	gl_Color =  texture(Texture1,TexCoord) * uColor;
}