// STATUS: equivalent (tools/equiv.py level 3: 1155 inputs, branch coverage 12/12)
// FUN_0025c6d0 @ 0x0025c6d0
struct Stream { char pad[0x24]; int depth; };
struct Context { Stream* stream; };
struct Entry_25c6d0 { const char* text; unsigned int other; };
extern Entry_25c6d0 DAT_004cd1e4[];
bool __cdecl FUN_00246f50(Stream*, const char*);
struct Temp_25c6d0 { char data[12]; void FUN_0023fc40(const char*, int); void FUN_00240060(); };
bool __cdecl FUN_0025bcb0(Context*, Temp_25c6d0*);
bool __cdecl FUN_0025c6d0(Context* context, const unsigned int* values) {
 if (!FUN_00246f50(context->stream, "\n[\n")) return false;
 ++context->stream->depth;
 for (unsigned int row=0; row<16; ++row) {
  for (unsigned int col=0; col<4; ++col) {
   Temp_25c6d0 temp;
   temp.FUN_0023fc40(DAT_004cd1e4[values[row*4+col]].text, 2);
   if (!FUN_0025bcb0(context, &temp)) { temp.FUN_00240060(); return false; }
   if (!FUN_00246f50(context->stream, " ")) { temp.FUN_00240060(); return false; }
   temp.FUN_00240060();
  }
  if (!FUN_00246f50(context->stream, "\n")) return false;
 }
 --context->stream->depth;
 return FUN_00246f50(context->stream, "]\n") != 0;
}