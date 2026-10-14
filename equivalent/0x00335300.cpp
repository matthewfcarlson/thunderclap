// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_00335300 @ 0x00335300
struct Stream { const char* FUN_00337980(); void FUN_003379b0(); };
struct Entry { char pad[8]; int type; };
struct Registry { int FUN_00337130(const char*); Entry* FUN_00337090(int); };
bool __cdecl FUN_003379c0(const char*);
struct Parser { void* reserved; Registry* registry; unsigned int* values; bool run(Stream*); };
typedef bool (Parser::*Handler)(unsigned int*, Stream*, Entry*, unsigned int);
extern Handler DAT_004d9800[];
bool Parser::run(Stream* stream) {
 const char* token = stream->FUN_00337980();
 if (!token) return false;
 int index = registry->FUN_00337130(token);
 if (index < 0) {
  if (FUN_003379c0(token)) return true;
  for (;;) {
   stream->FUN_003379b0();
   token = stream->FUN_00337980();
   if (!token) return false;
   if (FUN_003379c0(token)) return true;
  }
 }
 Entry* entry = registry->FUN_00337090(index);
 stream->FUN_003379b0();
 int kind = entry->type;
 unsigned int flag = (kind >= 4 && kind <= 8) ? 0 : 1;
 unsigned int argument = ((unsigned int)stream & 0xffffff00u) | flag;
 if (!(this->*DAT_004d9800[kind])(values + index, stream, entry, argument)) return false;
 stream->FUN_003379b0();
 return true;
}
