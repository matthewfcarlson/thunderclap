// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00128240..0x001296f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f253994b {
#define TREE_TU_END }
namespace fn_f253994b {} using namespace fn_f253994b;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f253994b {
extern char DAT_00491ca8;
extern char DAT_004a8a50;
extern "C" int Check(void*, int, hulk_intptr, hulk_intptr, int);
extern "C" int FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int g1;
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
extern Info a, b;
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
    void FUN_00123680();
    void FUN_00123690();
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
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f253994b
namespace hulkfight { namespace ai {
class TargetDirectionCondition_128830 {
public:
    void FUN_001236b0();
    void FUN_001236c0();
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
    void FUN_001236d0();
    void FUN_001236e0();
    void FUN_001236f0();
    void FUN_00123710();
    void FUN_00123730();
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
    void FUN_00123740();
    void FUN_00123760();
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
    void FUN_001237e0();
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
    void FUN_001237f0();
    void FUN_00123800();
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
    void FUN_00123810();
    void FUN_00123820();
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
    void FUN_001238d0();
    void FUN_001238e0();
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
    void FUN_001238f0();
    void FUN_00123900();
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
    void FUN_00123910();
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
    void FUN_00123920();
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
    void FUN_00123930();
    void FUN_00123950();
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
    void FUN_00123960();
    void FUN_00123980();
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
    void FUN_00123990();
    void FUN_001239a0();
    void FUN_001239c0();
    void FUN_001239f0();
    void FUN_00123a10();
    void FUN_00123a40();
};

} // namespace fn_f253994b

// 0x00128240 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_0 (36 B): matches/0x00128240.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return Check(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_004a8a50, 0) != 0;
}


// 0x00128270 fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::vfunc_0 (30 B): matches/0x00128270.cpp
// sym: ??_G?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::~ParamBool() {}


// 0x001282a0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_0 (36 B): matches/0x001282a0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetInvincibleCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_0(void* __p0) { hulk_intptr x = (hulk_intptr)__p0;

    return FUN_00344e74(x, 0, (hulk_intptr)&g2, (hulk_intptr)&g1, 0) != 0;
}


// 0x001282d0 fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::vfunc_0 (30 B): matches/0x001282d0.cpp
// sym: ??_G?$ParamBool@VTargetInvincibleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::~ParamBool() {}


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
template <> fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>::~ParamBool() {}


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
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::~ParamFloatConstRange() {}


// 0x001283b0 fight::ParamBool<hulkfight::ai::TargetClearTrack>::vfunc_0 (30 B): matches/0x001283b0.cpp
// sym: ??_G?$ParamBool@VTargetClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TargetClearTrack>::~ParamBool() {}


// 0x001283e0 fight::TrackFactoryCasterTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_0 (36 B): matches/0x001283e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (FUN_00344e74((void*)a, 0, &DAT_0049850c, (hulk_intptr)&DAT_004a8d20, 0) != 0);
}


// 0x00128410 fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::vfunc_0 (30 B): matches/0x00128410.cpp
// sym: ??_G?$ParamFloatConstRange@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::~ParamFloatConstRange() {}


// 0x00128430 fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::vfunc_0 (30 B): matches/0x00128430.cpp
// sym: ??_G?$ParamBool@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::~ParamBool() {}


// 0x00128450 fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::vfunc_0 (30 B): matches/0x00128450.cpp
// sym: ??_G?$ParamVector@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::~ParamVector() {}


// 0x00128480 fight::TrackFactoryCasterTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0 (36 B): matches/0x00128480.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return lookup(p, 0, &a, &b, 0) != 0;
}


// 0x001284b0 fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0 (30 B): matches/0x001284b0.cpp
// sym: ??_G?$ParamFloatConstRange@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::~ParamFloatConstRange() {}


// 0x001284d0 fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0 (30 B): matches/0x001284d0.cpp
// sym: ??_G?$ParamBool@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::~ParamBool() {}


// 0x001284f0 FUN_001284f0 (176 B): equivalent/0x001284f0.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamIntConstRange; hulkfight::ai::TargetDirectionYCondition]
// sym: _FUN_001284f0
namespace fn_001284f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_001284f0 @ 0x001284f0


extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class TargetDirectionYCondition {
public:
    void FUN_00123510();
    void FUN_00123520();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
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
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_001284f0()
{
    if (DAT_004e0d68 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::TargetDirectionYCondition::FUN_00123510);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>("direction", &hulkfight::ai::TargetDirectionYCondition::FUN_00123520);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d64), params, 2);
    }
    DAT_004e0d68++;
}
} // namespace fn_001284f0

namespace fn_f253994b {

// 0x00128780 FUN_00128780 (176 B): equivalent/0x00128780.cpp
// sym: _FUN_00128780
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00128780 @ 0x00128780
extern "C" void FUN_00128780()
{
    if (DAT_004e0d88 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_128780<hulkfight::ai::TargetAngleYCondition_128780>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_128780<hulkfight::ai::TargetAngleYCondition_128780>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::TargetAngleYCondition_128780::FUN_00123680);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128780<hulkfight::ai::TargetAngleYCondition_128780>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_128780<hulkfight::ai::TargetAngleYCondition_128780>("angle", &hulkfight::ai::TargetAngleYCondition_128780::FUN_00123690);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d84), params, 2);
    }
    DAT_004e0d88++;
}


// 0x00128830 FUN_00128830 (176 B): equivalent/0x00128830.cpp
// sym: _FUN_00128830
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00128830 @ 0x00128830
extern "C" void FUN_00128830()
{
    if (DAT_004e0d90 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_128830<hulkfight::ai::TargetDirectionCondition_128830>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_128830<hulkfight::ai::TargetDirectionCondition_128830>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::TargetDirectionCondition_128830::FUN_001236b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128830<hulkfight::ai::TargetDirectionCondition_128830>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_128830<hulkfight::ai::TargetDirectionCondition_128830>("direction", &hulkfight::ai::TargetDirectionCondition_128830::FUN_001236c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d8c), params, 2);
    }
    DAT_004e0d90++;
}


// 0x001288e0 FUN_001288e0 (325 B): equivalent/0x001288e0.cpp
// sym: _FUN_001288e0
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 12/12)
// FUN_001288e0 @ 0x001288e0
extern "C" void FUN_001288e0()
{
    if (DAT_004e0d98 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamEnumConstList<TargetDistanceYCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamEnumConstList<TargetDistanceYCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &TargetDistanceYCondition::FUN_001236d0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetDistanceYCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<TargetDistanceYCondition>("distance", &TargetDistanceYCondition::FUN_001236e0);
        mem = FUN_0008d690((int)sizeof(ParamBool<TargetDistanceYCondition>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<TargetDistanceYCondition>("absoluteValue", &TargetDistanceYCondition::FUN_001236f0);
        mem = FUN_0008d690((int)sizeof(ParamBool<TargetDistanceYCondition>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<TargetDistanceYCondition>("useHulk", &TargetDistanceYCondition::FUN_00123710);
        mem = FUN_0008d690((int)sizeof(ParamBool<TargetDistanceYCondition>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<TargetDistanceYCondition>("useGroundPoint", &TargetDistanceYCondition::FUN_00123730);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d94), params, 5);
    }
    DAT_004e0d98++;
}


// 0x00128a30 FUN_00128a30 (158 B): equivalent/0x00128a30.cpp
// sym: _FUN_00128a30
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00128a30 @ 0x00128a30
extern "C" void FUN_00128a30()
{
    if (DAT_004e0da0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128a30<hulkfight::ai::TargetOrientationCondition_128a30>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_128a30<hulkfight::ai::TargetOrientationCondition_128a30>("orientation", &hulkfight::ai::TargetOrientationCondition_128a30::FUN_00123740);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128a30<hulkfight::ai::TargetOrientationCondition_128a30>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_128a30<hulkfight::ai::TargetOrientationCondition_128a30>("arc", &hulkfight::ai::TargetOrientationCondition_128a30::FUN_00123760);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d9c), params, 2);
    }
    DAT_004e0da0++;
}


// 0x00128bf0 FUN_00128bf0 (95 B): equivalent/0x00128bf0.cpp
// sym: _FUN_00128bf0
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00128bf0 @ 0x00128bf0
extern "C" void FUN_00128bf0()
{
    if (DAT_004e0db0 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_128bf0<hulkfight::ai::HasTargetCondition_128bf0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_128bf0<hulkfight::ai::HasTargetCondition_128bf0>("hasTarget", &hulkfight::ai::HasTargetCondition_128bf0::FUN_001237e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0dac), params, 1);
    }
    DAT_004e0db0++;
}


// 0x00128c50 FUN_00128c50 (176 B): equivalent/0x00128c50.cpp
// sym: _FUN_00128c50
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00128c50 @ 0x00128c50
extern "C" void FUN_00128c50()
{
    if (DAT_004e0db8 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_128c50<hulkfight::ai::TargetVelocityYCondition_128c50>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_128c50<hulkfight::ai::TargetVelocityYCondition_128c50>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::TargetVelocityYCondition_128c50::FUN_001237f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128c50<hulkfight::ai::TargetVelocityYCondition_128c50>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_128c50<hulkfight::ai::TargetVelocityYCondition_128c50>("velocity", &hulkfight::ai::TargetVelocityYCondition_128c50::FUN_00123800);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0db4), params, 2);
    }
    DAT_004e0db8++;
}


