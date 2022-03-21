#version 330 core

layout (location = 0) out vec4 aColor;

in vec4 Color;

void main()
{
    aColor = Color;
}
