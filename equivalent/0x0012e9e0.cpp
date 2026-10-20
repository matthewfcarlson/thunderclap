// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e9e0 @ 0x0012e9e0
#include "compat/ptr.h"
extern "C" unsigned int __cdecl FUN_0008d340(void*);
extern "C" unsigned int __cdecl FUN_0008d6d0(unsigned int);
struct Object {
 char pad[0x10];
 char* value;
 unsigned int FUN_0012e9e0(const char* text);
};
unsigned int Object::FUN_0012e9e0(const char* text) {
 hulk_uintptr result = FUN_0008d340(value);
 if (!text) {
  value = 0;
  return (result & 0xffffff00) | 1;
 }
 unsigned int length = 0;
 while (text[length]) ++length;
 result = FUN_0008d6d0(length + 1);
 value = (char*)result;
 char* dest = value;
 do { *dest++ = *text; } while (*text++);
 return (result & 0xffffff00) | 1;
}