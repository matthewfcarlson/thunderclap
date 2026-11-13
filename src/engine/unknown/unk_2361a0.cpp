// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002361a0..0x002366e0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#include "decls/data/engine/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa6aa741 {
#define TREE_TU_END }
namespace fn_fa6aa741 {} using namespace fn_fa6aa741;
#include "engine/unknown.h"

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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
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
class Owner_2365b0 {
  public:
    char pad[0x10];
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


// 0x002361a0 FUN_002361a0 (176 B): equivalent/0x002361a0.cpp
// sym: _FUN_002361a0 @b2d6861d1e03 @w3d371fe7da4b
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_002361a0 @ 0x002361a0
extern "C" void FUN_002361a0()
{
    if (DAT_004e5be0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_2361a0<fight::FightNodeCondition_2361a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_2361a0<fight::FightNodeCondition_2361a0>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), (void (fight::FightNodeCondition_2361a0::*)())&fight::FightNodeCondition_2361a0::FUN_00235950);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_2361a0<fight::FightNodeCondition_2361a0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBranch_2361a0<fight::FightNodeCondition_2361a0>("fightNode", &fight::FightNodeCondition_2361a0::FUN_00235960);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5bdc), params, 2);
    }
    DAT_004e5be0++;
}


// 0x00236340 FUN_00236340 (176 B): equivalent/0x00236340.cpp
// sym: _FUN_00236340 @dd7619bab03d @w7a6bfdf1c7f8
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00236340 @ 0x00236340
extern "C" void FUN_00236340()
{
    if (DAT_004e5bf0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_236340<fight::FightNodeTimeCondition_236340>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_236340<fight::FightNodeTimeCondition_236340>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (fight::FightNodeTimeCondition_236340::*)())&fight::FightNodeTimeCondition_236340::FUN_002359a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_236340<fight::FightNodeTimeCondition_236340>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_236340<fight::FightNodeTimeCondition_236340>("time", (void (fight::FightNodeTimeCondition_236340::*)())&fight::FightNodeTimeCondition_236340::FUN_002359b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5bec), params, 2);
    }
    DAT_004e5bf0++;
}


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
