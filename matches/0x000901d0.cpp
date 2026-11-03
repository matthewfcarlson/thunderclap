#include "gen/owners.h"
typedef unsigned int u32_901d0;
struct ThisCall_00090130 {
};
void owners::C_901d0::FUN_000901d0(int index, u32_901d0 value) {
    if (index == 0) {
        ((owners::Stats_90130 *)(((ThisCall_00090130*)(this))))->FUN_00090130((int)value);
        return;
    }
    if (index >= 0 && index < 0x32)
        *(u32_901d0*)((char*)this + index * 0x40 + 0x38) = value;
}
