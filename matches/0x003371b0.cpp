#include "decls/data/engine/movie.h"

struct Item_3371b0 {
    void Init();
};
struct Obj_3371b0 {
    unsigned int v;
    char pad[0x44];
    Item_3371b0 items[0x18];
    void Finish();
};
Obj_3371b0* __fastcall FUN_003371b0(Obj_3371b0* self, void*) {
    self->v = ((int)((char*)&DAT_00434318));
    Item_3371b0* p = (Item_3371b0*)((char*)self + 0x48);
    int n = 0x18;
    do {
        p->Init();
        p = (Item_3371b0*)((char*)p + 0x18);
        --n;
    } while (n);
    self->Finish();
    return self;
}