$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// The characters' program (whulk1, docs/lighting.md "Characters"): the skin programs' draws (the Hulk, every co-op
// Hulk) with the generic combiner and the characters' look (fs_px_stage.sh PX_CHAR: detail normals, wrapped light,
// the rim; u_rmChar), when Video Options > Character Lighting is Enhanced.
#define PX_CHAR 1
#include <bgfx_shader.sh>
#include "fs_px_stage.sh"
