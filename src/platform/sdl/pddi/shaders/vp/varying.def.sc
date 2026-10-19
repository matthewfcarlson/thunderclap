// Varyings and vertex attributes of the vertex-program shaders (docs/shaders.md).
// Outputs, one per NV2A output register a program writes: oD0/oD1 -> v_color0/1, oFog.x -> v_fog,
// oT0..oT3 -> v_texcoord0..3; oPos -> gl_Position (clip space, before the Xbox screen-space transform).
vec4  v_color0    : COLOR0    = vec4(1.0, 1.0, 1.0, 1.0);
vec4  v_color1    : COLOR1    = vec4(0.0, 0.0, 0.0, 0.0);
float v_fog       : FOG       = 0.0;
vec4  v_texcoord0 : TEXCOORD0 = vec4(0.0, 0.0, 0.0, 1.0);
vec4  v_texcoord1 : TEXCOORD1 = vec4(0.0, 0.0, 0.0, 1.0);
vec4  v_texcoord2 : TEXCOORD2 = vec4(0.0, 0.0, 0.0, 1.0);
vec4  v_texcoord3 : TEXCOORD3 = vec4(0.0, 0.0, 0.0, 1.0);

// Attributes, as the vertex declaration gives them (missing components read (0, 0, 0, 1) on both the NV2A and
// a bgfx backend). Colours are D3DCOLOR bytes, which a bgfx Uint8-normalised attribute delivers as B, G, R, A.
vec3 a_position  : POSITION;
vec3 a_normal    : NORMAL;
vec4 a_color0    : COLOR0;
vec4 a_color1    : COLOR1;
vec4 a_indices   : BLENDINDICES;
vec4 a_weight    : BLENDWEIGHT;
vec4 a_tangent   : TANGENT;
vec2 a_texcoord0 : TEXCOORD0;
vec2 a_texcoord1 : TEXCOORD1;
vec2 a_texcoord2 : TEXCOORD2;
vec2 a_texcoord3 : TEXCOORD3;
