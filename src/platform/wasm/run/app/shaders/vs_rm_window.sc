$input a_position, a_normal, a_color0, a_color1, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3
$output v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Window interiors (wlook0, docs/look.md): a building draw again, as a decal over itself (vs_px_ff.sh).
#define PX_DECAL 1
#include "vs_px_ff.sh"
