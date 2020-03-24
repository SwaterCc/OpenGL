#version 330 core
//in vec4 vexOutColor;
in vec2 TexCoord;

out vec4 aColor;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
aColor = mix(texture(ourTexture1,TexCoord), texture(ourTexture2,TexCoord),0.9);
} 