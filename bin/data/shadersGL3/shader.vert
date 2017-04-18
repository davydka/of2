#version 150

// these are for the programmable pipeline system and are passed in
// by default from OpenFrameworks
uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;

// this is something we're creating for this shader
out vec2 texCoordVarying;

// this is coming from our C++ code
uniform float mouseX;

uniform sampler2DRect tex1;

void main()
{
	// get the position of the vertex relative to the modelViewProjectionMatrix
    vec4 modifiedPosition = modelViewProjectionMatrix * position;

	// we need to scale up the values we get from the texture
    float scale = 100;

	// here we get the red channel value from the texture
    // to use it as vertical displacement
    float displacementY = texture(tex1, texcoord).r;

    // use the displacement we created from the texture data
    // to modify the vertex position
	modifiedPosition.y += displacementY * scale;
	
    // this is the resulting vertex position
    gl_Position = modifiedPosition;

    // pass the texture coordinates to the fragment shader
    texCoordVarying = texcoord;


    // here we move the texture coordinates
    //texCoordVarying = vec2(texcoord.x + mouseX, texcoord.y);

    // send the vertices to the fragment shader
	//gl_Position = modelViewProjectionMatrix * position;
}
