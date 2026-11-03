// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 18/18)
// FUN_00246340 @ 0x00246340
#include "gen/owners.h"
struct Parser_246340 {
 char pad[0x90];
 unsigned int line;
 unsigned int position;
 unsigned int length;
};
extern "C" void __cdecl FUN_00245d40(void *);
double __cdecl FUN_003458c1(const char* text);
double __cdecl FUN_00246340(Parser_246340* parser) {
 char buffer[128];
 char* out = buffer;
 FUN_00245d40((Parser_246340 *)parser);
 if (((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) == '-' ||
     (((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) >= '0' && ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) <= '9') ||
     ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) == '.') {
   do {
     *out = ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position));
     if (parser->position < parser->length) {
       if (((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) == '\n') ++parser->line;
       ++parser->position;
     }
     ++out;
   } while ((((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) >= '0' && ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) <= '9') || ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) == '.');
 }
 *out = 0;
 return FUN_003458c1(buffer);
}
