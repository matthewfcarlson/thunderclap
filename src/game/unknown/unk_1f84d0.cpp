// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f84d0..0x001f94e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/pre.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#include "decls/encounter.h"   // (recs1, find2 G20) CEncounterGenerator
#define TREE_TU_BEGIN namespace fn_f6c21956 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6c21956 {} using namespace fn_f6c21956;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f6c21956 {
class Base_1f8530 {
  public:
    virtual void Foo();
};
// (recs1, find2 G20) the generator's small accessors, defined on its record (were owners.h stubs with 32-bit pads)
struct Gen_1f8710 : HulkEncounterGenerator { void FUN_001f8710(int); };
struct Gen_1f8720 : HulkEncounterGenerator { void FUN_001f8720(int i, unsigned char v); };
struct Gen_1f8740 : HulkEncounterGenerator { unsigned char FUN_001f8740(hulk_intptr index); };
struct Gen_1f8790 : HulkEncounterGenerator { Gen_1f8790* get_obj(); void FUN_001f8790(int); };
struct Gen_1f87c0 : HulkEncounterGenerator { void FUN_001f87c0(unsigned char x); };
struct Gen_1f87d0 : HulkEncounterGenerator { void FUN_001f87d0(int x); };
struct Gen_1f8f40 : HulkEncounterGenerator { void FUN_001f8f40(const char* arg); };
struct Slot_1f9130 : HulkEncounterSlot { char Check(unsigned int); char FUN_001f9130(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned char); };
struct Gen_1f93e0 : HulkEncounterGenerator { int FUN_001f93e0(hulk_intptr, int, int, int, int, int, int, int, int, int); };
class Holder_1f8530 {
  public:
    Base_1f8530* ptr;
    Holder_1f8530* Set(Base_1f8530* p);
};
struct Name {
    int lo, hi;
    ~Name();
    bool FUN_0027af90(const Name *other);
};
// (recs1, find2 G20) an entry: a pure3d::Entity's words (vftable, count, then the name; was char pad0[8])
struct Entry_1f85f0 {
    void* vftable;
    int refs;
    Name key;
};
// (recs1, find2 G20) the generator on its record (decls/encounter.h; was a view with 32-bit pads)
struct Table_1f85f0 : HulkEncounterGenerator {
    int FUN_001f85f0(Name name);
};
class Child_1f8760 {
  public:
};
class Thing_1f8760 {
  public:
};
// (recs1, find2 G20) the generator on its record: +0x448 is a script reference, an int (was a Child_1f8760 pointer at a
// 32-bit pad: natively 8 bytes over two ints)
class Owner_1f8760 : public HulkEncounterGenerator {
  public:
    Thing_1f8760* Get_001d4c90();
    void Set(int);
};
class D {
  public:
};
struct Key64 {
    unsigned int lo;
    unsigned int hi;
};
struct Slot_1f87e0 {
    char pad0[0x34];
    int value;              // 0x34
    char pad38[0x58 - 0x38];
};
// (recs1) pure3d::Entity's words (vftable, count, name), then the object's own (were char pad0[0x10] / pad0[8])
struct Ref_1f87e0 {
    void* vftable;
    int refs;
    unsigned int name[2];
    int *target;            // 0x10
};
struct Request {
    void* vftable;
    int refs;
    Key64 key;              // 0x08
};
} // namespace fn_f6c21956
// (recs1) FUN_0027b020: decls/address.h's declaration (the hash of a name; was declared on the encounter view)
namespace fn_f6c21956 {
class SlotTable_1f87e0 : public HulkEncounterGenerator {   // (recs1) on its record (was a view with 32-bit pads)
public:
    bool FUN_001f87e0(Ref_1f87e0 *ref, Request *req, unsigned int *outIndex);
};
struct Entry_1f8890 { float value; char padding[36]; };
struct Object : HulkEncounterGenerator {   // (recs1) on its record (was a view with 32-bit pads): the slots' floats
 float target();
};
struct Item_1f89e0 {
    __int64 Key_000443c0();
};
struct Collection_1f89e0 {
    char pad[12];
    int count;
    Item_1f89e0* Find_00044ad0(__int64);
};
struct Manager_1f89e0 {
    char pad[4];
    Collection_1f89e0* item;
};
struct Root_1f89e0 {
    char pad[0x20];
    Manager_1f89e0* mgr;
};
struct Owner_1f89e0 {
    Item_1f89e0* value;
    char Test(const char*);
};
extern Root_1f89e0* hulk_at_004dd700;
extern "C" __int64 __cdecl MakeKey_0027b020(const char*);
class Helper_1f8a80 {
  public:
};
class Owner_1f8a80 {   // (recs1) a tracker slot: decls/encounter.h HulkEncounterSlot's words (was char pad[0x20])
  public:
    void* obj;
    int w[6];
    float radius;
    volatile int member;
    Helper_1f8a80* GetHelper_001d4c90();
    void Set(int);
};
struct Vec3_1f8aa0 {
    float x, y, z;
};
struct Owner_1f8aa0 {
    bool FUN_00059a50(Vec3_1f8aa0 *out);
};
struct Source_1f8aa0 {   // (recs1) pure3d::Entity's words (was char pad0[0x10]), then the owner
    void* vftable;
    int refs;
    unsigned int name[2];
    Owner_1f8aa0 *owner;           // 0x10
};
class Target_1f8aa0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void GetPosition(Vec3_1f8aa0 *out);        // slot 8
};
class Sensor_1f8aa0 {   // (recs1) a tracker slot: HulkEncounterSlot's words (was char pad0[0x1c])
public:
    void* obj;
    int w[6];
    float radius;           // 0x1c

