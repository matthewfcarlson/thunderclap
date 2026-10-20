// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_11a0b0 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_11a0b0[];
extern "C" void opdel(void*);

class MotionLocatorAction_11a0b0 {
  public:
    void Cleanup();
    MotionLocatorAction_11a0b0* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_11a0b0* m_20;
};

MotionLocatorAction_11a0b0* MotionLocatorAction_11a0b0::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (int)&g_vt_11a0b0;
    RefCounted_11a0b0* q = (RefCounted_11a0b0*)p[8];
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
