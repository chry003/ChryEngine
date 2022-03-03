#version 330 core
layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec4 vColor;
layout (location = 2) in vec2 vTexCoords;

out vec4 mColor;
out vec2 mTexCoords;

void main()
{
    gl_Position = vec4(vPosition, 1.0f);
    mColor = vColor;
    mTexCoords = vTexCoords;
}