    bool FUN_001f8aa0(Source_1f8aa0 *src, Target_1f8aa0 *target);
};
struct V3_1f8b40 {
    float x, y, z;
};
struct Sub_1f8b40 {
    int FUN_00204200(float x, float y, float z);
    char FUN_00204440(int idx);
    char FUN_00204470(int idx);
};
struct Tracker_1f8b40 {
};
struct Mgr_1f8b40 {
    const char *FUN_001ff950(V3_1f8b40 pos, int a, int b, float lo, float hi);
    int FUN_001fc8c0(unsigned __int64 id);
};
struct Obj_1f8b40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void getPos(V3_1f8b40 *out);   // 0x20
};
} // namespace fn_f6c21956
struct World {
    char pad0[0x28];
    Mgr_1f8b40 *mgr;                       // 0x28
    char pad2c[0x54 - 0x2c];
    Tracker_1f8b40 *tracker;               // 0x54
};
namespace fn_f6c21956 {
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void FUN_0027af50();
extern void __cdecl FUN_00267760(char*, int, const char*, ...);
struct Sub_1f8f40 {
};
struct V3_1f9040 {
    float x, y, z;
};
class Target_1f9040 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(V3_1f9040 *out);
};
struct Tracker_1f9040 {
    bool FUN_00059a50(V3_1f9040 *out);
};
struct Source_1f9040 {   // (recs1) pure3d::Entity's words (was char pad0[0x10]), then the tracker
    void* vftable;
    int refs;
    unsigned int name[2];
    Tracker_1f9040 *tracker;       // 0x10
};
class Area : public HulkEncounterGenerator {   // (recs1) on its record (was char pad0[0x458], then the state)
public:
    float FUN_001f8890();
    bool FUN_001f9040(Source_1f9040 *src, Target_1f9040 *target);
};
typedef unsigned char u8_1f9130;
typedef unsigned int u32_1f9130;
class Ret_1f9130 {
  public:
};
extern "C" Ret_1f9130* FUN_001d4c90();
extern void InitText_00267760(char*, unsigned int, const char*, ...);
class Sub_1f9230 {
  public:
};
class Obj_1f9230 : public HulkEncounter {   // (recs1) a CEncounter on its record (was a view with 32-bit words)
};
struct Sub_1f93b0 {
    void Fnf_0027af50();
};
class X_1f93b0 : public HulkEncounterMapNode {   // (recs1) a node of the encounter map (was char pad[0x10] before the key)
  public:
    X_1f93b0* run(unsigned char);
};
class Elem_1f93e0 {
  public:
    char Test_001f9130(int, int, int, int, int, int, int, int, int, int);
};
class Inner_1f9460 {
  public:
    void Fng_001f9370(int, int);
};
class Obj_1f9460 : public HulkEncounterGenerator {   // (recs1) on its record (was a view with 32-bit pads): the encounters' flags
  public:
    bool f(int a, int b, int x);
};
class CEncounter {
  public:
    virtual void* FnV_001f94e0(int);
    // (recs1) decls/encounter.h HulkEncounter's words (were 32-bit pads)
    char pad[HULK_ENCR_PAD(key, 0x30, sizeof(void*))];
    class Sub {
      public:
        int x;
        void Init_0027af00();
    } sub;
    char pad2[HULK_ENCR_PAD(w52, 0x52, HULK_ENCR_PAD(key, 0x30, 0) + sizeof(int))];
    unsigned short field52;
    void InitEncounter_001f9230();
    CEncounter();
};

} // namespace fn_f6c21956

