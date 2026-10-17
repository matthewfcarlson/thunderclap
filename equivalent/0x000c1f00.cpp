// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c1f00 @ 0x000c1f00
struct Callee { void FUN_000c1790(int value); }; struct Target { char pad[4]; Callee* field4; int FUN_000c1f00(int count, int* value); }; int Target::FUN_000c1f00(int count, int* value) { if (!field4 || count != 1) return -1; field4->FUN_000c1790(*value); return 0; }