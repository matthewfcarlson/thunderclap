// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023d810..0x0023df40 (kind game, layer engine, confidence high), dominant class fight::CommentTrack
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_f010c1af {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f010c1af {} using namespace fn_f010c1af;
#include "engine/fight.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f010c1af {
extern "C" void* FUN_0008d690(unsigned int size);
namespace fight {
class CommentCondition {
public:
    void FUN_0023d880();
};
}
namespace fight {
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
namespace fight {
class CommentTrack {
public:
    void FUN_0023d970();
};
}


// 0x0023dc90 FUN_0023dc90 (95 B): equivalent/0x0023dc90.cpp
// sym: ?FUN_0023dc90@fn_f010c1af@@YAXXZ @df7bf089d55f @w93f237048200
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_0023dc90 @ 0x0023dc90
void FUN_0023dc90()
{
    if (DAT_004e5c60 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamString<fight::CommentCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<fight::CommentCondition>("text", &fight::CommentCondition::FUN_0023d880);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c5c), params, 1);
    }
    DAT_004e5c60++;
}


// 0x0023dcf0 FUN_0023dcf0 (95 B): equivalent/0x0023dcf0.cpp
// sym: ?FUN_0023dcf0@fn_f010c1af@@YAXXZ @1f92823d1519 @w4ac90f256ef0
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_0023dcf0 @ 0x0023dcf0
void FUN_0023dcf0()
{
    if (DAT_004e5c68 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamString<fight::CommentTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<fight::CommentTrack>("text", &fight::CommentTrack::FUN_0023d970);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c64), params, 1);
    }
    DAT_004e5c68++;
}

} // namespace fn_f010c1af
