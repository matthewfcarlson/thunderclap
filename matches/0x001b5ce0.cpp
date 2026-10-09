struct Vec {
    float x, y, z;
};
struct VecI {
    float x, y, z;
    int i;
};
class Callee {
  public:
    bool Call(Vec v, int i);
};
typedef bool (Callee::*Fn)(Vec, int);
class Method2 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(Callee* a, VecI* p, char* out);
    char pad[0x18];
    Fn fn;
};
void Method2::vfunc_2(Callee* a, VecI* p, char* out) {
    Fn f = fn;
    bool r = (a->*f)(*(Vec*)p, p->i);
    if (out)
        *out = r;
}
