// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024d5a0..0x0024d8e0 (kind game, layer engine, confidence high), dominant class audio::ListenerEffectXBoxType
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f8a82533 {
#define TREE_TU_END }
namespace fn_f8a82533 {} using namespace fn_f8a82533;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f8a82533 {
struct X_24d630 {
    virtual void f();
    virtual void g();
};
class MetaEntity {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual bool vfunc_4(int);
};
class ListenerEffectXBox : public MetaEntity {
    char pad[0x24];

  public:
    bool vfunc_4(int);
};
extern "C" void FUN_00241280(void*, int, int);
typedef unsigned int u32_24d690;
struct ListenerEffectXBoxType_nv_24d690 {
    void Init_002584d0(void*, void*, int, int);
};
struct Obj_24d690 {
    void* vf;
};
extern "C" char DAT_00429440[];
struct ListenerEffectXBoxType_nv_24d6b0 {
    void FUN_002584d0(void*, void*, void*, int);
};
class TypeT_24d6b0 {
  public:
    hulk_intptr m;
    TypeT_24d6b0();
};
typedef unsigned __int64 U64_24d7d0;
class FUN_0025e6c0 {
  public:
    FUN_0025e6c0(const U64_24d7d0*, const U64_24d7d0*, unsigned int, int, int);
    virtual void f();
};
class ListenerEffectXBoxType : public FUN_0025e6c0 {
  public:
    ListenerEffectXBoxType();
    virtual void f();
};
struct EffectRegistry;
} // namespace fn_f8a82533
namespace audio {
struct ListenerEffectXBox_24d840 {
    virtual void vfunc_0_00243360();
    virtual void vfunc_1_00243370();
    virtual void vfunc_2();
    virtual void vfunc_3();
    void FUN_0025e6f0(EffectRegistry*);
    void FUN_0025fb00(ListenerEffectXBox_24d840*);
};
}
namespace fn_f8a82533 {
struct EffectRegistry {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual audio::ListenerEffectXBox_24d840* vfunc_3();
};
extern "C" audio::ListenerEffectXBox_24d840* __cdecl FUN_00247530(void*);


// 0x0024d5a0 FUN_0024d5a0 (6 B): matches/0x0024d5a0.cpp
// sym: _FUN_0024d5a0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024d5a0() {
    return &(*(int*)&DAT_004e6468);
}


// 0x0024d630 FUN_0024d630 (13 B): matches/0x0024d630.cpp
// sym: _FUN_0024d630
// data: obj_24d630 = DAT_004e6468
extern "C" void FUN_0024d630() {
    ((X_24d630&)(*(void**)&DAT_004e6468)).g();
}


// 0x0024d640 audio::ListenerEffectXBox::vfunc_4 (35 B): matches/0x0024d640.cpp
// sym: ?vfunc_4@ListenerEffectXBox@fn_f8a82533@@UAE_NH@Z
bool ListenerEffectXBox::vfunc_4(int x) {
    MetaEntity::vfunc_4(x);
    FUN_00241280((char*)this + 0x28, 0, 0);
    return true;
}


// 0x0024d690 FUN_0024d690 (32 B): matches/0x0024d690.cpp
// sym: ?Target@fn_f8a82533@@YIPAUObj_24d690@1@PAU21@@Z
Obj_24d690* __fastcall Target(Obj_24d690* self) {
    ((ListenerEffectXBoxType_nv_24d690*)(((audio::ListenerEffectXBoxType*)(((audio::ListenerEffectXBoxType*)(self))))))->Init_002584d0((void*)((hulk_intptr)DAT_004e6328), (void*)((hulk_intptr)DAT_004e6320), 0x30, 4);
    self->vf = (void*)((hulk_intptr)DAT_00429434);
    return self;
}


// 0x0024d6b0 FUN_0024d6b0 (32 B): matches/0x0024d6b0.cpp
// sym: ??0TypeT_24d6b0@fn_f8a82533@@QAE@XZ
TypeT_24d6b0::TypeT_24d6b0() {
    HULK_SIZE32(OmMetaTypeAttribScalarFloat, 0x30);
    ((ListenerEffectXBoxType_nv_24d6b0*)(((audio::ListenerEffectXBoxType*)(((audio::ListenerEffectXBoxType*)this)))))->FUN_002584d0((void*)((hulk_intptr)DAT_004e6338), (void*)((hulk_intptr)DAT_004e6330), (void*)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
    m = ((hulk_intptr)DAT_00429440);
}

} // namespace fn_f8a82533

// 0x0024d720 om::MetaTypeAttrib<int>::vfunc_1 (27 B): equivalent/0x0024d720.cpp [wrapped: conflict: om::MetaTypeAttrib; om::MetaTypeAttribBase]
// sym: ?vfunc_1@MetaTypeAttrib@om@fn_0024d720@@UAEXHH@Z @6ba68da91dee @w163cf1e5e15b
namespace fn_0024d720 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// om::MetaTypeAttrib<int>::vfunc_1 @ 0x0024d720
namespace om { struct MetaTypeAttribBase { virtual void vfunc_0(); virtual void vfunc_1(int, int); virtual void vfunc_2(); virtual void vfunc_3(); char pad[16]; int* values; }; struct MetaTypeAttrib : MetaTypeAttribBase { void vfunc_1(int destination, int offset); }; }
extern "C" void __cdecl FUN_0025ab30(int, int);
void om::MetaTypeAttrib::vfunc_1(int destination, int offset) { FUN_0025ab30(destination, *(int*)((char*)values + offset)); }
} // namespace fn_0024d720


