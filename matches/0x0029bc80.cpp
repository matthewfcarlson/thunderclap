extern "C" void _ReadWriteBarrier();
struct Ref_29bc80 {
    virtual void add();
    virtual void release();
};
struct Item_29bc80 {
    char pad[20];
    Ref_29bc80* ref;
};
struct Owner_29bc80 {
    char pad[16];
    unsigned count;
    char pad2[4];
    Ref_29bc80* ref;
    Item_29bc80** items;
    void set(Ref_29bc80* p);
};
void Owner_29bc80::set(Ref_29bc80* p) {
    if (p)
        p->add();
    if (ref)
        ref->release();
    ref = p;
    _ReadWriteBarrier();
    for (unsigned i = 0; i < count; ++i) {
        Ref_29bc80** slot = &items[i]->ref;
        if (p)
            p->add();
        if (*slot)
            (*slot)->release();
        *slot = p;
    }
}