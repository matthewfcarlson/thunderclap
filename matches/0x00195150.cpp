extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void a();
    virtual void Release();
};
extern int vt;
class FireProjectileAction {
  public:
    int vptr;
    char pad[0x18];
    int m1c;
    Ref* m20;
    int m24;
    Ref* m28;
    Ref* m2c;
    void finish();
    void clean();
};
void FireProjectileAction::clean() {
    vptr = (int)&vt;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    finish();
}
