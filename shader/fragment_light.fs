#version 330 core
out vec4 colorFS;

uniform vec3 ObjectColor;
uniform vec3 LightColor;

void main(){
	colorFS = vec4(LightColor * ObjectColor, 1.0f);
}