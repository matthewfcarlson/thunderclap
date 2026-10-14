struct Src_16f400 {
    int a;
    int b;
    int c;
};

class Obj_16f400 {
  public:
    char pad[0x20];
    int m20;
    int m24;
    int m28;
    bool Set(Src_16f400* p);
};

bool Obj_16f400::Set(Src_16f400* p) {
    m20 = p->a;
    m24 = p->b;
    m28 = p->c;
    return true;
}
