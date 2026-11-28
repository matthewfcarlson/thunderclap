// Water (wwater1, docs/water.md; run/app/water.cpp): what the reflection pass needs from the water pass.
#pragma once
#include <stdint.h>

#include "pddi/draw_sink.h"

namespace rm {

// the draw is one of the game's water surfaces the water pass has taken this frame (its program is fs_px_water)
bool waterDraw(const hulk::pddi::DrawPacket& p);
// the ripples' constants (rm_water.sh's u_rmWater) of water draw p for the next draw: the reflection G-buffer's copy
void waterRippleUniforms(const hulk::pddi::DrawPacket& p);
// wlinux2: a copy of a water draw submitted again by another pass: its samplers (stages 4, 5) bound again
void waterRebind(const hulk::pddi::DrawPacket& q);

} // namespace rm