// 0x0024d740 om::MetaTypeAttrib<int>::vfunc_2 (26 B): equivalent/0x0024d740.cpp [wrapped: conflict: om::MetaTypeAttrib; om::MetaTypeAttribBase]
// sym: ?vfunc_2@?$MetaTypeAttrib@H@om@fn_0024d740@@UAEXPAXH@Z @63bbea5733ea @w732cb994973c
namespace fn_0024d740 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// om::MetaTypeAttrib<int>::vfunc_2 @ 0x0024d740
extern "C" void __cdecl FUN_0025ab50(hulk_intptr, int);
namespace om {
struct MetaTypeAttribBase {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, int);
    virtual void vfunc_3();
    char pad[0x10];
    int offset;
};
template<class T> struct MetaTypeAttrib : MetaTypeAttribBase {
    void vfunc_2(void *destination, int additionalOffset);
};
template<> void MetaTypeAttrib<int>::vfunc_2(void *destination, int additionalOffset) {
    FUN_0025ab50((hulk_intptr)destination, offset + additionalOffset);
}
}
} // namespace fn_0024d740


// 0x0024d790 om::MetaTypeAttrib<float>::vfunc_1 (27 B): equivalent/0x0024d790.cpp [wrapped: conflict: om::MetaTypeAttribBase]
// sym: ?vfunc_1@MetaTypeAttribFloat@om@fn_0024d790@@UAEHPAXH@Z @20509ecb8720 @wbea8ab986a53
namespace fn_0024d790 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// om::MetaTypeAttrib<float>::vfunc_1 @ 0x0024d790
namespace om { struct MetaTypeAttribBase { virtual void vfunc_0(); virtual int vfunc_1(void *, int); virtual void vfunc_2(); virtual void vfunc_3(); char pad[16]; char *values; }; struct MetaTypeAttribFloat : MetaTypeAttribBase { int vfunc_1(void *destination, int offset); }; }
extern "C" int __cdecl FUN_0025abf0(void *destination, unsigned int value);
int om::MetaTypeAttribFloat::vfunc_1(void *destination, int offset) { return FUN_0025abf0(destination, *(unsigned int *)(values + offset)); }
} // namespace fn_0024d790


