#include "gen/fight.h"

extern "C" char DAT_00428bf8[];
extern void* __cdecl alloc(unsigned int);
class CommentCondition_23de30 {
  public:
    int vtable;
    char pad[8];
    int value;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<fight::CommentCondition>::vfunc_5() {
    CommentCondition_23de30* p = (CommentCondition_23de30*)alloc(0x10);
    if (p) {
        p->Init(3);
        p->vtable = ((int)DAT_00428bf8);
        p->value = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
