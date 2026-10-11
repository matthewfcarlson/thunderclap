extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3c90[];
extern "C" void _ReadWriteBarrier();
struct Ref {
    virtual void f0();
    virtual void Release();
};
struct Obj;
void __fastcall BaseDtor(Obj* p);
struct Obj {
    virtual void a0();
    virtual void a1();
    char pad[0x18];
    Ref* mRef;
    int mUnknown;
    void Dtor();
};
void Obj::a0() {}
void Obj::a1() {}
void Obj::Dtor() {
    *(void**)this = (void*)((int)DAT_003f3c90);
    _ReadWriteBarrier();
    if (mUnknown)
        mUnknown = 0;
    *(void**)this = (void*)((int)DAT_003f3390);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    BaseDtor(this);
}
