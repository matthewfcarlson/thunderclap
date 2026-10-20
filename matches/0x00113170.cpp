// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_113170 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_113170[];
extern "C" void opdel(void*);

class HulkAction_113170 {
  public:
    void Cleanup();
    HulkAction_113170* vfunc_2(int flag);

  private:
    char pad[0x1c];
    int m_1c;
    RefCounted_113170* m_20;
};

HulkAction_113170* HulkAction_113170::vfunc_2(int flag) {
    volatile int* p = (volatile int*)this;
    *p = (int)&g_vt_113170;
    RefCounted_113170* q = (RefCounted_113170*)p[8];
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
