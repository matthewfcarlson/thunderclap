// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fda5378a {
#define TREE_TU_END }
namespace fn_fda5378a {} using namespace fn_fda5378a;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fda5378a {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fda5378a
namespace hulkfight { namespace ai {
class HasGroundPointCondition_118e40 {
public:
    void FUN_00114eb0();
    void FUN_00114ed0();
};
} }
namespace fn_fda5378a {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_fda5378a
namespace fight {
template <class T>
class ParamBool_118e40 : public ParamBoolBase {
public:
    ParamBool_118e40(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fda5378a {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_fda5378a
namespace hulkfight { namespace ai {
class LocatorDistanceCondition_118ee0 {
public:
    void FUN_00114ee0();
    void FUN_00114ef0();
};
} }
namespace fn_fda5378a {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_fda5378a
namespace fight {
template <class T>
class ParamEnumConstList_118ee0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_118ee0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_118ee0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_118ee0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fda5378a {
class ComputeDropZoneCondition {
public:
    void FUN_00114f10();
    void FUN_00114f30();
    void FUN_00114f50();
    void FUN_00114f60();
    void FUN_00114f80();
    void FUN_00114fa0();
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class HasGroundPointExtendedCondition {
public:
    void FUN_00114fb0();
    void FUN_00114fd0();
    void FUN_00114fe0();
    void FUN_00115000();
    void FUN_00115020();
    void FUN_00115040();
    void FUN_00115060();
    void FUN_00115080();
    void FUN_001150b0();
};
} // namespace fn_fda5378a
namespace hulkfight { namespace ai {
class MotionStopTrack_1193e0 {
public:
    void FUN_00115110();
    void FUN_00115120();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_1193e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1193e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fda5378a {
class MotionFacingTrack {
public:
    void FUN_00115130();
    void FUN_00115140();
    void FUN_00115160();
    void FUN_001151a0();
    void FUN_001151d0();
};
class MotionBoostTrack {
public:
    void FUN_001151e0();
    void FUN_001151f0();
    void FUN_00115210();
    void FUN_00115230();
    void FUN_00115240();
    void FUN_00115250();
    void FUN_00115270();
    void FUN_00115280();
};
class MotionTargetTrack {
public:
    void FUN_001153e0();
    void FUN_001153f0();
    void FUN_00115410();
    void FUN_00115450();
    void FUN_00115480();
};
class MotionChaseTrack {
public:
    void FUN_00115490();
    void FUN_001154a0();
    void FUN_001154c0();
    void FUN_001154e0();
    void FUN_00115500();
    void FUN_00115520();
    void FUN_00115540();
    void FUN_00115550();
};
class MotionClosestWaypointTrack {
public:
    void FUN_00115560();
    void FUN_00115570();
    void FUN_00115590();
    void FUN_001155b0();
    void FUN_001155d0();
    void FUN_001155f0();
    void FUN_00115610();
    void FUN_00115630();
    void FUN_00115650();
    void FUN_00115670();
    void FUN_00115690();
};
} // namespace fn_fda5378a
namespace fight {
template <class T>
class ParamBool_119aa0 : public ParamBoolBase {
public:
    ParamBool_119aa0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_119aa0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_119aa0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fda5378a {
class MotionLocatorTrack {
public:
    void FUN_00115290();
    void FUN_001152a0();
    void FUN_001152c0();
    void FUN_001152e0();
    void FUN_00115300();
    void FUN_00115320();
    void FUN_00115340();
    void FUN_00115360();
    void FUN_00115380();
    void FUN_001153a0();
    void FUN_001153c0();
    void FUN_001153d0();
};
} // namespace fn_fda5378a
namespace fight {
template <class T>
class ParamBool_11ab30 : public ParamBoolBase {
public:
    ParamBool_11ab30(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_11ab30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_11ab30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fda5378a {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_fda5378a
namespace fight {
template <class T>
class ParamName_11ab30 : public ParamNameBase {
public:
    ParamName_11ab30(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_fda5378a {

// 0x00118e40 FUN_00118e40 (158 B): equivalent/0x00118e40.cpp
// sym: ?FUN_00118e40@fn_fda5378a@@YAXXZ @1dcbf964f785 @w16f1a73127b5
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00118e40 @ 0x00118e40
void FUN_00118e40()
{
    if (DAT_004e0c28 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_118e40<hulkfight::ai::HasGroundPointCondition_118e40>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_118e40<hulkfight::ai::HasGroundPointCondition_118e40>("groundPoint", &hulkfight::ai::HasGroundPointCondition_118e40::FUN_00114eb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_118e40<hulkfight::ai::HasGroundPointCondition_118e40>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_118e40<hulkfight::ai::HasGroundPointCondition_118e40>("useMyTargetInstead", &hulkfight::ai::HasGroundPointCondition_118e40::FUN_00114ed0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c24), params, 2);
    }
    DAT_004e0c28++;
}


// 0x00118ee0 FUN_00118ee0 (176 B): equivalent/0x00118ee0.cpp
// sym: ?FUN_00118ee0@fn_fda5378a@@YAXXZ @15b84e19d96f @we21b2d1a2c1f
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00118ee0 @ 0x00118ee0
void FUN_00118ee0()
{
    if (DAT_004e0c30 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_118ee0<hulkfight::ai::LocatorDistanceCondition_118ee0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_118ee0<hulkfight::ai::LocatorDistanceCondition_118ee0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::LocatorDistanceCondition_118ee0::FUN_00114ee0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_118ee0<hulkfight::ai::LocatorDistanceCondition_118ee0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_118ee0<hulkfight::ai::LocatorDistanceCondition_118ee0>("distance", &hulkfight::ai::LocatorDistanceCondition_118ee0::FUN_00114ef0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c2c), params, 2);
    }
    DAT_004e0c30++;
}


// 0x00118f90 FUN_00118f90 (358 B): equivalent/0x00118f90.cpp
// sym: ?FUN_00118f90@fn_fda5378a@@YAXXZ @f07f1fbcadba @w64d8c44259d6
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 14/14)
// FUN_00118f90 @ 0x00118f90
void FUN_00118f90()
{
    if (DAT_004e0c38 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ComputeDropZoneCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("increment", &ComputeDropZoneCondition::FUN_00114f10);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ComputeDropZoneCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("heightMax", &ComputeDropZoneCondition::FUN_00114f30);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ComputeDropZoneCondition>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("dropDistance", &ComputeDropZoneCondition::FUN_00114f50);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ComputeDropZoneCondition>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("boostHeightTolerance", &ComputeDropZoneCondition::FUN_00114f60);
        mem = FUN_0008d690((int)sizeof(ParamBool<ComputeDropZoneCondition>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<ComputeDropZoneCondition>("useOffset", &ComputeDropZoneCondition::FUN_00114f80);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ComputeDropZoneCondition>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("offset", &ComputeDropZoneCondition::FUN_00114fa0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c34), params, 6);
    }
    DAT_004e0c38++;
}


// 0x00119100 FUN_00119100 (511 B): equivalent/0x00119100.cpp
// sym: ?FUN_00119100@fn_fda5378a@@YAXXZ @892e29151ded @wbba6ec77869f
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 20/20)
// FUN_00119100 @ 0x00119100
void FUN_00119100()
{
    if (DAT_004e0c40 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamBool<HasGroundPointExtendedCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamBool<HasGroundPointExtendedCondition>("groundPoint", &HasGroundPointExtendedCondition::FUN_00114fb0);
        mem = FUN_0008d690((int)sizeof(ParamBool<HasGroundPointExtendedCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamBool<HasGroundPointExtendedCondition>("useMyVelocity", &HasGroundPointExtendedCondition::FUN_00114fd0);
        mem = FUN_0008d690((int)sizeof(ParamBool<HasGroundPointExtendedCondition>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<HasGroundPointExtendedCondition>("useMyFacing", &HasGroundPointExtendedCondition::FUN_00114fe0);
        mem = FUN_0008d690((int)sizeof(ParamBool<HasGroundPointExtendedCondition>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<HasGroundPointExtendedCondition>("target", &HasGroundPointExtendedCondition::FUN_00115000);
        mem = FUN_0008d690((int)sizeof(ParamBool<HasGroundPointExtendedCondition>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<HasGroundPointExtendedCondition>("useCustomOffset", &HasGroundPointExtendedCondition::FUN_00115020);
        mem = FUN_0008d690((int)sizeof(ParamBool<HasGroundPointExtendedCondition>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<HasGroundPointExtendedCondition>("absolute", &HasGroundPointExtendedCondition::FUN_00115040);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HasGroundPointExtendedCondition>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<HasGroundPointExtendedCondition>("distance", &HasGroundPointExtendedCondition::FUN_00115060);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<HasGroundPointExtendedCondition>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<HasGroundPointExtendedCondition>("allowedHeight", &HasGroundPointExtendedCondition::FUN_00115080);
        mem = FUN_0008d690((int)sizeof(ParamVector<HasGroundPointExtendedCondition>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamVector<HasGroundPointExtendedCondition>("customOffset", &HasGroundPointExtendedCondition::FUN_001150b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c3c), params, 9);
    }
    DAT_004e0c40++;
}


// 0x001193e0 FUN_001193e0 (158 B): equivalent/0x001193e0.cpp
// sym: ?FUN_001193e0@fn_fda5378a@@YAXXZ @7e8024615307 @wfee6f77abe46
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001193e0 @ 0x001193e0
void FUN_001193e0()
{
    if (DAT_004e0c50 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1193e0<hulkfight::ai::MotionStopTrack_1193e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1193e0<hulkfight::ai::MotionStopTrack_1193e0>("timeBegin", &hulkfight::ai::MotionStopTrack_1193e0::FUN_00115110);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1193e0<hulkfight::ai::MotionStopTrack_1193e0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1193e0<hulkfight::ai::MotionStopTrack_1193e0>("timeEnd", &hulkfight::ai::MotionStopTrack_1193e0::FUN_00115120);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c4c), params, 2);
    }
    DAT_004e0c50++;
}


// 0x00119480 FUN_00119480 (307 B): equivalent/0x00119480.cpp
// sym: ?FUN_00119480@fn_fda5378a@@YAXXZ @740fad131b4c @w151df125218f
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// FUN_00119480 @ 0x00119480
void FUN_00119480()
{
    if (DAT_004e0c58 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionFacingTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<MotionFacingTrack>("timeBegin", &MotionFacingTrack::FUN_00115130);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionFacingTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<MotionFacingTrack>("timeEnd", &MotionFacingTrack::FUN_00115140);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionFacingTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<MotionFacingTrack>("angle", &MotionFacingTrack::FUN_00115160);
        mem = FUN_0008d690((int)sizeof(ParamVector<MotionFacingTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<MotionFacingTrack>("vector", &MotionFacingTrack::FUN_001151a0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionFacingTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<MotionFacingTrack>("speed", &MotionFacingTrack::FUN_001151d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c54), params, 5);
    }
    DAT_004e0c58++;
}


// 0x001195c0 FUN_001195c0 (460 B): equivalent/0x001195c0.cpp
// sym: ?FUN_001195c0@fn_fda5378a@@YAXXZ @56437c5c8e1b @w83ebd5d960e4
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_001195c0 @ 0x001195c0
void FUN_001195c0()
{
    if (DAT_004e0c60 == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionBoostTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<MotionBoostTrack>("timeBegin", &MotionBoostTrack::FUN_001151e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionBoostTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<MotionBoostTrack>("timeEnd", &MotionBoostTrack::FUN_001151f0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionBoostTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<MotionBoostTrack>("distanceMin", &MotionBoostTrack::FUN_00115210);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionBoostTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<MotionBoostTrack>("distanceMax", &MotionBoostTrack::FUN_00115230);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionBoostTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<MotionBoostTrack>("heightMin", &MotionBoostTrack::FUN_00115240);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionBoostTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<MotionBoostTrack>("heightMax", &MotionBoostTrack::FUN_00115250);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionBoostTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<MotionBoostTrack>("speed", &MotionBoostTrack::FUN_00115270);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionBoostTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<MotionBoostTrack>("boost", &MotionBoostTrack::FUN_00115280);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c5c), params, 8);
    }
    DAT_004e0c60++;
}


// 0x00119790 FUN_00119790 (307 B): equivalent/0x00119790.cpp
// sym: ?FUN_00119790@fn_fda5378a@@YAXXZ @5f69afa9aae3 @w13e403a8ec1e
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 12/12)
// FUN_00119790 @ 0x00119790
void FUN_00119790()
{
    if (DAT_004e0c70 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionTargetTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<MotionTargetTrack>("timeBegin", &MotionTargetTrack::FUN_001153e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionTargetTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<MotionTargetTrack>("timeEnd", &MotionTargetTrack::FUN_001153f0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionTargetTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<MotionTargetTrack>("angle", &MotionTargetTrack::FUN_00115410);
        mem = FUN_0008d690((int)sizeof(ParamVector<MotionTargetTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<MotionTargetTrack>("vector", &MotionTargetTrack::FUN_00115450);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionTargetTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<MotionTargetTrack>("speed", &MotionTargetTrack::FUN_00115480);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c6c), params, 5);
    }
    DAT_004e0c70++;
}


// 0x001198d0 FUN_001198d0 (460 B): equivalent/0x001198d0.cpp
// sym: ?FUN_001198d0@fn_fda5378a@@YAXXZ @000aed61b64f @w51c1afd3116c
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_001198d0 @ 0x001198d0
void FUN_001198d0()
{
    if (DAT_004e0c78 == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionChaseTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<MotionChaseTrack>("timeBegin", &MotionChaseTrack::FUN_00115490);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionChaseTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<MotionChaseTrack>("timeEnd", &MotionChaseTrack::FUN_001154a0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionChaseTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<MotionChaseTrack>("distanceMin", &MotionChaseTrack::FUN_001154c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionChaseTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<MotionChaseTrack>("distanceMax", &MotionChaseTrack::FUN_001154e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionChaseTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<MotionChaseTrack>("heightMin", &MotionChaseTrack::FUN_00115500);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionChaseTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<MotionChaseTrack>("heightMax", &MotionChaseTrack::FUN_00115520);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionChaseTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<MotionChaseTrack>("speed", &MotionChaseTrack::FUN_00115540);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<MotionChaseTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<MotionChaseTrack>("boost", &MotionChaseTrack::FUN_00115550);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c74), params, 8);
    }
    DAT_004e0c78++;
}


// 0x00119aa0 FUN_00119aa0 (613 B): equivalent/0x00119aa0.cpp
// sym: ?FUN_00119aa0@fn_fda5378a@@YAXXZ @0c1e3fdc368e @w9af3851c1b41
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_00119aa0 @ 0x00119aa0
void FUN_00119aa0()
{
    if (DAT_004e0c80 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("timeBegin", &MotionClosestWaypointTrack::FUN_00115560);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("timeEnd", &MotionClosestWaypointTrack::FUN_00115570);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("speed", &MotionClosestWaypointTrack::FUN_00115590);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("distanceMin", &MotionClosestWaypointTrack::FUN_001155b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("distanceMax", &MotionClosestWaypointTrack::FUN_001155d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("heightMin", &MotionClosestWaypointTrack::FUN_001155f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("heightMax", &MotionClosestWaypointTrack::FUN_00115610);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_119aa0<MotionClosestWaypointTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_119aa0<MotionClosestWaypointTrack>("useAvoidance", &MotionClosestWaypointTrack::FUN_00115630);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_119aa0<MotionClosestWaypointTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_119aa0<MotionClosestWaypointTrack>("setWaypointAsDriftPosition", &MotionClosestWaypointTrack::FUN_00115650);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("maxTimeInSamePosition", &MotionClosestWaypointTrack::FUN_00115670);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_119aa0<MotionClosestWaypointTrack>("minSpeedToKeepMoving", &MotionClosestWaypointTrack::FUN_00115690);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c7c), params, 11);
    }
    DAT_004e0c80++;
}


// 0x0011ab30 FUN_0011ab30 (664 B): equivalent/0x0011ab30.cpp
// sym: ?FUN_0011ab30@fn_fda5378a@@YAXXZ @4057707e7445 @w9cc5cb0d459c
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_0011ab30 @ 0x0011ab30
void FUN_0011ab30()
{
    if (DAT_004e0c68 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>("timeBegin", &MotionLocatorTrack::FUN_00115290);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>("timeEnd", &MotionLocatorTrack::FUN_001152a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>("speed", &MotionLocatorTrack::FUN_001152c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>("distanceMin", &MotionLocatorTrack::FUN_001152e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>("distanceMax", &MotionLocatorTrack::FUN_00115300);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>("heightMin", &MotionLocatorTrack::FUN_00115320);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_11ab30<MotionLocatorTrack>("heightMax", &MotionLocatorTrack::FUN_00115340);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_11ab30<MotionLocatorTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_11ab30<MotionLocatorTrack>("stringParamLocator", &MotionLocatorTrack::FUN_00115360);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_11ab30<MotionLocatorTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_11ab30<MotionLocatorTrack>("myLocator", &MotionLocatorTrack::FUN_00115380);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_11ab30<MotionLocatorTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_11ab30<MotionLocatorTrack>("defendLocator", &MotionLocatorTrack::FUN_001153a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_11ab30<MotionLocatorTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_11ab30<MotionLocatorTrack>("namedLocator", &MotionLocatorTrack::FUN_001153c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_11ab30<MotionLocatorTrack>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_11ab30<MotionLocatorTrack>("locatorName", &MotionLocatorTrack::FUN_001153d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c64), params, 12);
    }
    DAT_004e0c68++;
}

} // namespace fn_fda5378a
