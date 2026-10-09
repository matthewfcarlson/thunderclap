class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
extern void __cdecl thunk(void*);
class pure3d_Vector1DOFChannel {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[8];
    volatile int m12;
    char pad10[4];
    void* m14;
    char pad18[16];
    void* m28;
    void vfunc_1();
};
void pure3d_Vector1DOFChannel::vfunc_1() {
    if (m12 == 0)
        thunk(m28);
    m28 = 0;
    if (m12 == 0) {
        thunk(m14);
        m14 = 0;
        return;
    }
    Ref* p = (Ref*)m12;
    if (p != 0) {
        p->Release();
        m12 = 0;
    }
    m14 = 0;
}