struct In {
    int a;
    int b;
    int c;
};
class Obj_68a10 {
  public:
    char pad[0x2c];
    int m1;
    int m2;
    int m3;
    bool Set(In* p);
};
bool Obj_68a10::Set(In* p) {
    m1 = p->a;
    m2 = p->b;
    m3 = p->c;
    return true;
}
