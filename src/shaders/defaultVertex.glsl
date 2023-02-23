#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoords;


out vec4 fColor;
out vec2 fTexCoords;

uniform float u_Time;

uniform mat4 u_Projection;
uniform mat4 u_View;



void main()
{
    fColor = aColor;
    fTexCoords = aTexCoords;

    gl_Position = u_Projection * u_View * vec4(aPos.xyz * 300, 1.0f);

}