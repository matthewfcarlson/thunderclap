extern "C" void _ReadWriteBarrier();
struct Ref {
    virtual void f0();
    virtual void Release();
};
void __fastcall BaseDestroy(void*);
struct FaceTargetAction {
    int vptr;
    char pad[0x18];
    int field1c;
    Ref* field20;
    void Cleanup();
};
void FaceTargetAction::Cleanup() {
    vptr = 0x40d884;
    _ReadWriteBarrier();
    Ref* r = field20;
    if (r) {
        r->Release();
        field20 = 0;
    }
    if (field1c)
        field1c = 0;
    BaseDestroy(this);
}
