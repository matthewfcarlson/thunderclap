// Night lights (wlook2, docs/night.md; run/app/nightlights.cpp): the city's lamps and glows as lights of the per-pixel
// lighting (lighting.cpp) and of the atmosphere's in-scattering (atmosphere.cpp).
#pragma once
#include <stdint.h>

#include "pddi/draw_sink.h"

namespace rm {

// the presented frame has night lights placed (its camera known, at least one light on screen)
bool nightLightsActive();
// a camera-space sphere meets one of the frame's lights (the draw takes a per-pixel program)
bool nightLightsTouch(const float centre[3], float radius);
// for a draw with a program of ours (every one declares u_rmCity and s_rmCity, stage 5): binds the frame's lights when
// the draw receives them (an opaque draw of the world's pass), else none
void nightLightsBind(const hulk::pddi::DrawPacket& p);
// the same for a full-screen pass of the runner's (atmosphere.cpp): false when there are no lights this frame
bool nightLightsBindPost(uint8_t stage);
// the frame's night estimate (0 day .. 1 night: the rooms' fog colour) and fog colour (rgb; false: not known yet)
float nightAmount();
bool nightFogColour(float rgb[3]);
// the presented frame's camera, from its first room draw (false before it): the view as rows (camera = view x
// (world, 1)), its 3x3 inverse, the world pass's projection (c4..c7)
bool frameCamera(float view[3][4], float inv[3][3], float proj[16]);

} // namespace rm
