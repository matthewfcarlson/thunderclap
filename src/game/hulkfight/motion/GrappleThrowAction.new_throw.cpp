// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00146900..0x0014c470 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleThrowAction
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3a660e0 {
#define TREE_TU_END }
namespace fn_f3a660e0 {} using namespace fn_f3a660e0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f3a660e0 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f3a660e0
namespace hulkfight { namespace motion {
class GrappleAttachedCondition_14a1e0 {
public:
    bool FUN_00146920(char); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f3a660e0 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamBool_14a1e0 : public ParamBoolBase {
public:
    ParamBool_14a1e0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3a660e0 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f3a660e0
namespace hulkfight { namespace motion {
class CivilianAttachedCondition_14a240 {
public:
    char FUN_00146930(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_14a240 : public ParamBoolBase {
public:
    ParamBool_14a240(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CivilianTargetCondition_14a2a0 {
public:
    char FUN_00146940(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_14a2a0 : public ParamBoolBase {
public:
    ParamBool_14a2a0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class GrappleOrientationCondition_14a300 {
public:
    char FUN_00146950(float); /* (unb4) as defined; address taken only */
    bool FUN_00146970(float); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f3a660e0 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamFloatConstRange_14a300 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14a300(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3a660e0 {
class GrappleThrowTrack {
public:
    char FUN_00146a40(int); /* (unb4) as defined; address taken only */
    char FUN_00146a70(void*); /* (unb4) as defined; address taken only */
    bool FUN_00146aa0(int); /* (unb4) as defined; address taken only */
    bool FUN_00146ac0(int); /* (unb4) as defined; address taken only */
    char FUN_00146ae0(int); /* (unb4) as defined; address taken only */
    char FUN_00146b00(int); /* (unb4) as defined; address taken only */
    char FUN_00146b20(float); /* (unb4) as defined; address taken only */
    bool FUN_00146b50(float); /* (unb4) as defined; address taken only */
    bool FUN_00146b80(float); /* (unb4) as defined; address taken only */
    bool FUN_00146bb0(int); /* (unb4) as defined; address taken only */
    char FUN_00146bd0(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamFloatConstRange_14a480 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14a480(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_14a480 : public ParamVectorBase {
public:
    ParamVector_14a480(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3a660e0 {
class GrappleStruggleTrack {
public:
    char FUN_00146be0(int); /* (unb4) as defined; address taken only */
    bool FUN_00146bf0(int); /* (unb4) as defined; address taken only */
    bool FUN_00146c10(int); /* (unb4) as defined; address taken only */
    char FUN_00146c30(void*); /* (unb4) as defined; address taken only */
    char FUN_00146c50(int); /* (unb4) as defined; address taken only */
    bool FUN_00146c70(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CivilianThrowTrack {
public:
    bool FUN_00146c80(int); /* (unb4) as defined; address taken only */
    char FUN_00146cb0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00146ce0(int); /* (unb4) as defined; address taken only */
    char FUN_00146d00(int); /* (unb4) as defined; address taken only */
    bool FUN_00146d20(int); /* (unb4) as defined; address taken only */
    char FUN_00146d40(int); /* (unb4) as defined; address taken only */
    bool FUN_00146d60(float); /* (unb4) as defined; address taken only */
    char FUN_00146d90(float); /* (unb4) as defined; address taken only */
    bool FUN_00146dc0(float); /* (unb4) as defined; address taken only */
    bool FUN_00146df0(int); /* (unb4) as defined; address taken only */
    bool FUN_00146e10(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamFloatConstRange_14a860 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14a860(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_14a860 : public ParamVectorBase {
public:
    ParamVector_14a860(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CivilianAttachTrack_14aad0 {
public:
    char FUN_00146e20(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_14aad0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14aad0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3a660e0 {
class GrappleExecuteTrack {
public:
    char FUN_00147030(int); /* (unb4) as defined; address taken only */
    bool FUN_00147040(int); /* (unb4) as defined; address taken only */
    void FUN_00147050();
    char FUN_00147070(void*); /* (unb4) as defined; address taken only */
    void FUN_00147080();
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
template <class T>
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
} // namespace fn_f3a660e0
namespace hulkfight { namespace motion {
class GrappleAttachJointCondition_14b340 {
public:
    char FUN_00146900(int); /* (unb4) as defined; address taken only */
    void FUN_00146910();
};
} }
namespace fn_f3a660e0 {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamEnumConstList_14b340 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_14b340(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamNameConstList_14b340 : public ParamNameConstListBase {
public:
    ParamNameConstList_14b340(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class GrappleHitReactionTrack_14b5d0 {
public:
    bool FUN_00146e30(int); /* (unb4) as defined; address taken only */
    bool FUN_00146e50(void*); /* (unb4) as defined; address taken only */
    bool FUN_00146e70(int); /* (unb4) as defined; address taken only */
    char FUN_00146e90(float); /* (unb4) as defined; address taken only */
    void FUN_00146eb0();
    bool FUN_00146ed0(int); /* (unb4) as defined; address taken only */
    char FUN_00146ef0(int); /* (unb4) as defined; address taken only */
    bool FUN_00146f10(int); /* (unb4) as defined; address taken only */
    bool FUN_00146f30(char); /* (unb4) as defined; address taken only */
    char FUN_00146f50(void*); /* (unb4) as defined; address taken only */
    bool FUN_00146f70(int); /* (unb4) as defined; address taken only */
    char FUN_00146f90(float); /* (unb4) as defined; address taken only */
    char FUN_00146fc0(int); /* (unb4) as defined; address taken only */
    char FUN_00146fe0(int); /* (unb4) as defined; address taken only */
    char FUN_00147000(int); /* (unb4) as defined; address taken only */
    char FUN_00147020(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f3a660e0 {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamBool_14b5d0 : public ParamBoolBase {
public:
    ParamBool_14b5d0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_14b5d0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_14b5d0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_14b5d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14b5d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_14b5d0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_14b5d0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_14b5d0 : public ParamNameBase {
public:
    ParamName_14b5d0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CivilianAnimationTrack_14b9c0 {
public:
    bool FUN_00147090(int); /* (unb4) as defined; address taken only */
    bool FUN_001470b0(int); /* (unb4) as defined; address taken only */
    void FUN_001470c0();
    char FUN_001470e0(int); /* (unb4) as defined; address taken only */
    char FUN_00147100(int); /* (unb4) as defined; address taken only */
    char FUN_00147120(char); /* (unb4) as defined; address taken only */
    char FUN_00147140(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f3a660e0 {
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};


// 0x0014a1e0 FUN_0014a1e0 (95 B): equivalent/0x0014a1e0.cpp
// sym: ?FUN_0014a1e0@fn_f3a660e0@@YAXXZ @030462cf5ee7 @w566b84f2af9e
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_0014a1e0 @ 0x0014a1e0
void FUN_0014a1e0()
{
    if (DAT_004e0fc8 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14a1e0<hulkfight::motion::GrappleAttachedCondition_14a1e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_14a1e0<hulkfight::motion::GrappleAttachedCondition_14a1e0>("isAttached", (void (hulkfight::motion::GrappleAttachedCondition_14a1e0::*)())&hulkfight::motion::GrappleAttachedCondition_14a1e0::FUN_00146920);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fc4), params, 1);
    }
    DAT_004e0fc8++;
}


// 0x0014a240 FUN_0014a240 (95 B): equivalent/0x0014a240.cpp
// sym: ?FUN_0014a240@fn_f3a660e0@@YAXXZ @eefa8d83c1a6 @wb4b8b0b45b85
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_0014a240 @ 0x0014a240
void FUN_0014a240()
{
    if (DAT_004e0fd0 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14a240<hulkfight::motion::CivilianAttachedCondition_14a240>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_14a240<hulkfight::motion::CivilianAttachedCondition_14a240>("isAttached", (void (hulkfight::motion::CivilianAttachedCondition_14a240::*)())&hulkfight::motion::CivilianAttachedCondition_14a240::FUN_00146930);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fcc), params, 1);
    }
    DAT_004e0fd0++;
}


// 0x0014a2a0 FUN_0014a2a0 (95 B): equivalent/0x0014a2a0.cpp
// sym: ?FUN_0014a2a0@fn_f3a660e0@@YAXXZ @9ae9bf9865bf @w0c3e21cdf81d
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_0014a2a0 @ 0x0014a2a0
void FUN_0014a2a0()
{
    if (DAT_004e0fd8 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14a2a0<hulkfight::motion::CivilianTargetCondition_14a2a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_14a2a0<hulkfight::motion::CivilianTargetCondition_14a2a0>("hasTarget", (void (hulkfight::motion::CivilianTargetCondition_14a2a0::*)())&hulkfight::motion::CivilianTargetCondition_14a2a0::FUN_00146940);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fd4), params, 1);
    }
    DAT_004e0fd8++;
}


// 0x0014a300 FUN_0014a300 (158 B): equivalent/0x0014a300.cpp
// sym: ?FUN_0014a300@fn_f3a660e0@@YAXXZ @73efd9722e72 @wd770f0c2aa80
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_0014a300 @ 0x0014a300
void FUN_0014a300()
{
    if (DAT_004e0fe0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a300<hulkfight::motion::GrappleOrientationCondition_14a300>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14a300<hulkfight::motion::GrappleOrientationCondition_14a300>("angle", (void (hulkfight::motion::GrappleOrientationCondition_14a300::*)())&hulkfight::motion::GrappleOrientationCondition_14a300::FUN_00146950);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a300<hulkfight::motion::GrappleOrientationCondition_14a300>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_14a300<hulkfight::motion::GrappleOrientationCondition_14a300>("arc", (void (hulkfight::motion::GrappleOrientationCondition_14a300::*)())&hulkfight::motion::GrappleOrientationCondition_14a300::FUN_00146970);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fdc), params, 2);
    }
    DAT_004e0fe0++;
}


// 0x0014a480 FUN_0014a480 (613 B): equivalent/0x0014a480.cpp
// sym: ?FUN_0014a480@fn_f3a660e0@@YAXXZ @47312fb47d2f @w52d9dec57944
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0014a480 @ 0x0014a480
void FUN_0014a480()
{
    if (DAT_004e0ff0 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("timeBegin", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146a40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_14a480<GrappleThrowTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_14a480<GrappleThrowTrack>("direction", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146a70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("distanceMin", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146aa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("distanceMax", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146ac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("velocityMin", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146ae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("velocityMax", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146b00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("trackingMin", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146b20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("trackingMax", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146b50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("yFixupAngle", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146b80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("stunTimeMin", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146bb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("stunTimeMax", (void (GrappleThrowTrack::*)())&GrappleThrowTrack::FUN_00146bd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fec), params, 11);
    }
    DAT_004e0ff0++;
}


// 0x0014a6f0 FUN_0014a6f0 (358 B): equivalent/0x0014a6f0.cpp
// sym: ?FUN_0014a6f0@fn_f3a660e0@@YAXXZ @a9416428c651 @wd5c86282bf7b
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 14/14)
// FUN_0014a6f0 @ 0x0014a6f0
void FUN_0014a6f0()
{
    if (DAT_004e0ff8 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeBegin", (void (GrappleStruggleTrack::*)())&GrappleStruggleTrack::FUN_00146be0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeEnd", (void (GrappleStruggleTrack::*)())&GrappleStruggleTrack::FUN_00146bf0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeInput", (void (GrappleStruggleTrack::*)())&GrappleStruggleTrack::FUN_00146c10);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeRateMin", (void (GrappleStruggleTrack::*)())&GrappleStruggleTrack::FUN_00146c30);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeRateMax", (void (GrappleStruggleTrack::*)())&GrappleStruggleTrack::FUN_00146c50);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeButtonRate", (void (GrappleStruggleTrack::*)())&GrappleStruggleTrack::FUN_00146c70);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ff4), params, 6);
    }
    DAT_004e0ff8++;
}


// 0x0014a860 FUN_0014a860 (613 B): equivalent/0x0014a860.cpp
// sym: ?FUN_0014a860@fn_f3a660e0@@YAXXZ @ea7708f08671 @waddd02977075
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0014a860 @ 0x0014a860
void FUN_0014a860()
{
    if (DAT_004e1000 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("timeBegin", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146c80);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_14a860<CivilianThrowTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_14a860<CivilianThrowTrack>("direction", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146cb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("distanceMin", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146ce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("distanceMax", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146d00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("velocityMin", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146d20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("velocityMax", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146d40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("trackingMin", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146d60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("trackingMax", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146d90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("yFixupAngle", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146dc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("stunTimeMin", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146df0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("stunTimeMax", (void (CivilianThrowTrack::*)())&CivilianThrowTrack::FUN_00146e10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ffc), params, 11);
    }
    DAT_004e1000++;
}


// 0x0014aad0 FUN_0014aad0 (95 B): equivalent/0x0014aad0.cpp
// sym: ?FUN_0014aad0@fn_f3a660e0@@YAXXZ @7d80cb45842c @w6f5fbbfd9158
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0014aad0 @ 0x0014aad0
void FUN_0014aad0()
{
    if (DAT_004e1008 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14aad0<hulkfight::motion::CivilianAttachTrack_14aad0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14aad0<hulkfight::motion::CivilianAttachTrack_14aad0>("timeBegin", (void (hulkfight::motion::CivilianAttachTrack_14aad0::*)())&hulkfight::motion::CivilianAttachTrack_14aad0::FUN_00146e20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1004), params, 1);
    }
    DAT_004e1008++;
}


// 0x0014ab30 FUN_0014ab30 (307 B): equivalent/0x0014ab30.cpp
// sym: ?FUN_0014ab30@fn_f3a660e0@@YAXXZ @f1a94ab562e0 @w5a3f4c0dc250
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0014ab30 @ 0x0014ab30
void FUN_0014ab30()
{
    if (DAT_004e1018 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleExecuteTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<GrappleExecuteTrack>("timeBegin", (void (GrappleExecuteTrack::*)())&GrappleExecuteTrack::FUN_00147030);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleExecuteTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<GrappleExecuteTrack>("timeEnd", (void (GrappleExecuteTrack::*)())&GrappleExecuteTrack::FUN_00147040);
        mem = FUN_0008d690((int)sizeof(ParamBranch<GrappleExecuteTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBranch<GrappleExecuteTrack>("branch", &GrappleExecuteTrack::FUN_00147050);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<GrappleExecuteTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<GrappleExecuteTrack>("priority", (void (GrappleExecuteTrack::*)())&GrappleExecuteTrack::FUN_00147070);
        mem = FUN_0008d690((int)sizeof(ParamConditionGroup<GrappleExecuteTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamConditionGroup<GrappleExecuteTrack>("conditionGroup", &GrappleExecuteTrack::FUN_00147080);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1014), params, 5);
    }
    DAT_004e1018++;
}


// 0x0014b340 FUN_0014b340 (176 B): equivalent/0x0014b340.cpp
// sym: ?FUN_0014b340@fn_f3a660e0@@YAXXZ @40c7c0dcf05a @waa3694365786
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_0014b340 @ 0x0014b340
void FUN_0014b340()
{
    if (DAT_004e0fc0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), (void (hulkfight::motion::GrappleAttachJointCondition_14b340::*)())&hulkfight::motion::GrappleAttachJointCondition_14b340::FUN_00146900);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamNameConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>("joint", &hulkfight::motion::GrappleAttachJointCondition_14b340::FUN_00146910);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fbc), params, 2);
    }
    DAT_004e0fc0++;
}


// 0x0014b5d0 FUN_0014b5d0 (911 B): equivalent/0x0014b5d0.cpp
// sym: ?FUN_0014b5d0@fn_f3a660e0@@YAXXZ @906c58ee7780 @w1c00074cd91b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0014b5d0 @ 0x0014b5d0
void FUN_0014b5d0()
{
    if (DAT_004e1010 == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("timeBegin", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e30);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e50);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("directionFrom", ((const char**)&DAT_004ae340), 2, (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("direction", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e90);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("flag", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146eb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("damage", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146ed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("damageMax", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146ef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("interruptPriority", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f10);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("interrupt", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("hitReactionTime", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f50);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDirectionFrom", ((const char**)&DAT_004ae340), 2, (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDirection", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDistance", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146fc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackTime", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146fe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("height", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00147000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("stunTime", (void (hulkfight::motion::GrappleHitReactionTrack_14b5d0::*)())&hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00147020);
        FUN_002347b0(((ParamRegistry*)&DAT_004e100c), params, 16);
    }
    DAT_004e1010++;
}


// 0x0014b9c0 FUN_0014b9c0 (409 B): equivalent/0x0014b9c0.cpp
// sym: ?FUN_0014b9c0@fn_f3a660e0@@YAXXZ @d63be11a680b @wee25b256ff0b
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 16/16)
// FUN_0014b9c0 @ 0x0014b9c0
void FUN_0014b9c0()
{
    if ((*(int*)&DAT_004e1020) == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("timeBegin", (void (hulkfight::motion::CivilianAnimationTrack_14b9c0::*)())&hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_00147090);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("timeEnd", (void (hulkfight::motion::CivilianAnimationTrack_14b9c0::*)())&hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_001470b0);
        mem = FUN_0008d690((int)sizeof(ParamName<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<hulkfight::motion::CivilianAnimationTrack_14b9c0>("animation", &hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_001470c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("speed", (void (hulkfight::motion::CivilianAnimationTrack_14b9c0::*)())&hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_001470e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("startFrame", (void (hulkfight::motion::CivilianAnimationTrack_14b9c0::*)())&hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_00147100);
        mem = FUN_0008d690((int)sizeof(ParamBool<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<hulkfight::motion::CivilianAnimationTrack_14b9c0>("cyclic", (void (hulkfight::motion::CivilianAnimationTrack_14b9c0::*)())&hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_00147120);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("blendTime", (void (hulkfight::motion::CivilianAnimationTrack_14b9c0::*)())&hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_00147140);
        FUN_002347b0(((ParamRegistry*)&DAT_004e101c), params, 7);
    }
    (*(int*)&DAT_004e1020)++;
}

} // namespace fn_f3a660e0
