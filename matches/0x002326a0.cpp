extern "C" char DAT_003f6098[];
extern "C" char DAT_004276ec[];
extern "C" void _ReadWriteBarrier();
struct Ref_2326a0 {
    virtual void A();
    virtual void Release();
};
extern int g_count_2326a0;
struct Action {
    void* vptr;
    int pad;
    Ref_2326a0* member;
    void Cleanup();
};
void Action::Cleanup() {
    *(void* volatile*)&vptr = (void*)((int)DAT_004276ec);
    _ReadWriteBarrier();
    Ref_2326a0* m = member;
    if (m) {
        m->Release();
        member = 0;
    }
    --g_count_2326a0;
    vptr = (void*)((int)DAT_003f6098);
}
