extern "C" char DAT_003f6098[];
extern "C" char DAT_0041dc30[];
struct Other {
    virtual void A();
    virtual void B();
};
struct C {
    void* vptr;
    char pad[8];
    Other* obj;
    void F();
};
void C::F() {
    vptr = (void*)((int)DAT_0041dc30);
    obj->B();
    vptr = (void*)((int)DAT_003f6098);
}