#version 330 core

layout (location = 0) out vec4 aColor;

in vec4 uColor;
in vec2 uTexCoords;

uniform sampler2D uTexture;

void main()
{
    aColor = texture(uTexture, uTexCoords);
}
