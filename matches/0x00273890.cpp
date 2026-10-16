#include "gen/core.h"

class Request_273890 {
  public:
    virtual void a();
};
class ObjV {
  public:
    virtual void a();
    virtual void b();
};
class Inner_273890 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual int h();
    int helper();
};
struct Data_273890 {
    char pad[4];
    ObjV obj;
    char pad2[4];
    Inner_273890* inner;
    char pad3[4];
    int value;
};

int core::FileRequest::vfunc_4() {
    Inner_273890* p = (*(Data_273890 * *)&this->f_08)->inner;
    int first = p->h();
    int second = p->helper();
    (*(Data_273890 * *)&this->f_08)->obj.a();
    (*(Data_273890 * *)&this->f_08)->value = second;
    (*(Data_273890 * *)&this->f_08)->obj.b();
    return first;
}
