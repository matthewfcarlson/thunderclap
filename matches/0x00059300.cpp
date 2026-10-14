class Obj_59300 {
  public:
    virtual void a();
    virtual void Release();
};
class X_59300 {
  public:
    char p0[0x4c];
    Obj_59300* m4c;
    Obj_59300* m50;
    char p1[0xc];
    Obj_59300* m60;
    char p1b[8];
    Obj_59300* m6c;
    Obj_59300* m70;
    char p2[0x10];
    Obj_59300* m84;
    void F();
};
void X_59300::F() {
    if (m4c) {
        m4c->Release();
        m4c = 0;
    }
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m6c) {
        m6c->Release();
        m6c = 0;
    }
    if (m70) {
        m70->Release();
        m70 = 0;
    }
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
}
