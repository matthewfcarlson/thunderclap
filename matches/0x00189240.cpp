// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_189240 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_189240[];
extern "C" void opdel(void*);

class BallAndChainReturnAction_189240 {
  public:
    void Cleanup();
    BallAndChainReturnAction_189240* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_189240* m_20;
};

BallAndChainReturnAction_189240* BallAndChainReturnAction_189240::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (int)&g_vt_189240;
    RefCounted_189240* q = (RefCounted_189240*)p[8];
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
