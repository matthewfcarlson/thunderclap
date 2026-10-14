struct T {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0x2c];
    T m;
    bool FUN_0017fd40(const T* p);
};
bool Obj::FUN_0017fd40(const T* p) {
    m.a = p->a;
    m.b = p->b;
    m.c = p->c;
    return true;
}