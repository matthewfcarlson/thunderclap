// STATUS: equivalent (tools/equiv.py level 3: 4899 inputs, branch coverage 28/28)
// FUN_001f4420 @ 0x001f4420
#include "decls/address.h"
struct Name_1f4420 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

struct Ptr_1f4420 {
    char pad0[4];
};

struct Item_1f4420 {
    char pad0[4];
};

struct Params {
    int a;
    int b;
};

struct Linked_1f4420 {
    void FUN_001e8ac0();
};

struct Slot_1f4420 {
    char pad0[4];
    Ptr_1f4420 *p;
    Linked_1f4420 *linked;
    char padc[4];
    int f10;
    char f14;
    char pad15[3];
    void *buf;
};

struct Entry_1f4420 {
    unsigned int lo;
    unsigned int hi;
    void *value;
    char pad0c[0x28 - 0xc];
};

struct Obj_1f4420 {
    Name_1f4420 nameA;
    Name_1f4420 nameB;
    int active[4];
    Slot_1f4420 *slots[4];
    char pad30[0x60 - 0x30];
    int f60;
    int f64;
    int f68;
    char pad6c[0x74 - 0x6c];
    int f74;
    int f78;
    char pad7c[0x80 - 0x7c];
    Entry_1f4420 entries[4];
};

void *__cdecl FUN_002673a0(int a, int b);
Item_1f4420 *__cdecl FUN_0024a370(Ptr_1f4420 *p, void *key);
void __cdecl FUN_00249bd0(Ptr_1f4420 *p, Item_1f4420 *item, Params *params);
void __cdecl FUN_002497e0(void *buf);
void __cdecl FUN_00249a90(Ptr_1f4420 *p, int x);
void __cdecl FUN_0024a800(Ptr_1f4420 *p, int x);
void __cdecl FUN_0024af00(Ptr_1f4420 *p);
struct ThisWrap_001f4420 {
    Obj_1f4420 * FUN_001f31a0(int arg);
    void FUN_001f4420(int arg);
};

void ThisWrap_001f4420::FUN_001f4420(int arg) {
    Obj_1f4420 *obj = this->FUN_001f31a0(arg);
    if (!obj)
        return;

    for (int i = 0; i < 4; i++) {
        Entry_1f4420 *e = &obj->entries[i];
        unsigned __int64 h = FUN_002672f0(0, 0, 0);
        if (e->lo == (unsigned int)h && e->hi == (unsigned int)(h >> 32))
            continue;
        for (int j = 0; j < 4; j++) {
            Slot_1f4420 *s = obj->slots[j];
            if (obj->active[j] && s) {
                Item_1f4420 *item = FUN_0024a370(s->p, &e->value);
                if (item) {
                    Params params;
                    params.a = 0;
                    params.b = 0xc8;
                    FUN_00249bd0(s->p, item, &params);
                }
            }
        }
        h = FUN_002672f0(0, 0, 0);
        e->lo = (unsigned int)h;
        e->hi = (unsigned int)(h >> 32);
        e->value = FUN_002673a0(0, 0);
    }

    for (int j = 0; j < 4; j++) {
        Slot_1f4420 *s = obj->slots[j];
        if (s) {
            if (s->linked)
                s->linked->FUN_001e8ac0();
            void *buf = s->buf;
            s->linked = 0;
            s->f10 = 0;
            if (buf) {
                FUN_002497e0(buf);
                s->buf = 0;
            }
            if (s->p) {
                FUN_00249a90(s->p, 0);
                FUN_0024a800(s->p, 0x32);
                FUN_0024af00(s->p);
                s->p = 0;
            }
            s->f14 = 0;
            obj->slots[j]->f10 = 0;
            obj->slots[j] = 0;
        }
    }

    obj->f74 = 0x63;
    obj->f78 = 0;
    obj->f64 = 0;
    obj->f60 = 0;
    obj->f68 = 0;
    obj->nameA.FUN_0027b040(0);
    obj->nameB.FUN_0027b040(0);
    obj->active[0] = 0;
    obj->slots[0] = 0;
    obj->active[1] = 0;
    obj->slots[1] = 0;
    obj->active[2] = 0;
    obj->slots[2] = 0;
    obj->active[3] = 0;
    obj->slots[3] = 0;
    for (int i = 0; i < 4; i++) {
        unsigned __int64 h = FUN_002672f0(0, 0, 0);
        obj->entries[i].lo = (unsigned int)h;
        obj->entries[i].hi = (unsigned int)(h >> 32);
        obj->entries[i].value = FUN_002673a0(0, 0);
    }
}
