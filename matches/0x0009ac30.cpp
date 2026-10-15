class CCameraManager {
  public:
    void f();
};
struct Arg {
    bool b;
    char pad[3];
};
union Slot {
    unsigned int u;
    bool b;
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method4 : public Function {
  public:
    virtual void vfunc_2(CCameraManager*, Arg*, int);
    char pad[24];
    typedef void (CCameraManager::*Fn)(unsigned int, unsigned int, unsigned int, float);
    Fn fn;
};
void Method4::vfunc_2(CCameraManager* obj, Arg* p, int) {
    Slot a, b;
    a.b = p->b;
    ++p;
    b.b = p->b;
    ++p;
    (obj->*fn)(a.u, b.u, p->b, *(float*)(p + 1));
}