// 0x001f84d0 FUN_001f84d0 (94 B): equivalent/0x001f84d0.cpp
// sym: ?FUN_001f84d0@Key_1f84d0@owners@@QAE_NPBU12@@Z @f08329bc16bd @w0fac39feb209 @vf0adc4d14c64
// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 15/18, incomplete)
// FUN_001f84d0 @ 0x001f84d0
bool owners::Key_1f84d0::FUN_001f84d0(const owners::Key_1f84d0 *other) {
    if (category < other->category) return true;
    if (category > other->category) return false;
    if (high < other->high) return true;
    if (high > other->high) return false;
    if (low < other->low) return true;
    if (low > other->low) return false;
    return subcategory < other->subcategory;
}

namespace fn_f6c21956 {

// 0x001f8530 FUN_001f8530 (19 B): matches/0x001f8530.cpp
// sym: ?Set@Holder_1f8530@fn_f6c21956@@QAEPAV12@PAVBase_1f8530@2@@Z
Holder_1f8530* Holder_1f8530::Set(Base_1f8530* p) {
    ptr = p;
    p->Foo();
    return this;
}


// 0x001f85f0 FUN_001f85f0 (116 B): matches/0x001f85f0.cpp
// sym: ?FUN_001f85f0@Table_1f85f0@fn_f6c21956@@QAEHUName@2@@Z
// FUN_001f85f0 @ 0x001f85f0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
int Table_1f85f0::FUN_001f85f0(Name name)
{
    if (state == 0)
        return -1;
    for (int i = 0; i < count; i++) {
        if (((Entry_1f85f0 *)items[i])->key.FUN_0027af90(&name))
            return i;
    }
    return -1;
}

} // namespace fn_f6c21956

// 0x001f8670 FUN_001f8670 (146 B): equivalent/0x001f8670.cpp [wrapped: merged class would differ: Key: size 1 vs 8]
// sym: ?FUN_001f8670@Registry_1f8670@fn_001f8670@@QAEHUKey@2@@Z @7bbe5912df00 @w7e692cf26631 @v23eec4ea7ce8
namespace fn_001f8670 {
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// FUN_001f8670 @ 0x001f8670
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
// equiv-map: ??1Key@@QAE@XZ = 0x0027af50

struct Key {
    int lo, hi;
    Key(const Key &other);
    ~Key();
};

struct Item_1f8670 {
    char pad[1];
};

class Registry_1f8670 : public HulkEncounterGenerator {   // (recs1) on its record (was a view with a 32-bit pad)
public:

    int FUN_001f85f0(Key key);
    int FUN_001f8670(Key key);
};

// Removes the item named `key` by moving the last item into its slot; returns its old index or -1.
int Registry_1f8670::FUN_001f8670(Key key)
{
    if (activeCount != 0 && firstActive >= 0) {
        int index = FUN_001f85f0(key);
        if (index != -1 && index >= firstActive) {
            items[index] = items[count - 1];
            count--;
            activeCount--;
            if (activeCount == 0)
                firstActive = -1;
            return index;
        }
    }
    return -1;
}
} // namespace fn_001f8670


// 0x001f8710 FUN_001f8710 (13 B): matches/0x001f8710.cpp
// sym: ?FUN_001f8710@Gen_1f8710@fn_f6c21956@@QAEXH@Z
void fn_f6c21956::Gen_1f8710::FUN_001f8710(int x) {
    f43c = x;
}


// 0x001f8720 FUN_001f8720 (27 B): matches/0x001f8720.cpp
// sym: ?FUN_001f8720@Gen_1f8720@fn_f6c21956@@QAEXHE@Z
void fn_f6c21956::Gen_1f8720::FUN_001f8720(int i, unsigned char v) {
    if (i >= 0 && i < 6)
        flags440[i] = v;
}


