// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_19bc50 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_19bc50[];
extern "C" void opdel(void*);

class MissilePunchAction_19bc50 {
  public:
    void Cleanup();
    MissilePunchAction_19bc50* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_19bc50* m_20;
};

MissilePunchAction_19bc50* MissilePunchAction_19bc50::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (int)&g_vt_19bc50;
    RefCounted_19bc50* q = (RefCounted_19bc50*)p[8];
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
