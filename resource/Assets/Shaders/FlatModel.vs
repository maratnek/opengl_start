//#version 450 core
//#version 330 core
//
//layout (location = 0) in vec3 Position;
//layout (location = 1) in vec3 Color;
//uniform mat4 projection;
//uniform mat4 view;
//uniform mat4 model;
//
//out vec3 outColor;
//
//void main() {
//    gl_Position = projection * view * model * vec4(Position, 1.0);
//    outColor = Color;
//}



#version 330 core
layout(location = 0) in vec4 aPosition;
layout(location = 1) in vec4 aColor;
out vec4 oColor;
void main()
{
gl_Position = aPosition;
oColor = aColor;
}