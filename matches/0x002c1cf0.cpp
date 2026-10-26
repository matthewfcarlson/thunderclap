#include "decls/data/engine/pure3d/prop.h"
// data: gFactory_2c1cf0 = DAT_0052c2a0

struct Request {
    int x[8];
    char a;
    char b;
};
class Result_2c1cf0 {
  public:
    virtual void Finish();
};
class Factory_2c1cf0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual Result_2c1cf0* Create(Request*);
};
class Owner_2c1cf0 {
  public:
    char pad[0x10];
    Result_2c1cf0* result;
    bool Run(int, int, int, int, int, int, int, int);
};
bool Owner_2c1cf0::Run(int a, int b, int c, int d, int e, int f, int g, int h) {
    Request request;
    request.b = 0;
    request.x[0] = a;
    request.x[1] = b;
    request.x[2] = c;
    request.x[3] = d;
    request.x[4] = e;
    request.x[5] = f;
    request.x[6] = g;
    request.x[7] = h;
    request.a = 1;
    result = (*(Factory_2c1cf0**)&DAT_0052c2a0)->Create(&request);
    if (!result)
        return false;
    result->Finish();
    return true;
}
