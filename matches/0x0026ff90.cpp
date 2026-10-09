class Ref {
  public:
    virtual void X();
    virtual void A();
};
extern void Cleanup(int, int);
extern volatile int g_value;
class Pool {
  public:
    virtual void v0();
    virtual void v1();
    char pad4[4];
    volatile int field8;
    char padc[8];
    int field14;
    volatile int field18;
    char pad1c[0x14];
    Ref* field30;
    void Destroy();
};
void Pool::Destroy() {
    Ref* p = field30;
    *(int*)this = 0x42b5b4;
    *((int*)this + 1) = 0x42b5ac;
    if (p) {
        p->A();
        field30 = 0;
    }
    if (field14 >= 0)
        Cleanup(field14, field18);
    field18 = 0;
    g_value = field8;
    *((int*)this + 1) = 0x42af64;
    *(int*)this = 0x3f6098;
}
