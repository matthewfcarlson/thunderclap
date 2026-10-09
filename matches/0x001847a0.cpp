class Ref {
  public:
    virtual void A();
    virtual void Release();
};
class ShieldArcAction {
  public:
    volatile int vft;
    char pad[0x18];
    int m1c;
    Ref* volatile m20;
    void Cleanup();
    void Finish();
};
void ShieldArcAction::Cleanup() {
    vft = 0x419774;
    Ref* p = m20;
    if (p) {
        p->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Finish();
}