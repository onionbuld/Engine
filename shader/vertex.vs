#version 330 core
layout (location = 0) in vec3 pos;

out vec4 color;

void main(){
	gl_Position = vec4(pos, 1.0f);
	color = vec4(0.5f, 0.5f, 0.5f, 1.0f);
}