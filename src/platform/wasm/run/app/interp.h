// Display rates by interpolation (fps2, D228a): run/app/interp.cpp, called from app.cpp's sink imports
#pragma once
#include <stdint.h>
#include "pddi/draw_sink.h"

void interp_set_window(void* window);
void interp_set_rate(int rate);              // 30 (none), 60, 120, 0 (the display's refresh)
void interp_discontinuity();                 // a restore: the next update is drawn without interpolation
void interp_record_live();                   // a playthrough session's hand-off: pace from here on
bool interp_recording();                     // this update's drawing goes to the stream
void interp_pass(const hulk::pddi::SinkPass& p);
void interp_copy(uint16_t pass, const hulk::pddi::SinkTarget& t);
void interp_fx(const hulk::pddi::FxPacket& p);
void interp_present(const hulk::pddi::SinkPresent& p);
void interp_transient(const hulk::pddi::SinkVertex* staging, uint32_t count);
void interp_draw(const hulk::pddi::DrawPacket& p);
void interp_destroy(int kind, uint32_t a, uint32_t b);   // 1 texture, 2 buffers, 3 render target, 4 copy target
bool interp_frame();                         // the update's frame end: true when recorded (drawn in interp_pace)
void interp_context_destroyed();
void interp_pace(uint32_t fields);
// the display clock (wgrass1): seconds of the original's fields, at the drawn frame (between two updates' times at a
// display rate above 30); render-only animation (grass sway) takes it, so a still picture is the same at any rate
double interp_display_time();           // the SwapBuffers wait: fields of 60 Hz this update lasts
