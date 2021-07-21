// #version 450 core
// #version 330 core

// in vec3 outColor;

// out vec4 color;
// void main() {
//     color = vec4(outColor, 1.0f);
// }

#version 330 core
in vec4 oColor;
out vec4 fragColor;
void main()
{
    fragColor = oColor;
}