// 0x001f8740 FUN_001f8740 (25 B): matches/0x001f8740.cpp
// sym: ?FUN_001f8740@Gen_1f8740@fn_f6c21956@@QAEEH@Z
unsigned char fn_f6c21956::Gen_1f8740::FUN_001f8740(hulk_intptr index) {
    unsigned char result = 0;
    if (((int)index) >= 0 && ((int)index) < 6)
        result = flags440[((int)index)];
    return result;
}

namespace fn_f6c21956 {

// 0x001f8760 FUN_001f8760 (36 B): matches/0x001f8760.cpp
// sym: ?Set@Owner_1f8760@fn_f6c21956@@QAEXH@Z
void Owner_1f8760::Set(int arg) {   // (recs1) a script reference (was a Child_1f8760 pointer)
    Thing_1f8760* t = Get_001d4c90();
    int old = f448;
    ((owners::Obj_1d1900 *)t)->FUN_001d1900((hulk_intptr)old);
    f448 = arg;
}

} // namespace fn_f6c21956

// 0x001f8790 FUN_001f8790 (36 B): matches/0x001f8790.cpp
// sym: ?FUN_001f8790@Gen_1f8790@fn_f6c21956@@QAEXH@Z
void fn_f6c21956::Gen_1f8790::FUN_001f8790(int p) {
    D* q = (D*)get_obj();
    ((owners::Obj_1d1900 *)q)->FUN_001d1900((hulk_intptr)f44c);
    f44c = p;
}


// 0x001f87c0 FUN_001f87c0 (13 B): matches/0x001f87c0.cpp
// sym: ?FUN_001f87c0@Gen_1f87c0@fn_f6c21956@@QAEXE@Z
void fn_f6c21956::Gen_1f87c0::FUN_001f87c0(unsigned char x) {
    enabled = x;
}


// 0x001f87d0 FUN_001f87d0 (13 B): matches/0x001f87d0.cpp
// sym: ?FUN_001f87d0@Gen_1f87d0@fn_f6c21956@@QAEXH@Z
void fn_f6c21956::Gen_1f87d0::FUN_001f87d0(int x) {
    f454 = x;
}

namespace fn_f6c21956 {

// 0x001f87e0 FUN_001f87e0 (163 B): equivalent/0x001f87e0.cpp
// sym: ?FUN_001f87e0@SlotTable_1f87e0@fn_f6c21956@@QAE_NPAURef_1f87e0@2@PAURequest@2@PAI@Z @890f5e9bb32d @w658e28e75c99 @v04027fe76cd3
// STATUS: equivalent (tools/equiv.py level 3: 2939 inputs, branch coverage 12/12)
// FUN_001f87e0 @ 0x001f87e0
// (integ4, post) a found encounter's index is below the generator's encounter count (callers index encounters[] by it;
// a stub of this function draws one there)
// post: ge(*arg3, 0) lt(*arg3, *this+0xc68) when ret
bool SlotTable_1f87e0::FUN_001f87e0(Ref_1f87e0 *ref, Request *req, unsigned int *outIndex)
{
    if (state == 0)
        return false;
    for (int i = 0; i < encounterCount; i++) {
        HulkEncounter *slot = &encounters[i];   // (recs1) was a view 0xc bytes into the encounter
        unsigned int lo = req->key.lo;
        unsigned int hi = req->key.hi;
        unsigned __int64 id = FUN_0027b020(slot->name);
        if ((unsigned int)id == lo && (unsigned int)(id >> 32) == hi && slot->f40 == *ref->target) {
            *outIndex = i;
            HULK_POST_GE((int)*outIndex, 0);
            HULK_POST_LT((int)*outIndex, encounterCount);
            return true;
        }
    }
    return false;
}


// 0x001f8890 FUN_001f8890 (170 B): equivalent/0x001f8890.cpp
// sym: ?target@Object@fn_f6c21956@@QAEMXZ @d8a4a073de73 @wc2a016aa081f @v60b1d2553300
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 20/20)
// FUN_001f8890 @ 0x001f8890
float Object::target() {
 float result = 0.0f;
 if (!state) return result;
 for (int i=0; i<slotCount; ++i) {
  float v=slots[i].radius;
  if (result < v) result=v;
 }
 return result;
}

} // namespace fn_f6c21956

