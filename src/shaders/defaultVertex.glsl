#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;


out vec4 fColor;

uniform float u_Time;


void main()
{
    fColor = aColor;
    gl_Position = vec4(aPos.x + cos(u_Time), aPos.yz, 1.0f);

}