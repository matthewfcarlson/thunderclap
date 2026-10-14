class Obj_2807d0 {
  public:
    virtual void a();
    virtual void b();
};
class Target_2807d0 {
  public:
    char pad[0x14];
    int x14;
    Obj_2807d0* p18;
    int x1c;
    void f();
};
void Target_2807d0::f() {
    if (p18) {
        p18->b();
        p18 = 0;
    }
    x1c = 0;
    x14 = 0xf;
}