// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 8/8)
// FUN_003358a0 @ 0x003358a0
#include "gen/owners.h"
struct Entry { char pad[8]; int kind; }; struct Container { char pad[0x44]; int count;  }; struct Target { char pad[4]; Container* container; int** values; bool FUN_003358a0(int index, int* output); }; bool Target::FUN_003358a0(int index, int* output) { if (index < 0 || index >= container->count || ((Entry *)((owners::Thing_337090 *)container)->FUN_00337090(index))->kind != 9) return false; int* item = values[index]; *output = item ? *item : 0; return true; }