// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_001c6800 @ 0x001c6800
struct Profiler {
 void FUN_0023f720(int*, const char*);
 bool FUN_0023f760(const char*, int, int);
 void FUN_0023f740();
};
extern Profiler* DAT_004dd6e8;
extern int DAT_004c5328;
extern int DAT_004e2350;
struct Renderer {
 char pad0[0xc0];
 int option;
 void FUN_001c1330(int);
 void FUN_001c26a0(int, int, int);
};
struct Queue {
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
 void render(Renderer*, Queue*, int, int);
};
void Object::render(Renderer* renderer, Queue* queue, int context, int argument) {
 if (!active) return;
 queue->entries[queue->count] = index;
 ++queue->count;
 DAT_004dd6e8->FUN_0023f720(&DAT_004c5328, "Rendering");
 bool enabled = DAT_004dd6e8->FUN_0023f760("Light Room Geo", 0x6c, 0);
 renderer->FUN_001c1330(enabled ? renderer->option : 0);
 DAT_004dd6e8->FUN_0023f740();
 if (geometry) {
  DAT_004e2350 = context;
  renderer->FUN_001c26a0(geometry, argument, data);
  DAT_004e2350 = 0;
 }
}
