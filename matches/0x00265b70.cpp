#include "decls/data/engine/content.h"
// data: g_obj_265b70 = DAT_00527c58

struct Params {
    int a, b, c, d;
};
// the content loader (0x002656b0 constructs it; its layout, so that the allocation is its size on both builds)
struct Obj_265b70 {
    unsigned char a, b, c, pad;
    unsigned interval, unused;
    void *first, *second;
    char *storage, *begin, *current, *end;
    unsigned reserved;
    char *buffer, *bufferBegin, *bufferCurrent, *bufferEnd;
    unsigned tail;                 // +0x38 (not set by the constructor)
    Obj_265b70* FUN_002656b0(Params* p);
};
void* FUN_0008d690(int size);

extern "C" void FUN_00265b70(Params* p) {
    if (!p) {
        Params def;
        def.a = 0x10;
        def.b = 0x80;
        def.c = 0x20;
        def.d = 0x10000;
        Obj_265b70* o = (Obj_265b70*)FUN_0008d690((int)sizeof(Obj_265b70));
        if (o) {
            (*(Obj_265b70**)&DAT_00527c58) = o->FUN_002656b0(&def);
            return;
        }
        (*(Obj_265b70**)&DAT_00527c58) = 0;
        return;
    }
    Obj_265b70* o = (Obj_265b70*)FUN_0008d690((int)sizeof(Obj_265b70));
    if (o) {
        (*(Obj_265b70**)&DAT_00527c58) = o->FUN_002656b0(p);
        return;
    }
    (*(Obj_265b70**)&DAT_00527c58) = 0;
}
