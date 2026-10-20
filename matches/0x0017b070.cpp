// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_17b070 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_17b070[];
extern "C" void opdel(void*);

class MotionStateAction_17b070 {
  public:
    void Cleanup();
    MotionStateAction_17b070* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_17b070* m_20;
};

MotionStateAction_17b070* MotionStateAction_17b070::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (int)&g_vt_17b070;
    RefCounted_17b070* q = (RefCounted_17b070*)p[8];
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    Cleanup();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}
