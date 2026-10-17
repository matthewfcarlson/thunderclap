// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 5/6, incomplete)
// FUN_00067c80 @ 0x00067c80
#include "decls/data/game/global.h"

struct Value { void FUN_0027b040(const float *initial); }; struct Entry { unsigned a,b,c,d,e; char pad[4]; Value value; char tail[4]; }; struct Object { char pad[8]; unsigned handles[64]; Entry entries[256]; unsigned char FUN_00067c80(unsigned handle); };  unsigned char Object::FUN_00067c80(unsigned handle) { if (!handle) return 0; unsigned index = handle & 255; if (handles[index] != handle) return 0; handles[index] = 0; Entry &entry = entries[index]; entry.a = 0; entry.d = 0; entry.c = 0; entry.b = 0; entry.e = 0; entry.value.FUN_0027b040(((float*)&DAT_003f335c)); return 1; }