// 0x00128d00 FUN_00128d00 (176 B): equivalent/0x00128d00.cpp
// sym: _FUN_00128d00
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00128d00 @ 0x00128d00
extern "C" void FUN_00128d00()
{
    if (DAT_004e0dc0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_128d00<hulkfight::ai::TargetVelocityCondition_128d00>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_128d00<hulkfight::ai::TargetVelocityCondition_128d00>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::TargetVelocityCondition_128d00::FUN_00123810);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128d00<hulkfight::ai::TargetVelocityCondition_128d00>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_128d00<hulkfight::ai::TargetVelocityCondition_128d00>("velocity", &hulkfight::ai::TargetVelocityCondition_128d00::FUN_00123820);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0dbc), params, 2);
    }
    DAT_004e0dc0++;
}


// 0x00128fb0 FUN_00128fb0 (176 B): equivalent/0x00128fb0.cpp
// sym: _FUN_00128fb0
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00128fb0 @ 0x00128fb0
extern "C" void FUN_00128fb0()
{
    if (DAT_004e0dd8 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_128fb0<hulkfight::ai::TargetVelocityXZCondition_128fb0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_128fb0<hulkfight::ai::TargetVelocityXZCondition_128fb0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::TargetVelocityXZCondition_128fb0::FUN_001238d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128fb0<hulkfight::ai::TargetVelocityXZCondition_128fb0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_128fb0<hulkfight::ai::TargetVelocityXZCondition_128fb0>("velocity", &hulkfight::ai::TargetVelocityXZCondition_128fb0::FUN_001238e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0dd4), params, 2);
    }
    DAT_004e0dd8++;
}


// 0x00129060 FUN_00129060 (176 B): equivalent/0x00129060.cpp
// sym: _FUN_00129060
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_00129060 @ 0x00129060
extern "C" void FUN_00129060()
{
    if (DAT_004e0de0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_129060<hulkfight::ai::TargetDirectionXZCondition_129060>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_129060<hulkfight::ai::TargetDirectionXZCondition_129060>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::TargetDirectionXZCondition_129060::FUN_001238f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_129060<hulkfight::ai::TargetDirectionXZCondition_129060>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_129060<hulkfight::ai::TargetDirectionXZCondition_129060>("direction", &hulkfight::ai::TargetDirectionXZCondition_129060::FUN_00123900);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ddc), params, 2);
    }
    DAT_004e0de0++;
}


// 0x00129110 FUN_00129110 (95 B): equivalent/0x00129110.cpp
// sym: _FUN_00129110
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00129110 @ 0x00129110
extern "C" void FUN_00129110()
{
    if (DAT_004e0de8 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_129110<hulkfight::ai::TargetFirstShotCondition_129110>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_129110<hulkfight::ai::TargetFirstShotCondition_129110>("firstShot", &hulkfight::ai::TargetFirstShotCondition_129110::FUN_00123910);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0de4), params, 1);
    }
    DAT_004e0de8++;
}


// 0x00129170 FUN_00129170 (95 B): equivalent/0x00129170.cpp
// sym: _FUN_00129170
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00129170 @ 0x00129170
extern "C" void FUN_00129170()
{
    if (DAT_004e0df0 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_129170<hulkfight::ai::TargetInvincibleCondition_129170>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_129170<hulkfight::ai::TargetInvincibleCondition_129170>("invincible", &hulkfight::ai::TargetInvincibleCondition_129170::FUN_00123920);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0dec), params, 1);
    }
    DAT_004e0df0++;
}


