$input a_position, a_normal, a_color0, a_color1, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3
$output v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Per-pixel lighting of the fixed-function vertex path: vs_px_ff.sh.
#include "vs_px_ff.sh"
