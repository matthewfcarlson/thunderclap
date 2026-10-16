#include "gen/fight.h"

extern "C" char DAT_0041922c[];
class PropStateByIndexCondition_18ba50 {
  public:
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    void Init(int);
};
extern void* Alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropStateByIndexCondition>::vfunc_5() {
    PropStateByIndexCondition_18ba50* p = (PropStateByIndexCondition_18ba50*)Alloc(0x18);
    if (p) {
        p->Init(0);
        p->a = ((int)DAT_0041922c);
        p->d = -1;
        p->e = 0;
        p->f = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
