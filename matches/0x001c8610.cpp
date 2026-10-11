extern "C" char DAT_003f6098[];
extern "C" char DAT_00421abc[];
extern "C" void _ReadWriteBarrier();
struct Ref {
    virtual void A();
    virtual void Release();
};
struct Obj {
    virtual void V0();
    virtual void V1();
    char pad[0x1c - 4];
    Ref* mRef;
    void F();
};
void Obj::F() {
    *(void**)this = (void*)((int)DAT_00421abc);
    _ReadWriteBarrier();
    Ref* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
    *(void**)this = (void*)((int)DAT_003f6098);
}
