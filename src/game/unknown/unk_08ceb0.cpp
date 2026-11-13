// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008ceb0..0x0008dbb0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_fe5d7f9e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe5d7f9e {} using namespace fn_fe5d7f9e;
#include "game/unknown.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
namespace fn_fe5d7f9e {
struct NameEntry_8ced0 {
    const char *name;
    int a, b;
};
class Slot_8ced0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual void Query(int *x, int *c, int *b, int *a);   // slot 9
    virtual void v10();
    virtual int GetCount();                               // slot 11
};
class SlotTable_8ced0 {
public:
    int header;
    Slot_8ced0 *slots[19];         // 0x04
    void FUN_0008ced0(int index, int *outCount, int *outX, int *outA, int *outB, const char **outName);
};
class Item {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void Get(int*, int*, int*, int*);
};
class Owner {
  public:
    char pad[4];
    Item* items[19];
    int Sum();
};
class Inner_8cfb0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void Get(void*, void*, void*, void*);
    virtual void a10();
    virtual int Count();
};
class Obj_8cfb0 {
  public:
    char pad[4];
    Inner_8cfb0* p;
    int run();
};
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
struct Obj_8d3a0 {
    virtual void vfn0();
    virtual void vfn1();
};
struct HeapDesc {
    const char *name;
    int base;
    int size;
};
extern "C" Obj_8d3a0 *FUN_0026cf20(int addr, int a, const char *name);
void FUN_002670b0(int idx, int a, Obj_8d3a0 *obj);
class Holder_8d3a0 : public HeapSet {
public:
    void FUN_0008d3a0(int idx, int arg);
};
extern "C" void __cdecl FUN_0008d320();
struct Ref_8d480 { virtual void FUN_00000000(); virtual void FUN_00000004(); };
struct Obj_8d480 : HeapSet { void FUN_0008d3a0(int,int); void FUN_0008d480(); };
extern "C" void __cdecl FUN_00267280();
extern "C" int __cdecl FUN_00266d90();
extern "C" void __cdecl FUN_00266db0(hulk_intptr,int);
extern "C" void __stdcall FUN_00209f01(int*);
extern "C" Ref_8d480* __cdecl FUN_00266f40(int);
extern "C" void __cdecl FUN_002670b0(int,int,Ref_8d480*);
extern "C" void* __cdecl FUN_00266e00(int,hulk_intptr);
extern "C" Ref_8d480* __cdecl FUN_0026cfa0(void*,int,int,const char*);
extern "C" void __cdecl FUN_00267a50();
extern "C" void __cdecl FUN_0026da80(int);
struct Storage {
    void FUN_0008d480();
};
// (x64t9-mgr) the words of include/decls/managers.h's HulkPlatformManager: the archive, the window and the context
// are pointers
class CPlatformManager {
  public:
    virtual void* v0_0008de70(char);
    void* a;
    void* b;
    void* c;
    int d;
    int e;
    CPlatformManager();
};
HULK_MGR_SAME(CPlatformManager, HulkPlatformManager);
} // namespace fn_fe5d7f9e
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int strlen(const char*);
#endif
namespace fn_fe5d7f9e {
extern "C" int __cdecl FUN_00096600(int, const char*);
extern "C" void __cdecl FnA_002696a0();
extern "C" void __cdecl FnB_002656a0();
extern "C" void __cdecl FnC_0026ed70();
extern "C" void __cdecl FnD_00333ef0();
extern "C" int __cdecl FUN_0008ed50(int);
extern "C" char DAT_00400854[];
class CSPHulkPropLoader {
  public:
    virtual ~CSPHulkPropLoader();
    CSPHulkPropLoader* Init();
};
struct ThisCall_00290740 {
    void Initialize_00290740();
};
class pure3d_d3dToon2VertexShader_8db70 {
  public:
    virtual void vfunc_0();
    virtual bool IsEnabled();
};
class CAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(hulk_intptr a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};


// 0x0008ceb0 FUN_0008ceb0 (6 B): matches/0x0008ceb0.cpp
// sym: _FUN_0008ceb0
extern "C" HeapSet* FUN_0008ceb0() {
    return &DAT_004dd780;
}


// 0x0008ced0 FUN_0008ced0 (142 B): equivalent/0x0008ced0.cpp
// sym: ?FUN_0008ced0@SlotTable_8ced0@fn_fe5d7f9e@@QAEXHPAH000PAPBD@Z @d13a2eb5ff7c @we066369dba3a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_0008ced0 @ 0x0008ced0
void SlotTable_8ced0::FUN_0008ced0(int index, int *outCount, int *outX, int *outA, int *outB, const char **outName) {
    int slot = index;
    if (slot < 19 && slots[slot] != 0) {
        int a, b, c;
        slots[slot]->Query(&index, &c, &b, &a);
        if (outX)
            *outX = index;
        if (outA)
            *outA = a;
        if (outCount)
            *outCount = slots[slot]->GetCount();
        if (outB)
            *outB = b;
        if (outName)
            *outName = ((NameEntry_8ced0*)&DAT_00400520)[slot].name;
    }
}


// 0x0008cf60 FUN_0008cf60 (77 B): matches/0x0008cf60.cpp
// sym: ?Sum@Owner@fn_fe5d7f9e@@QAEHXZ
int Owner::Sum() {
    volatile int a;
    int b, c, d;
    int total = 0;
    int value = a;
    Item** p = items;
    for (unsigned i = 0; i < 19; i++, p++) {
        if ((int)i < 19 && *p) {
            (*p)->Get((int*)&a, &b, &c, &d);
            value = a;
        }
        total += value;
    }
    return total;
}


// 0x0008cfb0 FUN_0008cfb0 (63 B): matches/0x0008cfb0.cpp
// sym: ?run@Obj_8cfb0@fn_fe5d7f9e@@QAEHXZ
int Obj_8cfb0::run() {
    int result = 0;
    int value = 0;
    if (p) {
        int a, b, c, d;
        p->Get(&d, &a, &b, &c);
        value = d;
        result = p->Count();
    }
    return result - value;
}


// 0x0008d320 FUN_0008d320 (2 B): matches/0x0008d320.cpp
// sym: _FUN_0008d320
extern "C" void FUN_0008d320() {
    for (;;) {
    }
}

// 0x0008d330 thunk_FUN_00267090 (5 B): not yet verified
// 0x0008d340 thunk_FUN_00267090 (5 B): not yet verified

// 0x0008d350 FUN_0008d350 (36 B): matches/0x0008d350.cpp
// sym: ?Set@fn_fe5d7f9e@@YAXPAPAVObj@1@PAV21@@Z
void __cdecl Set(Obj** slot, Obj* obj) {
    if (obj)
        obj->AddRef();
    if (*slot)
        (*slot)->Release();
    *slot = obj;
}


// 0x0008d3a0 FUN_0008d3a0 (100 B): equivalent/0x0008d3a0.cpp
// sym: ?FUN_0008d3a0@Holder_8d3a0@fn_fe5d7f9e@@QAEXHH@Z @5db0f541928e @wb1695ce7944a
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 4/4)
// FUN_0008d3a0 @ 0x0008d3a0
void Holder_8d3a0::FUN_0008d3a0(int idx, int arg)
{
    Obj_8d3a0 *obj = FUN_0026cf20(((HeapDesc*)&DAT_00400520)[idx].base + ((HeapDesc*)&DAT_00400520)[idx].size, arg, ((HeapDesc*)&DAT_00400520)[idx].name);
    if (obj)
        obj->vfn0();
    if (heaps[idx])
        ((Obj_8d3a0 *)heaps[idx])->vfn1();
    heaps[idx] = obj;
    FUN_002670b0(idx, arg, obj);
}


