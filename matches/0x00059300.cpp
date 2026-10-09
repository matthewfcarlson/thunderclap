class Obj {
  public:
    virtual void a();
    virtual void Release();
};
class X {
  public:
    char p0[0x4c];
    Obj* m4c;
    Obj* m50;
    char p1[0xc];
    Obj* m60;
    char p1b[8];
    Obj* m6c;
    Obj* m70;
    char p2[0x10];
    Obj* m84;
    void F();
};
void X::F() {
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
