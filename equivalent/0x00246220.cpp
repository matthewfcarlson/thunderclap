// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 20/20)
// FUN_00246220 @ 0x00246220
#include "gen/owners.h"
struct Reader {
 char padding[0x90];
 unsigned line;
 unsigned position;
 unsigned end;
};
extern "C" void __cdecl FUN_00245d40(void *);
bool __cdecl FUN_00246220(Reader* reader, unsigned* result) {
 FUN_00245d40((Reader *)reader);
 unsigned value = 0;
 if (reader->position >= reader->end) return false;
 for (;;) {
  signed char ch = ((signed char)((owners::RingReader_245b70 *)reader)->FUN_00245b70((unsigned int)(reader->position)));
  if (ch == 9 || ch == 32 || ch == 10 || ch == 13) {
   *result = value; return true;
  }
  if (reader->position >= reader->end) {
   *result = value; return true;
  }
  ch = ((signed char)((owners::RingReader_245b70 *)reader)->FUN_00245b70((unsigned int)(reader->position)));
  if (ch < '0' || ch > '9') {
   *result = 0; return false;
  }
  value = value * 10 + ch - '0';
  if (reader->position < reader->end) {
   ch = ((signed char)((owners::RingReader_245b70 *)reader)->FUN_00245b70((unsigned int)(reader->position)));
   if (ch == 10) ++reader->line;
   ++reader->position;
  }
 }
}
