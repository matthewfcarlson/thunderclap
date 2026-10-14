struct Src_17ff30 {
    int a;
    int b;
    int c;
};

class Obj_17ff30 {
  public:
    virtual void Dummy();
    char pad[0x24 - 4];
    Src_17ff30 m;
    bool Copy(Src_17ff30* p);
};

bool Obj_17ff30::Copy(Src_17ff30* p) {
    m.a = p->a;
    m.b = p->b;
    m.c = p->c;
    return true;
}
