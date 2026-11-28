$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// A tinted co-op Hulk (wskin2, docs/multiplayer.md 6.5 and 20): fs_px_char.sc's program (the characters' look, u_rmChar)
// with a tint at the combiner's output (fs_px_stage.sh PX_TINT, u_rmTint), for the draws of an extra Hulk who wears
// player 0's skin (a mission's forced skin): run/app/lighting.cpp, the module's tag (gfx/skins.c).
#define PX_CHAR 1
#define PX_TINT 1
#include <bgfx_shader.sh>
#include "fs_px_stage.sh"
