// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_000592a0 @ 0x000592a0
// FUN_000592a0 @ 0x000592a0
#include "gen/owners.h"
struct Handler { int FUN_00059ba0(int value); };
struct Manager { char pad[0x44]; Handler *handler; };
extern Manager *DAT_004dd700;
hulk_intptr owners::Object_592a0::FUN_000592a0() { return DAT_004dd700->handler->FUN_00059ba0(value); }
