// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3623cd7 {
#define TREE_TU_END }
namespace fn_f3623cd7 {} using namespace fn_f3623cd7;
#include "game/global.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f3623cd7 {
void* FUN_0008d690(unsigned int size);
class CButtonValueCondition_528d0 {
public:
    char FUN_00047ab0(int); /* (unb4) as defined; address taken only */
    char FUN_00047ac0(int); /* (unb4) as defined; address taken only */
    char FUN_00047ad0(int); /* (unb4) as defined; address taken only */
    bool FUN_00047ae0(int); /* (unb4) as defined; address taken only */
    bool FUN_00047af0(int); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamFloatConstRange_528d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_528d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_528d0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_528d0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fn_f3623cd7 {
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class CAxisValueCondition_52c40 {
public:
    bool FUN_00047b00(int); /* (unb4) as defined; address taken only */
    bool FUN_00047b10(int); /* (unb4) as defined; address taken only */
    bool FUN_00047b20(int); /* (unb4) as defined; address taken only */
    char FUN_00047b50(int); /* (unb4) as defined; address taken only */
    char FUN_00047b60(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamFloatConstRange_52c40 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_52c40(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_52c40 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_52c40(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fn_f3623cd7 {
class CAxisArcCondition_52db0 {
public:
    bool FUN_00047b00(int); /* (unb4) as defined; address taken only */
    bool FUN_00047b10(int); /* (unb4) as defined; address taken only */
    bool FUN_00047b20(int); /* (unb4) as defined; address taken only */
    bool FUN_00047b70(int); /* (unb4) as defined; address taken only */
    char FUN_00047b80(float); /* (unb4) as defined; address taken only */
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamFloatConstRange_52db0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_52db0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_52db0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_52db0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fn_f3623cd7 {
class CAxisDoubleTapCondition_52f20 {
public:
    bool FUN_00047b00(int); /* (unb4) as defined; address taken only */
    bool FUN_00047ba0(int); /* (unb4) as defined; address taken only */
    bool FUN_00047bb0(float); /* (unb4) as defined; address taken only */
    char FUN_00047bd0(int); /* (unb4) as defined; address taken only */
    char FUN_00047be0(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamFloatConstRange_52f20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_52f20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_52f20 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_52f20(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fn_f3623cd7 {
class CGroundDistanceCondition_53170 {
public:
    void FUN_00047c40();
    void FUN_00047c50();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamEnumConstList_53170 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_53170(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_53170 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_53170(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CCollisionDirectionCondition_533a0 {
public:
    void FUN_00047ca0();
    void FUN_00047cc0();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamFloatConstRange_533a0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_533a0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CCollisionPushbackDirectionCondition_53440 {
public:
    void FUN_00047ce0();
    void FUN_00047d00();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamFloatConstRange_53440 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_53440(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
extern "C" void __cdecl FUN_00047d40();
extern "C" char DAT_003f7938[];
struct Param {
    char pad[24];
};
extern hulk_intptr __cdecl Alloc_0008d690(unsigned int);
extern void __cdecl Register_002347b0(void*, void*, int);
class CCollisionHeightCondition_53540 {
public:
    void FUN_00047d50();
    void FUN_00047d60();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamEnumConstList_53540 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_53540(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_53540 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_53540(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CCollisionPushbackVelocityCondition_535f0 {
public:
    void FUN_00047d70();
    void FUN_00047d80();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamEnumConstList_535f0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_535f0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_535f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_535f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CCollisionPushbackYCondition_536a0 {
public:
    void FUN_00047d90();
    void FUN_00047da0();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamEnumConstList_536a0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_536a0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_536a0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_536a0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CCollisionPushbackYAngleCondition_53750 {
public:
    void FUN_00047db0();
    void FUN_00047dc0();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamEnumConstList_53750 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_53750(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_53750 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_53750(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CCollisionStunTimeCondition_53800 {
public:
    void FUN_00047de0();
    void FUN_00047df0();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamEnumConstList_53800 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_53800(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_53800 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_53800(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CSmartPropAngleCondition_53bc0 {
public:
    void FUN_00047ec0();
    void FUN_0004c790();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamFloatConstRange_53bc0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_53bc0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CRageModeCondition_54300 {
public:
    void FUN_00048100();
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamBool_54300 : public ParamBoolBase {
public:
    ParamBool_54300(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CInactivityTimerCondition_54480 {
public:
    void FUN_00048170();
    void FUN_00048180();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamEnumConstList_54480 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_54480(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_54480 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_54480(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CIntentionSpeedCondition_54750 {
public:
    void FUN_000481c0();
    void FUN_000481d0();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamEnumConstList_54750 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_54750(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_54750 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_54750(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3623cd7 {
class CClimbEdgeCondition_54800 {
public:
    void FUN_000481e0();
    void FUN_000481f0();
};
} // namespace fn_f3623cd7
namespace fight {
template <class T>
class ParamBool_54800 : public ParamBoolBase {
public:
    ParamBool_54800(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_54800 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_54800(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
class CCollisionHitLocationCondition {};
namespace fn_f3623cd7 {
class ConditionFactoryCasterTemplate_54c30 {
  public:
    virtual bool cast_00050a00(void*);
    ConditionFactoryCasterTemplate_54c30() {}
};
void __cdecl findCondition_002343e0(void*, ConditionFactoryCasterTemplate_54c30*);
class ConditionFactoryCasterTemplate_54c90 {
  public:
    virtual bool cast_00050ac0(void*);
};
void __cdecl fun_002343e0(void*, ConditionFactoryCasterTemplate_54c90*);
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class ParamValueNameList_551f0 {
  public:
    ParamValueNameList_551f0(int arg);
    virtual void f();
};
class ParamNameConstList : public ParamValueNameList_551f0 {
  public:
    ParamNameConstList(int a, int b);
    virtual void f();
    char pad[12];
    int m10;
};


// 0x000528d0 FUN_000528d0 (355 B): equivalent/0x000528d0.cpp
// sym: _FUN_000528d0 @3e0d6fb101dd @w5f163de5e141
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 12/12)
// FUN_000528d0 @ 0x000528d0
extern "C" void FUN_000528d0()
{
    if (DAT_004dc40c == 0) {
        void* params[5];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_528d0<CButtonValueCondition_528d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_528d0<CButtonValueCondition_528d0>("button", ((const char**)&DAT_0049ee30), 13, (void (CButtonValueCondition_528d0::*)())&CButtonValueCondition_528d0::FUN_00047ab0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_528d0<CButtonValueCondition_528d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_528d0<CButtonValueCondition_528d0>("compareTime", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (CButtonValueCondition_528d0::*)())&CButtonValueCondition_528d0::FUN_00047ac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_528d0<CButtonValueCondition_528d0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_528d0<CButtonValueCondition_528d0>("time", (void (CButtonValueCondition_528d0::*)())&CButtonValueCondition_528d0::FUN_00047ad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_528d0<CButtonValueCondition_528d0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList_528d0<CButtonValueCondition_528d0>("compareValue", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (CButtonValueCondition_528d0::*)())&CButtonValueCondition_528d0::FUN_00047ae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_528d0<CButtonValueCondition_528d0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_528d0<CButtonValueCondition_528d0>("value", (void (CButtonValueCondition_528d0::*)())&CButtonValueCondition_528d0::FUN_00047af0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc408), params, 5);
    }
    DAT_004dc40c++;
}


// 0x00052c40 FUN_00052c40 (355 B): equivalent/0x00052c40.cpp
// sym: _FUN_00052c40 @38b1000e6522 @w57f384b88c08
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00052c40 @ 0x00052c40
extern "C" void FUN_00052c40()
{
    if (DAT_004dc424 == 0) {
        void* params[5];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_52c40<CAxisValueCondition_52c40>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_52c40<CAxisValueCondition_52c40>("axis", ((const char**)&DAT_0049ee74), 2, (void (CAxisValueCondition_52c40::*)())&CAxisValueCondition_52c40::FUN_00047b00);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_52c40<CAxisValueCondition_52c40>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_52c40<CAxisValueCondition_52c40>("compareTime", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (CAxisValueCondition_52c40::*)())&CAxisValueCondition_52c40::FUN_00047b10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_52c40<CAxisValueCondition_52c40>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_52c40<CAxisValueCondition_52c40>("time", (void (CAxisValueCondition_52c40::*)())&CAxisValueCondition_52c40::FUN_00047b20);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_52c40<CAxisValueCondition_52c40>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList_52c40<CAxisValueCondition_52c40>("compareValue", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (CAxisValueCondition_52c40::*)())&CAxisValueCondition_52c40::FUN_00047b50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_52c40<CAxisValueCondition_52c40>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_52c40<CAxisValueCondition_52c40>("value", (void (CAxisValueCondition_52c40::*)())&CAxisValueCondition_52c40::FUN_00047b60);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc420), params, 5);
    }
    DAT_004dc424++;
}


// 0x00052db0 FUN_00052db0 (355 B): equivalent/0x00052db0.cpp
// sym: _FUN_00052db0 @ad3c5b37e7cf @w987bcf2f7605
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 12/12)
// FUN_00052db0 @ 0x00052db0
extern "C" void FUN_00052db0()
{
    if (DAT_004dc42c == 0) {
        void* params[5];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_52db0<CAxisArcCondition_52db0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_52db0<CAxisArcCondition_52db0>("axis", ((const char**)&DAT_0049ee74), 2, (void (CAxisArcCondition_52db0::*)())&CAxisArcCondition_52db0::FUN_00047b00);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_52db0<CAxisArcCondition_52db0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_52db0<CAxisArcCondition_52db0>("compareTime", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (CAxisArcCondition_52db0::*)())&CAxisArcCondition_52db0::FUN_00047b10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_52db0<CAxisArcCondition_52db0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_52db0<CAxisArcCondition_52db0>("time", (void (CAxisArcCondition_52db0::*)())&CAxisArcCondition_52db0::FUN_00047b20);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_52db0<CAxisArcCondition_52db0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList_52db0<CAxisArcCondition_52db0>("compareArc", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (CAxisArcCondition_52db0::*)())&CAxisArcCondition_52db0::FUN_00047b70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_52db0<CAxisArcCondition_52db0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_52db0<CAxisArcCondition_52db0>("arc", (void (CAxisArcCondition_52db0::*)())&CAxisArcCondition_52db0::FUN_00047b80);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc428), params, 5);
    }
    DAT_004dc42c++;
}


// 0x00052f20 FUN_00052f20 (339 B): equivalent/0x00052f20.cpp
// sym: _FUN_00052f20 @58363548d14d @w5bbe0b32376a
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00052f20 @ 0x00052f20
extern "C" void FUN_00052f20()
{
    if (DAT_004dc434 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_52f20<CAxisDoubleTapCondition_52f20>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_52f20<CAxisDoubleTapCondition_52f20>("axis", ((const char**)&DAT_0049ee74), 2, (void (CAxisDoubleTapCondition_52f20::*)())&CAxisDoubleTapCondition_52f20::FUN_00047b00);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_52f20<CAxisDoubleTapCondition_52f20>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_52f20<CAxisDoubleTapCondition_52f20>("compareArc", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (CAxisDoubleTapCondition_52f20::*)())&CAxisDoubleTapCondition_52f20::FUN_00047ba0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>("arc", (void (CAxisDoubleTapCondition_52f20::*)())&CAxisDoubleTapCondition_52f20::FUN_00047bb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>("timeMin", (void (CAxisDoubleTapCondition_52f20::*)())&CAxisDoubleTapCondition_52f20::FUN_00047bd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>("timeMax", (void (CAxisDoubleTapCondition_52f20::*)())&CAxisDoubleTapCondition_52f20::FUN_00047be0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc430), params, 5);
    }
    DAT_004dc434++;
}


// 0x00053170 FUN_00053170 (176 B): equivalent/0x00053170.cpp
// sym: _FUN_00053170 @91ab4b307d45 @w49f8c9dae980
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00053170 @ 0x00053170
extern "C" void FUN_00053170()
{
    if (DAT_004dc444 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_53170<::CGroundDistanceCondition_53170>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_53170<::CGroundDistanceCondition_53170>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CGroundDistanceCondition_53170::FUN_00047c40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53170<::CGroundDistanceCondition_53170>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_53170<::CGroundDistanceCondition_53170>("distance", &::CGroundDistanceCondition_53170::FUN_00047c50);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc440), params, 2);
    }
    DAT_004dc444++;
}

} // namespace fn_f3623cd7

// 0x000532e0 FUN_000532e0 (192 B): matches/0x000532e0.cpp [wrapped: conflict: fight::ParamEnumConstList]
// sym: _FUN_000532e0
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_000532e0 {


bool FUN_00047c80(void*, int); /* (unb4) as defined; address taken only */
char FUN_00047c90(void*, int); /* (unb4) as defined; address taken only */
struct FUN_00234cc0 {
    FUN_00234cc0(const char*);
    virtual void slot0();
    char padding[12];
};
namespace fight {
class CCollisionHitLocationCondition;
template <class T> struct ParamEnumConstList : FUN_00234cc0 {
    virtual void slot0();
    const char* values;
    int count;
    void (*callback)();
    int tail;
    ParamEnumConstList(const char* name, const char* v, int n, void (*cb)()) : FUN_00234cc0(name) {
        values = v;
        count = n;
        callback = cb;
    }
};
} // namespace fight
void __cdecl FUN_002347b0(void*, void*, int);
extern "C" void __cdecl FUN_000532e0() {
    if (!DAT_004dc454) {
        typedef fight::ParamEnumConstList<fight::CCollisionHitLocationCondition> Param;
        Param* entries[2];
        entries[0] = new Param("compare", ((char*)&DAT_0042773c), (*(int*)&DAT_00427754), (void (*)())FUN_00047c80);
        entries[1] = new Param("hitLocation", DAT_0048f6cc, (*(int*)&DAT_003f5ed0), (void (*)())FUN_00047c90);
        FUN_002347b0(((int*)&DAT_004dc450), entries, 2);
    }
    ++DAT_004dc454;
}
} // namespace fn_000532e0

namespace fn_f3623cd7 {

// 0x000533a0 FUN_000533a0 (158 B): equivalent/0x000533a0.cpp
// sym: _FUN_000533a0 @fb07601b5c35 @w09d7f1e729f2
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_000533a0 @ 0x000533a0
extern "C" void FUN_000533a0()
{
    if (DAT_004dc45c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_533a0<::CCollisionDirectionCondition_533a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_533a0<::CCollisionDirectionCondition_533a0>("direction", &::CCollisionDirectionCondition_533a0::FUN_00047ca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_533a0<::CCollisionDirectionCondition_533a0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_533a0<::CCollisionDirectionCondition_533a0>("arc", &::CCollisionDirectionCondition_533a0::FUN_00047cc0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc458), params, 2);
    }
    DAT_004dc45c++;
}


// 0x00053440 FUN_00053440 (158 B): equivalent/0x00053440.cpp
// sym: _FUN_00053440 @245c113fd20a @w0336a00c26eb
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00053440 @ 0x00053440
extern "C" void FUN_00053440()
{
    if (DAT_004dc464 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53440<::CCollisionPushbackDirectionCondition_53440>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_53440<::CCollisionPushbackDirectionCondition_53440>("direction", &::CCollisionPushbackDirectionCondition_53440::FUN_00047ce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53440<::CCollisionPushbackDirectionCondition_53440>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_53440<::CCollisionPushbackDirectionCondition_53440>("arc", &::CCollisionPushbackDirectionCondition_53440::FUN_00047d00);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc460), params, 2);
    }
    DAT_004dc464++;
}


// 0x000534e0 FUN_000534e0 (95 B): matches/0x000534e0.cpp
// sym: _FUN_000534e0
// data: gCount_534e0 = DAT_004dc474, gSlot_534e0 = DAT_004dc470
extern "C" void FUN_000534e0() {
    if ((*(int*)&DAT_004dc474) == 0) {
        Param* p = (Param*)Alloc_0008d690(0x18);
        void* out;
        if (p) {
            ((fight::ParamValueBool *)p)->FUN_00234860("interrupt");
            *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f7938);
            *(hulk_uintptr*)((char*)p + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_00047d40);
            out = p;
        } else
            out = 0;
        Register_002347b0(((int*)&DAT_004dc470), &out, 1);
    }
    ++(*(int*)&DAT_004dc474);
}


// 0x00053540 FUN_00053540 (176 B): equivalent/0x00053540.cpp
// sym: _FUN_00053540 @9087303d5938 @w329ee42d9a67
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00053540 @ 0x00053540
extern "C" void FUN_00053540()
{
    if (DAT_004dc47c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_53540<::CCollisionHeightCondition_53540>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_53540<::CCollisionHeightCondition_53540>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CCollisionHeightCondition_53540::FUN_00047d50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53540<::CCollisionHeightCondition_53540>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_53540<::CCollisionHeightCondition_53540>("height", &::CCollisionHeightCondition_53540::FUN_00047d60);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc478), params, 2);
    }
    DAT_004dc47c++;
}


// 0x000535f0 FUN_000535f0 (176 B): equivalent/0x000535f0.cpp
// sym: _FUN_000535f0 @d5c279b3c55a @wffb3f5d596af
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_000535f0 @ 0x000535f0
extern "C" void FUN_000535f0()
{
    if (DAT_004dc484 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_535f0<::CCollisionPushbackVelocityCondition_535f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_535f0<::CCollisionPushbackVelocityCondition_535f0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CCollisionPushbackVelocityCondition_535f0::FUN_00047d70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_535f0<::CCollisionPushbackVelocityCondition_535f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_535f0<::CCollisionPushbackVelocityCondition_535f0>("velocity", &::CCollisionPushbackVelocityCondition_535f0::FUN_00047d80);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc480), params, 2);
    }
    DAT_004dc484++;
}


// 0x000536a0 FUN_000536a0 (176 B): equivalent/0x000536a0.cpp
// sym: _FUN_000536a0 @c3cad2eccb12 @wae63ad6df1ac
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_000536a0 @ 0x000536a0
extern "C" void FUN_000536a0()
{
    if (DAT_004dc48c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_536a0<::CCollisionPushbackYCondition_536a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_536a0<::CCollisionPushbackYCondition_536a0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CCollisionPushbackYCondition_536a0::FUN_00047d90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_536a0<::CCollisionPushbackYCondition_536a0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_536a0<::CCollisionPushbackYCondition_536a0>("pushbackY", &::CCollisionPushbackYCondition_536a0::FUN_00047da0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc488), params, 2);
    }
    DAT_004dc48c++;
}


// 0x00053750 FUN_00053750 (176 B): equivalent/0x00053750.cpp
// sym: _FUN_00053750 @cf4377b2c9f5 @w6dc4bf6f2153
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_00053750 @ 0x00053750
extern "C" void FUN_00053750()
{
    if (DAT_004dc494 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_53750<::CCollisionPushbackYAngleCondition_53750>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_53750<::CCollisionPushbackYAngleCondition_53750>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CCollisionPushbackYAngleCondition_53750::FUN_00047db0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53750<::CCollisionPushbackYAngleCondition_53750>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_53750<::CCollisionPushbackYAngleCondition_53750>("angle", &::CCollisionPushbackYAngleCondition_53750::FUN_00047dc0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc490), params, 2);
    }
    DAT_004dc494++;
}


// 0x00053800 FUN_00053800 (176 B): equivalent/0x00053800.cpp
// sym: _FUN_00053800 @ce1913590514 @wf48e9599277f
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00053800 @ 0x00053800
extern "C" void FUN_00053800()
{
    if (DAT_004dc49c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_53800<::CCollisionStunTimeCondition_53800>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_53800<::CCollisionStunTimeCondition_53800>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CCollisionStunTimeCondition_53800::FUN_00047de0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53800<::CCollisionStunTimeCondition_53800>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_53800<::CCollisionStunTimeCondition_53800>("stunTime", &::CCollisionStunTimeCondition_53800::FUN_00047df0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc498), params, 2);
    }
    DAT_004dc49c++;
}


// 0x00053bc0 FUN_00053bc0 (158 B): equivalent/0x00053bc0.cpp
// sym: _FUN_00053bc0 @d7c3557f1ccb @w43f89a7a83fd
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00053bc0 @ 0x00053bc0
extern "C" void FUN_00053bc0()
{
    if (DAT_004dc4cc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53bc0<::CSmartPropAngleCondition_53bc0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_53bc0<::CSmartPropAngleCondition_53bc0>("angle", &::CSmartPropAngleCondition_53bc0::FUN_00047ec0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53bc0<::CSmartPropAngleCondition_53bc0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_53bc0<::CSmartPropAngleCondition_53bc0>("arc", &::CSmartPropAngleCondition_53bc0::FUN_0004c790);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc4c8), params, 2);
    }
    DAT_004dc4cc++;
}

} // namespace fn_f3623cd7

// 0x00053c60 FUN_00053c60 (109 B): equivalent/0x00053c60.cpp [wrapped: conflict: fight::ParamEnumConstList]
// sym: _FUN_00053c60 @4836db47a7d6 @w60b9929c22fb
namespace fn_00053c60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00053c60 @ 0x00053c60


void* FUN_0008d690(unsigned int size);

class CSmartPropCSMableCondition {
public:
    bool FUN_00047f50(void*); /* (unb4) as defined; address taken only */
};

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00053c60()
{
    if (DAT_004dc4e4 == 0) {
        void* params[1];
        void* mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CSmartPropCSMableCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<CSmartPropCSMableCondition>("type", ((const char**)&DAT_003f6b40), 23, (void (CSmartPropCSMableCondition::*)())&CSmartPropCSMableCondition::FUN_00047f50);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc4e0), params, 1);
    }
    DAT_004dc4e4++;
}
} // namespace fn_00053c60


// 0x00053d80 FUN_00053d80 (176 B): matches/0x00053d80.cpp [wrapped: conflict: Alloc]
// sym: _FUN_00053d80
namespace fn_00053d80 {

// data: gGuard = DAT_004dc4f4, gTable_53d80 = DAT_004dc4f0

extern "C" void __cdecl FUN_00047f80();
extern "C" void __cdecl FUN_00047f90();
extern "C" char DAT_003f7d48[];
extern "C" char DAT_003f7d70[];
extern "C++" void* __cdecl Alloc_0008d690(unsigned int);
struct ParamEnumConstList {
    int pad[5];
    int field14;
    hulk_intptr field18;
    void Init_00234cc0(const char*);
};
struct ParamIntConstRange {
    int pad[4];
    hulk_intptr field10;
    void Init_002348e0(const char*);
};
extern void __cdecl Register_002347b0(void*, void**, int);
extern "C" void FUN_00053d80() {
    if ((*(int*)&DAT_004dc4f4)) {
        ++(*(int*)&DAT_004dc4f4);
        return;
    }
    void* slots[2];
    ParamEnumConstList* a = (ParamEnumConstList*)Alloc_0008d690(0x20);
    if (a) {
        int k = (*(int*)&DAT_00427754);
        a->Init_00234cc0("compare");
        a->field14 = k;
        a->pad[0] = ((hulk_intptr)DAT_003f7d48);
        a->pad[4] = ((hulk_intptr)((char*)&DAT_0042773c));
        a->field18 = ((hulk_intptr)(void (__cdecl*)())&FUN_00047f80);
        slots[0] = a;
    } else
        slots[0] = 0;
    ParamIntConstRange* b = (ParamIntConstRange*)Alloc_0008d690(0x18);
    if (b) {
        b->Init_002348e0("state");
        b->pad[0] = ((hulk_intptr)DAT_003f7d70);
        b->field10 = ((hulk_intptr)(void (__cdecl*)())&FUN_00047f90);
        slots[1] = b;
    } else
        slots[1] = 0;
    Register_002347b0(((int*)&DAT_004dc4f0), slots, 2);
    ++(*(int*)&DAT_004dc4f4);
}
} // namespace fn_00053d80

namespace fn_f3623cd7 {

// 0x00054300 FUN_00054300 (95 B): equivalent/0x00054300.cpp
// sym: _FUN_00054300 @9638aa1806b1 @w59f6600a3daa
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_00054300 @ 0x00054300
extern "C" void FUN_00054300()
{
    if (DAT_004dc544 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_54300<::CRageModeCondition_54300>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_54300<::CRageModeCondition_54300>("rageModeOn", &::CRageModeCondition_54300::FUN_00048100);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc540), params, 1);
    }
    DAT_004dc544++;
}


// 0x00054480 FUN_00054480 (176 B): equivalent/0x00054480.cpp
// sym: _FUN_00054480 @cb4094edaba5 @w7f06245e56f5
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00054480 @ 0x00054480
extern "C" void FUN_00054480()
{
    if (DAT_004dc554 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_54480<::CInactivityTimerCondition_54480>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_54480<::CInactivityTimerCondition_54480>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CInactivityTimerCondition_54480::FUN_00048170);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_54480<::CInactivityTimerCondition_54480>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_54480<::CInactivityTimerCondition_54480>("time", &::CInactivityTimerCondition_54480::FUN_00048180);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc550), params, 2);
    }
    DAT_004dc554++;
}


// 0x00054750 FUN_00054750 (176 B): equivalent/0x00054750.cpp
// sym: _FUN_00054750 @a5dadeceb3c5 @w7bbf245bcbbf
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00054750 @ 0x00054750
extern "C" void FUN_00054750()
{
    if (DAT_004dc574 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_54750<::CIntentionSpeedCondition_54750>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_54750<::CIntentionSpeedCondition_54750>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CIntentionSpeedCondition_54750::FUN_000481c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_54750<::CIntentionSpeedCondition_54750>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_54750<::CIntentionSpeedCondition_54750>("value", &::CIntentionSpeedCondition_54750::FUN_000481d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc570), params, 2);
    }
    DAT_004dc574++;
}


// 0x00054800 FUN_00054800 (172 B): equivalent/0x00054800.cpp
// sym: _FUN_00054800 @947b7e57c27b @w9a7017a735db
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_00054800 @ 0x00054800
extern "C" void FUN_00054800()
{
    if (DAT_004dc57c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_54800<::CClimbEdgeCondition_54800>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_54800<::CClimbEdgeCondition_54800>("edge", ((const char**)&DAT_0048f9fc), 6, &::CClimbEdgeCondition_54800::FUN_000481e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_54800<::CClimbEdgeCondition_54800>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_54800<::CClimbEdgeCondition_54800>("checkCorner", &::CClimbEdgeCondition_54800::FUN_000481f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc578), params, 2);
    }
    DAT_004dc57c++;
}


// 0x00054c30 FUN_00054c30 (27 B): matches/0x00054c30.cpp
// sym: ?FUN_00054c30@fn_f3623cd7@@YAXPAX@Z
void __cdecl FUN_00054c30(void* p) {
    ConditionFactoryCasterTemplate_54c30 c;
    findCondition_002343e0(p, &c);
}


// 0x00054c90 FUN_00054c90 (27 B): matches/0x00054c90.cpp
// sym: ?target@fn_f3623cd7@@YAXPAX@Z
void target(void* p) {
    ConditionFactoryCasterTemplate_54c90 c;
    fun_002343e0(p, &c);
}

} // namespace fn_f3623cd7

// 0x00055090 FUN_00055090 (27 B): matches/0x00055090.cpp [wrapped: same definition as 0x00054c90 in this TU]
// sym: ?target@fn_00055090@@YAXPAX@Z
namespace fn_00055090 {
class ConditionFactoryCasterTemplate_55090 {
  public:
    virtual bool cast_000512c0(void*);
};
void __cdecl helper_002343e0(void*, ConditionFactoryCasterTemplate_55090*);
void __cdecl target(void* p) {
    ConditionFactoryCasterTemplate_55090 c;
    helper_002343e0(p, &c);
}
} // namespace fn_00055090

namespace fn_f3623cd7 {

// 0x000551b0 fight::ParamName<CNameFlagConditionBase>::vfunc_7 (12 B): matches/0x000551b0.cpp
// sym: ?vfunc_6@ParamBranch@fn_f3623cd7@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f3623cd7

// 0x000551e0 fight::ParamName<CSmartPropNameCondition>::vfunc_7 (12 B): matches/0x000551e0.cpp [wrapped: same definition as 0x000551b0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000551e0@@UAEXPAX@Z
namespace fn_000551e0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_000551e0

namespace fn_f3623cd7 {

// 0x000551f0 FUN_000551f0 (32 B): matches/0x000551f0.cpp
// sym: ??0ParamNameConstList@fn_f3623cd7@@QAE@HH@Z
ParamNameConstList::ParamNameConstList(int a, int b) : ParamValueNameList_551f0(a) {
    m10 = b;
}

} // namespace fn_f3623cd7