// 0x0024d7b0 om::MetaTypeAttrib<float>::vfunc_2 (26 B): equivalent/0x0024d7b0.cpp [wrapped: conflict: om::MetaTypeAttrib; om::MetaTypeAttribBase]
// sym: ?vfunc_2@?$MetaTypeAttrib@M@om@fn_0024d7b0@@UAEHPAX0@Z @f9bf3528673c @wc3de6ea39898
namespace fn_0024d7b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// om::MetaTypeAttrib<float>::vfunc_2 @ 0x0024d7b0
namespace om {
struct MetaTypeAttribBase {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void* source, void* destination);
    virtual void vfunc_3();
    char reserved[0x10];
    char* data;
};
template <typename T> struct MetaTypeAttrib : MetaTypeAttribBase {
    virtual int vfunc_2(void* source, void* destination);
};
}
extern "C" int __cdecl FUN_0025ac10(void*, void*);
template <> int om::MetaTypeAttrib<float>::vfunc_2(void* source, void* destination) {
    return FUN_0025ac10(source, data + (hulk_uintptr)destination);
}
} // namespace fn_0024d7b0

namespace fn_f8a82533 {

// 0x0024d7d0 FUN_0024d7d0 (92 B): matches/0x0024d7d0.cpp
// sym: ??0ListenerEffectXBoxType@fn_f8a82533@@QAE@XZ
ListenerEffectXBoxType::ListenerEffectXBoxType()
    : FUN_0025e6c0(&(const U64_24d7d0&)FUN_002672f0("Data_Effect", 0, 0), &(const U64_24d7d0&)FUN_002672f0("ListenerEffectXBox", 0, 0), 0x1000100, 0x58, 8) {}


// 0x0024d830 audio::ListenerEffectXBoxType::vfunc_3 (6 B): matches/0x0024d830.cpp
// sym: _FUN_0024d830
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// the om::MetaType of an audio listener effect type (records.h)
extern "C" OmMetaType* FUN_0024d830() {
    return &DAT_004e6360;
}

} // namespace fn_f8a82533

// 0x0024d840 audio::ListenerEffectXBoxType::vfunc_2 (76 B): equivalent/0x0024d840.cpp
// sym: ?vfunc_2@ListenerEffectXBoxType@audio@@UAEPAXXZ @50b4b4d5a15c @w7a696f4cc0c7
// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 2/2)
// audio::ListenerEffectXBoxType::vfunc_2 @ 0x0024d840
void* audio::ListenerEffectXBoxType::vfunc_2() {
    ListenerEffectXBox_24d840* result = FUN_00247530(DAT_004e6468);
    if (result) {
        result->FUN_0025e6f0((EffectRegistry*)DAT_004e6468);
        ListenerEffectXBox_24d840 initial;
        *(void**)result = *(void**)&initial;
        ((EffectRegistry*)DAT_004e6468)->vfunc_3()->FUN_0025fb00(result);
    }
    return (void*)(result);
}

namespace fn_f8a82533 {

// 0x0024d890 audio::ListenerEffectXBox::vfunc_8 (6 B): matches/0x0024d890.cpp
// sym: _FUN_0024d890
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024d890() {
    return &(*(int*)&DAT_004e6468);
}

} // namespace fn_f8a82533

// 0x0024d8a0 audio::ListenerEffectXBox::vfunc_2 (35 B): matches/0x0024d8a0.cpp [wrapped: conflict: ListenerEffectXBox]
// sym: ?vfunc_2@ListenerEffectXBox@fn_0024d8a0@@UAEPAV12@H@Z
namespace fn_0024d8a0 {

class MetaEntity {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    void cleanup_00244f70();
};
class MetaEntity_24d8a0 : public MetaEntity {};
class IRefCount {};
class ListenerEffectXBox : public MetaEntity_24d8a0, public IRefCount {
  public:
    virtual void v0();
    virtual void v1();
    virtual ListenerEffectXBox* vfunc_2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};
extern "C" void __cdecl FUN_00247550(void*, void*);
ListenerEffectXBox* ListenerEffectXBox::vfunc_2(int flag) {
    cleanup_00244f70();
    if (flag & 1)
        FUN_00247550(DAT_004e6468, this);
    return this;
}
} // namespace fn_0024d8a0

