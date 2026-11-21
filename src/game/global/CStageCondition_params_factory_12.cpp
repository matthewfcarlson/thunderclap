// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00051480..0x00056af0 (kind game, layer game, confidence high), merged by D32: global/CStageCondition_params_factory.cpp
// piece 0x00052720..0x00055210 (kind game, layer game, confidence low); was game/global/CNameFlagConditionBase_reg.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/hulkfight.h"   // (gx3, D18) for the merged registrations
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#include "decls/data/engine/fight.h"   // (gx3, D32) its owner object's data, merged
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3623cd7 {
#define TREE_TU_END }
namespace fn_f3623cd7 {} using namespace fn_f3623cd7;
#include "game/global.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f64b1530 { class C_47f60; } 
namespace fn_f64b1530 { bool __fastcall Target(class fn_f64b1530::C_47f60 *, void *, int); }   // (gx3, D18) a setter, as defined in unk_047970.cpp
namespace fn_00047bf0 { struct Obj_47bf0 { bool SetAxis_00047bf0(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_00047fa0 { struct O_47fa0 { bool operator=(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f342e0ab { struct Obj_49ed0 { char Format(char const *); }; }   // (gx3, D18) setters, as defined in unk_049c80.cpp
namespace fn_f64b1530 { struct A_47c80 { bool Fn(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct C_47c70 { bool SetSize_00047c70(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct C_47c90 { char Fn(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct C_47d40 { char Set(char); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct C_480d0 { char SetUseIntentionMotion_000480d0(char); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct O_47e20 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj { bool SetArc_00047c20(float); char SetMinVelocity_00048240(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47b30 { bool SetCompareSpeed_00047b30(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47b40 { char SetSpeed_00047b40(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47c00 { char SetDirection_00047c00(float); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47c50 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47e00 { char Set(char); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47e10 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47e80 { bool SetType_00047e80(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47f80 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47f90 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47fb0 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47fd0 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48040 { char SetCompare_00048040(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48050 { char SetMotionState_00048050(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48070 { bool SetMotionHit_00048070(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48080 { char SetAngle_00048080(float); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_480a0 { bool SetArc_000480a0(float); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_480f0 { bool SetStatus_000480f0(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48110 { bool SetCompare_00048110(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48120 { char SetTime_00048120(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48160 { char SetKeyWord_00048160(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48190 { bool SetCompare_00048190(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_481a0 { void * GetFightNode_000481a0(); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_481b0 { char SetLastFrame_000481b0(char); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48200 { char SetAngle_00048200(float); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_48220 { unsigned char SetArc_00048220(float); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Target_47e70 { char SetCompare_00047e70(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Target_48060 { bool SetCompare_00048060(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Target_480e0 { bool SetCompare_000480e0(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct X_47c60 { char SetCompare_00047c60(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct X_47f70 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct X_47fc0 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct X_48140 { char SetUseKeyWordWait_00048140(char); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp

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
extern "C" char DAT_003f82a4[];   // (fix2) the game's caster vftable
class ConditionFactoryCasterTemplate_54c30 {   // (fix2) was polymorphic (virtual bool cast_00050a00(void*);): clang's vftable natively
  public:
    void *vftable;
    ConditionFactoryCasterTemplate_54c30() { vftable = DAT_003f82a4; }
};
void __cdecl findCondition_002343e0(void*, ConditionFactoryCasterTemplate_54c30*);
extern "C" char DAT_003f82c8[];   // (fix2) the game's caster vftable
class ConditionFactoryCasterTemplate_54c90 {   // (fix2) was polymorphic (virtual bool cast_00050ac0(void*);): clang's vftable natively
  public:
    void *vftable;
    ConditionFactoryCasterTemplate_54c90() { vftable = DAT_003f82c8; }
};
void __cdecl fun_002343e0(void*, ConditionFactoryCasterTemplate_54c90*);
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
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


} // namespace fn_f3623cd7

namespace fn_f3623cd7 {

} // namespace fn_f3623cd7

namespace fn_f3623cd7 {

} // namespace fn_f3623cd7

// 0x000514b0 fight::ParamEnumConstList<CStageCondition>::vfunc_0 (30 B): matches/0x000514b0.cpp
// sym: ??_G?$ParamEnumConstList@VCStageCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CStageCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000514d0 fight::ParamIntConstRange<CStageCondition>::vfunc_0 (30 B): matches/0x000514d0.cpp
// sym: ??_G?$ParamIntConstRange@VCStageCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CStageCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000514f0 fight::ParamEnumConstList<CButtonCondition>::vfunc_0 (30 B): matches/0x000514f0.cpp
// sym: ??_G?$ParamEnumConstList@VCButtonCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051510 fight::ParamFloatConstRange<CButtonCondition>::vfunc_0 (30 B): matches/0x00051510.cpp
// sym: ??_G?$ParamFloatConstRange@VCButtonCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051530 fight::ParamEnumConstList<CButtonValueCondition>::vfunc_0 (30 B): matches/0x00051530.cpp
// sym: ??_G?$ParamEnumConstList@VCButtonValueCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051550 fight::ParamFloatConstRange<CButtonValueCondition>::vfunc_0 (30 B): matches/0x00051550.cpp
// sym: ??_G?$ParamFloatConstRange@VCButtonValueCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051570 fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_0 (30 B): matches/0x00051570.cpp
// sym: ??_G?$ParamEnumConstList@VCAxisTimeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051590 fight::ParamFloatConstRange<CAxisTimeCondition>::vfunc_0 (30 B): matches/0x00051590.cpp
// sym: ??_G?$ParamFloatConstRange@VCAxisTimeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000515b0 fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_0 (30 B): matches/0x000515b0.cpp
// sym: ??_G?$ParamEnumConstList@VCAxisSpeedCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000515d0 fight::ParamFloatConstRange<CAxisSpeedCondition>::vfunc_0 (30 B): matches/0x000515d0.cpp
// sym: ??_G?$ParamFloatConstRange@VCAxisSpeedCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000515f0 fight::ParamEnumConstList<CAxisValueCondition>::vfunc_0 (30 B): matches/0x000515f0.cpp
// sym: ??_G?$ParamEnumConstList@VCAxisValueCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051610 fight::ParamFloatConstRange<CAxisValueCondition>::vfunc_0 (30 B): matches/0x00051610.cpp
// sym: ??_G?$ParamFloatConstRange@VCAxisValueCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051630 fight::ParamEnumConstList<CAxisArcCondition>::vfunc_0 (30 B): matches/0x00051630.cpp
// sym: ??_G?$ParamEnumConstList@VCAxisArcCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051650 fight::ParamFloatConstRange<CAxisArcCondition>::vfunc_0 (30 B): matches/0x00051650.cpp
// sym: ??_G?$ParamFloatConstRange@VCAxisArcCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051670 fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_0 (30 B): matches/0x00051670.cpp
// sym: ??_G?$ParamEnumConstList@VCAxisDoubleTapCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051690 fight::ParamFloatConstRange<CAxisDoubleTapCondition>::vfunc_0 (30 B): matches/0x00051690.cpp
// sym: ??_G?$ParamFloatConstRange@VCAxisDoubleTapCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000516b0 fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_0 (30 B): matches/0x000516b0.cpp
// sym: ??_G?$ParamEnumConstList@VCAxisDirectionCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000516d0 fight::ParamFloatConstRange<CAxisDirectionCondition>::vfunc_0 (30 B): matches/0x000516d0.cpp
// sym: ??_G?$ParamFloatConstRange@VCAxisDirectionCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000516f0 fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_0 (30 B): matches/0x000516f0.cpp
// sym: ??_G?$ParamEnumConstList@VCGroundDistanceCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051710 fight::ParamFloatConstRange<CGroundDistanceCondition>::vfunc_0 (30 B): matches/0x00051710.cpp
// sym: ??_G?$ParamFloatConstRange@VCGroundDistanceCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051730 fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_0 (30 B): matches/0x00051730.cpp
// sym: ??_G?$ParamEnumConstList@VCCharacterSizeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051750 fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_0 (30 B): matches/0x00051750.cpp
// sym: ??_G?$ParamEnumConstList@VCCollisionHitLocationCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051770 fight::ParamFloatConstRange<CCollisionDirectionCondition>::vfunc_0 (30 B): matches/0x00051770.cpp
// sym: ??_G?$ParamFloatConstRange@VCCollisionDirectionCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051790 fight::ParamFloatConstRange<CCollisionPushbackDirectionCondition>::vfunc_0 (30 B): matches/0x00051790.cpp
// sym: ??_G?$ParamFloatConstRange@VCCollisionPushbackDirectionCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000517e0 fight::ParamBool<CCollisionInterruptCondition>::vfunc_0 (30 B): matches/0x000517e0.cpp
// sym: ??_G?$ParamBool@VCCollisionInterruptCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051800 fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_0 (30 B): matches/0x00051800.cpp
// sym: ??_G?$ParamEnumConstList@VCCollisionHeightCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051820 fight::ParamFloatConstRange<CCollisionHeightCondition>::vfunc_0 (30 B): matches/0x00051820.cpp
// sym: ??_G?$ParamFloatConstRange@VCCollisionHeightCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051840 fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_0 (30 B): matches/0x00051840.cpp
// sym: ??_G?$ParamEnumConstList@VCCollisionPushbackVelocityCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051860 fight::ParamFloatConstRange<CCollisionPushbackVelocityCondition>::vfunc_0 (30 B): matches/0x00051860.cpp
// sym: ??_G?$ParamFloatConstRange@VCCollisionPushbackVelocityCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051880 fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_0 (30 B): matches/0x00051880.cpp
// sym: ??_G?$ParamEnumConstList@VCCollisionPushbackYCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000518a0 fight::ParamFloatConstRange<CCollisionPushbackYCondition>::vfunc_0 (30 B): matches/0x000518a0.cpp
// sym: ??_G?$ParamFloatConstRange@VCCollisionPushbackYCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000518c0 fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_0 (30 B): matches/0x000518c0.cpp
// sym: ??_G?$ParamEnumConstList@VCCollisionPushbackYAngleCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000518e0 fight::ParamFloatConstRange<CCollisionPushbackYAngleCondition>::vfunc_0 (30 B): matches/0x000518e0.cpp
// sym: ??_G?$ParamFloatConstRange@VCCollisionPushbackYAngleCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051900 fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_0 (30 B): matches/0x00051900.cpp
// sym: ??_G?$ParamEnumConstList@VCCollisionStunTimeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051920 fight::ParamFloatConstRange<CCollisionStunTimeCondition>::vfunc_0 (30 B): matches/0x00051920.cpp
// sym: ??_G?$ParamFloatConstRange@VCCollisionStunTimeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051940 fight::ParamBool<CSmartPropAttachedCondition>::vfunc_0 (30 B): matches/0x00051940.cpp
// sym: ??_G?$ParamBool@VCSmartPropAttachedCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropAttachedCondition_params_051940.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051960 fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_0 (30 B): matches/0x00051960.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropAttachedCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropAttachedCondition_params_051940.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051980 fight::ParamIntConstRange<CSmartPropAttachedCondition>::vfunc_0 (30 B): matches/0x00051980.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropAttachedCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropAttachedCondition_params_051940.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000519a0 fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_0 (30 B): matches/0x000519a0.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropWeaponizableTypeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropWeaponizableTypeCondition_params_0519a0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000519c0 fight::ParamIntConstRange<CSmartPropWeaponizableTypeCondition>::vfunc_0 (30 B): matches/0x000519c0.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropWeaponizableTypeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropWeaponizableTypeCondition_params_0519a0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x000519e0 fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_0 (30 B): matches/0x000519e0.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropWeaponTypeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropWeaponizableTypeCondition_params_0519a0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051a00 fight::ParamIntConstRange<CSmartPropWeaponTypeCondition>::vfunc_0 (30 B): matches/0x00051a00.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropWeaponTypeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropWeaponizableTypeCondition_params_0519a0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051a20 fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_0 (30 B): matches/0x00051a20.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropTypeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropWeaponizableTypeCondition_params_0519a0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051a80 fight::ParamFloatConstRange<CSmartPropAngleCondition>::vfunc_0 (30 B): matches/0x00051a80.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropAngleCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropWeaponizableTypeCondition_params_0519a0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051b30 fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_0 (30 B): matches/0x00051b30.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropCSMableCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051b50 fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_0 (30 B): matches/0x00051b50.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropStateCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051b70 fight::ParamIntConstRange<CSmartPropStateCondition>::vfunc_0 (30 B): matches/0x00051b70.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropStateCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051b90 fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_0 (30 B): matches/0x00051b90.cpp
// sym: ??_G?$ParamEnumConstList@VCPropActorStateCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051bb0 fight::ParamIntConstRange<CPropActorStateCondition>::vfunc_0 (30 B): matches/0x00051bb0.cpp
// sym: ??_G?$ParamIntConstRange@VCPropActorStateCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051bd0 fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_0 (30 B): matches/0x00051bd0.cpp
// sym: ??_G?$ParamEnumConstList@VCGrappleSizeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051bf0 fight::ParamString<CLuaNumberCondition>::vfunc_0 (30 B): matches/0x00051bf0.cpp
// sym: ??_G?$ParamString@VCLuaNumberCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051c10 fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_0 (30 B): matches/0x00051c10.cpp
// sym: ??_G?$ParamEnumConstList@VCLuaNumberCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051c30 fight::ParamFloatConstRange<CLuaNumberCondition>::vfunc_0 (30 B): matches/0x00051c30.cpp
// sym: ??_G?$ParamFloatConstRange@VCLuaNumberCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051cb0 fight::ParamEnumConstList<CMotionStateCondition>::vfunc_0 (30 B): matches/0x00051cb0.cpp
// sym: ??_G?$ParamEnumConstList@VCMotionStateCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051cd0 fight::ParamEnumConstList<CMotionHitCondition>::vfunc_0 (30 B): matches/0x00051cd0.cpp
// sym: ??_G?$ParamEnumConstList@VCMotionHitCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051cf0 fight::ParamFloatConstRange<CClimbableCondition>::vfunc_0 (30 B): matches/0x00051cf0.cpp
// sym: ??_G?$ParamFloatConstRange@VCClimbableCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051d10 fight::ParamBool<CClimbableCondition>::vfunc_0 (30 B): matches/0x00051d10.cpp
// sym: ??_G?$ParamBool@VCClimbableCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051d30 fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_0 (30 B): matches/0x00051d30.cpp
// sym: ??_G?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051d50 fight::ParamBool<CRageModeCondition>::vfunc_0 (30 B): matches/0x00051d50.cpp
// sym: ??_G?$ParamBool@VCRageModeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051d70 fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_0 (30 B): matches/0x00051d70.cpp
// sym: ??_G?$ParamEnumConstList@VCGrappleTimerCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleTimerCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051d90 fight::ParamFloatConstRange<CGrappleTimerCondition>::vfunc_0 (30 B): matches/0x00051d90.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleTimerCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051db0 fight::ParamBool<CGrappleTimerCondition>::vfunc_0 (30 B): matches/0x00051db0.cpp
// sym: ??_G?$ParamBool@VCGrappleTimerCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleTimerCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051dd0 fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_0 (30 B): matches/0x00051dd0.cpp
// sym: ??_G?$ParamEnumConstList@VCInactivityTimerCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodePrevCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051df0 fight::ParamFloatConstRange<CInactivityTimerCondition>::vfunc_0 (30 B): matches/0x00051df0.cpp
// sym: ??_G?$ParamFloatConstRange@VCInactivityTimerCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodePrevCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051e70 fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_0 (30 B): matches/0x00051e70.cpp
// sym: ??_G?$ParamEnumConstList@VCFightNodePrevCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodePrevCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051e90 fight::ParamBranch<CFightNodePrevCondition>::vfunc_0 (30 B): matches/0x00051e90.cpp
// sym: ??_G?$ParamBranch@VCFightNodePrevCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodePrevCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051eb0 fight::ParamBool<CFightNodePrevCondition>::vfunc_0 (30 B): matches/0x00051eb0.cpp
// sym: ??_G?$ParamBool@VCFightNodePrevCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodePrevCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051ed0 fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_0 (30 B): matches/0x00051ed0.cpp
// sym: ??_G?$ParamEnumConstList@VCIntentionSpeedCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051ef0 fight::ParamFloatConstRange<CIntentionSpeedCondition>::vfunc_0 (30 B): matches/0x00051ef0.cpp
// sym: ??_G?$ParamFloatConstRange@VCIntentionSpeedCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051f10 fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_0 (30 B): matches/0x00051f10.cpp
// sym: ??_G?$ParamEnumConstList@VCClimbEdgeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051f30 fight::ParamBool<CClimbEdgeCondition>::vfunc_0 (30 B): matches/0x00051f30.cpp
// sym: ??_G?$ParamBool@VCClimbEdgeCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00051f50 fight::ParamFloatConstRange<CMotionClimbAngleCondition>::vfunc_0 (30 B): matches/0x00051f50.cpp
// sym: ??_G?$ParamFloatConstRange@VCMotionClimbAngleCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CFightNodeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00052720 / FUN_000527d0 / FUN_000528d0 / FUN_00052a40 / FUN_00052b40 / FUN_00052c40 / FUN_00052db0 / FUN_00052f20 / FUN_00053080 / FUN_00053170 / FUN_00053220 / FUN_000532e0 / FUN_000533a0 / FUN_00053440 / FUN_000534e0 / FUN_00053540 / FUN_000535f0 / FUN_000536a0 / FUN_00053750 / FUN_00053800 / FUN_000538b0 / FUN_000539a0 / FUN_00053a50 / FUN_00053b00 / FUN_00053bc0 / FUN_00053c60 / FUN_00053cd0 / FUN_00053d80 / FUN_00053e30 / FUN_00053ef0 / FUN_00053fe0 / FUN_000540a0 / FUN_00054160 / FUN_00054240 / FUN_00054300 / FUN_00054360 / FUN_00054480 / FUN_00054660 / FUN_00054750 / FUN_00054800 / FUN_000548b0)



// 0x00052720 FUN_00052720 (176 B): matches/0x00052720.cpp
// sym: _FUN_00052720
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00052720.cpp; constructs the real ParamEnumConstList<CStageCondition>, ParamIntConstRange<CStageCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00052720()
{
    if ((*(int*)&DAT_004dc3fc) == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CStageCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::X_47a90::FUN_00047a90);
        params[1] = new ::fight::ParamIntConstRange< ::CStageCondition>("stage", &owners::Obj_47aa0::FUN_00047aa0);
        FUN_002347b0(&DAT_004dc3f8, params, 2);
    }
    (*(int*)&DAT_004dc3fc)++;
}



// 0x000527d0 FUN_000527d0 (245 B): matches/0x000527d0.cpp
// sym: _FUN_000527d0
// (gx2, D18) from CNameFlagConditionBase_reg.new_plain.cpp; constructs the real ParamEnumConstList<CButtonCondition>, ParamFloatConstRange<CButtonCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000527d0()
{
    if (DAT_004dc404 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::CButtonCondition>("button", (void*)&DAT_0049ee30, 13, &owners::Obj_47ab0::FUN_00047ab0);
        params[1] = new ::fight::ParamEnumConstList< ::CButtonCondition>("compareTime", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_47ac0::FUN_00047ac0);
        params[2] = new ::fight::ParamFloatConstRange< ::CButtonCondition>("time", &owners::C_47ad0::FUN_00047ad0);
        FUN_002347b0(&DAT_004dc400, params, 3);
    }
    DAT_004dc404++;
}



// 0x000528d0 FUN_000528d0 (355 B): matches/0x000528d0.cpp
// sym: _FUN_000528d0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CButtonValueCondition>, ParamFloatConstRange<CButtonValueCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000528d0()
{
    if (DAT_004dc40c == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamEnumConstList< ::CButtonValueCondition>("button", (void*)&DAT_0049ee30, 13, &owners::Obj_47ab0::FUN_00047ab0);
        params[1] = new ::fight::ParamEnumConstList< ::CButtonValueCondition>("compareTime", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_47ac0::FUN_00047ac0);
        params[2] = new ::fight::ParamFloatConstRange< ::CButtonValueCondition>("time", &owners::C_47ad0::FUN_00047ad0);
        params[3] = new ::fight::ParamEnumConstList< ::CButtonValueCondition>("compareValue", (void*)&DAT_0042773c, DAT_00427754, &owners::O_47ae0::FUN_00047ae0);
        params[4] = new ::fight::ParamFloatConstRange< ::CButtonValueCondition>("value", &owners::C_47af0::FUN_00047af0);
        FUN_002347b0(&DAT_004dc408, params, 5);
    }
    DAT_004dc40c++;
}



// 0x00052a40 FUN_00052a40 (245 B): matches/0x00052a40.cpp
// sym: _FUN_00052a40
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00052a40.cpp; constructs the real ParamEnumConstList<CAxisTimeCondition>, ParamFloatConstRange<CAxisTimeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00052a40()
{
    if (DAT_004dc414 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::CAxisTimeCondition>("axis", (void*)&DAT_0049ee74, 2, &owners::C_47b00::FUN_00047b00);
        params[1] = new ::fight::ParamEnumConstList< ::CAxisTimeCondition>("compareTime", (void*)&DAT_0042773c, DAT_00427754, &owners::Target_47b10::FUN_00047b10);
        params[2] = new ::fight::ParamFloatConstRange< ::CAxisTimeCondition>("time", &owners::A_47b20::FUN_00047b20);
        FUN_002347b0(&DAT_004dc410, params, 3);
    }
    DAT_004dc414++;
}



// 0x00052b40 FUN_00052b40 (245 B): matches/0x00052b40.cpp
// sym: _FUN_00052b40
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00052b40.cpp; constructs the real ParamEnumConstList<CAxisSpeedCondition>, ParamFloatConstRange<CAxisSpeedCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00052b40()
{
    if (DAT_004dc41c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::CAxisSpeedCondition>("axis", (void*)&DAT_0049ee74, 2, &owners::C_47b00::FUN_00047b00);
        params[1] = new ::fight::ParamEnumConstList< ::CAxisSpeedCondition>("compareSpeed", (void*)&DAT_0042773c, DAT_00427754, &fn_f64b1530::Obj_47b30::SetCompareSpeed_00047b30);
        params[2] = new ::fight::ParamFloatConstRange< ::CAxisSpeedCondition>("speed", &fn_f64b1530::Obj_47b40::SetSpeed_00047b40);
        FUN_002347b0(&DAT_004dc418, params, 3);
    }
    DAT_004dc41c++;
}



// 0x00052c40 FUN_00052c40 (355 B): matches/0x00052c40.cpp
// sym: _FUN_00052c40
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CAxisValueCondition>, ParamFloatConstRange<CAxisValueCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00052c40()
{
    if (DAT_004dc424 == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamEnumConstList< ::CAxisValueCondition>("axis", (void*)&DAT_0049ee74, 2, &owners::C_47b00::FUN_00047b00);
        params[1] = new ::fight::ParamEnumConstList< ::CAxisValueCondition>("compareTime", (void*)&DAT_0042773c, DAT_00427754, &owners::Target_47b10::FUN_00047b10);
        params[2] = new ::fight::ParamFloatConstRange< ::CAxisValueCondition>("time", &owners::A_47b20::FUN_00047b20);
        params[3] = new ::fight::ParamEnumConstList< ::CAxisValueCondition>("compareValue", (void*)&DAT_0042773c, DAT_00427754, &owners::C_47b50::FUN_00047b50);
        params[4] = new ::fight::ParamFloatConstRange< ::CAxisValueCondition>("value", &owners::Obj_47b60::FUN_00047b60);
        FUN_002347b0(&DAT_004dc420, params, 5);
    }
    DAT_004dc424++;
}



// 0x00052db0 FUN_00052db0 (355 B): matches/0x00052db0.cpp
// sym: _FUN_00052db0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CAxisArcCondition>, ParamFloatConstRange<CAxisArcCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00052db0()
{
    if (DAT_004dc42c == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamEnumConstList< ::CAxisArcCondition>("axis", (void*)&DAT_0049ee74, 2, &owners::C_47b00::FUN_00047b00);
        params[1] = new ::fight::ParamEnumConstList< ::CAxisArcCondition>("compareTime", (void*)&DAT_0042773c, DAT_00427754, &owners::Target_47b10::FUN_00047b10);
        params[2] = new ::fight::ParamFloatConstRange< ::CAxisArcCondition>("time", &owners::A_47b20::FUN_00047b20);
        params[3] = new ::fight::ParamEnumConstList< ::CAxisArcCondition>("compareArc", (void*)&DAT_0042773c, DAT_00427754, &owners::C_47b70::FUN_00047b70);
        params[4] = new ::fight::ParamFloatConstRange< ::CAxisArcCondition>("arc", &owners::O_47b80::FUN_00047b80);
        FUN_002347b0(&DAT_004dc428, params, 5);
    }
    DAT_004dc42c++;
}



// 0x00052f20 FUN_00052f20 (339 B): matches/0x00052f20.cpp
// sym: _FUN_00052f20
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CAxisDoubleTapCondition>, ParamFloatConstRange<CAxisDoubleTapCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00052f20()
{
    if (DAT_004dc434 == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamEnumConstList< ::CAxisDoubleTapCondition>("axis", (void*)&DAT_0049ee74, 2, &owners::C_47b00::FUN_00047b00);
        params[1] = new ::fight::ParamEnumConstList< ::CAxisDoubleTapCondition>("compareArc", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_47ba0::FUN_00047ba0);
        params[2] = new ::fight::ParamFloatConstRange< ::CAxisDoubleTapCondition>("arc", &owners::O_47bb0::FUN_00047bb0);
        params[3] = new ::fight::ParamFloatConstRange< ::CAxisDoubleTapCondition>("timeMin", &owners::X_47bd0::FUN_00047bd0);
        params[4] = new ::fight::ParamFloatConstRange< ::CAxisDoubleTapCondition>("timeMax", &owners::Obj_47be0::FUN_00047be0);
        FUN_002347b0(&DAT_004dc430, params, 5);
    }
    DAT_004dc434++;
}



// 0x00053080 FUN_00053080 (227 B): matches/0x00053080.cpp
// sym: _FUN_00053080
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00053080.cpp; constructs the real ParamEnumConstList<CAxisDirectionCondition>, ParamFloatConstRange<CAxisDirectionCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053080()
{
    if (DAT_004dc43c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::CAxisDirectionCondition>("axis", (void*)&DAT_0048f9b0, 4, &fn_00047bf0::Obj_47bf0::SetAxis_00047bf0);
        params[1] = new ::fight::ParamFloatConstRange< ::CAxisDirectionCondition>("direction", &fn_f64b1530::Obj_47c00::SetDirection_00047c00);
        params[2] = new ::fight::ParamFloatConstRange< ::CAxisDirectionCondition>("arc", &fn_f64b1530::Obj::SetArc_00047c20);
        FUN_002347b0(&DAT_004dc438, params, 3);
    }
    DAT_004dc43c++;
}



// 0x00053170 FUN_00053170 (176 B): matches/0x00053170.cpp
// sym: _FUN_00053170
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CGroundDistanceCondition>, ParamFloatConstRange<CGroundDistanceCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053170()
{
    if (DAT_004dc444 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CGroundDistanceCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_47c40::FUN_00047c40);
        params[1] = new ::fight::ParamFloatConstRange< ::CGroundDistanceCondition>("distance", &fn_f64b1530::Obj_47c50::Set);
        FUN_002347b0(&DAT_004dc440, params, 2);
    }
    DAT_004dc444++;
}



// 0x00053220 FUN_00053220 (192 B): matches/0x00053220.cpp
// sym: _FUN_00053220
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00053220.cpp; constructs the real ParamEnumConstList<CCharacterSizeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053220()
{
    if (DAT_004dc44c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCharacterSizeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f64b1530::X_47c60::SetCompare_00047c60);
        params[1] = new ::fight::ParamEnumConstList< ::CCharacterSizeCondition>("size", (void*)&DAT_0048f6b4, DAT_003f5eb4, &fn_f64b1530::C_47c70::SetSize_00047c70);
        FUN_002347b0(&DAT_004dc448, params, 2);
    }
    DAT_004dc44c++;
}



// 0x000532e0 FUN_000532e0 (192 B): matches/0x000532e0.cpp
// sym: _FUN_000532e0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CCollisionHitLocationCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000532e0()
{
    if (DAT_004dc454 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCollisionHitLocationCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f64b1530::A_47c80::Fn);
        params[1] = new ::fight::ParamEnumConstList< ::CCollisionHitLocationCondition>("hitLocation", (void*)&DAT_0048f6cc, DAT_003f5ed0, &fn_f64b1530::C_47c90::Fn);
        FUN_002347b0(&DAT_004dc450, params, 2);
    }
    DAT_004dc454++;
}



// 0x000533a0 FUN_000533a0 (158 B): matches/0x000533a0.cpp
// sym: _FUN_000533a0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CCollisionDirectionCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000533a0()
{
    if (DAT_004dc45c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CCollisionDirectionCondition>("direction", &owners::Obj_47ca0::FUN_00047ca0);
        params[1] = new ::fight::ParamFloatConstRange< ::CCollisionDirectionCondition>("arc", &owners::Obj_47cc0::FUN_00047cc0);
        FUN_002347b0(&DAT_004dc458, params, 2);
    }
    DAT_004dc45c++;
}



// 0x00053440 FUN_00053440 (158 B): matches/0x00053440.cpp
// sym: _FUN_00053440
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CCollisionPushbackDirectionCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053440()
{
    if (DAT_004dc464 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CCollisionPushbackDirectionCondition>("direction", &owners::Obj_47ce0::FUN_00047ce0);
        params[1] = new ::fight::ParamFloatConstRange< ::CCollisionPushbackDirectionCondition>("arc", &owners::V_47d00::FUN_00047d00);
        FUN_002347b0(&DAT_004dc460, params, 2);
    }
    DAT_004dc464++;
}



// 0x000534e0 FUN_000534e0 (95 B): matches/0x000534e0.cpp
// sym: _FUN_000534e0
// (gx2, D18) rewritten; constructs the real ParamBool<CCollisionInterruptCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000534e0()
{
    if ((*(int*)&DAT_004dc474) == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::CCollisionInterruptCondition>("interrupt", &fn_f64b1530::C_47d40::Set);
        FUN_002347b0(&DAT_004dc470, params, 1);
    }
    (*(int*)&DAT_004dc474)++;
}



// 0x00053540 FUN_00053540 (176 B): matches/0x00053540.cpp
// sym: _FUN_00053540
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CCollisionHeightCondition>, ParamFloatConstRange<CCollisionHeightCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053540()
{
    if (DAT_004dc47c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCollisionHeightCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_47d50::FUN_00047d50);
        params[1] = new ::fight::ParamFloatConstRange< ::CCollisionHeightCondition>("height", &owners::Obj_47d60::FUN_00047d60);
        FUN_002347b0(&DAT_004dc478, params, 2);
    }
    DAT_004dc47c++;
}



// 0x000535f0 FUN_000535f0 (176 B): matches/0x000535f0.cpp
// sym: _FUN_000535f0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CCollisionPushbackVelocityCondition>, ParamFloatConstRange<CCollisionPushbackVelocityCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000535f0()
{
    if (DAT_004dc484 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCollisionPushbackVelocityCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::A_47d70::FUN_00047d70);
        params[1] = new ::fight::ParamFloatConstRange< ::CCollisionPushbackVelocityCondition>("velocity", &owners::X_47d80::FUN_00047d80);
        FUN_002347b0(&DAT_004dc480, params, 2);
    }
    DAT_004dc484++;
}



// 0x000536a0 FUN_000536a0 (176 B): matches/0x000536a0.cpp
// sym: _FUN_000536a0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CCollisionPushbackYCondition>, ParamFloatConstRange<CCollisionPushbackYCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000536a0()
{
    if (DAT_004dc48c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCollisionPushbackYCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_47d90::FUN_00047d90);
        params[1] = new ::fight::ParamFloatConstRange< ::CCollisionPushbackYCondition>("pushbackY", &owners::Obj_47da0::FUN_00047da0);
        FUN_002347b0(&DAT_004dc488, params, 2);
    }
    DAT_004dc48c++;
}



// 0x00053750 FUN_00053750 (176 B): matches/0x00053750.cpp
// sym: _FUN_00053750
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CCollisionPushbackYAngleCondition>, ParamFloatConstRange<CCollisionPushbackYAngleCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053750()
{
    if (DAT_004dc494 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCollisionPushbackYAngleCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_47db0::FUN_00047db0);
        params[1] = new ::fight::ParamFloatConstRange< ::CCollisionPushbackYAngleCondition>("angle", &owners::Obj_47dc0::FUN_00047dc0);
        FUN_002347b0(&DAT_004dc490, params, 2);
    }
    DAT_004dc494++;
}



// 0x00053800 FUN_00053800 (176 B): matches/0x00053800.cpp
// sym: _FUN_00053800
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CCollisionStunTimeCondition>, ParamFloatConstRange<CCollisionStunTimeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053800()
{
    if (DAT_004dc49c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCollisionStunTimeCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::O_47de0::FUN_00047de0);
        params[1] = new ::fight::ParamFloatConstRange< ::CCollisionStunTimeCondition>("stunTime", &owners::X_47df0::FUN_00047df0);
        FUN_002347b0(&DAT_004dc498, params, 2);
    }
    DAT_004dc49c++;
}



// 0x000538b0 FUN_000538b0 (227 B): matches/0x000538b0.cpp
// sym: _FUN_000538b0
// (gx2, D18) from CNameFlagConditionBase_reg.iso_000538b0.cpp; constructs the real ParamBool<CSmartPropAttachedCondition>, ParamEnumConstList<CSmartPropAttachedCondition>, ParamIntConstRange<CSmartPropAttachedCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000538b0()
{
    if (DAT_004dc4a4 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamBool< ::CSmartPropAttachedCondition>("matchType", &fn_f64b1530::Obj_47e00::Set);
        params[1] = new ::fight::ParamEnumConstList< ::CSmartPropAttachedCondition>("type", (void*)&DAT_003f6b40, 23, &fn_f64b1530::Obj_47e10::Set);
        params[2] = new ::fight::ParamIntConstRange< ::CSmartPropAttachedCondition>("attachmentIndex", &fn_f64b1530::O_47e20::Set);
        FUN_002347b0(&DAT_004dc4a0, params, 3);
    }
    DAT_004dc4a4++;
}



// 0x000539a0 FUN_000539a0 (172 B): matches/0x000539a0.cpp
// sym: _FUN_000539a0
// (gx2, D18) from CNameFlagConditionBase_reg.iso_000539a0.cpp; constructs the real ParamEnumConstList<CSmartPropWeaponizableTypeCondition>, ParamIntConstRange<CSmartPropWeaponizableTypeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000539a0()
{
    if (DAT_004dc4ac == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CSmartPropWeaponizableTypeCondition>("type", (void*)&DAT_003f6b9c, 7, &owners::X_47e30::FUN_00047e30);
        params[1] = new ::fight::ParamIntConstRange< ::CSmartPropWeaponizableTypeCondition>("attachmentIndex", &owners::Obj_47e40::FUN_00047e40);
        FUN_002347b0(&DAT_004dc4a8, params, 2);
    }
    DAT_004dc4ac++;
}



// 0x00053a50 FUN_00053a50 (172 B): matches/0x00053a50.cpp
// sym: _FUN_00053a50
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00053a50.cpp; constructs the real ParamEnumConstList<CSmartPropWeaponTypeCondition>, ParamIntConstRange<CSmartPropWeaponTypeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053a50()
{
    if (DAT_004dc4b4 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CSmartPropWeaponTypeCondition>("type", (void*)&DAT_003f6b9c, 7, &owners::Target_47e50::FUN_00047e50);
        params[1] = new ::fight::ParamIntConstRange< ::CSmartPropWeaponTypeCondition>("attachmentIndex", &owners::Obj_47e60::FUN_00047e60);
        FUN_002347b0(&DAT_004dc4b0, params, 2);
    }
    DAT_004dc4b4++;
}



// 0x00053b00 FUN_00053b00 (190 B): matches/0x00053b00.cpp
// sym: _FUN_00053b00
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00053b00.cpp; constructs the real ParamEnumConstList<CSmartPropTypeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053b00()
{
    if (DAT_004dc4bc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CSmartPropTypeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f64b1530::Target_47e70::SetCompare_00047e70);
        params[1] = new ::fight::ParamEnumConstList< ::CSmartPropTypeCondition>("type", (void*)&DAT_003f6b40, 23, &fn_f64b1530::Obj_47e80::SetType_00047e80);
        FUN_002347b0(&DAT_004dc4b8, params, 2);
    }
    DAT_004dc4bc++;
}



// 0x00053bc0 FUN_00053bc0 (158 B): matches/0x00053bc0.cpp
// sym: _FUN_00053bc0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CSmartPropAngleCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053bc0()
{
    if (DAT_004dc4cc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CSmartPropAngleCondition>("angle", &owners::Obj_47ec0::FUN_00047ec0);
        params[1] = new ::fight::ParamFloatConstRange< ::CSmartPropAngleCondition>("arc", &owners::Thing_4c790::FUN_0004c790);
        FUN_002347b0(&DAT_004dc4c8, params, 2);
    }
    DAT_004dc4cc++;
}



// 0x00053c60 FUN_00053c60 (109 B): matches/0x00053c60.cpp
// sym: _FUN_00053c60
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CSmartPropCSMableCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053c60()
{
    if (DAT_004dc4e4 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamEnumConstList< ::CSmartPropCSMableCondition>("type", (void*)&DAT_003f6b40, 23, &owners::Obj_47f50::FUN_00047f50);
        FUN_002347b0(&DAT_004dc4e0, params, 1);
    }
    DAT_004dc4e4++;
}



// 0x00053cd0 FUN_00053cd0 (176 B): matches/0x00053cd0.cpp
// sym: _FUN_00053cd0
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00053cd0.cpp; constructs the real ParamEnumConstList<CSmartPropStateCondition>, ParamIntConstRange<CSmartPropStateCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053cd0()
{
    if (DAT_004dc4ec == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CSmartPropStateCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f64b1530::Target);
        params[1] = new ::fight::ParamIntConstRange< ::CSmartPropStateCondition>("state", &fn_f64b1530::X_47f70::Set);
        FUN_002347b0(&DAT_004dc4e8, params, 2);
    }
    DAT_004dc4ec++;
}



// 0x00053d80 FUN_00053d80 (176 B): matches/0x00053d80.cpp
// sym: _FUN_00053d80
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CPropActorStateCondition>, ParamIntConstRange<CPropActorStateCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053d80()
{
    if ((*(int*)&DAT_004dc4f4) == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CPropActorStateCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f64b1530::Obj_47f80::Set);
        params[1] = new ::fight::ParamIntConstRange< ::CPropActorStateCondition>("state", &fn_f64b1530::Obj_47f90::Set);
        FUN_002347b0(&DAT_004dc4f0, params, 2);
    }
    (*(int*)&DAT_004dc4f4)++;
}



// 0x00053e30 FUN_00053e30 (192 B): matches/0x00053e30.cpp
// sym: _FUN_00053e30
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00053e30.cpp; constructs the real ParamEnumConstList<CGrappleSizeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053e30()
{
    if (DAT_004dc4fc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CGrappleSizeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, static_cast<bool (fn_00047fa0::O_47fa0::*)(int)>(&fn_00047fa0::O_47fa0::operator=));
        params[1] = new ::fight::ParamEnumConstList< ::CGrappleSizeCondition>("size", (void*)&DAT_0048f6b4, DAT_003f5eb4, &fn_f64b1530::Obj_47fb0::Set);
        FUN_002347b0(&DAT_004dc4f8, params, 2);
    }
    DAT_004dc4fc++;
}



// 0x00053ef0 FUN_00053ef0 (231 B): matches/0x00053ef0.cpp
// sym: _FUN_00053ef0
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00053ef0.cpp; constructs the real ParamEnumConstList<CLuaNumberCondition>, ParamFloatConstRange<CLuaNumberCondition>, ParamString<CLuaNumberCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053ef0()
{
    if (DAT_004dc504 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamString< ::CLuaNumberCondition>("variableName", &fn_f342e0ab::Obj_49ed0::Format);
        params[1] = new ::fight::ParamEnumConstList< ::CLuaNumberCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f64b1530::X_47fc0::Set);
        params[2] = new ::fight::ParamFloatConstRange< ::CLuaNumberCondition>("luaValue", &fn_f64b1530::Obj_47fd0::Set);
        FUN_002347b0(&DAT_004dc500, params, 3);
    }
    DAT_004dc504++;
}



// 0x00053fe0 FUN_00053fe0 (192 B): matches/0x00053fe0.cpp
// sym: _FUN_00053fe0
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00053fe0.cpp; constructs the real ParamEnumConstList<CMotionStateCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00053fe0()
{
    if (DAT_004dc524 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CMotionStateCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f64b1530::Obj_48040::SetCompare_00048040);
        params[1] = new ::fight::ParamEnumConstList< ::CMotionStateCondition>("motionState", (void*)&DAT_0048f57c, DAT_003f5bb8, &fn_f64b1530::Obj_48050::SetMotionState_00048050);
        FUN_002347b0(&DAT_004dc520, params, 2);
    }
    DAT_004dc524++;
}



// 0x000540a0 FUN_000540a0 (190 B): matches/0x000540a0.cpp
// sym: ?FUN_000540a0@@YAXXZ
// (gx2, D18) from CNameFlagConditionBase_reg.iso_000540a0.cpp; constructs the real ParamEnumConstList<CMotionHitCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_000540a0()
{
    if (DAT_004dc52c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CMotionHitCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f64b1530::Target_48060::SetCompare_00048060);
        params[1] = new ::fight::ParamEnumConstList< ::CMotionHitCondition>("motionHit", (void*)&DAT_0048f9c0, 5, &fn_f64b1530::Obj_48070::SetMotionHit_00048070);
        FUN_002347b0(&DAT_004dc528, params, 2);
    }
    DAT_004dc52c++;
}



// 0x00054160 FUN_00054160 (213 B): matches/0x00054160.cpp
// sym: _FUN_00054160
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00054160.cpp; constructs the real ParamBool<CClimbableCondition>, ParamFloatConstRange<CClimbableCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00054160()
{
    if (DAT_004dc534 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CClimbableCondition>("angle", &fn_f64b1530::Obj_48080::SetAngle_00048080);
        params[1] = new ::fight::ParamFloatConstRange< ::CClimbableCondition>("arc", &fn_f64b1530::Obj_480a0::SetArc_000480a0);
        params[2] = new ::fight::ParamBool< ::CClimbableCondition>("useIntentionMotion", &fn_f64b1530::C_480d0::SetUseIntentionMotion_000480d0);
        FUN_002347b0(&DAT_004dc530, params, 3);
    }
    DAT_004dc534++;
}



// 0x00054240 FUN_00054240 (192 B): matches/0x00054240.cpp
// sym: _FUN_00054240
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00054240.cpp; constructs the real ParamEnumConstList<CAlertStatusCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00054240()
{
    if ((*(int*)&DAT_004dc53c) == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CAlertStatusCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f64b1530::Target_480e0::SetCompare_000480e0);
        params[1] = new ::fight::ParamEnumConstList< ::CAlertStatusCondition>("status", (void*)&DAT_004a1ab4, DAT_0040d0e4, &fn_f64b1530::Obj_480f0::SetStatus_000480f0);
        FUN_002347b0(&DAT_004dc538, params, 2);
    }
    (*(int*)&DAT_004dc53c)++;
}



// 0x00054300 FUN_00054300 (95 B): matches/0x00054300.cpp
// sym: _FUN_00054300
// (gx2, D18) rewritten; constructs the real ParamBool<CRageModeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00054300()
{
    if (DAT_004dc544 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::CRageModeCondition>("rageModeOn", &owners::Obj_48100::FUN_00048100);
        FUN_002347b0(&DAT_004dc540, params, 1);
    }
    DAT_004dc544++;
}



// 0x00054360 FUN_00054360 (288 B): matches/0x00054360.cpp
// sym: _FUN_00054360
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00054360.cpp; constructs the real ParamBool<CGrappleTimerCondition>, ParamEnumConstList<CGrappleTimerCondition>, ParamFloatConstRange<CGrappleTimerCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00054360()
{
    if (DAT_004dc54c == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamEnumConstList< ::CGrappleTimerCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f64b1530::Obj_48110::SetCompare_00048110);
        params[1] = new ::fight::ParamFloatConstRange< ::CGrappleTimerCondition>("time", &fn_f64b1530::Obj_48120::SetTime_00048120);
        params[2] = new ::fight::ParamBool< ::CGrappleTimerCondition>("useKeyWordWait", &fn_f64b1530::X_48140::SetUseKeyWordWait_00048140);
        params[3] = new ::fight::ParamEnumConstList< ::CGrappleTimerCondition>("keyWord", (void*)&DAT_0048f9d4, 10, &fn_f64b1530::Obj_48160::SetKeyWord_00048160);
        FUN_002347b0(&DAT_004dc548, params, 4);
    }
    DAT_004dc54c++;
}



// 0x00054480 FUN_00054480 (176 B): matches/0x00054480.cpp
// sym: _FUN_00054480
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CInactivityTimerCondition>, ParamFloatConstRange<CInactivityTimerCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00054480()
{
    if (DAT_004dc554 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CInactivityTimerCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_48170::FUN_00048170);
        params[1] = new ::fight::ParamFloatConstRange< ::CInactivityTimerCondition>("time", &owners::Obj_48180::FUN_00048180);
        FUN_002347b0(&DAT_004dc550, params, 2);
    }
    DAT_004dc554++;
}



// 0x00054660 FUN_00054660 (231 B): matches/0x00054660.cpp
// sym: _FUN_00054660
// (gx2, D18) from CNameFlagConditionBase_reg.iso_00054660.cpp; constructs the real ParamBool<CFightNodePrevCondition>, ParamBranch<CFightNodePrevCondition>, ParamEnumConstList<CFightNodePrevCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00054660()
{
    if (DAT_004dc56c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::CFightNodePrevCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f64b1530::Obj_48190::SetCompare_00048190);
        params[1] = new ::fight::ParamBranch< ::CFightNodePrevCondition>("fightNode", &fn_f64b1530::Obj_481a0::GetFightNode_000481a0);
        params[2] = new ::fight::ParamBool< ::CFightNodePrevCondition>("lastFrame", &fn_f64b1530::Obj_481b0::SetLastFrame_000481b0);
        FUN_002347b0(&DAT_004dc568, params, 3);
    }
    DAT_004dc56c++;
}



// 0x00054750 FUN_00054750 (176 B): matches/0x00054750.cpp
// sym: _FUN_00054750
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CIntentionSpeedCondition>, ParamFloatConstRange<CIntentionSpeedCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00054750()
{
    if (DAT_004dc574 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CIntentionSpeedCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_481c0::FUN_000481c0);
        params[1] = new ::fight::ParamFloatConstRange< ::CIntentionSpeedCondition>("value", &owners::Obj_481d0::FUN_000481d0);
        FUN_002347b0(&DAT_004dc570, params, 2);
    }
    DAT_004dc574++;
}



// 0x00054800 FUN_00054800 (172 B): matches/0x00054800.cpp
// sym: _FUN_00054800
// (gx2, D18) rewritten; constructs the real ParamBool<CClimbEdgeCondition>, ParamEnumConstList<CClimbEdgeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00054800()
{
    if (DAT_004dc57c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CClimbEdgeCondition>("edge", (void*)&DAT_0048f9fc, 6, &owners::Obj_481e0::FUN_000481e0);
        params[1] = new ::fight::ParamBool< ::CClimbEdgeCondition>("checkCorner", &owners::X_481f0::FUN_000481f0);
        FUN_002347b0(&DAT_004dc578, params, 2);
    }
    DAT_004dc57c++;
}



// 0x000548b0 FUN_000548b0 (213 B): matches/0x000548b0.cpp
// sym: _FUN_000548b0
// (gx2, D18) from CNameFlagConditionBase_reg.iso_000548b0.cpp; constructs the real ParamFloatConstRange<CMotionClimbAngleCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000548b0()
{
    if (DAT_004dc584 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CMotionClimbAngleCondition>("angle", &fn_f64b1530::Obj_48200::SetAngle_00048200);
        params[1] = new ::fight::ParamFloatConstRange< ::CMotionClimbAngleCondition>("arc", &fn_f64b1530::Obj_48220::SetArc_00048220);
        params[2] = new ::fight::ParamFloatConstRange< ::CMotionClimbAngleCondition>("minVelocity", &fn_f64b1530::Obj::SetMinVelocity_00048240);
        FUN_002347b0(&DAT_004dc580, params, 3);
    }
    DAT_004dc584++;
}

namespace fn_f3623cd7 {


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
extern "C" char DAT_003f8448[];   // (fix2) the game's caster vftable
class ConditionFactoryCasterTemplate_55090 {   // (fix2) was polymorphic (virtual bool cast_000512c0(void*);): clang's vftable natively
  public:
    void *vftable;
    ConditionFactoryCasterTemplate_55090() { vftable = DAT_003f8448; }
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
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
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
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_000551e0

namespace fn_f3623cd7 {

// 0x000551f0 FUN_000551f0 (32 B): matches/0x000551f0.cpp
// sym: ??0ParamNameConstList@fn_f3623cd7@@QAE@HH@Z
ParamNameConstList::ParamNameConstList(int a, int b) : ParamValueNameList_551f0(a) {
    m10 = b;
}

} // namespace fn_f3623cd7
