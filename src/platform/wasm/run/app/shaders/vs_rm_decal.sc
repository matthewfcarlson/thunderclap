$input a_position, a_normal, a_color0, a_color1, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3
$output v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Lasting decals (wdecal1, run/app/decals.cpp): the game's world-hit decals, pulled a little towards the camera
// (vs_px_ff.sh PX_DCPULL); fs_px_decal.sc fades them where they float.
#define PX_DCPULL 1
#include "vs_px_ff.sh"
