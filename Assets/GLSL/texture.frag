#version 330 core

layout (location = 0) out vec4 vColor;

in vec4 mColor;
in vec2 mTexCoords;

uniform sampler2D mTexture;

void main()
{
    // vColor = vec4(mColor * 0.5f + 0.5f);
    vColor = texture(mTexture, mTexCoords);
}
