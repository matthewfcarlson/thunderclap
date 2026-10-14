extern "C" void _ReadWriteBarrier();
struct Ref {
    virtual void add();
    virtual void release();
};
struct Item {
    char pad[20];
    Ref* ref;
};
struct Owner {
    char pad[16];
    unsigned count;
    char pad2[4];
    Ref* ref;
    Item** items;
    void set(Ref* p);
};
void Owner::set(Ref* p) {
    if (p)
        p->add();
    if (ref)
        ref->release();
    ref = p;
    _ReadWriteBarrier();
    for (unsigned i = 0; i < count; ++i) {
        Ref** slot = &items[i]->ref;
        if (p)
            p->add();
        if (*slot)
            (*slot)->release();
        *slot = p;
    }
}