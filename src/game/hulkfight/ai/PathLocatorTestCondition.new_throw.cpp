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
    int FUN_0011c290(void*); /* (unb4) as defined; address taken only */
    char FUN_0011b810(int); /* (unb4) as defined; address taken only */
    char FUN_0011b830(int); /* (unb4) as defined; address taken only */
    char FUN_0011b850(char); /* (unb4) as defined; address taken only */
    char FUN_0011b870(char); /* (unb4) as defined; address taken only */
    char FUN_0011b890(char); /* (unb4) as defined; address taken only */
    char FUN_0011b8b0(char); /* (unb4) as defined; address taken only */
    char FUN_0011b8d0(char); /* (unb4) as defined; address taken only */
    char FUN_0011b8f0(char); /* (unb4) as defined; address taken only */
    char FUN_0011b910(char); /* (unb4) as defined; address taken only */
    bool FUN_0011b930(bool); /* (unb4) as defined; address taken only */
    bool FUN_0011b960(void*); /* (unb4) as defined; address taken only */
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
    bool FUN_0011b980(int); /* (unb4) as defined; address taken only */
    char FUN_0011b990(int); /* (unb4) as defined; address taken only */
    char FUN_0011b9a0(float); /* (unb4) as defined; address taken only */
    bool FUN_0011b9d0(int); /* (unb4) as defined; address taken only */
    char FUN_0011b9f0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011ba10(int); /* (unb4) as defined; address taken only */
    bool FUN_0011ba30(int); /* (unb4) as defined; address taken only */
    char FUN_0011ba50(char); /* (unb4) as defined; address taken only */
    char FUN_0011ba70(int); /* (unb4) as defined; address taken only */
    char FUN_0011ba90(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bab0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bac0(int); /* (unb4) as defined; address taken only */
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
    char FUN_0011bad0(int); /* (unb4) as defined; address taken only */
    char FUN_0011bae0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011baf0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bb00(float); /* (unb4) as defined; address taken only */
    bool FUN_0011bb20(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bb30(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bb40(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bb60(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bb80(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bba0(int); /* (unb4) as defined; address taken only */
    char FUN_0011c470(void*); /* (unb4) as defined; address taken only */
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
    bool FUN_0011bbc0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bbd0(int); /* (unb4) as defined; address taken only */
    char FUN_0011bbf0(int); /* (unb4) as defined; address taken only */
    char FUN_0011bc10(float); /* (unb4) as defined; address taken only */
    char FUN_0011bc40(int); /* (unb4) as defined; address taken only */
    char FUN_0011bc60(int); /* (unb4) as defined; address taken only */
    char FUN_0011bc80(int); /* (unb4) as defined; address taken only */
    char FUN_0011bca0(int); /* (unb4) as defined; address taken only */
    char FUN_0011bcc0(char); /* (unb4) as defined; address taken only */
    char FUN_0011bce0(char); /* (unb4) as defined; address taken only */
    bool FUN_0011bd00(int); /* (unb4) as defined; address taken only */
    char FUN_0011bd20(int); /* (unb4) as defined; address taken only */
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
    bool FUN_0011bde0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bdf0(int); /* (unb4) as defined; address taken only */
    char FUN_0011be10(int); /* (unb4) as defined; address taken only */
    bool FUN_0011be30(int); /* (unb4) as defined; address taken only */
    char FUN_0011be50(int); /* (unb4) as defined; address taken only */
    bool FUN_0011be70(int); /* (unb4) as defined; address taken only */
    char FUN_0011be90(int); /* (unb4) as defined; address taken only */
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
    char FUN_0011bea0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011beb0(int); /* (unb4) as defined; address taken only */
    char FUN_0011bed0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bef0(int); /* (unb4) as defined; address taken only */
    char FUN_0011bf10(int); /* (unb4) as defined; address taken only */
    char FUN_0011bf30(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bf50(int); /* (unb4) as defined; address taken only */
    bool FUN_0011bf70(int); /* (unb4) as defined; address taken only */
    char FUN_0011bf90(char); /* (unb4) as defined; address taken only */
    char FUN_0011bfb0(int); /* (unb4) as defined; address taken only */
    char FUN_0011bfc0(char); /* (unb4) as defined; address taken only */
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
    char FUN_0011bfd0(int); /* (unb4) as defined; address taken only */
    char FUN_0011bfe0(int); /* (unb4) as defined; address taken only */
    char FUN_0011c000(int); /* (unb4) as defined; address taken only */
    char FUN_0011c010(float); /* (unb4) as defined; address taken only */
    bool FUN_0011c030(int); /* (unb4) as defined; address taken only */
    char FUN_0011c040(int); /* (unb4) as defined; address taken only */
    char FUN_0011c050(int); /* (unb4) as defined; address taken only */
    bool FUN_0011c060(void*); /* (unb4) as defined; address taken only */
    bool FUN_0011c070(int); /* (unb4) as defined; address taken only */
    bool FUN_0011c080(int); /* (unb4) as defined; address taken only */
    char FUN_0011c0a0(int); /* (unb4) as defined; address taken only */
    char FUN_0011c870(void*); /* (unb4) as defined; address taken only */
    char FUN_0011c0d0(char); /* (unb4) as defined; address taken only */
    char FUN_0011c0f0(int); /* (unb4) as defined; address taken only */
    void FUN_0011c100();
    char FUN_0011c120(char); /* (unb4) as defined; address taken only */
    char FUN_0011c140(char); /* (unb4) as defined; address taken only */
    bool FUN_0011c160(int); /* (unb4) as defined; address taken only */
    bool FUN_0011c180(int); /* (unb4) as defined; address taken only */
    char FUN_0011c1a0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011c1c0(int); /* (unb4) as defined; address taken only */
    bool FUN_0011c1e0(int); /* (unb4) as defined; address taken only */
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
// sym: ?FUN_00120a90@fn_f0aa4dae@@YAXXZ @22cc59cc6a5e @wac21458aac3b
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
            params[0] = new (mem) fight::ParamString_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("locatorType", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011c290);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b810);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("distance", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b830);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("distanceTest", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b850);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("min", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b870);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("max", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b890);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("defendLocator", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("myLocator", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("namedLocator", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("testLocatorExists", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b910);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("defaulttoVicinityCheck", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b930);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("vicinityLimits", (void (hulkfight::ai::PathLocatorTestCondition_120a90::*)())&hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b960);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ca8), params, 12);
    }
    DAT_004e0cac++;
}


// 0x00120d40 FUN_00120d40 (664 B): equivalent/0x00120d40.cpp
// sym: ?FUN_00120d40@fn_f0aa4dae@@YAXXZ @d199471144a0 @w065f1bcbc96c
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
            params[0] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("timeBegin", (void (RoutTrack::*)())&RoutTrack::FUN_0011b980);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("timeEnd", (void (RoutTrack::*)())&RoutTrack::FUN_0011b990);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("turnRate", (void (RoutTrack::*)())&RoutTrack::FUN_0011b9a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("speed", (void (RoutTrack::*)())&RoutTrack::FUN_0011b9d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("routRadius", (void (RoutTrack::*)())&RoutTrack::FUN_0011b9f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("maxTimeInSamePosition", (void (RoutTrack::*)())&RoutTrack::FUN_0011ba10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("minSpeedToKeepRunning", (void (RoutTrack::*)())&RoutTrack::FUN_0011ba30);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120d40<RoutTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_120d40<RoutTrack>("useAvoidanceCode", (void (RoutTrack::*)())&RoutTrack::FUN_0011ba50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("seperationBufferStart", (void (RoutTrack::*)())&RoutTrack::FUN_0011ba70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("seperationBufferStop", (void (RoutTrack::*)())&RoutTrack::FUN_0011ba90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("width", (void (RoutTrack::*)())&RoutTrack::FUN_0011bab0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120d40<RoutTrack>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_120d40<RoutTrack>("formationWidth", (void (RoutTrack::*)())&RoutTrack::FUN_0011bac0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cb0), params, 12);
    }
    DAT_004e0cb4++;
}


// 0x00120fe0 FUN_00120fe0 (613 B): equivalent/0x00120fe0.cpp
// sym: ?FUN_00120fe0@fn_f0aa4dae@@YAXXZ @4ed8cbe1b39a @wf0135b850680
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
            params[0] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("timeBegin", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("timeEnd", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("distance", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011baf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("turnRate", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bb00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("heightMin", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bb20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("heightMax", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("speed", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bb40);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_120fe0<PathFormationTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_120fe0<PathFormationTrack>("minMembers", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bb60);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_120fe0<PathFormationTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_120fe0<PathFormationTrack>("maxMembers", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bb80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("engagementDistance", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011bba0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_120fe0<PathFormationTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamString_120fe0<PathFormationTrack>("tactic", (void (PathFormationTrack::*)())&PathFormationTrack::FUN_0011c470);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cb8), params, 11);
    }
    DAT_004e0cbc++;
}


// 0x00121250 FUN_00121250 (664 B): equivalent/0x00121250.cpp
// sym: ?FUN_00121250@fn_f0aa4dae@@YAXXZ @9bcb5701bf69 @w2516c77bb198
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
            params[0] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("timeBegin", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bbc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("timeEnd", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bbd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("distance", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bbf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("turnRate", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bc10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("heightMin", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bc40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("heightMax", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bc60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("groundHeightCutoff", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bc80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("cutoffExponent", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121250<StrafeRunTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_121250<StrafeRunTrack>("useGroundHeightCutoff", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bcc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121250<StrafeRunTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_121250<StrafeRunTrack>("useOffset", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("offset", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bd00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("speed", (void (StrafeRunTrack::*)())&StrafeRunTrack::FUN_0011bd20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cc0), params, 12);
    }
    DAT_004e0cc4++;
}


// 0x00121690 FUN_00121690 (409 B): equivalent/0x00121690.cpp
// sym: _FUN_00121690 @d5496c151e97 @w89e2798654cc
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
            params[0] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("timeBegin", (void (hulkfight::ai::StrafeCircleHBTrack_121690::*)())&hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011bde0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("timeEnd", (void (hulkfight::ai::StrafeCircleHBTrack_121690::*)())&hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011bdf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("distanceMin", (void (hulkfight::ai::StrafeCircleHBTrack_121690::*)())&hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("distanceMax", (void (hulkfight::ai::StrafeCircleHBTrack_121690::*)())&hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("heightMin", (void (hulkfight::ai::StrafeCircleHBTrack_121690::*)())&hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("heightMax", (void (hulkfight::ai::StrafeCircleHBTrack_121690::*)())&hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121690<hulkfight::ai::StrafeCircleHBTrack_121690>("speed", (void (hulkfight::ai::StrafeCircleHBTrack_121690::*)())&hulkfight::ai::StrafeCircleHBTrack_121690::FUN_0011be90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cd0), params, 7);
    }
    DAT_004e0cd4++;
}


// 0x00121830 FUN_00121830 (613 B): equivalent/0x00121830.cpp
// sym: ?FUN_00121830@fn_f0aa4dae@@YAXXZ @cf1cb049da1c @we0183fba4459
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
            params[0] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("timeBegin", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("timeEnd", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011beb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("distanceMin", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("distanceMax", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("heightMin", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bf10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("heightMax", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bf30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("groundHeightCutoff", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bf50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("cutoffExponent", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bf70);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121830<StrafeCircleTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_121830<StrafeCircleTrack>("useGroundHeightCutoff", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bf90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121830<StrafeCircleTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_121830<StrafeCircleTrack>("speed", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bfb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121830<StrafeCircleTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_121830<StrafeCircleTrack>("useDefendLocation", (void (StrafeCircleTrack::*)())&StrafeCircleTrack::FUN_0011bfc0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cd8), params, 11);
    }
    DAT_004e0cdc++;
}


// 0x00121aa0 FUN_00121aa0 (1174 B): equivalent/0x00121aa0.cpp
// sym: ?FUN_00121aa0@fn_f0aa4dae@@YAXXZ @dd77387b9b1d @wa42f425200ba
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
            params[0] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("timeBegin", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011bfd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("timeEnd", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011bfe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("distance", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("turnRate", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c010);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("heightMin", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c030);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("heightMax", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c040);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("speed", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c050);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("destinationX", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("destinationY", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c070);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("destinationZ", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c080);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("engagementDistance", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c0a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamString_121aa0<hulkfight::ai::PathTrack_121aa0>("tactic", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c870);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>("defendLocator", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c0d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>("myLocator", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c0f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName_121aa0<hulkfight::ai::PathTrack_121aa0>("locatorName", &hulkfight::ai::PathTrack_121aa0::FUN_0011c100);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>("useAvoidanceCode", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c120);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_121aa0<hulkfight::ai::PathTrack_121aa0>("useFormationPoints", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c140);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("formationOffset", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c160);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("seperationBufferStart", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c180);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("seperationBufferStop", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c1a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("width", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c1c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange_121aa0<hulkfight::ai::PathTrack_121aa0>("formationWidth", (void (hulkfight::ai::PathTrack_121aa0::*)())&hulkfight::ai::PathTrack_121aa0::FUN_0011c1e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ce0), params, 22);
    }
    DAT_004e0ce4++;
}

} // namespace fn_f0aa4dae
