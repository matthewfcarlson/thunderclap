// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00235530..0x00235950 (kind game, layer engine, confidence high), dominant class fight::ParamValueInventoryEntity
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "gen/content.h"
#define TREE_TU_BEGIN namespace fn_f30d46c2 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f30d46c2 {} using namespace fn_f30d46c2;
#include "engine/fight.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f30d46c2 {
class Part_235560 {
  public:
    void Init_0027af50();
};
class ParamValueEnum_235560 {
  public:
    hulk_intptr vt;
    int pad;
    Part_235560 part;
    ParamValueEnum_235560* vfunc_0(int);
};
extern "C" void __cdecl thunk_FUN_00267090(ParamValueEnum_235560*);
class Part_235590 {
  public:
    void Init_0027af50();
};
class ParamValueVector_235590 {
  public:
    hulk_intptr vt;
    int pad;
    Part_235590 part;
    ParamValueVector_235590* vfunc_0(int);
};
extern "C++" void __cdecl thunk_FUN_00267090(ParamValueVector_235590*);
class Sub_235620 {
  public:
    void Init_0027af50();
};
class ParamValueInventoryEntity {
  public:
    virtual ParamValueInventoryEntity* vfunc_0(int);
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual bool v6(int param, Item* item);
    virtual void _m_vf7();
    virtual int v8(int param);
    char _m_pad_4[0x8];
};
extern void __cdecl thunk_FUN_00267090(ParamValueInventoryEntity*);
class ParamValueInventoryEntity_235650 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual char f6(int, int);
    virtual int f7(int, int);
};
struct Manager_235650 {
    char pad[12];
    int value;
};
class Iter_235650 {
  public:
    int pad[3];
    Iter_235650(int);
    int First_00231640();
    int Next_002314c0();
};
struct Manager_2356f0 { char pad00[0xc]; void* list; };
struct Iter_2356f0 {
    void* list;
    int index;
    Manager_2356f0* owner;
    void FUN_002314a0(void* list);
    Item* FUN_00231640();
    Item* FUN_002314c0();
};
struct Registry_235760 {
    char pad0[0xc];
    void *container;        // 0xc
};
struct Iter_235760 {
    void *container;
    int index;
    Registry_235760 *owner;
    void FUN_002314a0(void *container);
    Item *FUN_00231640();
    Item *FUN_002314c0();
};
namespace fight {
class ParamValueInventoryEntity {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual bool Accepts(Entity *owner, Item *item);        // vfunc_6
    virtual void vfunc_7(); virtual void vfunc_8();
    virtual int vfunc_9(Entity *owner, Item *wanted);
};
}
class Inner_235800 {
  public:
    void Init_0027af50();
};
extern void __cdecl thunk_FUN_00267090(void*);
class ParamValue {
  public:
    virtual void* v0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class ParamValueBranch : public ParamValue {
  public:
    virtual void* v0(unsigned int);
};
struct Sub_235830 {
    void Init_0027af50();
};
struct ParamValueConditionGroup {
    hulk_intptr vptr;
    char pad[4];
    Sub_235830 sub;
    ParamValueConditionGroup* vfunc_0(int);
};
extern void FUN_0008d330(ParamValueConditionGroup*);
typedef unsigned int u32_235870;

} // namespace fn_f30d46c2

