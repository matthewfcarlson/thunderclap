// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00235a20..0x002366e0 (kind game, layer engine, confidence high), merged by D32: fight/FightNodeTimeCondition.cpp
// piece 0x002361a0..0x002366e0 (kind game, layer engine, confidence low); was engine/unknown/unk_2361a0.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "decls/data/engine/fight.h"
#include "decls/data/engine/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa6aa741 {
#define TREE_TU_END }
namespace fn_fa6aa741 {} using namespace fn_fa6aa741;
#include "engine/unknown.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f7988f86 { struct Obj_235980 { void * GetParent_00235980(); }; }   // (gx3, D18) setters, as defined in unk_235950.cpp
namespace fn_f7988f86 { struct Obj_235990 { unsigned char SetRecurse_00235990(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_235950.cpp
namespace fn_f7988f86 { struct X_235970 { bool SetCompare_00235970(int); }; }   // (gx3, D18) setters, as defined in unk_235950.cpp

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fa6aa741 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fa6aa741
namespace fight {
class FightNodeCondition_2361a0 {
public:
    char FUN_00235950(int); /* (unb4) as defined; address taken only */
    void FUN_00235960();
};
}
namespace fn_fa6aa741 {
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
} // namespace fn_fa6aa741
namespace fight {
template <class T>
class ParamBranch_2361a0 : public ParamBranchBase {
public:
    ParamBranch_2361a0(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_2361a0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_2361a0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fn_fa6aa741 {
} // namespace fn_fa6aa741
namespace fight {
class FightNodeTimeCondition_236340 {
public:
    char FUN_002359a0(int); /* (unb4) as defined; address taken only */
    char FUN_002359b0(int); /* (unb4) as defined; address taken only */
};
}
namespace fn_fa6aa741 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_fa6aa741
namespace fight {
template <class T>
class ParamEnumConstList_236340 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_236340(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_236340 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_236340(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa6aa741 {
class Item_2365b0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_2365b0 {           // (gfx1) a fight node: pure3d::Entity's words (vftable, count, name), then the next node
  public:                       // (unk_232780's Node view: natively at 0x18, where a 32-bit pad[0x10] put it at 0x10)
    void* vftable;
    int words[3];
    Item_2365b0* item;
    void Set(Item_2365b0* p);
};
struct Tmp_236630 {
    char pad[0x18];
    Tmp_236630(void*);
    void Run_00231180(int, int);
};
struct C_236630 {
    void F(int, int);
};
struct Tmp_2366b0 {
    char pad[0x18];
    Tmp_2366b0(void*);
    void Run_00231180(int, int);
};
struct C_2366b0 {
    void F(int, int);
};


} // namespace fn_fa6aa741

// 0x002360c0 fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_0 (30 B): matches/0x002360c0.cpp
// sym: ??_G?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FightNodeTimeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_002361a0 / FUN_00236250 / FUN_00236340)



// 0x002360e0 fight::ParamBranch<fight::FightNodeCondition>::vfunc_0 (30 B): matches/0x002360e0.cpp
// sym: ??_G?$ParamBranch@VFightNodeCondition@fight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FightNodeTimeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_002361a0 / FUN_00236250 / FUN_00236340)



// 0x00236100 fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_0 (30 B): matches/0x00236100.cpp
// sym: ??_G?$ParamEnumConstList@VFightNodeParentCondition@fight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FightNodeTimeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_002361a0 / FUN_00236250 / FUN_00236340)



// 0x00236120 fight::ParamBranch<fight::FightNodeParentCondition>::vfunc_0 (30 B): matches/0x00236120.cpp
// sym: ??_G?$ParamBranch@VFightNodeParentCondition@fight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FightNodeTimeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_002361a0 / FUN_00236250 / FUN_00236340)



// 0x00236140 fight::ParamBool<fight::FightNodeParentCondition>::vfunc_0 (30 B): matches/0x00236140.cpp
// sym: ??_G?$ParamBool@VFightNodeParentCondition@fight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FightNodeTimeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_002361a0 / FUN_00236250 / FUN_00236340)



// 0x00236160 fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_0 (30 B): matches/0x00236160.cpp
// sym: ??_G?$ParamEnumConstList@VFightNodeTimeCondition@fight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FightNodeTimeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_002361a0 / FUN_00236250 / FUN_00236340)



// 0x00236180 fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::vfunc_0 (30 B): matches/0x00236180.cpp
// sym: ??_G?$ParamFloatConstRange@VFightNodeTimeCondition@fight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FightNodeTimeCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_002361a0 / FUN_00236250 / FUN_00236340)



// 0x002361a0 FUN_002361a0 (176 B): matches/0x002361a0.cpp
// sym: _FUN_002361a0
// (gx2, D18) rewritten; constructs the real ParamBranch<FightNodeCondition>, ParamEnumConstList<FightNodeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_002361a0()
{
    if (DAT_004e5be0 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::fight::FightNodeCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &owners::C_235950::FUN_00235950);
        params[1] = new ::fight::ParamBranch< ::fight::FightNodeCondition>("fightNode", &owners::Thing_235960::FUN_00235960);
        FUN_002347b0(&DAT_004e5bdc, params, 2);
    }
    DAT_004e5be0++;
}



// 0x00236250 FUN_00236250 (231 B): matches/0x00236250.cpp
// sym: _FUN_00236250
// (gx2, D18) from unk_2361a0.new_plain.cpp; constructs the real ParamBool<FightNodeParentCondition>, ParamBranch<FightNodeParentCondition>, ParamEnumConstList<FightNodeParentCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00236250()
{
    if (DAT_004e5be8 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::fight::FightNodeParentCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f7988f86::X_235970::SetCompare_00235970);
        params[1] = new ::fight::ParamBranch< ::fight::FightNodeParentCondition>("parent", &fn_f7988f86::Obj_235980::GetParent_00235980);
        params[2] = new ::fight::ParamBool< ::fight::FightNodeParentCondition>("recurse", &fn_f7988f86::Obj_235990::SetRecurse_00235990);
        FUN_002347b0(&DAT_004e5be4, params, 3);
    }
    DAT_004e5be8++;
}



// 0x00236340 FUN_00236340 (176 B): matches/0x00236340.cpp
// sym: _FUN_00236340
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<FightNodeTimeCondition>, ParamFloatConstRange<FightNodeTimeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00236340()
{
    if (DAT_004e5bf0 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::fight::FightNodeTimeCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::X_2359a0::FUN_002359a0);
        params[1] = new ::fight::ParamFloatConstRange< ::fight::FightNodeTimeCondition>("time", &owners::Obj_2359b0::FUN_002359b0);
        FUN_002347b0(&DAT_004e5bec, params, 2);
    }
    DAT_004e5bf0++;
}

namespace fn_fa6aa741 {


// 0x002363f0 FUN_002363f0 (1 B): matches/0x002363f0.cpp
// sym: ?FUN_002363f0@fn_fa6aa741@@YGXXZ
void __stdcall FUN_002363f0() {}


// 0x00236400 FUN_00236400 (1 B): matches/0x00236400.cpp
// sym: ?FUN_00236400@fn_fa6aa741@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00236400(void* /*this, unused: callers pass it (unb4)*/) {}


// 0x002365b0 FUN_002365b0 (38 B): matches/0x002365b0.cpp
// sym: ?Set@Owner_2365b0@fn_fa6aa741@@QAEXPAVItem_2365b0@2@@Z
// Same code shape as 0x00059790 (propagated; names are from that function)
void Owner_2365b0::Set(Item_2365b0* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x00236630 FUN_00236630 (38 B): matches/0x00236630.cpp
// sym: ?F@C_236630@fn_fa6aa741@@QAEXHH@Z
void C_236630::F(int a, int b) {
    Tmp_236630 t(this);
    t.Run_00231180(a, b);
}


// 0x002366b0 FUN_002366b0 (38 B): matches/0x002366b0.cpp
// sym: ?F@C_2366b0@fn_fa6aa741@@QAEXHH@Z
// Same code shape as 0x00236630 (propagated; names are from that function)
void C_2366b0::F(int a, int b) {
    Tmp_2366b0 t(this);
    t.Run_00231180(a, b);
}

} // namespace fn_fa6aa741
