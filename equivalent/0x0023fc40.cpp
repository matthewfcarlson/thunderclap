// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_0023fc40 @ 0x0023fc40
#include "decls/data/engine/audio.h"

struct String { char *data; unsigned short capacity; char pad[2]; unsigned short extra; String *FUN_0023fc40(const char *text, int option); void FUN_0023fb20(const char *text, int length, int capacity, int option); };  String *String::FUN_0023fc40(const char *text, int option) { if (!text) { data = (*(char**)&DAT_004cc02c); ++*(unsigned short *)((*(char**)&DAT_004cc02c) - 4); extra = 0; capacity = 2; } else { const char *end = text; while (*end) ++end; int length = end - text; FUN_0023fb20(text, length, length, option); } return this; }