// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 18/18)
// FUN_00246100 @ 0x00246100
#include "compat/ptr.h"
#include "gen/owners.h"
struct Reader {
 char pad[0x90];
 unsigned int line, position, length;
};
extern "C" void __cdecl FUN_00245d40(void *);
int __cdecl FUN_00245890(const char*, hulk_intptr);
int __cdecl FUN_00245850(const char*, int);
extern "C" int __cdecl FUN_00246100(Reader* r) {
 char buffer[128];
 char* out = buffer;
 FUN_00245d40((Reader *)r);
 if (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) == '-') {
  *out = ((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position));
  if (r->position < r->length) {
   if (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) == '\n') ++r->line;
   ++r->position;
  }
  ++out;
 }
 while (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) >= '0') {
  if (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) > '9') break;
  *out = ((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position));
  if (r->position < r->length) {
   if (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) == '\n') ++r->line;
   ++r->position;
  }
  ++out;
 }
 *out = 0;
 hulk_intptr size = out-buffer;
 if (buffer[0] == '-') return FUN_00245890(buffer,size);
 return FUN_00245850(buffer,size);
}
