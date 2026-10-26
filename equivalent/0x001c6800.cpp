// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_001c6800 @ 0x001c6800
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

struct Profiler_1c6800 {
 void FUN_0023f720(int*, const char*);
 bool FUN_0023f760(const char*, int, int);
 void FUN_0023f740();
};
struct Renderer_1c6800 {
 char pad0[0xc0];
 int option;
 void FUN_001c1330(int);
 void FUN_001c26a0(int, int, int);
};
struct Queue_1c6800 {
 char pad0[0x54c];
 int count;
 int entries[1];
};
struct Object {
 char pad0[8];
 unsigned char active;
 char pad9[3];
 int geometry;
 char pad10[0x44];
 short index;
 char pad56[6];
 int data;
 void render(Renderer_1c6800*, Queue_1c6800*, int, int);
};
void Object::render(Renderer_1c6800* renderer, Queue_1c6800* queue, int context, int argument) {
 if (!active) return;
 queue->entries[queue->count] = index;
 ++queue->count;
 (*(Profiler_1c6800**)&DAT_004dd6e8)->FUN_0023f720(&DAT_004c5328, "Rendering");
 bool enabled = (*(Profiler_1c6800**)&DAT_004dd6e8)->FUN_0023f760("Light Room Geo", 0x6c, 0);
 renderer->FUN_001c1330(enabled ? renderer->option : 0);
 (*(Profiler_1c6800**)&DAT_004dd6e8)->FUN_0023f740();
 if (geometry) {
  (*(hulk_intptr*)&DAT_004e2350) = context;
  renderer->FUN_001c26a0(geometry, argument, data);
  (*(hulk_intptr*)&DAT_004e2350) = 0;
 }
}
