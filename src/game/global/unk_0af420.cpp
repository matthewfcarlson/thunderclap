// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000af420..0x000afd00 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6541536 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6541536 {} using namespace fn_f6541536;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6541536 {
class Ref_af510 {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj_af510 {
    char pad[0x2c];
    Ref_af510* ref;

  public:
    void clear();
};
extern "C" float __cdecl FUN_000af420(float);
struct Value_af530 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void set(float);
};
struct Provider_af530 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual Value_af530* get(unsigned);
};
struct Record_af530 { unsigned count; unsigned types[8]; float values[2]; Provider_af530* provider; };
struct Object {
 char pad0[8]; unsigned char enabled; char pad9[11]; Record_af530* records;
 void target(unsigned group,unsigned index,float value);
};
class Info_af700 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char *v4();
};
class Device_af700 {
public:
    virtual void v0();
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
    virtual void v11();
    virtual unsigned int v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual Info_af700 *v16(unsigned int i);
};
struct Record_af700 {
    unsigned int count;
    int kind[2];
    int state[2];
    char pad14[0x18];
    Device_af700 *device;
};
class Controller_af700 {
public:
    char pad0[0x14];
    Record_af700 *records;
    void FUN_000af530(int index, unsigned int port, int flag);
    void FUN_000af700(int index, Device_af700 *dev);
};
class Voice_af8e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual float v5();
    virtual void v6(float value);
};
class Emitter_af8e0 {
public:
    virtual void v0();
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual Voice_af8e0 *v16(int slot);
};
struct Entry_af8e0 {
    char pad00[0x0d];
    char skip;          // 0x0d
    char pad0e[2];
    int value;          // 0x10
};
struct EntryList_af8e0 {
};
struct Group_af8e0 {
    unsigned int count;     // 0x00
    char pad04[8];
    float timer[2];         // 0x0c
    float level[2];         // 0x14
    float decay[2];         // 0x1c
    float limit[2];         // 0x24
    Emitter_af8e0 *emitter;       // 0x2c
};
class Mixer {
public:
    char pad00[8];
    bool enabled;           // 0x08
    char pad09[3];
    EntryList_af8e0 *entries;     // 0x0c
    int groupCount;         // 0x10
    Group_af8e0 *groups;          // 0x14
    int ticks;              // 0x18

    void FUN_000af700(int index, int value);
    void FUN_000af530(int index, int slot, int flag);
    void FUN_000af8e0(float dt);
};
class Notifier_afaf0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void Reset(int flag);        // slot 6
};
class Source_afaf0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual Notifier_afaf0 *GetNotifier(unsigned int index);   // slot 16
};
struct Group_afaf0 {
    unsigned int count;      // 0x00
    char pad04[8];
    void *entries[8];        // 0x0c
    Source_afaf0 *owner;           // 0x2c
};
class Manager_afaf0 {
public:
    char pad00[8];
    char active;             // 0x08
    char pad09[7];
    int groupCount;          // 0x10
    Group_afaf0 *groups;           // 0x14
    void FUN_000af530(int group, unsigned int entry, int flag);
    void FUN_000afaf0();
};
struct ThisCall_000afaf0 {
    void Refresh_000afaf0();
};
extern "C" void* __cdecl FUN_0008d690(unsigned size);
class Source_afbf0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad[0xc];
    int count;
};
struct Elem_afbf0 { int f0; char pad[0x2c - 4]; int f2c; };
class CHapticController {
public:
    virtual void v0_00018b30();
    int f4;
    char f8;
    char pad9[3];
    Source_afbf0* src;
    int count;
    Elem_afbf0* items;
    int f18;
    CHapticController(Source_afbf0* s);
};


// 0x000af420 FUN_000af420 (52 B): matches/0x000af420.cpp
// sym: _FUN_000af420
// data: fallback = DAT_00405e5c, results = DAT_004dda14, thresholds = DAT_004dda28
extern "C" float __cdecl FUN_000af420(float x) {
    int i = 4;
    do {
        if (((float*)&DAT_004dda28)[i] <= x)
            return ((float*)&DAT_004dda14)[i];
        --i;
    } while (i >= 0);
    return DAT_00405e5c;
}


