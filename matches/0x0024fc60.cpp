#include "gen/audio.h"

struct SeqEventCondition_nv_24fc60 {
    bool Base0(void*);
    bool Base1(void*);
};
bool Check(void*, void*);

int audio::SeqEventCondition::vfunc_0(void* __p0) { void * arg = (void *)__p0;

    if (((SeqEventCondition_nv_24fc60*)this)->Base0(arg) && ((SeqEventCondition_nv_24fc60*)this)->Base1(arg) && Check(arg, (char*)this + 0x14))
        return 1;
    return 0;
}
