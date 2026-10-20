#include "compat/ptr.h"
extern int vftable_183060;
class Sub_183060 {
  public:
    void Init();
};
namespace hulkfight { namespace motion { class PropStateByNameCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual PropStateByNameCondition* vfunc_5(unsigned int);
    virtual void vfunc_6();
    char pad[0x18 - 4];
    void Second();
}; }}
extern void thunk_FUN_00267090(void*);
hulkfight::motion::PropStateByNameCondition* hulkfight::motion::PropStateByNameCondition::vfunc_5(unsigned int flags) {
    Sub_183060* s = (Sub_183060*)((char*)this + 0x18);
    *(hulk_intptr*)this = (hulk_intptr)&vftable_183060;
    s->Init();
    Second();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}