// 0x000af480 FUN_000af480 (108 B): matches/0x000af480.cpp
// sym: _FUN_000af480
extern "C" void FUN_000af480() {
    (*(int*)&DAT_004dda28) = 0x3e46a7f0;
    (*(int*)&DAT_004dda14) = 0x43700000;
    (*(int*)&DAT_004dda2c) = 0x3e96872b;
    (*(int*)&DAT_004dda18) = 0x43160000;
    (*(int*)&DAT_004dda30) = 0x3efced91;
    (*(int*)&DAT_004dda1c) = 0x42960000;
    (*(int*)&DAT_004dda34) = 0x3f31a9fc;
    (*(int*)&DAT_004dda20) = 0x42480000;
    (*(int*)&DAT_004dda38) = 0x3f64dd2f;
    (*(int*)&DAT_004dda24) = 0;
    (*(unsigned char*)&DAT_004dda3c) = 1;
}


// 0x000af510 FUN_000af510 (24 B): matches/0x000af510.cpp
// sym: ?clear@Obj_af510@fn_f6541536@@QAEXXZ
void Obj_af510::clear() {
    if (ref) {
        ref->f1();
        ref = 0;
    }
}


// 0x000af530 FUN_000af530 (197 B): equivalent/0x000af530.cpp
// sym: ?target@Object@fn_f6541536@@QAEXIIM@Z @cbfa50c46e0e @w6b7f662364f5
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// FUN_000af530 @ 0x000af530
void Object::target(unsigned group,unsigned index,float value) {
 if (!enabled) return;
 Record_af530* base=records;
 Record_af530* record=&base[group];
 if(index>=record->count || !record->provider) return;
 unsigned type=record->types[index];
 if(type==2) {
  value=value>0.5f?1.0f:0.0f;
  Value_af530* dest=records[group].provider->get(index);
  dest->set(value);
 } else if(type==1) {
  if((*(unsigned char*)&DAT_004dda3d)) {
   float result=FUN_000af420(value);
   record->values[index]=result;
  } else {
   Value_af530* dest=records[group].provider->get(index);
   dest->set(value);
  }
 }
}

} // namespace fn_f6541536

// 0x000af650 FUN_000af650 (79 B): matches/0x000af650.cpp
// sym: ?FUN_000af650@Obj_af650@owners@@QAEXHIM@Z
// data: gFlag_af650 = DAT_004dda3d
void owners::Obj_af650::FUN_000af650(int index, unsigned int element, float value) {
    if (enabled && element < (unsigned int)data[index * 12]) {
        if ((*(unsigned char*)&DAT_004dda3d))
            data[index * 12 + element + 5] = 0;
        *(float*)(data + index * 12 + element + 3) = value;
    }
}

