#include "decls/data/engine/content.h"
#include "decls/data/engine/core.h"
// data: gEntries_2670b0 = DAT_00527c60, gFallback_2670b0 = DAT_00527f40

#include "compat/ptr.h"
typedef unsigned int U_2670b0;
struct Obj_2670b0 {
    virtual void F();
};
struct Entry_2670b0 {
    Obj_2670b0* object;
    hulk_uintptr field4;
    hulk_uintptr field8;
    Entry_2670b0* next;
};
void FUN_002670b0(int a, int b, Obj_2670b0* obj) {
    Entry_2670b0* dest = &((Entry_2670b0*)((char*)&DAT_00527c58 + 8))[a];
    Entry_2670b0* list;
    if (b == 45)
        list = ((Entry_2670b0*)&DAT_00527f40);
    else {
        list = &((Entry_2670b0*)((char*)&DAT_00527c58 + 8))[b];
        if (list->next == 0)
            list = ((Entry_2670b0*)&DAT_00527f40);
    }
    obj->F();
    dest->object = obj;
    dest->next = list;
    dest->field4 = 0;
    dest->field8 = list->field4;
    list->field4 = (hulk_uintptr)dest;
}
