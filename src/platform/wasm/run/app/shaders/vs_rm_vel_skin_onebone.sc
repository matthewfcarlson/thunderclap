$input a_position, a_indices
$output v_texcoord0, v_texcoord1

// TAA's motion vectors (wperf1): vs_rm_vel.sh for the skin_onebone vertex programs
#define VEL_SKIN 2
#include "vs_rm_vel.sh"
