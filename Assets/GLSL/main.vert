#version 330 core
layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;
layout (location = 2) in vec2 vTexCoords;

out vec4 mColor;
out vec2 mTexCoords;

uniform mat4 uViewProjectionMatrix = mat4(1.0f);
uniform mat4 uTransform = mat4(1.0f);

void main()
{
    gl_Position = uViewProjectionMatrix * uTransform * vPosition;
    mColor = vColor;
    mTexCoords = vTexCoords;
}
