$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// The generic combiner with per-pixel two-sided lighting (vs_vp_ff2s's draws: the back face lit with the reversed
// normal, as the faithful pair's back colours are): fs_px_stage.sh.
#define PX_TWO_SIDED 1
#include <bgfx_shader.sh>
#include "fs_px_stage.sh"
