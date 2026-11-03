// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 19/20, incomplete)
// FUN_000b4b60 @ 0x000b4b60
#include "gen/owners.h"
extern "C" char* __cdecl FUN_00096450(const char*);
void owners::Registry_b4b60::FUN_000b4b60(const char* key, const char* value) {
 if (!*key || !*value) return;
 for (int i=0; i<128; ++i) {
  const char* stored=keys[i];
  if (!stored) {
   keys[i]=FUN_00096450(key);
   values[i]=FUN_00096450(value);
   return;
  }
  const char* p=key;
  while (*p == *stored) {
   if (!*p) return;
   ++p; ++stored;
  }
 }
}
