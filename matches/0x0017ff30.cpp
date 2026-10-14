struct Src {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    virtual void Dummy();
    char pad[0x24 - 4];
    Src m;
    bool Copy(Src* p);
};

bool Obj::Copy(Src* p) {
    m.a = p->a;
    m.b = p->b;
    m.c = p->c;
    return true;
}