// 0x001f8940 FUN_001f8940 (33 B): matches/0x001f8940.cpp
// sym: ?FUN_001f8940@Obj_1f8940@owners@@QAEPAU12@PAU12@@Z
owners::Obj_1f8940* owners::Obj_1f8940::FUN_001f8940(owners::Obj_1f8940* other) {
    Copy(other);
    a = other->a;
    b = other->b;
    return this;
}

namespace fn_f6c21956 {

// 0x001f89e0 FUN_001f89e0 (151 B): matches/0x001f89e0.cpp
// sym: ?Test@Owner_1f89e0@fn_f6c21956@@QAEDPBD@Z
char Owner_1f89e0::Test(const char* name) {
    Owner_1f89e0* saved = this;
    Collection_1f89e0* c = hulk_at_004dd700->mgr->item;
    if (c) {
        value = c->Find_00044ad0(MakeKey_0027b020(name));
        if (value)
            return 1;
        __int64 p = MakeKey_0027b020(name);
        for (int i = 0; i < c->count; ++i) {
            if (((Item_1f89e0 *)((owners::C_44ab0 *)c)->FUN_00044ab0(i))->Key_000443c0() == p) {
                saved->value = ((Item_1f89e0 *)((owners::C_44ab0 *)c)->FUN_00044ab0(i));
                return 1;
            }
        }
        Item_1f89e0* dead = *(Item_1f89e0* volatile*)&saved->value;
    }
    return 0;
}


// 0x001f8a80 FUN_001f8a80 (30 B): matches/0x001f8a80.cpp
// sym: ?Set@Owner_1f8a80@fn_f6c21956@@QAEXH@Z
void Owner_1f8a80::Set(int value) {
    Helper_1f8a80* h = GetHelper_001d4c90();
    ((owners::Obj_1d1900 *)h)->FUN_001d1900((hulk_intptr)member);
    member = value;
}


// 0x001f8aa0 FUN_001f8aa0 (146 B): equivalent/0x001f8aa0.cpp
// sym: ?FUN_001f8aa0@Sensor_1f8aa0@fn_f6c21956@@QAE_NPAUSource_1f8aa0@2@PAVTarget_1f8aa0@2@@Z @32ea06f9b7db @w694b23e249e0 @ve7b1122fe13e
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 8/8)
// FUN_001f8aa0 @ 0x001f8aa0
// True when the target lies within `radius` of the source owner's position.
bool Sensor_1f8aa0::FUN_001f8aa0(Source_1f8aa0 *src, Target_1f8aa0 *target)
{
    Vec3_1f8aa0 origin;
    if (!src->owner->FUN_00059a50(&origin))
        return false;
    hulk_freg r = radius;
    if (r <= 0.0f)
        return false;
    if (target == 0)
        return false;

    Vec3_1f8aa0 pos;
    target->GetPosition(&pos);
    hulk_freg dx = pos.x - origin.x;
    hulk_freg dy = pos.y - origin.y;
    hulk_freg dz = pos.z - origin.z;
    hulk_freg sum = dz * dz + dy * dy + dx * dx;
    return sum <= r * r;
}


