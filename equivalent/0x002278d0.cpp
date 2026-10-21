// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_002278d0 @ 0x002278d0
#include "compat/ptr.h"
extern "C" double __cdecl FUN_00224fc0(float, float);
struct Thing {
 char pad0[0x2c];
 volatile int count;
 char pad1[0x12e0-0x30];
 float valueA;
 float valueB;
 float FUN_00226960(int, float);
 hulk_freg FUN_002278d0(float scale);
};
hulk_freg Thing::FUN_002278d0(float scale) {
 int index = count - 1;
 float factor = (float)FUN_00224fc0(valueB, valueA);
 return FUN_00226960(index, factor) * scale;
}