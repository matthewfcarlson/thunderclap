extern int DriftVTable;

struct VObj_17b610 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Sub38_17b610 {
    void Fn();
};

void __cdecl opdel(void* p);

class DriftToPositionAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual DriftToPositionAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup();

  private:
    char pad0[0x18];
    int m1c;
    VObj_17b610* m20;
    char pad24[0x38 - 0x24];
    Sub38_17b610 m38;
};

DriftToPositionAction* DriftToPositionAction::vfunc_2(unsigned char param) {
    volatile unsigned int* p = (volatile unsigned int*)this;
    p[0] = (unsigned int)&DriftVTable;
    VObj_17b610* m = (VObj_17b610*)p[8];
    if (m != 0) {
        m->f1();
        p[8] = 0;
    }
    if (m1c != 0) {
        int* q = &m1c;
        *q = 0;
    }
    m38.Fn();
    Cleanup();
    if (param & 1) {
        opdel((void*)this);
    }
    return this;
}
