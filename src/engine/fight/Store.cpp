// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023c500..0x0023c670 (kind game, layer engine, confidence medium), dominant class fight::Store
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_f0d621c3 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0d621c3 {} using namespace fn_f0d621c3;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f0d621c3 {
extern "C" char DAT_0042886c[];
struct ThisCall_0023c640 {
    void BaseInit(int);
};
class Store {
  public:
    void* vptr;
};
typedef unsigned long DWORD;
typedef unsigned __int64 Key_23c530;
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual bool slot13();
 virtual Key_23c530 slot14();
 virtual void slot15();
 virtual void slot16(Key_23c530);
 virtual void slot17();
};
struct Record_23c530 { char pad[0x28]; DWORD value; };
struct Collection_23c530 { void FUN_00236ec0(); void FUN_00237160(Key_23c530, DWORD, Object*); };
namespace fight {
struct Store {
 char pad[0x18]; Collection_23c530 collection;
 void FUN_00233c50(Record_23c530*, Object*, DWORD);
 void FUN_002337c0(Record_23c530*, Object*, int);
 bool vfunc_9(Record_23c530*, Object*, DWORD);
};
}
extern void* Bank_23c5e0_vftable[];
class Bank_23c5e0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class Store_23c5e0 : public Bank_23c5e0 {
  public:
    Store_23c5e0* vfunc_5(signed char flags);
};
class Branch_23c620 {
  public:
    virtual void f();
    Branch_23c620(int);
};
class Bank : public Branch_23c620 {
  public:
    Bank();
};
class Bank_23c640 {
  public:
    virtual void f();
    Bank_23c640* construct(void*);
};
struct ThisCall_00232e90 {
    void InitRestPose(void*);
};
void __fastcall FUN_00233970(CEffectStopTrack*);


// 0x0023c500 FUN_0023c500 (20 B): matches/0x0023c500.cpp
// sym: ?target@fn_f0d621c3@@YIPAVStore@1@PAV21@@Z
Store* __fastcall target(Store* self) {
    ((ThisCall_0023c640*)(self))->BaseInit(2);
    self->vptr = (void*)((hulk_intptr)DAT_0042886c);
    return self;
}


// 0x0023c530 fight::Store::vfunc_9 (169 B): equivalent/0x0023c530.cpp
// sym: ?vfunc_9@Store@fight@fn_f0d621c3@@QAE_NPAURecord_23c530@3@PAUObject@3@K@Z
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 12/12)
// fight::Store::vfunc_9 @ 0x0023c530
namespace fight {
bool Store::vfunc_9(Record_23c530* record, Object* object, DWORD arg) {
 if (!object->slot13()) return false;
 Key_23c530 key = object->slot14();
 if ((DWORD)key != (*(DWORD*)&DAT_004e5ba8) || (DWORD)(key >> 32) != (*(DWORD*)((char*)&DAT_004e5ba8 + 4))) return false;
 object->slot16(((Key_23c530)(*(DWORD*)((char*)&DAT_004e5ba8 + 4)) << 32) | (*(DWORD*)&DAT_004e5ba8));
 FUN_00233c50(record, object, arg);
 collection.FUN_00236ec0();
 if (object->slot13()) {
  key = object->slot14();
  if ((DWORD)key == (*(DWORD*)&DAT_004e5b20) && (DWORD)(key >> 32) == (*(DWORD*)((char*)&DAT_004e5b20 + 4)))
   collection.FUN_00237160(((Key_23c530)(*(DWORD*)((char*)&DAT_004e5b20 + 4)) << 32) | (*(DWORD*)&DAT_004e5b20), record->value, object);
 }
 FUN_002337c0(record, object, -1);
 object->slot17();
 return true;
}
}


// 0x0023c5e0 fight::Store::vfunc_2 (36 B): matches/0x0023c5e0.cpp
// sym: ?vfunc_5@Store_23c5e0@fn_f0d621c3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Store_23c5e0* Store_23c5e0::vfunc_5(signed char flags) {
    *(void***)this = Bank_23c5e0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0023c620 FUN_0023c620 (20 B): matches/0x0023c620.cpp
// sym: ??0Bank@fn_f0d621c3@@QAE@XZ
Bank::Bank() : Branch_23c620(0) {}


// 0x0023c640 FUN_0023c640 (25 B): matches/0x0023c640.cpp
// sym: ?construct@Bank_23c640@fn_f0d621c3@@QAEPAV12@PAX@Z
// Same code shape as 0x0022a5d0 (propagated; names are from that function)
Bank_23c640* Bank_23c640::construct(void* arg) {
    ((ThisCall_00232e90*)(this))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}


// 0x0023c660 FUN_0023c660 (11 B): matches/0x0023c660.cpp
// sym: ?FUN_0023c660@fn_f0d621c3@@YIXPAVCEffectStopTrack@1@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_0023c660(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_00233970(self);
}

} // namespace fn_f0d621c3
