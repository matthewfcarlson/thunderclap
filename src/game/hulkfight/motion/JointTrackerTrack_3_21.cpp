// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178d00..0x0017e1a0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/JointTrackerTrack_3.cpp
// piece 0x00179c10..0x0017afd0 (kind game, layer game, confidence low); was game/unknown/unk_179c10.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ff8057c2 {
#define TREE_TU_END }
namespace fn_ff8057c2 {} using namespace fn_ff8057c2;
#include "game/unknown.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_0016f390 { struct Vec; } 
namespace fn_fa642773 { struct Data_16f9a0; } 
namespace fn_fa642773 { struct Src_16f1a0; } 
namespace fn_fa642773 { struct Src_16fa40; } 
namespace fn_fa642773 { struct Vec3_16f0f0; } 
namespace fn_0016f390 { struct Obj { char Set(struct fn_0016f390::Vec const *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_f18c5a89 { struct TextHolder { bool SetText_00170de0(char const *); }; }   // (gx3, D18) setters, as defined in ChargeClearTrack.cpp
namespace fn_f659ad5b { struct Obj { unsigned char Set(char const *); }; }   // (gx3, D18) setters, as defined in DriftToHulkTrack.cpp
namespace fn_fa642773 { struct A_16f160 { char f(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct A_16f1f0 { bool SetMotionState_0016f1f0(void *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct O_16f0f0 { bool Fn(struct fn_fa642773::Vec3_16f0f0 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f170 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f1a0 { unsigned char Fn(struct fn_fa642773::Src_16f1a0 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f1c0 { bool SetTimeBegin_0016f1c0(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f1d0 { char SetTimeEnd_0016f1d0(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f200 { bool SetTimeBegin_0016f200(void *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f210 { char SetTimeEnd_0016f210(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f880 { bool Fn(void *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f8a0 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f930 { bool SetTimeBegin_0016f930(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f960 { char SetOffset_0016f960(void *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f9a0 { char SetMinimum_0016f9a0(struct fn_fa642773::Data_16f9a0 *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16f9d0 { bool SetTraceWidth_0016f9d0(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16fa00 { bool SetTimeBegin_0016fa00(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16fa40 { bool SetOffset_0016fa40(struct fn_fa642773::Src_16fa40 const *); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16fa70 { bool SetTimeEnd_0016fa70(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct Obj_16fa90 { char SetClearOnBegin_0016fa90(char); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct X_16f230 { bool SetFinalVelocity_0016f230(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
namespace fn_fa642773 { struct X_16fa60 { char SetTimeBegin_0016fa60(int); }; }   // (gx3, D18) setters, as defined in unk_16e720.cpp
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_ff8057c2 {
void* FUN_0008d690(unsigned int size);
class ChargeTrack {
public:
    char FUN_0016e9b0(int); /* (unb4) as defined; address taken only */
    char FUN_0016e9c0(void*); /* (unb4) as defined; address taken only */
    char FUN_0016e9e0(int); /* (unb4) as defined; address taken only */
    char FUN_0016ea00(char); /* (unb4) as defined; address taken only */
    char FUN_0016ea20(int); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
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
} // namespace fn_ff8057c2
namespace hulkfight { namespace motion {
class SnapToGroundTrack_179d60 {
public:
    char FUN_0016eac0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_179d60 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_179d60(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff8057c2 {
class SuckTrack {
public:
    char FUN_0016ede0(int); /* (unb4) as defined; address taken only */
    char FUN_0016edf0(int); /* (unb4) as defined; address taken only */
    char FUN_0016ee10(int); /* (unb4) as defined; address taken only */
    char FUN_0016ee30(int); /* (unb4) as defined; address taken only */
    bool FUN_0016ee50(int); /* (unb4) as defined; address taken only */
    char FUN_0016ee70(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_ff8057c2
namespace hulkfight { namespace motion {
class LocomotionStateTrack_179f30 {
public:
    bool FUN_0016ee80(int); /* (unb4) as defined; address taken only */
    char FUN_0016eea0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_179f30 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_179f30(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_179f30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_179f30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff8057c2 {
class DriftToPositionTrack {
public:
    bool FUN_0016f090(int); /* (unb4) as defined; address taken only */
    char FUN_0016f0a0(int); /* (unb4) as defined; address taken only */
    char FUN_0016f0c0(char); /* (unb4) as defined; address taken only */
    bool FUN_0016f0f0(void*); /* (unb4) as defined; address taken only */
    char FUN_0016f120(char); /* (unb4) as defined; address taken only */
    bool FUN_0016f140(char); /* (unb4) as defined; address taken only */
    char FUN_00170480(void*); /* (unb4) as defined; address taken only */
};
} // namespace fn_ff8057c2
namespace hulkfight { namespace motion {
class TargetBreakTrack_17a420 {
public:
    bool FUN_0016f240(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_17a420 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17a420(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class TeleportTrack_17a480 {
public:
    char FUN_0016f360(int); /* (unb4) as defined; address taken only */
    char FUN_0016f390(void*); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_17a480 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17a480(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_17a480 : public ParamVectorBase {
public:
    ParamVector_17a480(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class SurfTrack_17a520 {
public:
    bool FUN_0016f5e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f5f0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f610(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f630(int); /* (unb4) as defined; address taken only */
    char FUN_0016f650(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f670(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f690(float); /* (unb4) as defined; address taken only */
    char FUN_0016f6c0(float); /* (unb4) as defined; address taken only */
    char FUN_0016f6f0(float); /* (unb4) as defined; address taken only */
    char FUN_0016f720(float); /* (unb4) as defined; address taken only */
    char FUN_0016f750(float); /* (unb4) as defined; address taken only */
    char FUN_0016f780(float); /* (unb4) as defined; address taken only */
    char FUN_0016f7b0(int); /* (unb4) as defined; address taken only */
    char FUN_0016f7d0(int); /* (unb4) as defined; address taken only */
    char FUN_0016f7f0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_17a520 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17a520(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_17a520 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17a520(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff8057c2 {
class TargetIconDistanceTrack {
public:
    bool FUN_0016f800(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f810(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f830(int); /* (unb4) as defined; address taken only */
    char FUN_0016f850(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f870(int); /* (unb4) as defined; address taken only */
};
extern "C" void __cdecl FUN_0016f880();
extern "C" void __cdecl FUN_0016f8a0();
extern "C" char DAT_0041872c[];
struct Param {
    char pad[0x18];
};
} // namespace fn_ff8057c2
void* operator new(size_t n);
namespace fn_ff8057c2 {
void Register_002347b0(void* reg, Param** arr, int n);
struct Base_17a9a0 {
    int vt;
    char pad[0xc];
    int f10;
    int f14;
    Base_17a9a0(const char* name);
};
class SuckInPropsTrack {
public:
    char FUN_0016f8b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f8c0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f8e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0016f900(int); /* (unb4) as defined; address taken only */
    char FUN_0016f920(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_ff8057c2
namespace hulkfight { namespace motion {
class IntentionClearTrack_17ac80 {
public:
    bool FUN_0016f9e0(int); /* (unb4) as defined; address taken only */
    char FUN_0016f9f0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_17ac80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17ac80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class VisibilityTrack_17aee0 {
public:
    char FUN_0016faa0(int); /* (unb4) as defined; address taken only */
    char FUN_0016fac0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_17aee0 : public ParamBoolBase {
public:
    ParamBool_17aee0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_17aee0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17aee0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff8057c2 {
class Params_17af80 {
  public:
    int x;
};
extern Params_17af80 hulk_at_00494b44;
extern Params_17af80 hulk_at_00494b60;
class Object_17af80 {
  public:
    int Init_001732f0(hulkfight::motion::LocomotionStateTrack*, hulk_intptr);
};
Object_17af80* __cdecl Alloc_0008d690(int);


} // namespace fn_ff8057c2

// 0x00178e10 fight::ParamFloatConstRange<hulkfight::motion::ChargeTrack>::vfunc_0 (30 B): matches/0x00178e10.cpp
// sym: ??_G?$ParamFloatConstRange@VChargeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ChargeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00178e30 fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_0 (30 B): matches/0x00178e30.cpp
// sym: ??_G?$ParamEnumConstList@VChargeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ChargeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00178e50 fight::ParamBool<hulkfight::motion::ChargeTrack>::vfunc_0 (30 B): matches/0x00178e50.cpp
// sym: ??_G?$ParamBool@VChargeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ChargeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00178f30 fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::vfunc_0 (30 B): matches/0x00178f30.cpp
// sym: ??_G?$ParamFloatConstRange@VSnapToGroundTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from JointRelativeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179130 fight::ParamFloatConstRange<hulkfight::motion::SuckTrack>::vfunc_0 (30 B): matches/0x00179130.cpp
// sym: ??_G?$ParamFloatConstRange@VSuckTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from LocomotionStateTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179190 fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>::vfunc_0 (30 B): matches/0x00179190.cpp
// sym: ??_G?$ParamFloatConstRange@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from LocomotionStateTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001791b0 fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_0 (30 B): matches/0x001791b0.cpp
// sym: ??_G?$ParamEnumConstList@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from LocomotionStateTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001792d0 fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (30 B): matches/0x001792d0.cpp
// sym: ??_G?$ParamFloatConstRange@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from DriftToPositionTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001792f0 fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (30 B): matches/0x001792f0.cpp
// sym: ??_G?$ParamBool@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from DriftToPositionTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179310 fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (30 B): matches/0x00179310.cpp
// sym: ??_G?$ParamVector@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from DriftToPositionTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179330 fight::ParamString<hulkfight::motion::DriftToPositionTrack>::vfunc_0 (30 B): matches/0x00179330.cpp
// sym: ??_G?$ParamString@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from DriftToPositionTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179390 fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::vfunc_0 (30 B): matches/0x00179390.cpp
// sym: ??_G?$ParamFloatConstRange@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from DriftToHulkTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001793b0 fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::vfunc_0 (30 B): matches/0x001793b0.cpp
// sym: ??_G?$ParamVector@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from DriftToHulkTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179410 fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::vfunc_0 (30 B): matches/0x00179410.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionStateTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from MotionStateTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179430 fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_0 (30 B): matches/0x00179430.cpp
// sym: ??_G?$ParamEnumConstList@VMotionStateTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from MotionStateTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179490 fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::vfunc_0 (30 B): matches/0x00179490.cpp
// sym: ??_G?$ParamFloatConstRange@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PushOutTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001794f0 fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::vfunc_0 (30 B): matches/0x001794f0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetBreakTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PushOutTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001795f0 fight::ParamFloatConstRange<hulkfight::motion::TeleportTrack>::vfunc_0 (30 B): matches/0x001795f0.cpp
// sym: ??_G?$ParamFloatConstRange@VTeleportTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TeleportTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179610 fight::ParamVector<hulkfight::motion::TeleportTrack>::vfunc_0 (30 B): matches/0x00179610.cpp
// sym: ??_G?$ParamVector@VTeleportTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TeleportTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179750 fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::vfunc_0 (30 B): matches/0x00179750.cpp
// sym: ??_G?$ParamFloatConstRange@VSurfTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SurfTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179770 fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::vfunc_0 (30 B): matches/0x00179770.cpp
// sym: ??_G?$ParamIntConstRange@VSurfTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SurfTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001797d0 fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::vfunc_0 (30 B): matches/0x001797d0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SuckInPropsTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179830 fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::vfunc_0 (30 B): matches/0x00179830.cpp
// sym: ??_G?$ParamFloatConstRange@VCriticalMassDrainTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SuckInPropsTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179890 fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_0 (30 B): matches/0x00179890.cpp
// sym: ??_G?$ParamFloatConstRange@VSuckInPropsTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SuckInPropsTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001798b0 fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_0 (30 B): matches/0x001798b0.cpp
// sym: ??_G?$ParamIntConstRange@VSuckInPropsTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SuckInPropsTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179910 fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::vfunc_0 (30 B): matches/0x00179910.cpp
// sym: ??_G?$ParamFloatConstRange@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TeleportRelativeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179930 fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::vfunc_0 (30 B): matches/0x00179930.cpp
// sym: ??_G?$ParamVector@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TeleportRelativeTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179990 fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::vfunc_0 (30 B): matches/0x00179990.cpp
// sym: ??_G?$ParamFloatConstRange@VIntentionClearTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TeleportToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x001799f0 fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0 (30 B): matches/0x001799f0.cpp
// sym: ??_G?$ParamFloatConstRange@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TeleportToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179a10 fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0 (30 B): matches/0x00179a10.cpp
// sym: ??_G?$ParamString@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TeleportToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179a30 fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0 (30 B): matches/0x00179a30.cpp
// sym: ??_G?$ParamVector@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TeleportToLocatorTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179a90 fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::vfunc_0 (30 B): matches/0x00179a90.cpp
// sym: ??_G?$ParamFloatConstRange@VChargeClearTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ChargeClearTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179ab0 fight::ParamBool<hulkfight::motion::ChargeClearTrack>::vfunc_0 (30 B): matches/0x00179ab0.cpp
// sym: ??_G?$ParamBool@VChargeClearTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ChargeClearTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179b10 fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::vfunc_0 (30 B): matches/0x00179b10.cpp
// sym: ??_G?$ParamFloatConstRange@VVisibilityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VisibilityTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179b30 fight::ParamBool<hulkfight::motion::VisibilityTrack>::vfunc_0 (30 B): matches/0x00179b30.cpp
// sym: ??_G?$ParamBool@VVisibilityTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VisibilityTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00179c10 / FUN_00179d60 / FUN_00179dc0 / FUN_00179f30 / FUN_00179fe0 / FUN_0017a180 / FUN_0017a260 / FUN_0017a340 / FUN_0017a420 / FUN_0017a480 / FUN_0017a520 / FUN_0017a860 / FUN_0017a9a0 / FUN_0017aa40 / FUN_0017ab80 / FUN_0017ac80 / FUN_0017ad20 / FUN_0017ae00 / FUN_0017aee0)



// 0x00179c10 FUN_00179c10 (325 B): matches/0x00179c10.cpp
// sym: ?FUN_00179c10@@YAXXZ
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::ChargeTrack>, ParamEnumConstList<hulkfight::motion::ChargeTrack>, ParamFloatConstRange<hulkfight::motion::ChargeTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00179c10()
{
    if (DAT_004e12f4 == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ChargeTrack>("timeBegin", &owners::Obj_16e9b0::FUN_0016e9b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ChargeTrack>("timeEnd", &owners::Obj_16e9c0::FUN_0016e9c0);
        params[2] = new ::fight::ParamEnumConstList< ::hulkfight::motion::ChargeTrack>("type", (void*)&DAT_004b4d7c, DAT_00416640, &owners::Obj_16e9e0::FUN_0016e9e0);
        params[3] = new ::fight::ParamBool< ::hulkfight::motion::ChargeTrack>("clearOnBegin", &owners::O_16ea00::FUN_0016ea00);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ChargeTrack>("finalCharge", &owners::O_16ea20::FUN_0016ea20);
        FUN_002347b0(&DAT_004e12f0, params, 5);
    }
    DAT_004e12f4++;
}



// 0x00179d60 FUN_00179d60 (95 B): matches/0x00179d60.cpp
// sym: ?FUN_00179d60@@YAXXZ
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00179d60()
{
    if (DAT_004e1304 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SnapToGroundTrack>("timeBegin", &owners::C_16eac0::FUN_0016eac0);
        FUN_002347b0(&DAT_004e1300, params, 1);
    }
    DAT_004e1304++;
}



// 0x00179dc0 FUN_00179dc0 (358 B): matches/0x00179dc0.cpp
// sym: _FUN_00179dc0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::SuckTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00179dc0()
{
    if (DAT_004e131c == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckTrack>("timeBegin", &owners::X_16ede0::FUN_0016ede0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckTrack>("timeEnd", &owners::Obj_16edf0::FUN_0016edf0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckTrack>("distanceMin", &owners::X_16ee10::FUN_0016ee10);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckTrack>("distanceMax", &owners::Obj_16ee30::FUN_0016ee30);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckTrack>("velocityMin", &owners::O_16ee50::FUN_0016ee50);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckTrack>("velocityMax", &owners::Obj_16ee70::FUN_0016ee70);
        FUN_002347b0(&DAT_004e1318, params, 6);
    }
    DAT_004e131c++;
}



// 0x00179f30 FUN_00179f30 (170 B): matches/0x00179f30.cpp
// sym: _FUN_00179f30
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>, ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00179f30()
{
    if (DAT_004e1324 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStateTrack>("timeBegin", &owners::X_16ee80::FUN_0016ee80);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::LocomotionStateTrack>("locomotionState", (void*)&DAT_0048f590, DAT_003f5bbc, &owners::C_16eea0::FUN_0016eea0);
        FUN_002347b0(&DAT_004e1320, params, 2);
    }
    DAT_004e1324++;
}



// 0x00179fe0 FUN_00179fe0 (409 B): matches/0x00179fe0.cpp
// sym: _FUN_00179fe0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::DriftToPositionTrack>, ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>, ParamString<hulkfight::motion::DriftToPositionTrack>, ParamVector<hulkfight::motion::DriftToPositionTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00179fe0()
{
    if (DAT_004e1334 == 0) {
        ::fight::ParamValue* params[7];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::DriftToPositionTrack>("timeBegin", &owners::X_16f090::FUN_0016f090);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::DriftToPositionTrack>("timeEnd", &owners::Obj_16f0a0::FUN_0016f0a0);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::DriftToPositionTrack>("letMeSpecifyPosition", &owners::C_16f0c0::FUN_0016f0c0);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::DriftToPositionTrack>("position", &fn_fa642773::O_16f0f0::Fn);
        params[4] = new ::fight::ParamBool< ::hulkfight::motion::DriftToPositionTrack>("ditchYIfInDefaultMode", &owners::Obj_16f120::FUN_0016f120);
        params[5] = new ::fight::ParamBool< ::hulkfight::motion::DriftToPositionTrack>("teleportAtEnd", &owners::X_16f140::FUN_0016f140);
        params[6] = new ::fight::ParamString< ::hulkfight::motion::DriftToPositionTrack>("variable", &fn_f659ad5b::Obj::Set);
        FUN_002347b0(&DAT_004e1330, params, 7);
    }
    DAT_004e1334++;
}



// 0x0017a180 FUN_0017a180 (213 B): matches/0x0017a180.cpp
// sym: ?FUN_0017a180@@YAXXZ
// (gx2, D18) from unk_179c10.new_plain.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>, ParamVector<hulkfight::motion::DriftToHulkTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_0017a180()
{
    if (DAT_004e133c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::DriftToHulkTrack>("timeBegin", &fn_fa642773::A_16f160::f);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::DriftToHulkTrack>("timeEnd", &fn_fa642773::Obj_16f170::Set);
        params[2] = new ::fight::ParamVector< ::hulkfight::motion::DriftToHulkTrack>("offset", &fn_fa642773::Obj_16f1a0::Fn);
        FUN_002347b0(&DAT_004e1338, params, 3);
    }
    DAT_004e133c++;
}



// 0x0017a260 FUN_0017a260 (221 B): matches/0x0017a260.cpp
// sym: _FUN_0017a260
// (gx2, D18) from unk_179c10.new_plain.cpp; constructs the real ParamEnumConstList<hulkfight::motion::MotionStateTrack>, ParamFloatConstRange<hulkfight::motion::MotionStateTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017a260()
{
    if ((*(int*)&DAT_004e1344) == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MotionStateTrack>("timeBegin", &fn_fa642773::Obj_16f1c0::SetTimeBegin_0016f1c0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MotionStateTrack>("timeEnd", &fn_fa642773::Obj_16f1d0::SetTimeEnd_0016f1d0);
        params[2] = new ::fight::ParamEnumConstList< ::hulkfight::motion::MotionStateTrack>("motionState", (void*)&DAT_0048f57c, DAT_003f5bb8, &fn_fa642773::A_16f1f0::SetMotionState_0016f1f0);
        FUN_002347b0(&DAT_004e1340, params, 3);
    }
    (*(int*)&DAT_004e1344)++;
}



// 0x0017a340 FUN_0017a340 (213 B): matches/0x0017a340.cpp
// sym: ?FUN_0017a340@@YAXXZ
// (gx2, D18) from unk_179c10.new_plain.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_0017a340()
{
    if (DAT_004e134c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MomentumXZAddTrack>("timeBegin", &fn_fa642773::Obj_16f200::SetTimeBegin_0016f200);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MomentumXZAddTrack>("timeEnd", &fn_fa642773::Obj_16f210::SetTimeEnd_0016f210);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::MomentumXZAddTrack>("finalVelocity", &fn_fa642773::X_16f230::SetFinalVelocity_0016f230);
        FUN_002347b0(&DAT_004e1348, params, 3);
    }
    DAT_004e134c++;
}



// 0x0017a420 FUN_0017a420 (95 B): matches/0x0017a420.cpp
// sym: _FUN_0017a420
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017a420()
{
    if (DAT_004e1354 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TargetBreakTrack>("timeBegin", &owners::X_16f240::FUN_0016f240);
        FUN_002347b0(&DAT_004e1350, params, 1);
    }
    DAT_004e1354++;
}



// 0x0017a480 FUN_0017a480 (158 B): matches/0x0017a480.cpp
// sym: _FUN_0017a480
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::TeleportTrack>, ParamVector<hulkfight::motion::TeleportTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017a480()
{
    if (DAT_004e1364 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TeleportTrack>("timeBegin", &owners::Obj_16f360::FUN_0016f360);
        params[1] = new ::fight::ParamVector< ::hulkfight::motion::TeleportTrack>("vector", &fn_0016f390::Obj::Set);
        FUN_002347b0(&DAT_004e1360, params, 2);
    }
    DAT_004e1364++;
}



// 0x0017a520 FUN_0017a520 (817 B): matches/0x0017a520.cpp
// sym: _FUN_0017a520
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::SurfTrack>, ParamIntConstRange<hulkfight::motion::SurfTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017a520()
{
    if (DAT_004e1374 == 0) {
        ::fight::ParamValue* params[15];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("timeBegin", &owners::Obj_16f5e0::FUN_0016f5e0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("timeEnd", &owners::Obj_16f5f0::FUN_0016f5f0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("minInitVelocity", &owners::Obj_16f610::FUN_0016f610);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("minVelocity", &owners::Obj_16f630::FUN_0016f630);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("deceleration", &owners::Target_16f650::FUN_0016f650);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("userDeceleration", &owners::O_16f670::FUN_0016f670);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("turnVelocity", &owners::Thing_16f690::FUN_0016f690);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("turnAcceleration", &owners::Obj_16f6c0::FUN_0016f6c0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("leanMaxAngle", &owners::Obj_16f6f0::FUN_0016f6f0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("leanActiveRate", &owners::Obj_16f720::FUN_0016f720);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("leanPassiveRate", &owners::Obj_16f750::FUN_0016f750);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("slopeRate", &owners::Obj_16f780::FUN_0016f780);
        params[12] = new ::fight::ParamIntConstRange< ::hulkfight::motion::SurfTrack>("priority", &owners::O_16f7b0::FUN_0016f7b0);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("blendInTime", &owners::Obj_16f7d0::FUN_0016f7d0);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SurfTrack>("blendOutTime", &owners::Obj_16f7f0::FUN_0016f7f0);
        FUN_002347b0(&DAT_004e1370, params, 15);
    }
    DAT_004e1374++;
}



// 0x0017a860 FUN_0017a860 (307 B): matches/0x0017a860.cpp
// sym: _FUN_0017a860
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017a860()
{
    if (DAT_004e137c == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TargetIconDistanceTrack>("timeBegin", &owners::Obj_16f800::FUN_0016f800);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TargetIconDistanceTrack>("timeEnd", &owners::Obj_16f810::FUN_0016f810);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TargetIconDistanceTrack>("distanceMin", &owners::Obj_16f830::FUN_0016f830);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TargetIconDistanceTrack>("distanceMax", &owners::Obj_16f850::FUN_0016f850);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TargetIconDistanceTrack>("extensionTime", &owners::X_16f870::FUN_0016f870);
        FUN_002347b0(&DAT_004e1378, params, 5);
    }
    DAT_004e137c++;
}



// 0x0017a9a0 FUN_0017a9a0 (158 B): matches/0x0017a9a0.cpp
// sym: _FUN_0017a9a0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017a9a0()
{
    if ((*(int*)&DAT_004e1384) == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::CriticalMassDrainTrack>("timeBegin", &fn_fa642773::Obj_16f880::Fn);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::CriticalMassDrainTrack>("power", &fn_fa642773::Obj_16f8a0::Set);
        FUN_002347b0(&DAT_004e1380, params, 2);
    }
    (*(int*)&DAT_004e1384)++;
}



// 0x0017aa40 FUN_0017aa40 (307 B): matches/0x0017aa40.cpp
// sym: _FUN_0017aa40
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>, ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017aa40()
{
    if (DAT_004e138c == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckInPropsTrack>("timeBegin", &owners::Obj_16f8b0::FUN_0016f8b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckInPropsTrack>("timeEnd", &owners::Obj_16f8c0::FUN_0016f8c0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::SuckInPropsTrack>("number", &owners::X_16f8e0::FUN_0016f8e0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckInPropsTrack>("velocity", &owners::Obj_16f900::FUN_0016f900);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::SuckInPropsTrack>("distance", &owners::C_16f920::FUN_0016f920);
        FUN_002347b0(&DAT_004e1388, params, 5);
    }
    DAT_004e138c++;
}



// 0x0017ab80 FUN_0017ab80 (256 B): matches/0x0017ab80.cpp
// sym: _FUN_0017ab80
// (gx2, D18) from unk_179c10.new_plain.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>, ParamVector<hulkfight::motion::TeleportRelativeTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017ab80()
{
    if (DAT_004e1394 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TeleportRelativeTrack>("timeBegin", &fn_fa642773::Obj_16f930::SetTimeBegin_0016f930);
        params[1] = new ::fight::ParamVector< ::hulkfight::motion::TeleportRelativeTrack>("offset", &fn_fa642773::Obj_16f960::SetOffset_0016f960);
        params[2] = new ::fight::ParamVector< ::hulkfight::motion::TeleportRelativeTrack>("minimum", &fn_fa642773::Obj_16f9a0::SetMinimum_0016f9a0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TeleportRelativeTrack>("traceWidth", &fn_fa642773::Obj_16f9d0::SetTraceWidth_0016f9d0);
        FUN_002347b0(&DAT_004e1390, params, 4);
    }
    DAT_004e1394++;
}



// 0x0017ac80 FUN_0017ac80 (158 B): matches/0x0017ac80.cpp
// sym: _FUN_0017ac80
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017ac80()
{
    if (DAT_004e139c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::IntentionClearTrack>("timeBegin", &owners::X_16f9e0::FUN_0016f9e0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::IntentionClearTrack>("timeEnd", &owners::Obj_16f9f0::FUN_0016f9f0);
        FUN_002347b0(&DAT_004e1398, params, 2);
    }
    DAT_004e139c++;
}



// 0x0017ad20 FUN_0017ad20 (213 B): matches/0x0017ad20.cpp
// sym: _FUN_0017ad20
// (gx2, D18) from unk_179c10.new_plain.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>, ParamString<hulkfight::motion::TeleportToLocatorTrack>, ParamVector<hulkfight::motion::TeleportToLocatorTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017ad20()
{
    if (DAT_004e13a4 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TeleportToLocatorTrack>("timeBegin", &fn_fa642773::Obj_16fa00::SetTimeBegin_0016fa00);
        params[1] = new ::fight::ParamString< ::hulkfight::motion::TeleportToLocatorTrack>("text", &fn_f18c5a89::TextHolder::SetText_00170de0);
        params[2] = new ::fight::ParamVector< ::hulkfight::motion::TeleportToLocatorTrack>("offset", &fn_fa642773::Obj_16fa40::SetOffset_0016fa40);
        FUN_002347b0(&DAT_004e13a0, params, 3);
    }
    DAT_004e13a4++;
}



// 0x0017ae00 FUN_0017ae00 (213 B): matches/0x0017ae00.cpp
// sym: ?FUN_0017ae00@@YAXXZ
// (gx2, D18) from unk_179c10.new_plain.cpp; constructs the real ParamBool<hulkfight::motion::ChargeClearTrack>, ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_0017ae00()
{
    if (DAT_004e13ac == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ChargeClearTrack>("timeBegin", &fn_fa642773::X_16fa60::SetTimeBegin_0016fa60);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ChargeClearTrack>("timeEnd", &fn_fa642773::Obj_16fa70::SetTimeEnd_0016fa70);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::ChargeClearTrack>("clearOnBegin", &fn_fa642773::Obj_16fa90::SetClearOnBegin_0016fa90);
        FUN_002347b0(&DAT_004e13a8, params, 3);
    }
    DAT_004e13ac++;
}



// 0x0017aee0 FUN_0017aee0 (158 B): matches/0x0017aee0.cpp
// sym: _FUN_0017aee0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::VisibilityTrack>, ParamFloatConstRange<hulkfight::motion::VisibilityTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0017aee0()
{
    if (DAT_004e13b4 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VisibilityTrack>("timeBegin", &owners::Obj_16faa0::FUN_0016faa0);
        params[1] = new ::fight::ParamBool< ::hulkfight::motion::VisibilityTrack>("visible", &owners::Obj_16fac0::FUN_0016fac0);
        FUN_002347b0(&DAT_004e13b0, params, 2);
    }
    DAT_004e13b4++;
}



// 0x0017af80 hulkfight::motion::LocomotionStateTrack::vfunc_10 (70 B): matches/0x0017af80.cpp
// sym: ?vfunc_10@LocomotionStateTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotionStateTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        Object_17af80* p = Alloc_0008d690(sizeof(::hulkfight::motion::LocomotionStateAction));
        if (p)
            return p->Init_001732f0(this, c);
    }
    return 0;
}

