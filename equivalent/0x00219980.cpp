// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 8/8)
// FUN_00219980 @ 0x00219980
#include "decls/data/game/global.h"

struct NumberValue { int type; float value; };
// equiv-conv: FUN_00219980 esi stack
int __cdecl FUN_00219980(NumberValue* number, float limit) {
    if (number->type == 3) {
        float value = number->value;
        if (value > (*(float*)&DAT_003f32e0) && !(value > limit)) {
            int result = (int)value;
            if (number->value == (float)result)
                return result;
        }
    }
    return -1;
}