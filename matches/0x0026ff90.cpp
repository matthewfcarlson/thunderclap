extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b5ac[];
extern "C" char DAT_0042b5b4[];
class Ref_26ff90 {
  public:
    virtual void X();
    virtual void A();
};
extern void Cleanup(int, int);
extern volatile int g_value_26ff90;
class Pool_26ff90 {
  public:
    virtual void v0();
    virtual void v1();
    char pad4[4];
    volatile int field8;
    char padc[8];
    int field14;
    volatile int field18;
    char pad1c[0x14];
    Ref_26ff90* field30;
    void Destroy();
};
void Pool_26ff90::Destroy() {
    Ref_26ff90* p = field30;
    *(int*)this = ((int)DAT_0042b5b4);
    *((int*)this + 1) = ((int)DAT_0042b5ac);
    if (p) {
        p->A();
        field30 = 0;
    }
    if (field14 >= 0)
        Cleanup(field14, field18);
    field18 = 0;
    g_value_26ff90 = field8;
    *((int*)this + 1) = ((int)DAT_0042af64);
    *(int*)this = ((int)DAT_003f6098);
}
