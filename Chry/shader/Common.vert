#version 330 core
layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoords;

out vec4 uColor;
out vec2 uTexCoords;

uniform mat4 uViewProjectionMatrix = mat4(1.0f);
uniform mat4 uTransform = mat4(1.0f);

void main()
{
    gl_Position = uViewProjectionMatrix * uTransform * aPosition;
    uColor = aColor;
    uTexCoords = aTexCoords;
}
