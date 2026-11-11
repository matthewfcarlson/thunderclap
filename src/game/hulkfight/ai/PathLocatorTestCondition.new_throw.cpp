// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011fa30..0x00123510 (kind game, layer game, confidence high), dominant class hulkfight::ai::PathLocatorTestCondition
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0aa4dae {
#define TREE_TU_END }
namespace fn_f0aa4dae {} using namespace fn_f0aa4dae;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f0aa4dae {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f0aa4dae
namespace hulkfight { namespace ai {
class PathLocatorTestCondition_120a90 {
public:
    void FUN_0011c290();
    void FUN_0011b810();
    void FUN_0011b830();
    void FUN_0011b850();
    void FUN_0011b870();
    void FUN_0011b890();
    void FUN_0011b8b0();
    void FUN_0011b8d0();
    void FUN_0011b8f0();
    void FUN_0011b910();
    void FUN_0011b930();
    void FUN_0011b960();
};
} }
namespace fn_f0aa4dae {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f0aa4dae
namespace fight {
template <class T>
class ParamBool_120a90 : public ParamBoolBase {
public:
    ParamBool_120a90(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_120a90 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_120a90(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_120a90 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_120a90(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamString_120a90 : public ParamStringBase {
public:
    ParamString_120a90(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_120a90 : public ParamVectorBase {
public:
    ParamVector_120a90(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f0aa4dae {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class RoutTrack {
public:
    void FUN_0011b980();
    void FUN_0011b990();
    void FUN_0011b9a0();
    void FUN_0011b9d0();
    void FUN_0011b9f0();
    void FUN_0011ba10();
    void FUN_0011ba30();
    void FUN_0011ba50();
    void FUN_0011ba70();
    void FUN_0011ba90();
    void FUN_0011bab0();
    void FUN_0011bac0();
};
} // namespace fn_f0aa4dae
namespace fight {
template <class T>
class ParamBool_120d40 : public ParamBoolBase {
public:
    ParamBool_120d40(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_120d40 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_120d40(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f0aa4dae {
class PathFormationTrack {
public:
    void FUN_0011bad0();
    void FUN_0011bae0();
    void FUN_0011baf0();
    void FUN_0011bb00();
    void FUN_0011bb20();
    void FUN_0011bb30();
    void FUN_0011bb40();
    void FUN_0011bb60();
    void FUN_0011bb80();
    void FUN_0011bba0();
    void FUN_0011c470();
};
} // namespace fn_f0aa4dae
namespace fight {
template <class T>
class ParamFloatConstRange_120fe0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_120fe0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_120fe0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_120fe0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamString_120fe0 : public ParamStringBase {
public:
    ParamString_120fe0(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f0aa4dae {
class StrafeRunTrack {
public:
    void FUN_0011bbc0();
    void FUN_0011bbd0();
    void FUN_0011bbf0();
    void FUN_0011bc10();
    void FUN_0011bc40();
    void FUN_0011bc60();
    void FUN_0011bc80();
    void FUN_0011bca0();
    void FUN_0011bcc0();
    void FUN_0011bce0();
    void FUN_0011bd00();
    void FUN_0011bd20();
};
} // namespace fn_f0aa4dae
namespace fight {
template <class T>
class ParamBool_121250 : public ParamBoolBase {
public:
    ParamBool_121250(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_121250 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_121250(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class StrafeCircleHBTrack_121690 {
public:
    void FUN_0011bde0();
    void FUN_0011bdf0();
    void FUN_0011be10();
    void FUN_0011be30();
    void FUN_0011be50();
    void FUN_0011be70();
    void FUN_0011be90();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_121690 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_121690(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f0aa4dae {
class StrafeCircleTrack {
public:
    void FUN_0011bea0();
    void FUN_0011beb0();
    void FUN_0011bed0();
    void FUN_0011bef0();
    void FUN_0011bf10();
    void FUN_0011bf30();
    void FUN_0011bf50();
    void FUN_0011bf70();
    void FUN_0011bf90();
    void FUN_0011bfb0();
    void FUN_0011bfc0();
};
} // namespace fn_f0aa4dae
namespace fight {
template <class T>
class ParamBool_121830 : public ParamBoolBase {
public:
    ParamBool_121830(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_121830 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_121830(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class PathTrack_121aa0 {
public:
    void FUN_0011bfd0();
    void FUN_0011bfe0();
    void FUN_0011c000();
    void FUN_0011c010();
    void FUN_0011c030();
    void FUN_0011c040();
    void FUN_0011c050();
    void FUN_0011c060();
    void FUN_0011c070();
    void FUN_0011c080();
    void FUN_0011c0a0();
    void FUN_0011c870();
    void FUN_0011c0d0();
    void FUN_0011c0f0();
    void FUN_0011c100();
    void FUN_0011c120();
    void FUN_0011c140();
    void FUN_0011c160();
    void FUN_0011c180();
    void FUN_0011c1a0();
    void FUN_0011c1c0();
    void FUN_0011c1e0();
};
} }
namespace fn_f0aa4dae {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f0aa4dae
namespace fight {
template <class T>
class ParamBool_121aa0 : public ParamBoolBase {
public:
    ParamBool_121aa0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_121aa0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_121aa0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_121aa0 : public ParamNameBase {
public:
    ParamName_121aa0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamString_121aa0 : public ParamStringBase {
public:
    ParamString_121aa0(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_f0aa4dae {

// 0x00120a90 FUN_00120a90 (682 B): equivalent/0x00120a90.cpp
// sym: ?FUN_00120a90@fn_f0aa4dae@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 26/26)
// FUN_00120a90 @ 0x00120a90
void FUN_00120a90()
{
    if (DAT_004e0cac == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamString_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("locatorType", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011c290);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b810);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("distance", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b830);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("distanceTest", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b850);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("min", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b870);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("max", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b890);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("defendLocator", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("myLocator", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("namedLocator", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("testLocatorExists", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b910);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("defaulttoVicinityCheck", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b930);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("vicinityLimits", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b960);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ca8), params, 12);
    }
    DAT_004e0cac++;
}


// 0x00120d40 FUN_00120d40 (664 B): equivalent/0x00120d40.cpp
// sym: ?FUN_00120d40@fn_f0aa4dae@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 26/26)
// FUN_00120d40 @ 0x00120d40
void FUN_00120d40()
{
    if (DAT_004e0cb4 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("timeBegin", &RoutTrack::FUN_0011b980);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("timeEnd", &RoutTrack::FUN_0011b990);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("turnRate", &RoutTrack::FUN_0011b9a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("speed", &RoutTrack::FUN_0011b9d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("routRadius", &RoutTrack::FUN_0011b9f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("maxTimeInSamePosition", &RoutTrack::FUN_0011ba10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("minSpeedToKeepRunning", &RoutTrack::FUN_0011ba30);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120d40<RoutTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_120d40<RoutTrack>("useAvoidanceCode", &RoutTrack::FUN_0011ba50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("seperationBufferStart", &RoutTrack::FUN_0011ba70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("seperationBufferStop", &RoutTrack::FUN_0011ba90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("width", &RoutTrack::FUN_0011bab0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("formationWidth", &RoutTrack::FUN_0011bac0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cb0), params, 12);
    }
    DAT_004e0cb4++;
}


// 0x00120fe0 FUN_00120fe0 (613 B): equivalent/0x00120fe0.cpp
// sym: ?FUN_00120fe0@fn_f0aa4dae@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 24/24)
// FUN_00120fe0 @ 0x00120fe0
void FUN_00120fe0()
{
    if (DAT_004e0cbc == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("timeBegin", &PathFormationTrack::FUN_0011bad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("timeEnd", &PathFormationTrack::FUN_0011bae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("distance", &PathFormationTrack::FUN_0011baf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("turnRate", &PathFormationTrack::FUN_0011bb00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("heightMin", &PathFormationTrack::FUN_0011bb20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("heightMax", &PathFormationTrack::FUN_0011bb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("speed", &PathFormationTrack::FUN_0011bb40);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_120fe0<PathFormationTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_120fe0<PathFormationTrack>("minMembers", &PathFormationTrack::FUN_0011bb60);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_120fe0<PathFormationTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_120fe0<PathFormationTrack>("maxMembers", &PathFormationTrack::FUN_0011bb80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("engagementDistance", &PathFormationTrack::FUN_0011bba0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_120fe0<PathFormationTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamString_120fe0<PathFormationTrack>("tactic", &PathFormationTrack::FUN_0011c470);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cb8), params, 11);
    }
    DAT_004e0cbc++;
}


// 0x00121250 FUN_00121250 (664 B): equivalent/0x00121250.cpp
// sym: ?FUN_00121250@fn_f0aa4dae@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 26/26)
// FUN_00121250 @ 0x00121250
void FUN_00121250()
{
    if (DAT_004e0cc4 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("timeBegin", &StrafeRunTrack::FUN_0011bbc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("timeEnd", &StrafeRunTrack::FUN_0011bbd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("distance", &StrafeRunTrack::FUN_0011bbf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("turnRate", &StrafeRunTrack::FUN_0011bc10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("heightMin", &StrafeRunTrack::FUN_0011bc40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("heightMax", &StrafeRunTrack::FUN_0011bc60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("groundHeightCutoff", &StrafeRunTrack::FUN_0011bc80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("cutoffExponent", &StrafeRunTrack::FUN_0011bca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121250<StrafeRunTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_121250<StrafeRunTrack>("useGroundHeightCutoff", &StrafeRunTrack::FUN_0011bcc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121250<StrafeRunTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_121250<StrafeRunTrack>("useOffset", &StrafeRunTrack::FUN_0011bce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("offset", &StrafeRunTrack::FUN_0011bd00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("speed", &StrafeRunTrack::FUN_0011bd20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cc0), params, 12);
    }
    DAT_004e0cc4++;
}


// 0x00121690 FUN_00121690 (409 B): equivalent/0x00121690.cpp
// sym: _FUN_00121690
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 16/16)
// FUN_00121690 @ 0x00121690
extern "C" void FUN_00121690()
{
    if (DAT_004e0cd4 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("timeBegin", &hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011bde0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("timeEnd", &hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011bdf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("distanceMin", &hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("distanceMax", &hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("heightMin", &hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("heightMax", &hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("speed", &hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cd0), params, 7);
    }
    DAT_004e0cd4++;
}


// 0x00121830 FUN_00121830 (613 B): equivalent/0x00121830.cpp
// sym: ?FUN_00121830@fn_f0aa4dae@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 24/24)
// FUN_00121830 @ 0x00121830
void FUN_00121830()
{
    if (DAT_004e0cdc == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("timeBegin", &StrafeCircleTrack::FUN_0011bea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("timeEnd", &StrafeCircleTrack::FUN_0011beb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("distanceMin", &StrafeCircleTrack::FUN_0011bed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("distanceMax", &StrafeCircleTrack::FUN_0011bef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("heightMin", &StrafeCircleTrack::FUN_0011bf10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("heightMax", &StrafeCircleTrack::FUN_0011bf30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("groundHeightCutoff", &StrafeCircleTrack::FUN_0011bf50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("cutoffExponent", &StrafeCircleTrack::FUN_0011bf70);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121830<StrafeCircleTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_121830<StrafeCircleTrack>("useGroundHeightCutoff", &StrafeCircleTrack::FUN_0011bf90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("speed", &StrafeCircleTrack::FUN_0011bfb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121830<StrafeCircleTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_121830<StrafeCircleTrack>("useDefendLocation", &StrafeCircleTrack::FUN_0011bfc0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cd8), params, 11);
    }
    DAT_004e0cdc++;
}


// 0x00121aa0 FUN_00121aa0 (1174 B): equivalent/0x00121aa0.cpp
// sym: ?FUN_00121aa0@fn_f0aa4dae@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 46/46)
// FUN_00121aa0 @ 0x00121aa0
void FUN_00121aa0()
{
    if (DAT_004e0ce4 == 0) {
        void* params[22];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("timeBegin", &hulkfight::ai::PathTrack_121aa0::FUN_0011bfd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("timeEnd", &hulkfight::ai::PathTrack_121aa0::FUN_0011bfe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("distance", &hulkfight::ai::PathTrack_121aa0::FUN_0011c000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("turnRate", &hulkfight::ai::PathTrack_121aa0::FUN_0011c010);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("heightMin", &hulkfight::ai::PathTrack_121aa0::FUN_0011c030);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("heightMax", &hulkfight::ai::PathTrack_121aa0::FUN_0011c040);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("speed", &hulkfight::ai::PathTrack_121aa0::FUN_0011c050);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("destinationX", &hulkfight::ai::PathTrack_121aa0::FUN_0011c060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("destinationY", &hulkfight::ai::PathTrack_121aa0::FUN_0011c070);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("destinationZ", &hulkfight::ai::PathTrack_121aa0::FUN_0011c080);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("engagementDistance", &hulkfight::ai::PathTrack_121aa0::FUN_0011c0a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamString_121aa0<hulkfight::ai::PathTrack_121aa0>("tactic", &hulkfight::ai::PathTrack_121aa0::FUN_0011c870);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>("defendLocator", &hulkfight::ai::PathTrack_121aa0::FUN_0011c0d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>("myLocator", &hulkfight::ai::PathTrack_121aa0::FUN_0011c0f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName_121aa0<hulkfight::ai::PathTrack_121aa0>("locatorName", &hulkfight::ai::PathTrack_121aa0::FUN_0011c100);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>("useAvoidanceCode", &hulkfight::ai::PathTrack_121aa0::FUN_0011c120);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>("useFormationPoints", &hulkfight::ai::PathTrack_121aa0::FUN_0011c140);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("formationOffset", &hulkfight::ai::PathTrack_121aa0::FUN_0011c160);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("seperationBufferStart", &hulkfight::ai::PathTrack_121aa0::FUN_0011c180);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("seperationBufferStop", &hulkfight::ai::PathTrack_121aa0::FUN_0011c1a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("width", &hulkfight::ai::PathTrack_121aa0::FUN_0011c1c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("formationWidth", &hulkfight::ai::PathTrack_121aa0::FUN_0011c1e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ce0), params, 22);
    }
    DAT_004e0ce4++;
}

} // namespace fn_f0aa4dae
