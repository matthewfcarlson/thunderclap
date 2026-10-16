// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 7/8, incomplete)
// FUN_00240500 @ 0x00240500
#include "decls/data/engine/audio.h"

extern "C" int __cdecl sprintf(char *, const char *, ...);
struct StringValue_240500 { char *text; unsigned int flags; unsigned short length; unsigned short padding; };
struct StringHeader_240500 { unsigned int capacity; unsigned short references; unsigned short extra; };
extern void __cdecl FUN_0023fa40(char **result, const char *text, int length, int capacity);
extern void __cdecl FUN_00247570(void *allocation);
struct Object {
 Object *FUN_00240500(unsigned int value);
 void FUN_0023ff50(StringValue_240500 *value);
};
Object *Object::FUN_00240500(unsigned int value) {
 char buffer[64];
 int length = sprintf(buffer, "%u", value);
 StringValue_240500 temporary;
 temporary.flags = (temporary.flags & 0xffff0002u) | 2u;
 temporary.length = (unsigned short)length;
 char *text;
 FUN_0023fa40(&text, buffer, length, length);
 temporary.text = text;
 FUN_0023ff50(&temporary);
 if ((unsigned short)temporary.flags == 2) {
  StringHeader_240500 *header = reinterpret_cast<StringHeader_240500 *>(text) - 1;
  if (header->references == 1) {
   if (text != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
  } else {
   --header->references;
  }
 }
 return this;
}