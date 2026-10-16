#include "gen/fight.h"

extern "C" char DAT_0040d984[];
typedef unsigned int uint;
extern void* __cdecl operator_new(unsigned int);
class Condition_113d90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[0x14];
};
class Base_113d90 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_5() {
    Condition_113d90* p = (Condition_113d90*)operator_new(0x18);
    if (p) {
        ((Base_113d90*)p)->Init(0);
        *(uint*)p = ((int)DAT_0040d984);
        *(uint*)((char*)p + 0xc) = 0;
        *((char*)p + 0x10) = 0;
        *(uint*)((char*)p + 0x14) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
