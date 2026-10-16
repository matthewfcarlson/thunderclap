#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
namespace fight {
class Base {
  public:
    Base() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
};
class Sub {
  public:
    Sub() throw();
};
class Tail {
  public:
    Tail() throw();
};
class ExecuteTrack_239cc0 : public Base {
  public:
    ExecuteTrack_239cc0() throw() : fieldC(0), field10(-1.0f), field20(-1000) {}
    int fieldC;
    float field10;
    Sub sub;
    char pad2[11];
    int field20;
    Tail tail;
};

} // namespace fight
template <> void* fight::TrackFactoryTemplate<fight::ExecuteTrack>::vfunc_5() {
    return (void*)(new ExecuteTrack_239cc0);
}
