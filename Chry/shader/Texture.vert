#version 330 core
layout (location = 0) in vec4 aPosition;

out vec4 uColor;
out vec2 uTexCoords;

uniform mat4 uViewProjectionMatrix = mat4(1.0f);
uniform mat4 uTransform = mat4(1.0f);

uniform vec4 Color = vec4(1.0f);
uniform vec2 TexCoords = vec2(1.0f);

void main()
{
    gl_Position = uViewProjectionMatrix * uTransform * aPosition;
    uColor = Color;
    uTexCoords = TexCoords;
}