// 0x0008d480 FUN_0008d480 (367 B): equivalent/0x0008d480.cpp
// sym: ?FUN_0008d480@Obj_8d480@fn_fe5d7f9e@@QAEXXZ @f9b44beac221 @w5f65a616dba4
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 8/8)
// FUN_0008d480 @ 0x0008d480
// FUN_0008d480 @ 0x0008d480
void Obj_8d480::FUN_0008d480() { FUN_00267280(); FUN_00266d90(); FUN_00266db0(((hulk_intptr)(void (__cdecl*)())&FUN_0008d320),0); int bounds[8]; FUN_00209f01(bounds); size=bounds[2]-bounds[3]; Ref_8d480* p=FUN_00266f40(0); if(p)p->FUN_00000000(); if(heaps[0])((Ref_8d480*)heaps[0])->FUN_00000004(); heaps[0]=p; FUN_002670b0(0,0,p); void* h=FUN_00266e00(0,0x20800); temporaryArena=h; p=FUN_0026cfa0(h,0x20800,0,"Temporary Heap"); if(p)p->FUN_00000000(); if(heaps[1])((Ref_8d480*)heaps[1])->FUN_00000004(); heaps[1]=p; FUN_002670b0(1,0,p); int ids[]={3,4,5,6,10,11,7,12,13,15,16,17,18,14,9}; for(int i=0;i<15;i++) FUN_0008d3a0(ids[i],0); DAT_0052c284=9; (*(unsigned char*)&DAT_004dd778)=1; }


// 0x0008d660 FUN_0008d660 (42 B): matches/0x0008d660.cpp
// sym: _FUN_0008d660
// data: flag_8d660 = DAT_004dd778, obj_8d660 = DAT_004dd780
extern "C" void FUN_0008d660() {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
}


// 0x0008d690 FUN_0008d690 (61 B): matches/0x0008d690.cpp
// sym: _FUN_0008d690
// data: obj = DAT_004dd780, ready = DAT_004dd778
extern "C" void* __cdecl FUN_0008d690(int x) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return FUN_00266e00(FUN_00266d90(), x);
}


// 0x0008d6d0 FUN_0008d6d0 (61 B): matches/0x0008d6d0.cpp
// sym: _FUN_0008d6d0
extern "C" void* __cdecl FUN_0008d6d0(int value) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return FUN_00266e00(FUN_00266d90(), value);
}