// 0x001291d0 FUN_001291d0 (158 B): equivalent/0x001291d0.cpp
// sym: _FUN_001291d0
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_001291d0 @ 0x001291d0
extern "C" void FUN_001291d0()
{
    if (DAT_004e0df8 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1291d0<hulkfight::ai::CanSeeTargetCondition_1291d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1291d0<hulkfight::ai::CanSeeTargetCondition_1291d0>("canSee", &hulkfight::ai::CanSeeTargetCondition_1291d0::FUN_00123930);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1291d0<hulkfight::ai::CanSeeTargetCondition_1291d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_1291d0<hulkfight::ai::CanSeeTargetCondition_1291d0>("ignoreFriendInTheWay", &hulkfight::ai::CanSeeTargetCondition_1291d0::FUN_00123950);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0df4), params, 2);
    }
    DAT_004e0df8++;
}


// 0x00129270 FUN_00129270 (158 B): equivalent/0x00129270.cpp
// sym: _FUN_00129270
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00129270 @ 0x00129270
extern "C" void FUN_00129270()
{
    if (DAT_004e0e00 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_129270<hulkfight::ai::TargetClearTrack_129270>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_129270<hulkfight::ai::TargetClearTrack_129270>("timeBegin", &hulkfight::ai::TargetClearTrack_129270::FUN_00123960);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_129270<hulkfight::ai::TargetClearTrack_129270>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_129270<hulkfight::ai::TargetClearTrack_129270>("forceClear", &hulkfight::ai::TargetClearTrack_129270::FUN_00123980);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0dfc), params, 2);
    }
    DAT_004e0e00++;
}


// 0x00129310 FUN_00129310 (358 B): equivalent/0x00129310.cpp
// sym: _FUN_00129310
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 14/14)
// FUN_00129310 @ 0x00129310
extern "C" void FUN_00129310()
{
    if (DAT_004e0e08 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AcquireTargetTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<AcquireTargetTrack>("timeBegin", &AcquireTargetTrack::FUN_00123990);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AcquireTargetTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<AcquireTargetTrack>("timeEnd", &AcquireTargetTrack::FUN_001239a0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AcquireTargetTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<AcquireTargetTrack>("targetArc", &AcquireTargetTrack::FUN_001239c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AcquireTargetTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<AcquireTargetTrack>("targetDistance", &AcquireTargetTrack::FUN_001239f0);
        mem = FUN_0008d690((int)sizeof(ParamBool<AcquireTargetTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<AcquireTargetTrack>("useDirection", &AcquireTargetTrack::FUN_00123a10);
        mem = FUN_0008d690((int)sizeof(ParamVector<AcquireTargetTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamVector<AcquireTargetTrack>("direction", &AcquireTargetTrack::FUN_00123a40);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e04), params, 6);
    }
    DAT_004e0e08++;
}

} // namespace fn_f253994b

// 0x001295b0 hulkfight::ai::AcquireTargetAction::vfunc_2 (71 B): matches/0x001295b0.cpp [wrapped: conflict: hulkfight::ai::AcquireTargetAction]
// sym: ?vfunc_2@AcquireTargetAction@ai@hulkfight@fn_001295b0@@QAEPAV1234@H@Z
namespace fn_001295b0 {
// Same code shape as 0x0010bd90 (propagated; names are from that function)
struct RefCounted_1295b0 {
  public:
    virtual void f0();
    virtual void Release();
};

extern char g_vt_1295b0[];
extern "C++" __declspec(nothrow) void opdel(void*);

namespace hulkfight { namespace ai { class AcquireTargetAction {
  public:
    void Cleanup();
    AcquireTargetAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1295b0* m_20;
}; }}

hulkfight::ai::AcquireTargetAction* hulkfight::ai::AcquireTargetAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_1295b0;
    RefCounted_1295b0* q = *(RefCounted_1295b0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    Cleanup();
    if (flag & 1) {
        opdel(this);
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

extern char g_vt_129650[];
extern "C++" __declspec(nothrow) void opdel(void*);

namespace hulkfight { namespace ai { class ClearProjectileDistanceAction {
  public:
    void Cleanup();
    ClearProjectileDistanceAction* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_129650* m_20;
}; }}

hulkfight::ai::ClearProjectileDistanceAction* hulkfight::ai::ClearProjectileDistanceAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_129650;
    RefCounted_129650* q = *(RefCounted_129650* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    Cleanup();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}
} // namespace fn_00129650

