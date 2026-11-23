$input a_position, a_indices, a_weight
$output v_texcoord0, v_texcoord1

// TAA's motion vectors (wperf1): vs_rm_vel.sh for the skin vertex programs
#define VEL_SKIN 1
#include "vs_rm_vel.sh"
