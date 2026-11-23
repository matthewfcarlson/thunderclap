// Sun shadows (wr3a, docs/hdr-shadows.md): what the lighting pass's receivers need from the shadow pass.
#pragma once
#include <stdint.h>

#include "pddi/draw_sink.h"

namespace rm {

// shadows are on and drawn this frame
bool shadowsOn();
// the u_rmShadow[12] constants for a draw of the game's current pass (null: it receives no shadows); `takesWorld`: the
// draw also takes the world's shadows (it is not part of the baked world). *atlas: the depth atlas (kNoHandle: none)
const float* shadowConstants(bool takesWorld, uint16_t* atlas);
// wlook1: the draw is part of the baked world (a room: it casts into the world's row and takes only the
// characters' and objects' shadows, never its own row's)
bool shadowWorldDraw(const hulk::pddi::DrawPacket& p);
// a 1x1 depth texture for programs that declare the shadow sampler but receive nothing
uint16_t shadowDummy();

} // namespace rm
