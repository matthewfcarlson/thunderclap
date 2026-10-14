// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_001f5b70 @ 0x001f5b70
struct Source {
 unsigned __int64 FUN_001f57e0();
 bool FUN_001f3550();
};
struct Timer { void FUN_001e9b20(int); };
struct Object {
 char pad0[0x8c];
 Source* source;
 int state;
 unsigned char active;
 char pad95[3];
 unsigned __int64 value;
 char pada0[0x338-0xa0];
 Timer* timer;
 void update();
};
void Object::update() {
 if (state == -1 || !source) return;
 unsigned __int64 current = source->FUN_001f57e0();
 unsigned __int64 old = value;
 if (!old && current) { value = current; return; }
 if (old && (!current || (source && source->FUN_001f3550()))) {
  if (active) { timer->FUN_001e9b20(500); active = 0; }
  value = 0;
  state = -1;
 }
}
