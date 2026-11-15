// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127a00..0x0012a270 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/TargetDirectionYCondition.cpp
// piece 0x00128240..0x001296f0 (kind game, layer game, confidence high, dominant class hulkfight::ai::AcquireTargetTrack); was game/hulkfight/ai/AcquireTargetTrack_2.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#include "decls/data/engine/fight.h"   // (gx3, D32) its owner object's data, merged
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f253994b {
#define TREE_TU_END }
namespace fn_f253994b {} using namespace fn_f253994b;
#include "game/hulkfight/ai.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f239bcb5 { struct Vec; } 
namespace fn_f239bcb5 { struct C_123620 { bool SetCompare_00123620(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct C_123670 { unsigned char SetUseGroundPoint_00123670(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct O_123780 { char SetCompare_00123780(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct O_123a60 { char SetTimeBegin_00123a60(void *); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj { char Set(struct fn_f239bcb5::Vec const *); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123600 { char SetCompare_00123600(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123610 { char SetType_00123610(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123630 { bool SetDistance_00123630(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123650 { bool SetUseHulk_00123650(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123790 { char SetDistance_00123790(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_1237b0 { char SetOnlyRespondtoEvil_001237b0(char); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_1237d0 { unsigned char SetOnlyRespondtoProps_001237d0(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123840 { bool SetDistance_00123840(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123860 { char SetUseHulk_00123860(char); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123880 { char SetUseGroundPoint_00123880(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_1238c0 { char Set(char); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123a70 { bool SetTimeEnd_00123a70(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct Obj_123a90 { char SetClearEveryFrame_00123a90(char); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct X_123830 { unsigned char SetCompare_00123830(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct X_123890 { unsigned char F(float); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp
namespace fn_f239bcb5 { struct X_1238b0 { char F(int); }; }   // (gx3, D18) setters, as defined in unk_123510.cpp

// ---- declarations shared by the functions below
namespace fn_f253994b {
extern char DAT_00491ca8;
extern char DAT_004a8a50;
extern "C" int Check(void*, int, hulk_intptr, hulk_intptr, int);
extern "C" int FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_004a8b08;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004a8bc8;
} // namespace fn_f253994b
namespace fight {
class ConditionFactoryCaster_128300 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class CanSeeTargetCondition_128300;
} }
namespace fn_f253994b {
extern char DAT_004a8c78;
} // namespace fn_f253994b
namespace fight {
class TrackFactoryCaster_128360 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TargetClearTrack_128360 {};
} }
namespace fn_f253994b {
extern "C++" __declspec(nothrow) int FUN_00344e74(void*, int, void*, hulk_intptr, int);
extern char DAT_004a8d20;
class TrackFactoryCaster_1283e0 {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1(int a);
};
struct Info {
    int x;
};
extern Info hulk_at_0049850c, hulk_at_004a8dd0;
extern "C" void* __cdecl lookup(void*, int, Info*, Info*, int);
} // namespace fn_f253994b
namespace fight {
class TrackFactoryCaster_128480 {
  public:
    virtual bool Make(void*);
    virtual void Other();
};
}
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f253994b {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f253994b
namespace hulkfight { namespace ai {
class TargetAngleYCondition_128780 {
public:
    char FUN_00123680(int); /* (unb4) as defined; address taken only */
    char FUN_00123690(float); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f253994b {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f253994b
namespace fight {
template <class T>
class ParamEnumConstList_128780 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_128780(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_128780 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_128780(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f253994b {
} // namespace fn_f253994b
namespace hulkfight { namespace ai {
class TargetDirectionCondition_128830 {
public:
    char FUN_001236b0(int); /* (unb4) as defined; address taken only */
    bool FUN_001236c0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_128830 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_128830(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_128830 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_128830(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f253994b {
class TargetDistanceYCondition {
public:
    bool FUN_001236d0(int); /* (unb4) as defined; address taken only */
    bool FUN_001236e0(int); /* (unb4) as defined; address taken only */
    char FUN_001236f0(char); /* (unb4) as defined; address taken only */
    char FUN_00123710(char); /* (unb4) as defined; address taken only */
    char FUN_00123730(char); /* (unb4) as defined; address taken only */
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
} // namespace fn_f253994b
namespace hulkfight { namespace ai {
class TargetOrientationCondition_128a30 {
public:
    char FUN_00123740(float); /* (unb4) as defined; address taken only */
    char FUN_00123760(float); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_128a30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_128a30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class HasTargetCondition_128bf0 {
public:
    bool FUN_001237e0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_128bf0 : public ParamBoolBase {
public:
    ParamBool_128bf0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class TargetVelocityYCondition_128c50 {
public:
    bool FUN_001237f0(int); /* (unb4) as defined; address taken only */
    char FUN_00123800(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_128c50 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_128c50(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_128c50 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_128c50(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class TargetVelocityCondition_128d00 {
public:
    char FUN_00123810(int); /* (unb4) as defined; address taken only */
    bool FUN_00123820(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_128d00 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_128d00(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_128d00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_128d00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class TargetVelocityXZCondition_128fb0 {
public:
    bool FUN_001238d0(int); /* (unb4) as defined; address taken only */
    bool FUN_001238e0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_128fb0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_128fb0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_128fb0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_128fb0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class TargetDirectionXZCondition_129060 {
public:
    bool FUN_001238f0(int); /* (unb4) as defined; address taken only */
    bool FUN_00123900(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_129060 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_129060(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_129060 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_129060(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class TargetFirstShotCondition_129110 {
public:
    char FUN_00123910(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_129110 : public ParamBoolBase {
public:
    ParamBool_129110(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class TargetInvincibleCondition_129170 {
public:
    char FUN_00123920(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_129170 : public ParamBoolBase {
public:
    ParamBool_129170(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class CanSeeTargetCondition_1291d0 {
public:
    char FUN_00123930(char); /* (unb4) as defined; address taken only */
    bool FUN_00123950(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_1291d0 : public ParamBoolBase {
public:
    ParamBool_1291d0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class TargetClearTrack_129270 {
public:
    char FUN_00123960(int); /* (unb4) as defined; address taken only */
    char FUN_00123980(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_129270 : public ParamBoolBase {
public:
    ParamBool_129270(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_129270 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_129270(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f253994b {
class AcquireTargetTrack {
public:
    char FUN_00123990(int); /* (unb4) as defined; address taken only */
    bool FUN_001239a0(int); /* (unb4) as defined; address taken only */
    char FUN_001239c0(float); /* (unb4) as defined; address taken only */
    bool FUN_001239f0(int); /* (unb4) as defined; address taken only */
    char FUN_00123a10(char); /* (unb4) as defined; address taken only */
    char FUN_00123a40(void*); /* (unb4) as defined; address taken only */
};

} // namespace fn_f253994b

// 0x00127a30 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_0 (30 B): matches/0x00127a30.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDirectionYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127a50 fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::vfunc_0 (30 B): matches/0x00127a50.cpp
// sym: ??_G?$ParamIntConstRange@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDirectionYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127b50 fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_0 (30 B): matches/0x00127b50.cpp
// sym: ??_G?$ParamEnumConstList@VTargetTypeCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127bb0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_0 (30 B): matches/0x00127bb0.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127bd0 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::vfunc_0 (30 B): matches/0x00127bd0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127bf0 fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::vfunc_0 (30 B): matches/0x00127bf0.cpp
// sym: ??_G?$ParamBool@VTargetDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127c50 fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_0 (30 B): matches/0x00127c50.cpp
// sym: ??_G?$ParamEnumConstList@VTargetAngleYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetAngleYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127c70 fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::vfunc_0 (30 B): matches/0x00127c70.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetAngleYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetAngleYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127cd0 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_0 (30 B): matches/0x00127cd0.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDirectionCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDirectionCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127cf0 fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::vfunc_0 (30 B): matches/0x00127cf0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDirectionCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDirectionCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127d50 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_0 (30 B): matches/0x00127d50.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127d70 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::vfunc_0 (30 B): matches/0x00127d70.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127d90 fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::vfunc_0 (30 B): matches/0x00127d90.cpp
// sym: ??_G?$ParamBool@VTargetDistanceYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127df0 fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>::vfunc_0 (30 B): matches/0x00127df0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetOrientationCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ProjectileDistanceCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127e50 fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_0 (30 B): matches/0x00127e50.cpp
// sym: ??_G?$ParamEnumConstList@VProjectileDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ProjectileDistanceCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127e70 fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>::vfunc_0 (30 B): matches/0x00127e70.cpp
// sym: ??_G?$ParamFloatConstRange@VProjectileDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ProjectileDistanceCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127e90 fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition>::vfunc_0 (30 B): matches/0x00127e90.cpp
// sym: ??_G?$ParamBool@VProjectileDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ProjectileDistanceCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127ef0 fight::ParamBool<hulkfight::ai::HasTargetCondition>::vfunc_0 (30 B): matches/0x00127ef0.cpp
// sym: ??_G?$ParamBool@VHasTargetCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetVelocityYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127f50 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_0 (30 B): matches/0x00127f50.cpp
// sym: ??_G?$ParamEnumConstList@VTargetVelocityYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetVelocityYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127f70 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::vfunc_0 (30 B): matches/0x00127f70.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetVelocityYCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetVelocityYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127fd0 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_0 (30 B): matches/0x00127fd0.cpp
// sym: ??_G?$ParamEnumConstList@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetVelocityCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00127ff0 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::vfunc_0 (30 B): matches/0x00127ff0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetVelocityCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00128050 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0 (30 B): matches/0x00128050.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceXZCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00128070 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0 (30 B): matches/0x00128070.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceXZCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00128090 fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::vfunc_0 (30 B): matches/0x00128090.cpp
// sym: ??_G?$ParamBool@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDistanceXZCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x001280f0 fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::vfunc_0 (30 B): matches/0x001280f0.cpp
// sym: ??_G?$ParamFloatConstRange@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from AcquireTargetCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00128110 fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::vfunc_0 (30 B): matches/0x00128110.cpp
// sym: ??_G?$ParamBool@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from AcquireTargetCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00128170 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0 (30 B): matches/0x00128170.cpp
// sym: ??_G?$ParamEnumConstList@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetVelocityXZCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00128190 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0 (30 B): matches/0x00128190.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetVelocityXZCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x001281f0 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_0 (30 B): matches/0x001281f0.cpp
// sym: ??_G?$ParamEnumConstList@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDirectionXZCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00128210 fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::vfunc_0 (30 B): matches/0x00128210.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetDirectionXZCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_001284f0 / FUN_001285a0 / FUN_00128660 / FUN_00128780 / FUN_00128830 / FUN_001288e0 / FUN_00128a30 / FUN_00128ad0 / FUN_00128bf0 / FUN_00128c50 / FUN_00128d00 / FUN_00128db0 / FUN_00128ed0 / FUN_00128fb0 / FUN_00129060 / FUN_00129110 / FUN_00129170 / FUN_001291d0 / FUN_00129270 / FUN_00129310 / FUN_00129480)



// 0x00128240 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_0 (36 B): matches/0x00128240.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return Check(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_004a8a50, 0) != 0;
}


// 0x00128270 fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::vfunc_0 (30 B): matches/0x00128270.cpp
// sym: ??_G?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001282a0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_0 (36 B): matches/0x001282a0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetInvincibleCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_0(void* __p0) { hulk_intptr x = (hulk_intptr)__p0;

    return FUN_00344e74(x, 0, (hulk_intptr)&g2, (hulk_intptr)&hulk_at_004a8b08, 0) != 0;
}


// 0x001282d0 fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::vfunc_0 (30 B): matches/0x001282d0.cpp
// sym: ??_G?$ParamBool@VTargetInvincibleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00128300 fight::ConditionFactoryCasterTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_0 (36 B): matches/0x00128300.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCanSeeTargetCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a8bc8, 0) != 0;
}


// 0x00128330 fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>::vfunc_0 (30 B): matches/0x00128330.cpp
// sym: ??_G?$ParamBool@VCanSeeTargetCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00128360 fight::TrackFactoryCasterTemplate<hulkfight::ai::TargetClearTrack>::vfunc_0 (36 B): matches/0x00128360.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTargetClearTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::TargetClearTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a8c78, 0) != 0;
}


// 0x00128390 fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::vfunc_0 (30 B): matches/0x00128390.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001283b0 fight::ParamBool<hulkfight::ai::TargetClearTrack>::vfunc_0 (30 B): matches/0x001283b0.cpp
// sym: ??_G?$ParamBool@VTargetClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001283e0 fight::TrackFactoryCasterTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_0 (36 B): matches/0x001283e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (FUN_00344e74((void*)a, 0, &DAT_0049850c, (hulk_intptr)&DAT_004a8d20, 0) != 0);
}


// 0x00128410 fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::vfunc_0 (30 B): matches/0x00128410.cpp
// sym: ??_G?$ParamFloatConstRange@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00128430 fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::vfunc_0 (30 B): matches/0x00128430.cpp
// sym: ??_G?$ParamBool@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00128450 fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::vfunc_0 (30 B): matches/0x00128450.cpp
// sym: ??_G?$ParamVector@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00128480 fight::TrackFactoryCasterTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0 (36 B): matches/0x00128480.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return lookup(p, 0, &hulk_at_0049850c, &hulk_at_004a8dd0, 0) != 0;
}


// 0x001284b0 fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0 (30 B): matches/0x001284b0.cpp
// sym: ??_G?$ParamFloatConstRange@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001284d0 fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0 (30 B): matches/0x001284d0.cpp
// sym: ??_G?$ParamBool@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


namespace fn_f253994b {

} // namespace fn_f253994b

// 0x001284f0 FUN_001284f0 (176 B): matches/0x001284f0.cpp
// sym: _FUN_001284f0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>, ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001284f0()
{
    if (DAT_004e0d68 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetDirectionYCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::T_123510::FUN_00123510);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::ai::TargetDirectionYCondition>("direction", &owners::X_123520::FUN_00123520);
        FUN_002347b0(&DAT_004e0d64, params, 2);
    }
    DAT_004e0d68++;
}



// 0x001285a0 FUN_001285a0 (190 B): matches/0x001285a0.cpp
// sym: ?FUN_001285a0@@YAXXZ
// (gx2, D18) from AcquireTargetTrack_2.new_plain.cpp; constructs the real ParamEnumConstList<hulkfight::ai::TargetTypeCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_001285a0()
{
    if (DAT_004e0d78 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetTypeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f239bcb5::Obj_123600::SetCompare_00123600);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetTypeCondition>("type", (void*)&DAT_004a6acc, 2, &fn_f239bcb5::Obj_123610::SetType_00123610);
        FUN_002347b0(&DAT_004e0d74, params, 2);
    }
    DAT_004e0d78++;
}



// 0x00128660 FUN_00128660 (274 B): matches/0x00128660.cpp
// sym: ?FUN_00128660@@YAXXZ
// (gx2, D18) from AcquireTargetTrack_2.iso_00128660.cpp; constructs the real ParamBool<hulkfight::ai::TargetDistanceCondition>, ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>, ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_00128660()
{
    if (DAT_004e0d80 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetDistanceCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f239bcb5::C_123620::SetCompare_00123620);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetDistanceCondition>("distance", &fn_f239bcb5::Obj_123630::SetDistance_00123630);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::TargetDistanceCondition>("useHulk", &fn_f239bcb5::Obj_123650::SetUseHulk_00123650);
        params[3] = new ::fight::ParamBool< ::hulkfight::ai::TargetDistanceCondition>("useGroundPoint", &fn_f239bcb5::C_123670::SetUseGroundPoint_00123670);
        FUN_002347b0(&DAT_004e0d7c, params, 4);
    }
    DAT_004e0d80++;
}



// 0x00128780 FUN_00128780 (176 B): matches/0x00128780.cpp
// sym: _FUN_00128780
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>, ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128780()
{
    if (DAT_004e0d88 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetAngleYCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::C_123680::FUN_00123680);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetAngleYCondition>("angle", &owners::Thing_123690::FUN_00123690);
        FUN_002347b0(&DAT_004e0d84, params, 2);
    }
    DAT_004e0d88++;
}



// 0x00128830 FUN_00128830 (176 B): matches/0x00128830.cpp
// sym: _FUN_00128830
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>, ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128830()
{
    if (DAT_004e0d90 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetDirectionCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_1236b0::FUN_001236b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetDirectionCondition>("direction", &owners::Obj_1236c0::FUN_001236c0);
        FUN_002347b0(&DAT_004e0d8c, params, 2);
    }
    DAT_004e0d90++;
}



// 0x001288e0 FUN_001288e0 (325 B): matches/0x001288e0.cpp
// sym: _FUN_001288e0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::TargetDistanceYCondition>, ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>, ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001288e0()
{
    if (DAT_004e0d98 == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetDistanceYCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::O_1236d0::FUN_001236d0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetDistanceYCondition>("distance", &owners::Obj_1236e0::FUN_001236e0);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::TargetDistanceYCondition>("absoluteValue", &owners::Obj_1236f0::FUN_001236f0);
        params[3] = new ::fight::ParamBool< ::hulkfight::ai::TargetDistanceYCondition>("useHulk", &owners::Obj_123710::FUN_00123710);
        params[4] = new ::fight::ParamBool< ::hulkfight::ai::TargetDistanceYCondition>("useGroundPoint", &owners::X_123730::FUN_00123730);
        FUN_002347b0(&DAT_004e0d94, params, 5);
    }
    DAT_004e0d98++;
}



// 0x00128a30 FUN_00128a30 (158 B): matches/0x00128a30.cpp
// sym: _FUN_00128a30
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128a30()
{
    if (DAT_004e0da0 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetOrientationCondition>("orientation", &owners::Obj_123740::FUN_00123740);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetOrientationCondition>("arc", &owners::X_123760::FUN_00123760);
        FUN_002347b0(&DAT_004e0d9c, params, 2);
    }
    DAT_004e0da0++;
}



// 0x00128ad0 FUN_00128ad0 (274 B): matches/0x00128ad0.cpp
// sym: _FUN_00128ad0
// (gx2, D18) from AcquireTargetTrack_2.iso_00128ad0.cpp; constructs the real ParamBool<hulkfight::ai::ProjectileDistanceCondition>, ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>, ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128ad0()
{
    if (DAT_004e0da8 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::ProjectileDistanceCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f239bcb5::O_123780::SetCompare_00123780);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::ProjectileDistanceCondition>("distance", &fn_f239bcb5::Obj_123790::SetDistance_00123790);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::ProjectileDistanceCondition>("onlyRespondtoEvil", &fn_f239bcb5::Obj_1237b0::SetOnlyRespondtoEvil_001237b0);
        params[3] = new ::fight::ParamBool< ::hulkfight::ai::ProjectileDistanceCondition>("onlyRespondtoProps", &fn_f239bcb5::Obj_1237d0::SetOnlyRespondtoProps_001237d0);
        FUN_002347b0(&DAT_004e0da4, params, 4);
    }
    DAT_004e0da8++;
}



// 0x00128bf0 FUN_00128bf0 (95 B): matches/0x00128bf0.cpp
// sym: _FUN_00128bf0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::HasTargetCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128bf0()
{
    if (DAT_004e0db0 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::ai::HasTargetCondition>("hasTarget", &owners::Obj_1237e0::FUN_001237e0);
        FUN_002347b0(&DAT_004e0dac, params, 1);
    }
    DAT_004e0db0++;
}



// 0x00128c50 FUN_00128c50 (176 B): matches/0x00128c50.cpp
// sym: _FUN_00128c50
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>, ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128c50()
{
    if (DAT_004e0db8 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetVelocityYCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::X_1237f0::FUN_001237f0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetVelocityYCondition>("velocity", &owners::Obj_123800::FUN_00123800);
        FUN_002347b0(&DAT_004e0db4, params, 2);
    }
    DAT_004e0db8++;
}



// 0x00128d00 FUN_00128d00 (176 B): matches/0x00128d00.cpp
// sym: _FUN_00128d00
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>, ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128d00()
{
    if (DAT_004e0dc0 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetVelocityCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_123810::FUN_00123810);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetVelocityCondition>("velocity", &owners::X_123820::FUN_00123820);
        FUN_002347b0(&DAT_004e0dbc, params, 2);
    }
    DAT_004e0dc0++;
}



// 0x00128db0 FUN_00128db0 (274 B): matches/0x00128db0.cpp
// sym: _FUN_00128db0
// (gx2, D18) from AcquireTargetTrack_2.iso_00128db0.cpp; constructs the real ParamBool<hulkfight::ai::TargetDistanceXZCondition>, ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>, ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128db0()
{
    if (DAT_004e0dc8 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetDistanceXZCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f239bcb5::X_123830::SetCompare_00123830);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetDistanceXZCondition>("distance", &fn_f239bcb5::Obj_123840::SetDistance_00123840);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::TargetDistanceXZCondition>("useHulk", &fn_f239bcb5::Obj_123860::SetUseHulk_00123860);
        params[3] = new ::fight::ParamBool< ::hulkfight::ai::TargetDistanceXZCondition>("useGroundPoint", &fn_f239bcb5::Obj_123880::SetUseGroundPoint_00123880);
        FUN_002347b0(&DAT_004e0dc4, params, 4);
    }
    DAT_004e0dc8++;
}



// 0x00128ed0 FUN_00128ed0 (213 B): matches/0x00128ed0.cpp
// sym: _FUN_00128ed0
// (gx2, D18) from AcquireTargetTrack_2.iso_00128ed0.cpp; constructs the real ParamBool<hulkfight::ai::AcquireTargetCondition>, ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128ed0()
{
    if (DAT_004e0dd0 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AcquireTargetCondition>("arc", &fn_f239bcb5::X_123890::F);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AcquireTargetCondition>("distance", &fn_f239bcb5::X_1238b0::F);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::AcquireTargetCondition>("validateTarget", &fn_f239bcb5::Obj_1238c0::Set);
        FUN_002347b0(&DAT_004e0dcc, params, 3);
    }
    DAT_004e0dd0++;
}



// 0x00128fb0 FUN_00128fb0 (176 B): matches/0x00128fb0.cpp
// sym: _FUN_00128fb0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>, ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00128fb0()
{
    if (DAT_004e0dd8 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetVelocityXZCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_1238d0::FUN_001238d0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetVelocityXZCondition>("velocity", &owners::Obj_1238e0::FUN_001238e0);
        FUN_002347b0(&DAT_004e0dd4, params, 2);
    }
    DAT_004e0dd8++;
}



// 0x00129060 FUN_00129060 (176 B): matches/0x00129060.cpp
// sym: _FUN_00129060
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>, ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00129060()
{
    if (DAT_004e0de0 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::TargetDirectionXZCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_1238f0::FUN_001238f0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetDirectionXZCondition>("direction", &owners::X_123900::FUN_00123900);
        FUN_002347b0(&DAT_004e0ddc, params, 2);
    }
    DAT_004e0de0++;
}



// 0x00129110 FUN_00129110 (95 B): matches/0x00129110.cpp
// sym: _FUN_00129110
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::TargetFirstShotCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00129110()
{
    if (DAT_004e0de8 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::ai::TargetFirstShotCondition>("firstShot", &owners::Obj_123910::FUN_00123910);
        FUN_002347b0(&DAT_004e0de4, params, 1);
    }
    DAT_004e0de8++;
}



// 0x00129170 FUN_00129170 (95 B): matches/0x00129170.cpp
// sym: _FUN_00129170
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::TargetInvincibleCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00129170()
{
    if (DAT_004e0df0 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::ai::TargetInvincibleCondition>("invincible", &owners::Thing_123920::FUN_00123920);
        FUN_002347b0(&DAT_004e0dec, params, 1);
    }
    DAT_004e0df0++;
}



// 0x001291d0 FUN_001291d0 (158 B): matches/0x001291d0.cpp
// sym: _FUN_001291d0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::CanSeeTargetCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001291d0()
{
    if (DAT_004e0df8 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamBool< ::hulkfight::ai::CanSeeTargetCondition>("canSee", &owners::Obj_123930::FUN_00123930);
        params[1] = new ::fight::ParamBool< ::hulkfight::ai::CanSeeTargetCondition>("ignoreFriendInTheWay", &owners::O_123950::FUN_00123950);
        FUN_002347b0(&DAT_004e0df4, params, 2);
    }
    DAT_004e0df8++;
}



// 0x00129270 FUN_00129270 (158 B): matches/0x00129270.cpp
// sym: _FUN_00129270
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::TargetClearTrack>, ParamFloatConstRange<hulkfight::ai::TargetClearTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00129270()
{
    if (DAT_004e0e00 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TargetClearTrack>("timeBegin", &owners::Obj_123960::FUN_00123960);
        params[1] = new ::fight::ParamBool< ::hulkfight::ai::TargetClearTrack>("forceClear", &owners::Obj_123980::FUN_00123980);
        FUN_002347b0(&DAT_004e0dfc, params, 2);
    }
    DAT_004e0e00++;
}



// 0x00129310 FUN_00129310 (358 B): matches/0x00129310.cpp
// sym: _FUN_00129310
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::AcquireTargetTrack>, ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>, ParamVector<hulkfight::ai::AcquireTargetTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00129310()
{
    if (DAT_004e0e08 == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AcquireTargetTrack>("timeBegin", &owners::Obj_123990::FUN_00123990);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AcquireTargetTrack>("timeEnd", &owners::O_1239a0::FUN_001239a0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AcquireTargetTrack>("targetArc", &owners::Obj_1239c0::FUN_001239c0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AcquireTargetTrack>("targetDistance", &owners::Obj_1239f0::FUN_001239f0);
        params[4] = new ::fight::ParamBool< ::hulkfight::ai::AcquireTargetTrack>("useDirection", &owners::Obj_123a10::FUN_00123a10);
        params[5] = new ::fight::ParamVector< ::hulkfight::ai::AcquireTargetTrack>("direction", &fn_f239bcb5::Obj::Set);
        FUN_002347b0(&DAT_004e0e04, params, 6);
    }
    DAT_004e0e08++;
}



// 0x00129480 FUN_00129480 (213 B): matches/0x00129480.cpp
// sym: ?FUN_00129480@@YAXXZ
// (gx2, D18) from AcquireTargetTrack_2.iso_00129480.cpp; constructs the real ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>, ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00129480()
{
    if (DAT_004e0e10 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::ClearProjectileDistanceTrack>("timeBegin", &fn_f239bcb5::O_123a60::SetTimeBegin_00123a60);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::ClearProjectileDistanceTrack>("timeEnd", &fn_f239bcb5::Obj_123a70::SetTimeEnd_00123a70);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::ClearProjectileDistanceTrack>("clearEveryFrame", &fn_f239bcb5::Obj_123a90::SetClearEveryFrame_00123a90);
        FUN_002347b0(&DAT_004e0e0c, params, 3);
    }
    DAT_004e0e10++;
}



// 0x001295b0 hulkfight::ai::AcquireTargetAction::vfunc_2 (71 B): matches/0x001295b0.cpp [wrapped: conflict: hulkfight::ai::AcquireTargetAction]
// sym: ?vfunc_2@AcquireTargetAction@ai@hulkfight@fn_001295b0@@QAEPAV1234@H@Z
namespace fn_001295b0 {
// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_1295b0 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char hulk_at_00410004[];
extern "C++" __declspec(nothrow) void opdel_0008d330(void*);

namespace hulkfight { namespace ai { class AcquireTargetAction {
  public:
    void Cleanup_002326a0();
    AcquireTargetAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1295b0* m_20;
}; }}

hulkfight::ai::AcquireTargetAction* hulkfight::ai::AcquireTargetAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00410004;
    RefCounted_1295b0* q = *(RefCounted_1295b0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    Cleanup_002326a0();
    if (flag & 1) {
        opdel_0008d330(this);
    }
    return this;
}
} // namespace fn_001295b0


// 0x00129650 hulkfight::ai::ClearProjectileDistanceAction::vfunc_2 (71 B): matches/0x00129650.cpp [wrapped: conflict: hulkfight::ai::ClearProjectileDistanceAction]
// sym: ?vfunc_2@ClearProjectileDistanceAction@ai@hulkfight@fn_00129650@@QAEPAV1234@H@Z
namespace fn_00129650 {
// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_129650 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char hulk_at_00410020[];
extern "C++" __declspec(nothrow) void opdel(void*);

namespace hulkfight { namespace ai { class ClearProjectileDistanceAction {
  public:
    void Cleanup_002326a0();
    ClearProjectileDistanceAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_129650* m_20;
}; }}

hulkfight::ai::ClearProjectileDistanceAction* hulkfight::ai::ClearProjectileDistanceAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00410020;
    RefCounted_129650* q = *(RefCounted_129650* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    Cleanup_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}
} // namespace fn_00129650

