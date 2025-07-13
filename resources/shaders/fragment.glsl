#version 330 core
in vec3 ourColor;
out vec4 FragColor;

uniform float time;

void main()
{
    vec3 rainbowColor = ourColor * (0.5 + 0.5 * sin(time + gl_FragCoord.x * 0.01));
    FragColor = vec4(rainbowColor, 1.0);
}