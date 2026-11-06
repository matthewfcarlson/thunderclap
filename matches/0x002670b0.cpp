#include "decls/data/records.h"

struct Obj_2670b0 {
    virtual void F();
};
extern "C" void FUN_002670b0(int a, int b, Obj_2670b0* obj) {
    MemoryHeapSlot* dest = &DAT_00527c60[a];
    MemoryHeapSlot* list;
    if (b == 45)
        list = &DAT_00527f40;
    else {
        list = &DAT_00527c60[b];
        if (list->parent == 0)
            list = &DAT_00527f40;
    }
    obj->F();
    dest->allocator = (void*)obj;
    dest->parent = list;
    dest->child = 0;
    dest->next = list->child;
    list->child = dest;
}
