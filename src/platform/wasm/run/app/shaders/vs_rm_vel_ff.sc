$input a_position
$output v_texcoord0, v_texcoord1

// TAA's motion vectors (wperf1): vs_rm_vel.sh for the ff vertex programs
#define VEL_SKIN 0
#include "vs_rm_vel.sh"