namespace fn_f6541536 {

// 0x000af700 FUN_000af700 (387 B): matches/0x000af700.cpp
// sym: ?FUN_000af700@Controller_af700@fn_f6541536@@QAEXHPAVDevice_af700@2@@Z
// FUN_000af700 @ 0x000af700
void Controller_af700::FUN_000af700(int index, Device_af700 *dev)
{
    if (dev == records[index].device)
        return;
    if (dev)
        dev->v0();
    if (records[index].device)
        records[index].device->v1();
    records[index].device = dev;
    if (records[index].device) {
        records[index].count = records[index].device->v12();
        if (records[index].count > 2)
            records[index].count = 2;
        for (unsigned int i = 0; i < records[index].count; i++) {
            Info_af700 *info = records[index].device->v16(i);
            info->v3();
            const char *name = info->v4();
            if (strcmp(name, "Analog") == 0)
                records[index].kind[i] = 1;
            else if (strcmp(name, "Digital") == 0)
                records[index].kind[i] = 2;
            else
                records[index].kind[i] = 0;
            records[index].state[i] = 0;
            FUN_000af530(index, i, 0);
        }
    } else {
        records[index].count = 0;
        for (unsigned int i = 0; i < records[index].count; i++) {
            records[index].kind[i] = 0;
            records[index].state[i] = 0;
        }
    }
}


// 0x000af8e0 FUN_000af8e0 (525 B): matches/0x000af8e0.cpp
// sym: ?FUN_000af8e0@Mixer@fn_f6541536@@QAEXM@Z
// FUN_000af8e0 @ 0x000af8e0
void Mixer::FUN_000af8e0(float dt)
{
    ticks++;
    if (!enabled)
        return;

    for (int i = 0; i < groupCount; i++) {
        if (((Entry_af8e0 *)((owners::C_ace20 *)entries)->FUN_000ace20(i))->skip != 0) {
            FUN_000af700(i, 0);
            continue;
        }
        FUN_000af700(i, ((Entry_af8e0 *)((owners::C_ace20 *)entries)->FUN_000ace20(i))->value);

        for (unsigned int j = 0; j < groups[i].count; j++) {
            Group_af8e0 *g = groups;
            if (g[i].timer[j] > 0.0f) {
                g[i].timer[j] = g[i].timer[j] - dt;
                if ((*(bool*)&DAT_004dda3d)) {
                    g = groups;
                    float *level = &g[i].level[j];
                    float *limit = &g[i].limit[j];
                    float *decay = &g[i].decay[j];
                    Voice_af8e0 *v = g[i].emitter->v16(j);
                    if (v->v5() > 0.0f) {
                        float d = dt + *decay;
                        *decay = d;
                        if (d > 0.05f) {
                            *decay = 0.0f;
                            groups[i].emitter->v16(j)->v6(0.0f);
                        }
                    }
                    float l = dt + *level;
                    *level = l;
                    if (l > *limit * 0.001f) {
                        groups[i].emitter->v16(j)->v6(1.0f);
                        *level = 0.0f;
                        *decay = 0.0f;
                    }
                }
            } else {
                if ((*(bool*)&DAT_004dda3d))
                    g[i].emitter->v16(j)->v6(0.0f);
                groups[i].timer[j] = 0.0f;
                FUN_000af530(i, j, 0);
            }
        }
    }
}


// 0x000afaf0 FUN_000afaf0 (143 B): matches/0x000afaf0.cpp
// sym: ?FUN_000afaf0@Manager_afaf0@fn_f6541536@@QAEXXZ
// FUN_000afaf0 @ 0x000afaf0
void Manager_afaf0::FUN_000afaf0() {
    if (!active)
        return;
    for (int g = 0; g < groupCount; g++) {
        for (unsigned int e = 0; e < groups[g].count; e++) {
            if ((*(char*)&DAT_004dda3d))
                groups[g].owner->GetNotifier(e)->Reset(0);
            groups[g].entries[e] = 0;
            FUN_000af530(g, e, 0);
        }
    }
}

} // namespace fn_f6541536

// 0x000afb80 FUN_000afb80 (26 B): matches/0x000afb80.cpp
// sym: ?FUN_000afb80@Thing_afb80@owners@@QAEXD@Z
void owners::Thing_afb80::FUN_000afb80(char x) {
    if (value != x)
        ((ThisCall_000afaf0*)(this))->Refresh_000afaf0();
    value = x;
}

namespace fn_f6541536 {

// 0x000afbf0 FUN_000afbf0 (137 B): equivalent/0x000afbf0.cpp
// sym: ??0CHapticController@fn_f6541536@@QAE@PAVSource_afbf0@1@@Z @ba10eeefd3e5 @wa29a741767d6
// STATUS: equivalent (tools/equiv.py level 3: 153 inputs, branch coverage 10/10)
// FUN_000afbf0 @ 0x000afbf0
CHapticController::CHapticController(Source_afbf0* s) {
    f4 = 0;
    f8 = 1;
    src = 0;
    count = 0;
    items = 0;
    f18 = 0;
    if (s) s->AddRef();
    if (src) src->Release();
    src = s;
    int n = s->count;
    count = n;
    int* raw = (int*)FUN_0008d690(n * 0x30 + 4);
    if (!raw) {
        items = 0;
        return;
    }
    raw[0] = n;
    Elem_afbf0* e = (Elem_afbf0*)(raw + 1);
    for (int i = 0; i < n; i++) {
        e[i].f0 = 0;
        e[i].f2c = 0;
    }
    items = e;
}

} // namespace fn_f6541536
