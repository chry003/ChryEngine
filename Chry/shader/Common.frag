#version 330 core

layout (location = 0) out vec4 aColor;

in vec4 uColor;
in vec2 uTexCoords;

uniform sampler2D uTexture;
uniform bool uTextured = false;

void main()
{
    if(uTextured)
        aColor = texture(uTexture, uTexCoords);
    else
        aColor = uColor;
}

