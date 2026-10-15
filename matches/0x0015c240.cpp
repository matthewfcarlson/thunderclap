struct A {
    char pad[0x138];
    int n;
};
struct B {
    A* get();
};
struct C {
    B* get();
};
extern int t1, t2;
extern "C" void* __cdecl cast(void*, int, void*, void*, int);
class Cond {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool f6(int, C*, int);
    char pad[8];
    unsigned char flag;
};
bool Cond::f6(int x, C* obj, int z) {
    if (!cast(obj, 0, &t1, &t2, 0))
        return false;
    unsigned char v = obj->get()->get()->n > 0;
    return (unsigned char)(v - flag) == 0;
}