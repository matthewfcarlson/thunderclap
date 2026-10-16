// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 3/4, incomplete)
// FUN_0027b8f0 @ 0x0027b8f0
#include "decls/address.h"
struct Bitset { unsigned int bits; unsigned int words[17]; };
extern "C" unsigned int DAT_0052c288;
extern "C" unsigned int DAT_004ce408;
extern "C" unsigned int DAT_004ce40c;
extern "C" Bitset* DAT_004ce410;
extern "C" Bitset* __cdecl FUN_0008d6d0(unsigned int);
void FUN_0027b8f0(){
  if (DAT_0052c288 == 0) {
    long long hash = FUN_002672f0("root", 0, 0);
    DAT_004ce408 = (unsigned int)hash;
    DAT_004ce40c = (unsigned int)(hash >> 32);
    Bitset* b = FUN_0008d6d0(0x48);
    b->bits = 0x201;
    for (int i = 0; i < 17; i++) b->words[i] = 0;
    DAT_004ce410 = b;
    unsigned int n = (b->bits + 0x1f) >> 5;
    for (unsigned int i = 0; i < n; i++) b->words[i] = 0xffffffff;
  }
  DAT_0052c288++;
}