// 0x001f8b40 FUN_001f8b40 (552 B): equivalent/0x001f8b40.cpp
// sym: ?FUN_001f8b40@fn_f6c21956@@YGHHPAUObj_1f8b40@1@MMM@Z @8b91387b08d9 @w879aec9e2096 @v26683c4f1237
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 24/24)
// FUN_001f8b40 @ 0x001f8b40
hulk_intptr __stdcall FUN_001f8b40(int a1, Obj_1f8b40 *obj, float x, float y, float z)
{
    struct Frame {
        V3_1f8b40 p;
        V3_1f8b40 q;
    } f;

    Mgr_1f8b40 *mgr = DAT_004dd700->mgr;
    if (mgr == 0)
        return 0;

    if (a1 == 1) {
        obj->getPos(&f.q);
        obj->getPos(&f.p);
        int idx = ((Sub_1f8b40 *)((owners::Target_862a0 *)(DAT_004dd700->tracker))->FUN_000862a0())->FUN_00204200(f.p.x, f.p.y, f.p.z);
        if (idx == -1) {
            f.p.x = x; f.p.y = y; f.p.z = z;
        } else {
            char b1 = ((Sub_1f8b40 *)((owners::Target_862a0 *)(DAT_004dd700->tracker))->FUN_000862a0())->FUN_00204440(idx);
            char b2 = ((Sub_1f8b40 *)((owners::Target_862a0 *)(DAT_004dd700->tracker))->FUN_000862a0())->FUN_00204470(idx);
            if (!b1 && !b2) {
                f.p.x = x; f.p.y = y; f.p.z = z;
            }
        }
        const char *name = mgr->FUN_001ff950(f.p, 1, 2, -3.4028235e38f, 30.0f);
        if (name == 0)
            return (hulk_intptr)obj;
        return mgr->FUN_001fc8c0(FUN_0027b020(name));
    }

    if (a1 > 1 && a1 <= 5) {
        obj->getPos(&f.p);
        int idx = ((Sub_1f8b40 *)((owners::Target_862a0 *)(DAT_004dd700->tracker))->FUN_000862a0())->FUN_00204200(f.p.x, f.p.y, f.p.z);
        if (idx == -1) {
            f.p.x = x; f.p.y = y; f.p.z = z;
        } else {
            char b1 = ((Sub_1f8b40 *)((owners::Target_862a0 *)(DAT_004dd700->tracker))->FUN_000862a0())->FUN_00204440(idx);
            char b2 = ((Sub_1f8b40 *)((owners::Target_862a0 *)(DAT_004dd700->tracker))->FUN_000862a0())->FUN_00204470(idx);
            if (!b1 && !b2) {
                f.p.x = x; f.p.y = y; f.p.z = z;
            }
        }
        const char *name = mgr->FUN_001ff950(f.p, a1, 0, -3.4028235e38f, 3.4028235e38f);
        if (name != 0)
            return mgr->FUN_001fc8c0(FUN_0027b020(name));
    }
    return (hulk_intptr)obj;
}


// 0x001f8ed0 FUN_001f8ed0 (30 B): matches/0x001f8ed0.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f6c21956@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0027af50();
    if ((flags & 1) != 0)
        ::operator delete(this);
    return this;
}

} // namespace fn_f6c21956

// 0x001f8f40 FUN_001f8f40 (45 B): matches/0x001f8f40.cpp
// sym: ?FUN_001f8f40@Gen_1f8f40@fn_f6c21956@@QAEXPBD@Z
// data: fmt_1f8f40 = DAT_003f3f38
void fn_f6c21956::Gen_1f8f40::FUN_001f8f40(const char* arg) {
    ((owners::Target_27b040 *)(((Sub_1f8f40*)entityName)))->FUN_0027b040((hulk_uintptr)arg);
    FUN_00267760(title, 0x20, DAT_003f3f38, arg);
}


// 0x001f8f70 FUN_001f8f70 (112 B): equivalent/0x001f8f70.cpp [wrapped: conflict: Key; World]
// sym: ?FUN_001f8f70@Registry_1f8f70@fn_001f8f70@@QAEHPBD@Z @ee4aa9f451b8 @w432cd92fb3aa @v401fa9e70e98
namespace fn_001f8f70 {
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 4/4)
// FUN_001f8f70 @ 0x001f8f70
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Key {
    int lo, hi;
    Key() {}
    Key(const Key& other);
    void FUN_0027b0e0(const char* name);
    void FUN_0027af50();
};

struct Item_1f8f70 {
    char pad[1];
};

struct Factory_1f8f70 {
    Item_1f8f70* FUN_001fc8c0(int lo, int hi);
};

struct World {
    char pad[0x28];
    Factory_1f8f70* factory;       // 0x28
};

class Registry_1f8f70 : public HulkEncounterGenerator {   // (recs1) on its record (was a view with a 32-bit pad)
public:
    int FUN_001f85f0(Key key);
    int FUN_001f8f70(const char* name);
};

// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
int Registry_1f8f70::FUN_001f8f70(const char* name)
{
    Key key;
    key.FUN_0027b0e0(name);
    int index = FUN_001f85f0(key);
    if (index == -1) {
        Item_1f8f70* item = DAT_004dd700->factory->FUN_001fc8c0(key.lo, key.hi);
        if (item != 0) {
            index = count;
            items[index] = item;
            count++;
        }
    }
    key.FUN_0027af50();
    return index;
}
} // namespace fn_001f8f70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001f8fe0 FUN_001f8fe0 (87 B): matches/0x001f8fe0.cpp [wrapped: merged class would differ: Item: field key: Field(+0x8 Key key) vs Field(+0x8 Key key)]
// sym: ?FUN_001f8fe0@Registry@fn_001f8fe0@@QAEHPAUItem@2@@Z
namespace fn_001f8fe0 {
struct Key {
    int lo, hi;
    Key() {}
    Key(const Key& other);
};

struct Item {   // (recs1) pure3d::Entity's words (vftable, count; was char pad[8]), then the name
    void* vftable;
    int refs;
    Key key;                // 0x08
};

class Registry : public HulkEncounterGenerator {   // (recs1) on its record (was a view with a 32-bit pad)
public:
    int FUN_001f85f0(Key key);
    int FUN_001f8fe0(Item* item);
};

// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
int Registry::FUN_001f8fe0(Item* item)
{
    if (item == 0)
        return -1;
    int index = FUN_001f85f0(item->key);
    if (index == -1) {
        index = count;
        items[index] = item;
        count++;
        activeCount++;
    }
    return index;
}
} // namespace fn_001f8fe0

namespace fn_f6c21956 {

// 0x001f9040 FUN_001f9040 (164 B): equivalent/0x001f9040.cpp
// sym: ?FUN_001f9040@Area@fn_f6c21956@@QAE_NPAUSource_1f9040@2@PAVTarget_1f9040@2@@Z @cb0e8f625016 @wf599b314374a @v0079c00f73dd
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 10/10)
// FUN_001f9040 @ 0x001f9040
bool Area::FUN_001f9040(Source_1f9040 *src, Target_1f9040 *target)
{
    if (state == 0)
        return false;
    struct Frame {
        V3_1f9040 other;
        V3_1f9040 pos;
    } fr;
    if (!src->tracker->FUN_00059a50(&fr.pos))
        return false;
    hulk_freg radius = FUN_001f8890();
    if (radius <= 0.0f)
        return false;
    if (target == 0)
        return false;
    target->v8(&fr.other);
    hulk_freg dx = fr.other.x - fr.pos.x;
    hulk_freg dy = fr.other.y - fr.pos.y;
    hulk_freg dz = fr.other.z - fr.pos.z;
    if ((dz * dz + dy * dy) + dx * dx <= radius * radius)
        return true;
    return false;
}

} // namespace fn_f6c21956

// 0x001f9130 FUN_001f9130 (106 B): matches/0x001f9130.cpp
// sym: ?FUN_001f9130@Slot_1f9130@fn_f6c21956@@QAEDIIIIIIIIIE@Z
char fn_f6c21956::Slot_1f9130::FUN_001f9130(u32_1f9130 p1, u32_1f9130 p2, u32_1f9130 p3, u32_1f9130 p4, u32_1f9130 p5, u32_1f9130 p6, u32_1f9130 p7, u32_1f9130 p8, u32_1f9130 p9, u8_1f9130 p10) {
    char r = Check(p1);
    if (r) {
        w[0] = p2;   // (recs1) the slot's words on its record (was an owners.h view: char pad[4], then a .. h)
        w[1] = p3;
        w[2] = p4;
        w[3] = p5;
        w[4] = p6;
        w[5] = p7;
        *(u32_1f9130*)&radius = p8;
        Ret_1f9130* o = FUN_001d4c90();
        ((owners::Obj_1d1900 *)o)->FUN_001d1900((hulk_intptr)tracker);
        tracker = p9;
        active = p10;
    }
    return r;
}


// 0x001f91b0 FUN_001f91b0 (118 B): equivalent/0x001f91b0.cpp [wrapped: conflict: FUN_00267760; Name]
// sym: ?FUN_001f91b0@Record_1f91b0@fn_001f91b0@@QAEPAV12@PBV12@@Z @4510ae5176e5 @we85dc2d00ce6 @v34bdf50c6e20
namespace fn_001f91b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f91b0 @ 0x001f91b0
// equiv-map: ??4Name@@QAEAAU0@ABU0@@Z = 0x0027af70
struct Name {
    char d[8];
    Name &operator=(const Name &o);
};

