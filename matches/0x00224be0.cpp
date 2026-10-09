class Base { public: Base(); virtual void g(); char b[12]; };
class Sub { public: Sub(); void Init(void* p); char pad[8]; };
struct Arg { char x[16]; int a; int b; char c[4]; };
class JointDriver : public Base {
public:
    JointDriver(Arg* p);
    virtual void f();
    int m10;
    int m14;
    Sub m18;
};
extern int gCount;
extern int gMax;
JointDriver::JointDriver(Arg* p) {
    m10 = p->a;
    m14 = p->b;
    m18.Init((char*)p + 0x18);
    int n = gCount + 1;
    gCount = n;
    if (n > gMax) gMax = n;
}
void JointDriver::f() {}
