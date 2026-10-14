class Obj_232a50 {
  public:
    virtual void f0();
    virtual void f1();
};
void __cdecl thunk(void*);
class Target_232a50 {
  public:
    Obj_232a50* m;
    Target_232a50* f(unsigned char flags);
};
Target_232a50* Target_232a50::f(unsigned char flags) {
    if (m) {
        m->f1();
        m = 0;
    }
    if (flags & 1)
        thunk(this);
    return this;
}