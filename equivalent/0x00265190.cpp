// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00265190 @ 0x00265190
class Releasable {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Entry {
    int tag;
    Releasable* obj;
};

struct Ring {
    Entry* head;
    Entry* tail;
    Entry* start;
    Entry* end;
    void FUN_00264e10(Entry* e);
};

class Queue {
public:
    char pad0[8];
    int pending;
    char pad1[8];
    Ring ring;
    void FUN_00265190(Releasable* obj);
};

void Queue::FUN_00265190(Releasable* obj) {
    if (!obj)
        return;
    unsigned int count;
    if (ring.head <= ring.tail)
        count = ring.tail - ring.head;
    else
        count = (ring.tail - ring.start) + (ring.end - ring.head);
    if (count == 0 && pending == 0) {
        obj->v3();
        obj->v1();
        return;
    }
    Entry e;
    obj->v0();
    e.tag = 0;
    e.obj = obj;
    ring.FUN_00264e10(&e);
}
