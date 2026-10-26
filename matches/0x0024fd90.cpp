#include "compat/ptr.h"
#include "gen/audio.h"

class SeqEvent_24fd90 {
  public:
    char vfunc_1(int*);
};
class SeqEventContainer_24fd90 {
  public:
    char vfunc_1(int*);
};
extern "C" char Parse(const char*, const char*);
extern "C" char Expr(int*, const char*, char*);

int audio::SeqEventCondition::vfunc_1(void* __p0) { int * p = (int *)__p0;

    if (((SeqEvent_24fd90*)this)->vfunc_1(p) && Parse((const char*)*(hulk_intptr*)p, "\n[\n")) {
        ++*(int*)((char*)*(hulk_intptr*)p + 0x24);
        if (((SeqEventContainer_24fd90*)this)->vfunc_1(p) && Expr(p, "mExpression", (char*)this + 0x14)) {
            --*(int*)((char*)*(hulk_intptr*)p + 0x24);
            p = (int*)*(hulk_intptr*)p;
            if (Parse((const char*)p, "]\n"))
                return 1;
        }
    }
    return 0;
}
