// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c3e70 @ 0x000c3e70
struct Worker { void FUN_000c31e0(int value); }; struct Obj { char pad[4]; Worker* worker; int FUN_000c3e70(int command, int* value); }; int Obj::FUN_000c3e70(int command, int* value) { if (!worker || command != 1) return -1; worker->FUN_000c31e0(*value); return 0; }