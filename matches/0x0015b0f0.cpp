struct S {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char pad[0x74];
    int m74;
    int m78;
    int m7c;
    bool Set(S* p);
};

bool Obj::Set(S* p) {
    m74 = p->a;
    m78 = p->b;
    m7c = p->c;
    return true;
}
