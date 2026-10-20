// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00265190 @ 0x00265190
#include "compat/ptr.h"
class Releasable_265190 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Entry_265190 {
    int tag;
    Releasable_265190* obj;
};

struct Ring_265190 {
    Entry_265190* head;
    Entry_265190* tail;
    Entry_265190* start;
    Entry_265190* end;
    void FUN_00264e10(Entry_265190* e);
};

class Queue_265190 {
public:
    char pad0[8];
    int pending;
    char pad1[8];
    Ring_265190 ring;
    void FUN_00265190(Releasable_265190* obj);
};

void Queue_265190::FUN_00265190(Releasable_265190* obj) {
    if (!obj)
        return;
    hulk_uintptr count;
    if (ring.head <= ring.tail)
        count = ring.tail - ring.head;
    else
        count = (ring.tail - ring.start) + (ring.end - ring.head);
    if (count == 0 && pending == 0) {
        obj->v3();
        obj->v1();
        return;
    }
    Entry_265190 e;
    obj->v0();
    e.tag = 0;
    e.obj = obj;
    ring.FUN_00264e10(&e);
}
