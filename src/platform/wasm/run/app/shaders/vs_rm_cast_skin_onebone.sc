$input a_position, a_normal, a_indices, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3
$output v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// A shadow caster (wr3a): the skin program into the sun's view (vs_px_skin.sh).
#define PX_CAST 1
#define PX_ONEBONE 1
#include "vs_px_skin.sh"
