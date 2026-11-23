$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// The generic combiner with per-pixel lighting (fs_px_stage.sh); fs_pxcmb_<hash>.sc are the generated ones.
#include <bgfx_shader.sh>
#include "fs_px_stage.sh"
