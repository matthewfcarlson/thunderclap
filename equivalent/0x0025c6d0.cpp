// STATUS: equivalent (tools/equiv.py level 3: 1155 inputs, branch coverage 12/12)
// FUN_0025c6d0 @ 0x0025c6d0
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

struct Stream { char pad[0x24]; int depth; };
struct Context { Stream* stream; };
struct Entry_25c6d0 { const char* text; unsigned int other; };
bool __cdecl FUN_00246f50(Stream*, const char*);
struct Temp_25c6d0 { char data[12];   };
bool __cdecl FUN_0025bcb0(Context*, Temp_25c6d0*);
bool __cdecl FUN_0025c6d0(Context* context, const unsigned int* values) {
 if (!FUN_00246f50(context->stream, "\n[\n")) return false;
 ++context->stream->depth;
 for (unsigned int row=0; row<16; ++row) {
  for (unsigned int col=0; col<4; ++col) {
   Temp_25c6d0 temp;
   ((owners::String_23fc40 *)&temp)->FUN_0023fc40(((Entry_25c6d0*)&DAT_004cd1e4)[values[row*4+col]].text, (hulk_intptr)2);
   if (!FUN_0025bcb0(context, &temp)) { ((owners::Str_240060 *)&temp)->FUN_00240060(); return false; }
   if (!FUN_00246f50(context->stream, " ")) { ((owners::Str_240060 *)&temp)->FUN_00240060(); return false; }
   ((owners::Str_240060 *)&temp)->FUN_00240060();
  }
  if (!FUN_00246f50(context->stream, "\n")) return false;
 }
 --context->stream->depth;
 return FUN_00246f50(context->stream, "]\n") != 0;
}