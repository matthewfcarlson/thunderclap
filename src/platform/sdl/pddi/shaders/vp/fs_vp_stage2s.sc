$input v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_bcolor0, v_bcolor1

// The generic texture-stage combiner for vs_vp_ff2s (two-sided lighting, G5): fs_vp_stage.sh with the colours
// picked by the face's orientation.
#define FS_TWO_SIDED 1
#include <bgfx_shader.sh>
#include "fs_vp_stage.sh"
