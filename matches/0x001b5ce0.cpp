struct Vec_1b5ce0 {
    float x, y, z;
};
struct VecI {
    float x, y, z;
    int i;
};
class Callee_1b5ce0 {
  public:
    bool Call(Vec_1b5ce0 v, int i);
};
typedef bool (Callee_1b5ce0::*Fn_1b5ce0)(Vec_1b5ce0, int);
class Method2 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(Callee_1b5ce0* a, VecI* p, char* out);
    char pad[0x18];
    Fn_1b5ce0 fn;
};
void Method2::vfunc_2(Callee_1b5ce0* a, VecI* p, char* out) {
    Fn_1b5ce0 f = fn;
    bool r = (a->*f)(*(Vec_1b5ce0*)p, p->i);
    if (out)
        *out = r;
}
