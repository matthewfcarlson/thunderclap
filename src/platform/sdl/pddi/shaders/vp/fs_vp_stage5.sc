$input v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1

// The generic combiner for the vertex programs with five outputs (refract, skin_refract): fs_vp_stage.sh.
#define FS_UV_SETS 2
#include <bgfx_shader.sh>
#include "fs_vp_stage.sh"