struct NameEx {
    Name n;
    unsigned char b8;
    unsigned char b9;
};

int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

class Record_1f91b0 {
public:
    char pad0[8];
    int f8;
    char label[0x20];
    char pad2c[4];
    NameEx name;
    char pad3a[6];
    int f40, f44, f48, f4c;
    unsigned char b50, b51;
    unsigned short w52;
    Record_1f91b0 *FUN_001f91b0(const Record_1f91b0 *src);
};

Record_1f91b0 *Record_1f91b0::FUN_001f91b0(const Record_1f91b0 *src)
{
    f8 = src->f8;
    FUN_00267760(label, 0x20, "%s", src->label);
    f40 = src->f40;
    f44 = src->f44;
    f48 = src->f48;
    f4c = src->f4c;
    name.n = src->name.n;
    name.b8 = src->name.b8;
    name.b9 = src->name.b9;
    b50 = src->b50;
    b51 = src->b51;
    w52 = src->w52;
    return this;
}
} // namespace fn_001f91b0

namespace fn_f6c21956 {

// 0x001f9230 FUN_001f9230 (77 B): matches/0x001f9230.cpp
// sym: ?Target@fn_f6c21956@@YIXPAVObj_1f9230@1@@Z
// data: gText_1f9230 = DAT_00424f08, gZero_1f9230 = DAT_003f335c
void __fastcall Target(Obj_1f9230* self) {
    self->table = 0;
    InitText_00267760(self->name, 0x20, DAT_00424f08);
    self->f40 = 0;
    self->f44 = 0;
    self->f48 = 0;
    self->f4c = 0;
    self->key.a = 0xff;
    ((owners::Target_27b040 *)(((Sub_1f9230*)&self->key)))->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
    self->b50 = 0;
    self->key.b = 0xff;
    self->b51 = 1;
    self->w52 = 0xffff;
}

} // namespace fn_f6c21956

// 0x001f9370 FUN_001f9370 (37 B): matches/0x001f9370.cpp
// sym: ?FUN_001f9370@C_1f9370@owners@@QAEXHD@Z
void owners::C_1f9370::FUN_001f9370(int bit, char set) {
    if (set)
        *reinterpret_cast<ushort*>(this) |= (ushort)(1 << bit);
    else
        *reinterpret_cast<ushort*>(this) &= (ushort) ~(1 << bit);
}

namespace fn_f6c21956 {

// 0x001f93b0 FUN_001f93b0 (33 B): matches/0x001f93b0.cpp
// sym: ?run@X_1f93b0@fn_f6c21956@@QAEPAV12@E@Z
X_1f93b0* X_1f93b0::run(unsigned char flags) {
    ((Sub_1f93b0*)&key)->Fnf_0027af50();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

} // namespace fn_f6c21956

// 0x001f93e0 FUN_001f93e0 (114 B): matches/0x001f93e0.cpp
// sym: ?FUN_001f93e0@Gen_1f93e0@fn_f6c21956@@QAEHHHHHHHHHHH@Z
int fn_f6c21956::Gen_1f93e0::FUN_001f93e0(hulk_intptr a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    int r = -1;
    if (slotCount < 16) {
        if (((Elem_1f93e0*)&slots[slotCount])->Test_001f9130(((int)a), b, c, d, e, f, g, h, i, j)) {
            r = slotCount;
            slotCount = r + 1;
        }
    }
    return r;
}

namespace fn_f6c21956 {

// 0x001f9460 FUN_001f9460 (71 B): matches/0x001f9460.cpp
// sym: ?f@Obj_1f9460@fn_f6c21956@@QAE_NHHH@Z
bool Obj_1f9460::f(int a, int b, int x) {
    if (a < 0 || a >= encounterCount)
        return false;
    if (b < 0 || b >= slotCount)
        return false;
    ((Inner_1f9460 *)&encounters[a].w52)->Fng_001f9370(b, x);
    return true;
}


// 0x001f94b0 FUN_001f94b0 (34 B): matches/0x001f94b0.cpp
// sym: ??0CEncounter@fn_f6c21956@@QAE@XZ
CEncounter::CEncounter() {
    sub.Init_0027af00();
    field52 = 0;
    InitEncounter_001f9230();
}

} // namespace fn_f6c21956
