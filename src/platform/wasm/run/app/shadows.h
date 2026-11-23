// Sun shadows (wr3a, docs/hdr-shadows.md): what the lighting pass's receivers need from the shadow pass.
#pragma once
#include <stdint.h>

namespace rm {

// shadows are on and drawn this frame
bool shadowsOn();
// the u_rmShadow[12] constants for a draw of the game's current pass (null: it receives no shadows); `takesWorld`: the
// draw also takes the world's shadows (it is not part of the baked world). *atlas: the depth atlas (kNoHandle: none)
const float* shadowConstants(bool takesWorld, uint16_t* atlas);
// a 1x1 depth texture for programs that declare the shadow sampler but receive nothing
uint16_t shadowDummy();

} // namespace rm
