$input v_color0, v_fog, v_texcoord0

// The stage fragment shader for the vertex programs with three outputs (simple_proximity: no specular colour):
// fs_vp_stage.sh.
#define FS_NO_SPECULAR 1
#include <bgfx_shader.sh>
#include "fs_vp_stage.sh"
