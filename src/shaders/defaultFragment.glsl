#version 330 core

in vec4 fColor;
in vec2 fTexCoords;
uniform sampler2D TEX_SAMPLER;

out vec4 color;

void main()
{
    //float noise = fract(sin(dot(fColor.xy, vec2(12.9898, 78.233))) * 43758.5453);
    color = texture(TEX_SAMPLER, fTexCoords) ;
}