$input v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3

// The generic texture-stage combiner for the vertex programs with all seven outputs (the fixed-function program,
// skin, skin_onebone): the stages as uniforms (fs_vp_stage.sh). Draws whose combiner key has a generated program
// (fs_cmb_<hash>.sc) use that instead.

#include <bgfx_shader.sh>
#include "fs_vp_stage.sh"
