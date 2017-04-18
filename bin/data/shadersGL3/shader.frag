#version 150

// this is how we receive the texture
uniform sampler2DRect tex0;
uniform sampler2DRect tex1;
uniform sampler2DRect tex3;
uniform sampler2DRect tex4;

in vec2 texCoordVarying;

out vec4 outputColor;
 
void main()
{
    outputColor = texture(tex0, texCoordVarying);
	//vec4 tex = texture ( tex0, texCoordVarying );
	//gl_FragColor = vec4(tex.r,tex.g,tex.b,1.0);
}
