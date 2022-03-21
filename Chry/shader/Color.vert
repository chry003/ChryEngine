#version 330 core
layout (location = 0) in vec4 aPosition;

out vec4 Color;

uniform mat4 uViewProjectionMatrix = mat4(1.0f);
uniform mat4 uTransform = mat4(1.0f);
uniform vec4 uColor = vec4(1.0f);

void main()
{
    gl_Position = uViewProjectionMatrix * uTransform * aPosition;
    Color = uColor;
}
