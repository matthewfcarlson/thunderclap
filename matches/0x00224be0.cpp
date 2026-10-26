#include "decls/data/engine/choreo2.h"
// data: gCount_224be0 = DAT_004e5aac

class Driver_224be0 {
  public:
    Driver_224be0();
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
class JointDriver : public Driver_224be0 {
  public:
    JointDriver(Arg_224be0* p);
    virtual void f();
    int m10;
    int m14;
    Sub_224be0 m18;
};
JointDriver::JointDriver(Arg_224be0* p) {
    m10 = p->a;
    m14 = p->b;
    m18.Init((char*)p + 0x18);
    int n = (*(int*)&DAT_004e5aac) + 1;
    (*(int*)&DAT_004e5aac) = n;
    if (n > (*(int*)&DAT_004e5ab0))
        (*(int*)&DAT_004e5ab0) = n;
}
void JointDriver::f() {}
