// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 48/48)
// FUN_002071e0 @ 0x002071e0
#include "decls/address.h"
extern unsigned char DAT_004c91d8;

void *__cdecl FUN_00263ea0(unsigned int size);
int __cdecl FUN_00266da0(int tag);
void __cdecl FUN_00267110(int id);
void __cdecl FUN_00267090(void *p);

struct Voice_2071e0 {
    virtual void v0();
    virtual void v1();
};

struct Stream {
    void *FUN_00266480(int size);
    void FUN_002660a0(Stream *first);
    virtual void v0();
    virtual void v1();
};

struct Handle_2071e0 {
    void FUN_00263e90();
};

struct Mgr54_2071e0 {
    void *FUN_00086290();
};
struct Dummy_2071e0 {
    void FUN_001b9020();
};
struct Mgr3c {
    int FUN_000d6f50();
    void FUN_000d7030(int v);
};
struct World {
    char pad0[0x3c];
    Mgr3c *mgr3c;          // 0x3c
    char pad40[0x54 - 0x40];
    Mgr54_2071e0 *mgr54;          // 0x54
};

struct Slot_2071e0 {
    unsigned char used;            // 0x00
    unsigned char used2;           // 0x01
    char pad02[0x22 - 2];
    short id;                      // 0x22
    char pad24[4];
    void *buf;                     // 0x28
    Voice_2071e0 *voice;                  // 0x2c
    char pad30[4];
    Handle_2071e0 *handle;                // 0x34
    char pad38[4];
};

class Mixer {
public:
    char pad0[0x4c];
    Slot_2071e0 slots[20];                // 0x4c
    char pad4fc[0x578 - 0x4fc];
    Stream *streams[3];            // 0x578
    char pad584[0x5a4 - 0x584];
    unsigned char flags[0x400];    // 0x5a4
    int field9a4;                  // 0x9a4
    int count;                     // 0x9a8
    int ids[20];                   // 0x9ac
    int vals[20];                  // 0x9fc
    char pada4c[0xaf1 - 0xa4c];
    unsigned char ready;           // 0xaf1
    char padaf2[2];
    unsigned char dirty;           // 0xaf4

    int FUN_00204c10(int a);
    int FUN_00204ad0(int a, int *b);
    void FUN_00207080(int a);
    void FUN_002071e0(int n);
};

void Mixer::FUN_002071e0(int n)
{
    if (ready)
        return;

    for (int i = 0; i < n; ++i) {
        int r = FUN_00204c10(0);
        if (r > 0)
            FUN_00207080(r);
    }

    int used = 0;
    for (int i = 0; i < 0x400; ++i) {
        if (flags[i] == 1)
            ++used;
    }

    int limit = 0x14 - n;
    if (used > limit) {
        int k = used - limit;
        do {
            int r = FUN_00204c10(0);
            if (r < 0) {
                r = FUN_00204ad0(count, &ids[0]);
                ids[count] = -1;
                vals[count] = r;
                ++count;
            }
            FUN_00207080(r);
            --k;
        } while (k != 0);
    }

    if (DAT_004c91d8) {
        for (int i = 0; i < 20; ++i) {
            Slot_2071e0 *s = &slots[i];
            if (s->used)
                continue;
            if (s->handle != 0) {
                s->handle->FUN_00263e90();
                s->handle = 0;
            }
            if (s->voice != 0)
                FUN_00267110(s->id);
            if (s->voice != 0) {
                s->voice->v1();
                s->voice = 0;
            }
            if (s->buf != 0) {
                FUN_00267090(s->buf);
                s->buf = 0;
            }
            s->used = 0;
            s->used2 = 0;
            s->id = 0;
        }
        dirty = 1;
    }

    ids[count] = -1;
    vals[count] = -1;
    ++count;
    int tag = FUN_00266da0(7);

    for (int i = 0; i < 3; ++i) {
        Stream *st = 0;
        void *mem = FUN_00263ea0(0x14);
        if (mem) {
            st = (Stream *)((Stream *)mem)->FUN_00266480(0x400);
            if (st)
                st->v0();
        }
        if (streams[i])
            streams[i]->v1();
        streams[i] = st;
        if (i > 0)
            st->FUN_002660a0(streams[0]);
    }
    ready = 1;
    Mgr54_2071e0 *m54 = DAT_004dd700->mgr54;
    ((Dummy_2071e0 *)m54->FUN_00086290())->FUN_001b9020();
    field9a4 = DAT_004dd700->mgr3c->FUN_000d6f50();
    DAT_004dd700->mgr3c->FUN_000d7030(0x180);
    FUN_00266da0(tag);
}
