// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 21/22, incomplete)
// FUN_000e67b0 @ 0x000e67b0
#include "compat/ptr.h"
struct Entry_e67b0 {
 char padding[0x18];
 char name[0x20];
 Entry_e67b0* FUN_000fb470(const char* name);
};
void* __cdecl FUN_0008d690(hulk_uintptr size);
struct Registry_e67b0 {
 char padding[0x160c];
 Entry_e67b0* entries[64];
 Entry_e67b0* findOrCreate(const char* name);
};
Entry_e67b0* Registry_e67b0::findOrCreate(const char* name) {
 for (int i = 0; i < 64; ++i) {
  Entry_e67b0* entry = entries[i];
  if (entry) {
   const unsigned char* a = (const unsigned char*)name;
   const unsigned char* b = (const unsigned char*)entry->name;
   while (*a == *b && *a) { ++a; ++b; }
   if (*a == *b) return entries[i];
  }
 }
 for (int slot = 0; slot < 64; ++slot) {
  if (!entries[slot]) {
   Entry_e67b0* memory = (Entry_e67b0*)FUN_0008d690(0x38);
   Entry_e67b0* result = memory ? memory->FUN_000fb470(name) : 0;
   entries[slot] = result;
   return result;
  }
 }
 return 0;
}
