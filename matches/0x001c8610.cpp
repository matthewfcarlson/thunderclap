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
    *(void**)this = (void*)0x421abc;
    _ReadWriteBarrier();
    Ref* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
    *(void**)this = (void*)0x3f6098;
}
