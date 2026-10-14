struct VObj_151950 {
    virtual void v0();
    virtual void v1();
};

struct Sub_151950 {
    void release();
};

extern "C" void _ReadWriteBarrier(void);
extern int g_vtable_151950;

class Action {
  public:
    void destroy();
    void finalize();
    char pad0[0x1c];
    void* m1c;
    VObj_151950* m20;
    char pad1[0x28];
    VObj_151950* m4c;
};

void Action::destroy() {
    *(int**)this = &g_vtable_151950;
    _ReadWriteBarrier();
    if (m4c) {
        m4c->v1();
        m4c = 0;
    }
    if (m20) {
        m20->v1();
        m20 = 0;
    }
    if (m1c) {
        m1c = 0;
    }
    ((Sub_151950*)((char*)this + 0x24))->release();
    finalize();
}
