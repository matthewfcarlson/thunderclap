$input v_color0, v_fog, v_texcoord0

// The generic combiner for the vertex programs with three outputs (simple_proximity: no specular colour, one uv
// set): fs_vp_stage.sh.
#define FS_NO_SPECULAR 1
#define FS_UV_SETS 1
#include <bgfx_shader.sh>
#include "fs_vp_stage.sh"