// 0x0008d710 FUN_0008d710 (60 B): matches/0x0008d710.cpp
// sym: _FUN_0008d710
// data: flag_8d710 = DAT_004dd778, object_8d710 = DAT_004dd780
extern "C" void* __cdecl FUN_0008d710(hulk_intptr size, int heap) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return FUN_00266e00(heap, size);
}


// 0x0008d750 FUN_0008d750 (60 B): matches/0x0008d750.cpp
// sym: _FUN_0008d750
// data: flag_8d750 = DAT_004dd778, object_8d750 = DAT_004dd780
extern "C" void* __cdecl FUN_0008d750(hulk_intptr size, int heap) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return FUN_00266e00(heap, size);
}


// 0x0008d850 FUN_0008d850 (26 B): matches/0x0008d850.cpp
// sym: ??0CPlatformManager@fn_fe5d7f9e@@QAE@XZ
CPlatformManager::CPlatformManager() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
}


// 0x0008d880 FUN_0008d880 (134 B): matches/0x0008d880.cpp
// sym: _FUN_0008d880
extern "C" bool FUN_0008d880(const char* a, const char* b) {
    if (!a)
        return false;
    if (!b)
        return false;
    int la = (int)strlen(a), lb = (int)strlen(b);
    if (la < lb)
        return false;
    return strcmp(a + la - lb, b) == 0;
}


// 0x0008da80 FUN_0008da80 (59 B): matches/0x0008da80.cpp
// sym: _FUN_0008da80@8
// data: logname = DAT_00400844, lua = DAT_003f8d4c, visual = DAT_00400848
extern "C" void __stdcall FUN_0008da80(hulk_intptr a, hulk_intptr b) {
    if (FUN_00096600(b, DAT_00400848) != 0) {
        if (FUN_00096600(b, DAT_00400844) != 0) {
            FUN_00096600(b, DAT_003f8d4c);
        }
    }
}


// 0x0008dac0 FUN_0008dac0 (3 B): matches/0x0008dac0.cpp
// sym: _FUN_0008dac0@4
extern "C" void __stdcall FUN_0008dac0(int x) {}


// 0x0008dad0 FUN_0008dad0 (3 B): matches/0x0008dad0.cpp
// sym: _FUN_0008dad0@4
extern "C" void __stdcall FUN_0008dad0(int x) {}


// 0x0008db00 FUN_0008db00 (20 B): matches/0x0008db00.cpp
// sym: _FUN_0008db00
extern "C" void __cdecl FUN_0008db00(void* /*this, unused: callers pass it (unb4)*/) {
    FnA_002696a0();
    FnB_002656a0();
    FnC_0026ed70();
    FnD_00333ef0();
}


// 0x0008db20 FUN_0008db20 (16 B): matches/0x0008db20.cpp
// sym: _FUN_0008db20@4
extern "C" int __stdcall FUN_0008db20(int x) {
    return FUN_0008ed50(x);
}


// 0x0008db30 FUN_0008db30 (18 B): matches/0x0008db30.cpp
// sym: ?Init@CSPHulkPropLoader@fn_fe5d7f9e@@QAEPAV12@XZ
CSPHulkPropLoader* CSPHulkPropLoader::Init() {
    ((ThisCall_00290740*)(this))->Initialize_00290740();
    *(void**)this = (void*)((hulk_intptr)DAT_00400854);
    return this;
}


// 0x0008db50 content::SimpleChunkHandler::vfunc_4 (4 B): matches/0x0008db50.cpp
// sym: ?FUN_0008db50@fn_fe5d7f9e@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_0008db50(void* p) {
    return *(int*)((char*)p + 8);
}


// 0x0008db60 FUN_0008db60 (12 B): matches/0x0008db60.cpp
// sym: ?FUN_0008db60@fn_fe5d7f9e@@YGXE@Z
// data: g_byte = DAT_005554a0
void __stdcall FUN_0008db60(unsigned char value) {
    (*(unsigned char*)&DAT_005554a0) = value;
}


// 0x0008db70 FUN_0008db70 (3 B): matches/0x0008db70.cpp
// sym: ?IsEnabled@pure3d_d3dToon2VertexShader_8db70@fn_fe5d7f9e@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d_d3dToon2VertexShader_8db70::IsEnabled() {
    return true;
}


// 0x0008db80 FUN_0008db80 (6 B): matches/0x0008db80.cpp
// sym: _FUN_0008db80
// Same code shape as 0x00035da0 (propagated; names are from that function)
// data: gValue_8db80 = DAT_0049ca18
extern "C" unsigned char __cdecl FUN_0008db80() {
    return (*(unsigned char*)&DAT_0049ca18);
}


// 0x0008db90 FUN_0008db90 (13 B): matches/0x0008db90.cpp
// sym: _FUN_0008db90
// data: gLoading = DAT_0049ca10
extern "C" void __cdecl FUN_0008db90() {
    FUN_001bb0b0(DAT_0049ca10);
}


// 0x0008dba0 FUN_0008dba0 (3 B): matches/0x0008dba0.cpp
// sym: ?vfunc_7@CAgent@fn_fe5d7f9e@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void CAgent::vfunc_7(hulk_intptr a) {
    (void)a;
}

} // namespace fn_fe5d7f9e
