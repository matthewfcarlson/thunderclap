// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_157350 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_157350[];
extern "C" void opdel(void*);

class HitDamageAction_157350 {
  public:
    void Cleanup();
    HitDamageAction_157350* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_157350* m_20;
};

HitDamageAction_157350* HitDamageAction_157350::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (int)&g_vt_157350;
    RefCounted_157350* q = (RefCounted_157350*)p[8];
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
