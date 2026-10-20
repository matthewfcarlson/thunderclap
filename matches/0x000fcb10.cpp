#include "compat/ptr.h"
typedef unsigned int u32_fcb10;
struct Base_fcb10 {
    void InitBase(u32_fcb10);
};
struct CChaseAgent : Base_fcb10 {
    char pad0[8];
    u32_fcb10 a;
    char padc[0x68 - 0x0c];
    float f;
    char b;
    char pad70[3];
    u32_fcb10 c;
    CChaseAgent* Init(u32_fcb10);
};
extern char CChaseAgent_vftable;
CChaseAgent* CChaseAgent::Init(u32_fcb10 x) {
    ((Base_fcb10*)this)->InitBase(x);
    a = 0;
    c = 0;
    b = 0;
    *(hulk_uintptr*)this = (hulk_uintptr)&CChaseAgent_vftable;
    f = -1.0f;
    return this;
}