#version 330 core

layout (location = 0) out vec4 aColor;

in vec4 uColor;

void main()
{
    aColor = vec4(uColor * 0.5f + 0.5f);
}
