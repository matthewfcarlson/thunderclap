class Obj {
  public:
    virtual void a();
    virtual void b();
};
class Target {
  public:
    char pad[0x14];
    int x14;
    Obj* p18;
    int x1c;
    void f();
};
void Target::f() {
    if (p18) {
        p18->b();
        p18 = 0;
    }
    x1c = 0;
    x14 = 0xf;
}