// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_0023fc40 @ 0x0023fc40
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

  owners::String_23fc40 *owners::String_23fc40::FUN_0023fc40(const char *text, hulk_intptr option) { if (!text) { data = (*(char**)&DAT_004cc02c); ++*(unsigned short *)((*(char**)&DAT_004cc02c) - 4); extra = 0; capacity = 2; } else { const char *end = text; while (*end) ++end; hulk_intptr length = end - text; FUN_0023fb20(text, length, length, ((int)option)); } return this; }