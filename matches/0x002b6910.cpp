struct I {
    virtual void A();
    virtual void B();
};
extern void* shadowVtable;
extern void* refVtable;
struct Obj {
    void* vptr;
    char pad[16];
    I* member;
    void F();
};
void Obj::F() {
    vptr = &shadowVtable;
    member->B();
    vptr = &refVtable;
}