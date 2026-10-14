class Base_224be0 {
  public:
    Base_224be0();
    virtual void g();
    char b[12];
};
class Sub_224be0 {
  public:
    Sub_224be0();
    void Init(void* p);
    char pad[8];
};
struct Arg_224be0 {
    char x[16];
    int a;
    int b;
    char c[4];
};
class JointDriver : public Base_224be0 {
  public:
    JointDriver(Arg_224be0* p);
    virtual void f();
    int m10;
    int m14;
    Sub_224be0 m18;
};
extern int gCount_224be0;
extern int gMax_224be0;
JointDriver::JointDriver(Arg_224be0* p) {
    m10 = p->a;
    m14 = p->b;
    m18.Init((char*)p + 0x18);
    int n = gCount_224be0 + 1;
    gCount_224be0 = n;
    if (n > gMax_224be0)
        gMax_224be0 = n;
}
void JointDriver::f() {}
