// The performance overlay's hooks (wperf1, perfov.cpp; Video Options > Performance Overlay). Off (g_perfOv 0): the
// callers test the flag and take no times.
#pragma once
#include <stdint.h>

extern int g_perfOv;                    // 0 off, 1 FPS, 2 graph
void perfov_pace_begin();               // interp_pace: an update's module work ends (its draws included)
void perfov_pace_end();                 // interp_pace: the module's next update begins
void perfov_interp(uint64_t ns);        // a presented frame's replay (interp.cpp drawStream), waits excluded
void perfov_encode(uint64_t ns);        // a bgfx::frame (Metal encoding and the wait for a free frame)
