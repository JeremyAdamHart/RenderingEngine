#version 410
#define M_PI 3.1415926535897932384626433832795

// first output is mapped to the framebuffer's colour index by default
out vec4 PixelColour;

in vec3 ModelPosition;
in vec2 FragmentTexCoord;
in vec3 FragmentNormal;

uniform vec3 camera_position;

uniform sampler2D colorTexture;

vec3 lightPos = vec3(1000.0, 1000.0, 1000.0);
uniform float ks = 0.5;
uniform float kd = 0.4;
uniform float alpha = 5.0;
uniform float ka = 0.3;

float torranceSparrowLighting(vec3 normal, vec3 position, vec3 viewPosition)
{
	vec3 viewer = normalize(viewPosition - position);
	vec3 light = normalize(lightPos);
	vec3 h = normalize(viewer + light);

	return ks*(alpha+2.0)*(0.5/M_PI) * clamp(pow(dot(normal, h), alpha), 0.0, 1.0)
			+ kd*clamp(dot(normal, light), 0.0, 1.0) + ka;
}

void main(void)
{
 	vec3 color = torranceSparrowLighting(normalize(FragmentNormal), ModelPosition, camera_position)
 	*texture(colorTexture, FragmentTexCoord).rgb;

 	PixelColour = vec4(color, 1);
}
