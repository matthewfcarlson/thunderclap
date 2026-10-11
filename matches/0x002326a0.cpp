extern "C" char DAT_003f6098[];
extern "C" char DAT_004276ec[];
extern "C" void _ReadWriteBarrier();
struct Ref {
    virtual void A();
    virtual void Release();
};
extern int g_count;
struct Action {
    void* vptr;
    int pad;
    Ref* member;
    void Cleanup();
};
void Action::Cleanup() {
    *(void* volatile*)&vptr = (void*)((int)DAT_004276ec);
    _ReadWriteBarrier();
    Ref* m = member;
    if (m) {
        m->Release();
        member = 0;
    }
    --g_count;
    vptr = (void*)((int)DAT_003f6098);
}
