// Varyings and attributes of the full-screen pass shaders (the framebuffer effects extension, bgfx_effects.cpp):
// a position in the target's pixels and up to four texture coordinate sets (normalised), as the game's
// pre-transformed DrawVerticesUP quads carry them (XYZRHW + TEX1..4).
vec2 v_texcoord0 : TEXCOORD0 = vec2(0.0, 0.0);
vec2 v_texcoord1 : TEXCOORD1 = vec2(0.0, 0.0);
vec2 v_texcoord2 : TEXCOORD2 = vec2(0.0, 0.0);
vec2 v_texcoord3 : TEXCOORD3 = vec2(0.0, 0.0);

vec3 a_position  : POSITION;
vec2 a_texcoord0 : TEXCOORD0;
vec2 a_texcoord1 : TEXCOORD1;
vec2 a_texcoord2 : TEXCOORD2;
vec2 a_texcoord3 : TEXCOORD3;
