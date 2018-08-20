#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 TexCoord;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
out vec4 color;

void main(){
	gl_Position = projection * view * model * vec4(pos, 1.0f);
	color = vec4(0.5f, 0.5f, 0.5f, 1.0f);
}