struct Val {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char pad[0x34];
    int m34;
    int m38;
    int m3c;
    bool Set(const Val* v);
};

bool Obj::Set(const Val* v) {
    m34 = v->a;
    m38 = v->b;
    m3c = v->c;
    return true;
}
