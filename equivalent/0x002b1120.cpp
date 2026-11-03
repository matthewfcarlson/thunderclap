// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b1120 @ 0x002b1120
#include "gen/owners.h"
struct Pair { unsigned a; unsigned b; };
struct Thing {  void FUN_002b1120(unsigned value); };
void Thing::FUN_002b1120(unsigned value) {
    Pair result = {0, 0};
    ((owners::Buffer_2b0fb0 *)this)->FUN_002b0fb0((unsigned int)value, (Pair *)(&result));
}