// Varyings of the app's per-pixel lighting shaders (run/app/lighting.cpp, docs/lighting.md). The faithful outputs
// (shaders/vp/varying.def.sc) less the two lit colours, which the fragment shader makes: v_pxbase / v_pxspec are the
// vertex's unlit colours (lit draws: the emissive + ambient part, and nothing), v_pxnormal the camera-space normal
// (xyz: its direction, w: its length as the faithful path uses it), v_pxpos the camera-space position.
vec4  v_pxbase    : COLOR0    = vec4(1.0, 1.0, 1.0, 1.0);
vec4  v_pxspec    : COLOR1    = vec4(0.0, 0.0, 0.0, 0.0);
float v_fog       : FOG       = 0.0;
vec4  v_texcoord0 : TEXCOORD0 = vec4(0.0, 0.0, 0.0, 1.0);
vec4  v_texcoord1 : TEXCOORD1 = vec4(0.0, 0.0, 0.0, 1.0);
vec4  v_texcoord2 : TEXCOORD2 = vec4(0.0, 0.0, 0.0, 1.0);
vec4  v_texcoord3 : TEXCOORD3 = vec4(0.0, 0.0, 0.0, 1.0);
vec4  v_pxnormal  : TEXCOORD4 = vec4(0.0, 0.0, 0.0, 0.0);
vec3  v_pxpos     : TEXCOORD5 = vec3(0.0, 0.0, 0.0);

vec3 a_position  : POSITION;
vec3 a_normal    : NORMAL;
vec4 a_color0    : COLOR0;
vec4 a_color1    : COLOR1;
vec4 a_indices   : BLENDINDICES;
vec4 a_weight    : BLENDWEIGHT;
vec2 a_texcoord0 : TEXCOORD0;
vec2 a_texcoord1 : TEXCOORD1;
vec2 a_texcoord2 : TEXCOORD2;
vec2 a_texcoord3 : TEXCOORD3;

// wgrass1 (run/app/grass.cpp): the grass blades' instances (bgfx's instance data: TEXCOORD7 down)
vec4 i_data0     : TEXCOORD7;
vec4 i_data1     : TEXCOORD6;
vec4 i_data2     : TEXCOORD5;
