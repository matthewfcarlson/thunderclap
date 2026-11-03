// STATUS: equivalent (tools/equiv.py level 3: 13401 inputs, branch coverage 10/10)
// FUN_00233460 @ 0x00233460
// cl-flags: /GS
#include "decls/data/engine/fight.h"
#include "gen/owners.h"

extern "C" int __cdecl FUN_00267760(char*, int, const char*, ...);
bool owners::Node_233460::FUN_00233460(char* output, int capacity) {
 char temporary[1024];
 if ((low | high) == 0) { if (capacity > 0) output[0] = 0; }
 else FUN_00267760(output, capacity, "%08x%08x", high, low);
 owners::Node_233460* current = next;
 while (current) {
  if ((current->low | current->high) == 0)
   FUN_00267760(temporary, 1024, "%s%s", (*(const char**)&DAT_004ca248), output);
  else
   FUN_00267760(temporary, 1024, "%08x%08x%s%s", current->high, current->low, (*(const char**)&DAT_004ca248), output);
  FUN_00267760(output, capacity, "%s", temporary);
  current = current->next;
 }
 FUN_00267760(temporary, 1024, "%s%s", (*(const char**)&DAT_004ca248), output);
 FUN_00267760(output, capacity, "%s", temporary);
 return true;
}