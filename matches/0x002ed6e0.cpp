#include "gen/owners.h"
typedef unsigned int u32_2ed6e0;
struct Sub_2ed6e0 {
    void Call(void*, u32_2ed6e0, int);
};
void owners::Obj_2ed6e0::FUN_002ed6e0(u32_2ed6e0 arg) {
    ((Sub_2ed6e0*)((char*)this + 0xb0))->Call((char*)this + 0x2c, arg, 0);
}