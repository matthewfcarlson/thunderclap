// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002088a0 @ 0x002088a0
#include "decls/data/game/global.h"

class Releasable_2088a0 {
public:
    virtual void v0();
    virtual void Release();
};

struct Buffer_2088a0 {
    void FUN_00263e90();
};

struct Slot_2088a0 {
    unsigned char active;       // +0x00
    unsigned char ready;        // +0x01
    char pad02[0x20];
    short handle;               // +0x22
    char pad24[4];
    char *name;                 // +0x28
    Releasable_2088a0 *resource;       // +0x2c
    char pad30[4];
    Buffer_2088a0 *buffer;             // +0x34
    char pad38[4];
};


void __cdecl FUN_00267090(char *p);
void __cdecl FUN_00267110(int handle);

class Pool_2088a0 {
public:
    void FUN_002088a0();
    void FUN_00207e80();

    char pad0[0x4c];
    Slot_2088a0 slots[20];             // +0x4c
    char pad4fc[0xaf4 - 0x4fc];
    char cleared;               // +0xaf4
};

void Pool_2088a0::FUN_002088a0() {
    FUN_00207e80();
    if ((*(char*)&DAT_004c91d8) != 0) {
        for (int i = 0; i < 20; i++) {
            Slot_2088a0 *s = &slots[i];
            if (s->buffer != 0) {
                s->buffer->FUN_00263e90();
                s->buffer = 0;
            }
            if (s->resource != 0) {
                FUN_00267110(s->handle);
            }
            if (s->resource != 0) {
                s->resource->Release();
                s->resource = 0;
            }
            if (s->name != 0) {
                FUN_00267090(s->name);
                s->name = 0;
            }
            s->active = 0;
            s->ready = 0;
            s->handle = 0;
        }
    }
    cleared = 1;
}
