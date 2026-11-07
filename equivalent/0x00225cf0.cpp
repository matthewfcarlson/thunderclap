// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00225cf0 @ 0x00225cf0
#include "compat/ptr.h"
#include "gen/owners.h"
extern hulk_freg __cdecl FUN_00225be0(int, int, int, unsigned char);
void owners::Object_225cf0::FUN_00225cf0(int input) {
 float result = FUN_00225be0(input, value1, value2, flag);
 result1 = result;
 result2 = result;
}