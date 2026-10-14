struct Src {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char pad[0x18];
    int x;
    int y;
    int z;
    bool Set(const Src* p);
};

bool Obj::Set(const Src* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
