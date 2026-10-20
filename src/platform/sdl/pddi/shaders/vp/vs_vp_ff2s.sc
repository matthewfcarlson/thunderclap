$input a_position, a_normal, a_color0, a_color1, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3
$output v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_bcolor0, v_bcolor1

// The fixed-function vertex path with two-sided lighting (G5): drawn instead of vs_vp_ff.sc only while a lit
// shader draws two-sided (D3DRS_TWOSIDEDLIGHTING, FUN_00329f70); the back face's colours as two more outputs, which
// fs_vp_stage2s.sc picks by the face's orientation. vs_vp_ff.sc (proven) is unchanged.
#define FF_TWO_SIDED 1
#include "vs_vp_ff.sh"
