#include "compat/ptr.h"
extern "C" char DAT_0040d564[];
void ReleaseThing(void*);
void DeleteThing(void*);
class CPatrolPath {
  public:
    virtual void a();
    virtual void b();
    virtual CPatrolPath* vfunc_2(unsigned char);
    virtual void d();
    virtual void e();
    char pad[12];
    void* field10;
    int field14;
    void InitMember();
};
CPatrolPath* CPatrolPath::vfunc_2(unsigned char flag) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0040d564);
    ReleaseThing(field10);
    this->field14 = 0;
    this->InitMember();
    if (flag & 1)
        DeleteThing(this);
    return this;
}