// 0x00235530 fight::ParamValueScript::vfunc_0 (39 B): matches/0x00235530.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0ParamValueScript@fn_00235530@@QAE@H@Z
namespace fn_00235530 {
class Sub_235530 {
  public:
    Sub_235530();
};
class ParamValue {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class ParamValueScript : public ParamValue {
  public:
    char pad[4];
    Sub_235530 sub;
    ParamValueScript(int);
    virtual void vfunc_0();
    virtual void vfunc_1() HULK_PURE64;
    virtual void vfunc_5() HULK_PURE64;
};
extern void __cdecl thunk_FUN_00267090(ParamValueScript*);
ParamValueScript::ParamValueScript(int f) : sub() {
    if (f & 1)
        thunk_FUN_00267090(this);
}
void ParamValueScript::vfunc_0() {}
} // namespace fn_00235530

namespace fn_f30d46c2 {

// 0x00235560 fight::ParamValueEnum::vfunc_0 (39 B): matches/0x00235560.cpp
// sym: ?vfunc_0@ParamValueEnum_235560@fn_f30d46c2@@QAEPAV12@H@Z
// Same code shape as 0x00235300 (propagated; names are from that function)
ParamValueEnum_235560* ParamValueEnum_235560::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init_0027af50();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00235590 fight::ParamValueVector::vfunc_0 (39 B): matches/0x00235590.cpp
// sym: ?vfunc_0@ParamValueVector_235590@fn_f30d46c2@@QAEPAV12@H@Z
// Same code shape as 0x00235300 (propagated; names are from that function)
ParamValueVector_235590* ParamValueVector_235590::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init_0027af50();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f30d46c2

// 0x002355c0 fight::ParamValueColour::vfunc_0 (39 B): matches/0x002355c0.cpp [wrapped: merged class would differ: ParamValueColour: virtual vfunc_0 at slot 5, merged 7]
// sym: ?vfunc_0@ParamValueColour@fn_002355c0@@UAEPAV12@H@Z
namespace fn_002355c0 {
class ParamValue {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    int pad;
};
class Elem_2355c0 {
  public:
    void Fn_0027af50();
};
class ParamValueColour : public ParamValue {
  public:
    char gap[4];
    virtual ParamValueColour* vfunc_0(int);
};
extern int hulk_at_004279fc;
extern void FUN_0008d330(ParamValueColour*);
ParamValueColour* ParamValueColour::vfunc_0(int flags) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_004279fc;
    Elem_2355c0* q = (Elem_2355c0*)((char*)&this->gap);
    q->Fn_0027af50();
    if (flags & 1)
        FUN_0008d330(this);
    return this;
}
} // namespace fn_002355c0


// 0x002355f0 fight::ParamValueEntity::vfunc_0 (39 B): matches/0x002355f0.cpp [wrapped: lost its match in the tree (codegen differs (2 of 13 instructions))]
// sym: ?v0@ParamValueEntity@fn_002355f0@@UAEPAV12@I@Z
namespace fn_002355f0 {
extern void* pvtable;
extern void thunk_FUN_00267090(void*);
struct Sub_2355f0 {
    void Init_0027af50();
};
class ParamValue {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueEntity : public ParamValue {
  public:
    virtual ParamValueEntity* v0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[4];
    Sub_2355f0 sub;
};
ParamValueEntity* ParamValueEntity::v0(unsigned int flags) {
    *(void**)this = &pvtable;
    sub.Init_0027af50();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002355f0

namespace fn_f30d46c2 {

// 0x00235620 fight::ParamValueInventoryEntity::vfunc_0 (39 B): matches/0x00235620.cpp
// sym: ?vfunc_0@ParamValueInventoryEntity@fn_f30d46c2@@UAEPAV12@H@Z
ParamValueInventoryEntity* ParamValueInventoryEntity::vfunc_0(int flag) {
    ParamValueInventoryEntity* self = this;
    *(hulk_ulongptr*)self = ((hulk_intptr)DAT_004279fc);
    ((Sub_235620*)((char*)self + 8))->Init_0027af50();
    if (flag & 1)
        thunk_FUN_00267090(self);
    return self;
}


// 0x00235650 fight::ParamValueInventoryEntity::vfunc_7 (146 B): matches/0x00235650.cpp
// sym: ?f7@ParamValueInventoryEntity_235650@fn_f30d46c2@@UAEHHH@Z
// data: gManager_235650 = DAT_004e5bb8
int ParamValueInventoryEntity_235650::f7(int wanted, int limit) {
    if (limit <= 0)
        return 0;
    Manager_235650* m = (*(Manager_235650**)&DAT_004e5bb8);
    if (!m)
        return 0;
    int n = 1;
    Iter_235650 it(m->value);
    *(Manager_235650**)((char*)&it + 8) = m;
    int item = it.First_00231640();
    while (item) {
        if (f6(wanted, item)) {
            if (limit == n)
                return item;
            ++n;
        }
        item = it.Next_002314c0();
    }
    return 0;
}


// 0x002356f0 fight::ParamValueInventoryEntity::vfunc_8 (105 B): matches/0x002356f0.cpp
// sym: ?v8@ParamValueInventoryEntity@fn_f30d46c2@@UAEHH@Z
// fight::ParamValueInventoryEntity::vfunc_8 @ 0x002356f0
int ParamValueInventoryEntity::v8(int param)
{
    Manager_2356f0* mgr = (*(Manager_2356f0**)&DAT_004e5bb8);
    if (mgr == 0)
        return 0;
    int count = 1;
    Iter_2356f0 it;
    it.FUN_002314a0(mgr->list);
    it.owner = mgr;
    Item* item = it.FUN_00231640();
    while (item != 0) {
        if (v6(param, item))
            count++;
        item = it.FUN_002314c0();
    }
    return count;
}


// 0x00235760 fight::ParamValueInventoryEntity::vfunc_9 (146 B): matches/0x00235760.cpp
// sym: ?vfunc_9@ParamValueInventoryEntity@fight@fn_f30d46c2@@UAEHPAUEntity@3@PAUItem@3@@Z
// fight::ParamValueInventoryEntity::vfunc_9 @ 0x00235760
// Returns the 1-based position of `wanted` among the items this value accepts, or 0.
namespace fight {
int ParamValueInventoryEntity::vfunc_9(Entity *owner, Item *wanted)
{
    if (wanted == 0)
        return 0;
    Registry_235760 *reg = (*(Registry_235760**)&DAT_004e5bb8);
    if (reg == 0)
        return 0;

    int pos = 1;
    Iter_235760 it;
    it.FUN_002314a0(reg->container);
    it.owner = reg;
    for (Item *item = it.FUN_00231640(); item != 0; item = it.FUN_002314c0()) {
        if (Accepts(owner, item)) {
            if (item == wanted)
                return pos;
            pos++;
        }
    }
    return 0;
}
}


// 0x00235800 fight::ParamValueBranch::vfunc_0 (39 B): matches/0x00235800.cpp
// sym: ?v0@ParamValueBranch@fn_f30d46c2@@UAEPAXI@Z
void* ParamValueBranch::v0(unsigned int flags) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Inner_235800*)((char*)this + 8))->Init_0027af50();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00235830 fight::ParamValueConditionGroup::vfunc_0 (39 B): matches/0x00235830.cpp
// sym: ?vfunc_0@ParamValueConditionGroup@fn_f30d46c2@@QAEPAU12@H@Z
ParamValueConditionGroup* ParamValueConditionGroup::vfunc_0(int flags) {
    vptr = ((hulk_intptr)DAT_004279fc);
    sub.Init_0027af50();
    if (flags & 1)
        FUN_0008d330(this);
    return this;
}

} // namespace fn_f30d46c2

// 0x00235870 content::LoadInventory::DynamicCaster<pure3d::Entity>::vfunc_0 (30 B): matches/0x00235870.cpp
// sym: ?vfunc_0@?$DynamicCaster@VEntity@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::Entity>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    __RTDynamicCast((void*)((hulk_uintptr)p), 0, (void*)(&type_refcount), (void*)(&type_animation), 0);
}


// 0x002358c0 fight::ParamValueInventoryEntity::vfunc_10 (141 B): equivalent/0x002358c0.cpp [wrapped: conflict: ParamValueInventoryEntity; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?FUN_002358c0@ParamValueInventoryEntity@fn_002358c0@@QAEPAVEntity@2@PAXII@Z @4348a74c610d @w67cb6b6b00f5
namespace fn_002358c0 {
// STATUS: equivalent (tools/equiv.py level 3: 427 inputs, branch coverage 16/16)
// fight::ParamValueInventoryEntity::vfunc_10 @ 0x002358c0
// ParamValueInventoryEntity: find an entity by 64-bit id, first in the global inventory, then among our own entries.

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}
namespace pure3d { class Entity; }

class Entity {
public:
    char pad0[8];
    unsigned int idLo;
    unsigned int idHi;
};

class Loader_2358c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Entity *v3(content::LoadInventory::DynamicCaster<pure3d::Entity> *caster, unsigned int lo, unsigned int hi);
};

class ParamValueInventoryEntity {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void *owner, Entity *entity);
    virtual Entity *vfunc_7(void *owner, int index);
    virtual int vfunc_8(void *owner);

    Entity *FUN_002358c0(void *owner, unsigned int idLo, unsigned int idHi);
};

Entity *ParamValueInventoryEntity::FUN_002358c0(void *owner, unsigned int idLo, unsigned int idHi)
{
    if ((*(Loader_2358c0**)&DAT_004e5bb8)) {
        content::LoadInventory::DynamicCaster<pure3d::Entity> caster;
        Entity *found = (*(Loader_2358c0**)&DAT_004e5bb8)->v3(&caster, idLo, idHi);
        if (found && vfunc_6(owner, found)) {
            return found;
        }
    }
    int count = vfunc_8(owner);
    for (int i = 0; i < count; i++) {
        Entity *e = vfunc_7(owner, i);
        if (e && idLo == e->idLo && idHi == e->idHi) {
            return e;
        }
    }
    return 0;
}
} // namespace fn_002358c0

