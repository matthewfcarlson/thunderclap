struct T_17fd40 {
    int a;
    int b;
    int c;
};
class Obj_17fd40 {
  public:
    char pad[0x2c];
    T_17fd40 m;
    bool FUN_0017fd40(const T_17fd40* p);
};
bool Obj_17fd40::FUN_0017fd40(const T_17fd40* p) {
    m.a = p->a;
    m.b = p->b;
    m.c = p->c;
    return true;
}