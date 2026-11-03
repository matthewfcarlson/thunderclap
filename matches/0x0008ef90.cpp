#include "gen/owners.h"
typedef unsigned int u32_8ef90;
void owners::Obj_8ef90::FUN_0008ef90(u32_8ef90* src, u32_8ef90 val) {
    u32_8ef90* d = a;
    u32_8ef90* s = src;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    u32_8ef90* q = b;
    *q = val;
    CopyTail();
}