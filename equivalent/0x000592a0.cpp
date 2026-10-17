// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000592a0 @ 0x000592a0
struct Handler { void FUN_00059ba0(int value); };
struct Manager { char pad[0x44]; Handler *handler; };
extern Manager *DAT_004dd700;
struct Object { char pad[8]; int value; void FUN_000592a0(); };
void Object::FUN_000592a0() { DAT_004dd700->handler->FUN_00059ba0(value); }