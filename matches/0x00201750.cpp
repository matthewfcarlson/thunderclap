class Callee_201750 {
  public:
    void f(unsigned short*, int, int, int);
};
class Obj_201750 {
  public:
    char pad[0x284];
    Callee_201750* member;
    unsigned short f();
};
unsigned short Obj_201750::f() {
    unsigned short local;
    member->f(&local, 1, 2, 1);
    return local;
}
