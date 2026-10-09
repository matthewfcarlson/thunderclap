class CActorManager;
struct Vector {
    float x, y, z;
};
class Method2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int);
    char pad[0x18];
};
class Function {
  public:
    virtual void g0();
};
class Closure2 : public Method2, public Function {
  public:
    int val;
    virtual void vfunc_2(int);
};
void Closure2::vfunc_2(int x) {
    Method2::vfunc_2(val);
}
