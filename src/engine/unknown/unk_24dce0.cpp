// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024dce0..0x0024e520 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/listener_effect.h"   // (recs1, D144)
#include "gen/om.h"
#define TREE_TU_BEGIN namespace fn_fb3c10a1 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fb3c10a1 {} using namespace fn_fb3c10a1;
namespace fn_fb3c10a1 { extern "C" char DAT_00429420[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fb3c10a1 {
struct Helper_24dce0 {
    void init_002584d0(void*, void*, int, int);
    void fini_002580e0();
};
extern int __cdecl F247530_00247530(void*);
struct MetaTypeAttribScalar {
    void* vftable;
    MetaTypeAttribScalar* vfunc_0(unsigned char flags);
};
extern "C" void __cdecl FUN_00247550(void*, void*);
extern "C" void* hulk_at_00429420;
struct TypeT_24de80 : OmType {   // (recs1) an om::Type on its record (was char pad[0x48], the 32-bit size)
    void* Build_0024d690();
    void Destroy_002580e0();
};
class MetaTypeAttribBase_24e440 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
} // namespace fn_fb3c10a1
namespace pure3d {
class NonCopyable_24e440 : public MetaTypeAttribBase_24e440 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_24e440* f2(unsigned char);
};
}
namespace fn_fb3c10a1 {
void FUN_0024e460(pure3d::NonCopyable_24e440*);
class MetaTypeAttribBase_24e4a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
} // namespace fn_fb3c10a1
namespace pure3d {
class NonCopyable_24e4a0 : public MetaTypeAttribBase_24e4a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_24e4a0* f2(unsigned char);
};
}
namespace fn_fb3c10a1 {
void FUN_0024e4c0(pure3d::NonCopyable_24e4a0*);


// 0x0024dce0 FUN_0024dce0 (66 B): matches/0x0024dce0.cpp
// sym: ?target@fn_fb3c10a1@@YAHXZ
int __cdecl target() {
    char local[sizeof(OmType)];  // an om::Type (records.h)
    ((Helper_24dce0*)local)->init_002584d0((void*)((hulk_intptr)DAT_004e6328), (void*)((hulk_intptr)DAT_004e6320), 0x30, 4);
    *(void**)local = (void*)((hulk_intptr)DAT_00429434);
    int result = F247530_00247530(local);
    ((Helper_24dce0*)local)->fini_002580e0();
    return result;
}

} // namespace fn_fb3c10a1

// 0x0024dd30 FUN_0024dd30 (66 B): matches/0x0024dd30.cpp [wrapped: conflict: target]
// sym: ?target@fn_0024dd30@@YAPAXXZ
namespace fn_0024dd30 {

extern char DAT_00429440[];
struct Obj_24dd30 {
    void* vptr;
    char d[sizeof(OmType) - sizeof(void*)];  // the rest of an om::Type (records.h)
    void Init_002584d0(char*, char*, int, int);
    void Finish_002580e0();
};
extern void* FUN_00247530(void*);
void* target() {
    Obj_24dd30 o;
    o.Init_002584d0(DAT_004e6338, DAT_004e6330, 0x30, 4);
    o.vptr = DAT_00429440;
    void* p = FUN_00247530(&o);
    o.Finish_002580e0();
    return p;
}
} // namespace fn_0024dd30


// 0x0024ddd0 om::MetaTypeAttribScalar<int>::vfunc_4 (4 B): matches/0x0024ddd0.cpp
// sym: ?vfunc_4@?$MetaTypeAttribScalar@H@om@@UAEIXZ
// Same code shape as 0x000862a0 (propagated; names are from that function)
template <> hulk_uintptr om::MetaTypeAttribScalar<int>::vfunc_4() {
    return (hulk_uintptr)this->f_28;
}


// 0x0024dde0 om::MetaTypeAttribScalar<int>::vfunc_5 (4 B): matches/0x0024dde0.cpp
// sym: ?vfunc_5@?$MetaTypeAttribScalar@H@om@@UAEIXZ
// Same code shape as 0x000862b0 (propagated; names are from that function)
template <> hulk_uintptr om::MetaTypeAttribScalar<int>::vfunc_5() {
    return (hulk_uintptr)this->f_2c;   // (recs1) the limit on gen's words (was a 32-bit offset)
}


// 0x0024ddf0 om::MetaTypeAttribScalar<int>::vfunc_3 (16 B): matches/0x0024ddf0.cpp
// sym: ?vfunc_3@?$MetaTypeAttribScalar@H@om@@UAEXH@Z
template <> void om::MetaTypeAttribScalar<int>::vfunc_3(hulk_intptr p) {
    *(int*)((char*)p + this->f_14) = this->f_24;
}


// 0x0024de50 om::MetaTypeAttribScalar<float>::vfunc_4 (4 B): matches/0x0024de50.cpp
// sym: ?vfunc_4@?$MetaTypeAttribScalar@H@om@@UAEIXZ
// Same code shape as 0x000862a0 (propagated; names are from that function)
template <> hulk_uintptr om::MetaTypeAttribScalar<float>::vfunc_4() {
    return (hulk_uintptr)this->f_28;
}


// 0x0024de60 om::MetaTypeAttribScalar<float>::vfunc_5 (4 B): matches/0x0024de60.cpp
// sym: ?vfunc_5@?$MetaTypeAttribScalar@H@om@@UAEIXZ
// Same code shape as 0x000862b0 (propagated; names are from that function)
template <> hulk_uintptr om::MetaTypeAttribScalar<float>::vfunc_5() {
    return (hulk_uintptr)this->f_2c;   // (recs1) the limit on gen's words (was a 32-bit offset)
}


// 0x0024de70 om::MetaTypeAttribScalar<float>::vfunc_3 (16 B): matches/0x0024de70.cpp
// sym: ?vfunc_3@?$MetaTypeAttribScalar@H@om@@UAEXH@Z
// Same code shape as 0x0024ddf0 (propagated; names are from that function)
template <> void om::MetaTypeAttribScalar<float>::vfunc_3(hulk_intptr p) {
    *(int*)((char*)p + this->f_14) = this->f_24;
}

namespace fn_fb3c10a1 {

// 0x0024de80 om::MetaTypeAttribScalar<int>::vfunc_0 (57 B): matches/0x0024de80.cpp
// sym: ?vfunc_0@MetaTypeAttribScalar@fn_fb3c10a1@@QAEPAU12@E@Z
MetaTypeAttribScalar* MetaTypeAttribScalar::vfunc_0(unsigned char flags) {
    *(void**)this = &hulk_at_00429420;
    if (flags & 1) {
        TypeT_24de80 buf;
        FUN_00247550(buf.Build_0024d690(), this);
        buf.Destroy_002580e0();
    }
    return this;
}

} // namespace fn_fb3c10a1

// 0x0024dec0 om::MetaTypeAttribScalar<float>::vfunc_0 (57 B): matches/0x0024dec0.cpp [wrapped: same definition as 0x0024de80 in this TU]
// sym: ?vfunc_0@MetaTypeAttribScalar@fn_0024dec0@@QAEPAU12@E@Z
namespace fn_0024dec0 {
// Same code shape as 0x0024de80 (propagated; names are from that function)
struct MetaTypeAttribScalar {
    void* vftable;
    MetaTypeAttribScalar* vfunc_0(unsigned char flags);
};

extern "C" void __cdecl FUN_00247550(void*, void*);
extern "C" char DAT_00429420[];   // (decl1) was `void* g_BaseVftable` (a C++ name bound nowhere natively)

struct TypeT_24dec0 : OmType {   // (recs1) an om::Type on its record (was char pad[0x48], the 32-bit size)
    void* Build_0024d6b0();
    void Destroy_002580e0();
};

MetaTypeAttribScalar* MetaTypeAttribScalar::vfunc_0(unsigned char flags) {
    *(void**)this = &(*(void**)&DAT_00429420);
    if (flags & 1) {
        TypeT_24dec0 buf;
        FUN_00247550(buf.Build_0024d6b0(), this);
        buf.Destroy_002580e0();
    }
    return this;
}
} // namespace fn_0024dec0


// 0x0024df00 FUN_0024df00 (1334 B): matches/0x0024df00.cpp [wrapped: conflict: om::MetaTypeAttribScalar; om::TypeT]
// sym: _FUN_0024df00
inline void* operator new(size_t, void* p) throw() {
    return p;
}
namespace fn_0024df00 {
// FUN_0024df00 @ 0x0024df00
// (recs1, D144) the listener effect's twelve scalar attributes on their records (records.h OmMetaTypeAttribScalarInt /
// Float; decls/listener_effect.h): each built in the pool of its om::TypeT (a temporary om::Type, OmType, holding the
// TypeT's vftable 0x00429434 / 0x00429440), then om::MetaTypeAttribBase's constructor 0x0025fba0 (the meta type
// 0x004e6360, the name, the member's offset: offsetof() on AudioListenerEffectXBox, natively further in than the
// 32-bit 0x28 .. 0x54) and the scalar's vftable 0x00429610 / 0x0042962c by address. Were local polymorphic stand-ins
// (clang's own vftables natively) with 32-bit offsets.
extern "C" char DAT_00429434[], DAT_00429440[], DAT_00429610[], DAT_0042962c[];
struct TypeTemp_24df00 : OmType {
    void FUN_002580e0();
    void FUN_002584d0(const void* a, const void* b, int size, int align);
};
struct Attrib_24df00 : OmMetaTypeAttribBase {
    void FUN_0025fba0(const void* reg, const char* name, hulk_intptr offset);   // (decl1) passes as defined
};
struct Registry_24df00 {
    virtual void v0();
};
extern void* __cdecl FUN_00247530(OmType* temp);
extern "C" void FUN_0024df00() {
    HULK_SIZE32(OmMetaTypeAttribScalarInt, 0x30);
    HULK_SIZE32(OmMetaTypeAttribScalarFloat, 0x30);
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6328), ((unsigned int*)&DAT_004e6320), (int)sizeof(OmMetaTypeAttribScalarInt), (int)__alignof(OmMetaTypeAttribScalarInt));
        temp.vftable = DAT_00429434;
        OmMetaTypeAttribScalarInt* p = (OmMetaTypeAttribScalarInt*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.room", HULK_LFX_AT(hal.room));
            p->base.vftable = DAT_00429610;
            p->minimum = -10000;
            p->defaultValue = 0;
            p->current = -10000;
            p->label = "Room";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6328), ((unsigned int*)&DAT_004e6320), (int)sizeof(OmMetaTypeAttribScalarInt), (int)__alignof(OmMetaTypeAttribScalarInt));
        temp.vftable = DAT_00429434;
        OmMetaTypeAttribScalarInt* p = (OmMetaTypeAttribScalarInt*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.roomHF", HULK_LFX_AT(hal.roomHF));
            p->base.vftable = DAT_00429610;
            p->minimum = -10000;
            p->defaultValue = 0;
            p->current = -10000;
            p->label = "Room High Frequency";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), (int)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
        temp.vftable = DAT_00429440;
        OmMetaTypeAttribScalarFloat* p = (OmMetaTypeAttribScalarFloat*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.roomRolloffFactor", HULK_LFX_AT(hal.roomRolloffFactor));
            p->base.vftable = DAT_0042962c;
            p->minimum = 0.0f;
            p->defaultValue = 10.0f;
            p->current = 0.0f;
            p->label = "Room Roll Off Factor";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), (int)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
        temp.vftable = DAT_00429440;
        OmMetaTypeAttribScalarFloat* p = (OmMetaTypeAttribScalarFloat*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.decayTime", HULK_LFX_AT(hal.decayTime));
            p->base.vftable = DAT_0042962c;
            p->minimum = 0.1f;
            p->defaultValue = 20.0f;
            p->current = 0.1f;
            p->label = "Decay Time";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), (int)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
        temp.vftable = DAT_00429440;
        OmMetaTypeAttribScalarFloat* p = (OmMetaTypeAttribScalarFloat*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.decayHFRatio", HULK_LFX_AT(hal.decayHFRatio));
            p->base.vftable = DAT_0042962c;
            p->minimum = 0.1f;
            p->defaultValue = 2.0f;
            p->current = 0.1f;
            p->label = "Decay HF Ratio";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6328), ((unsigned int*)&DAT_004e6320), (int)sizeof(OmMetaTypeAttribScalarInt), (int)__alignof(OmMetaTypeAttribScalarInt));
        temp.vftable = DAT_00429434;
        OmMetaTypeAttribScalarInt* p = (OmMetaTypeAttribScalarInt*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.reflections", HULK_LFX_AT(hal.reflections));
            p->base.vftable = DAT_00429610;
            p->minimum = -10000;
            p->defaultValue = 1000;
            p->current = -10000;
            p->label = "Reflections";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), (int)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
        temp.vftable = DAT_00429440;
        OmMetaTypeAttribScalarFloat* p = (OmMetaTypeAttribScalarFloat*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.reflectionsDelay", HULK_LFX_AT(hal.reflectionsDelay));
            p->base.vftable = DAT_0042962c;
            p->minimum = 0.0f;
            p->defaultValue = 0.3f;
            p->current = 0.0f;
            p->label = "Reflections Delay";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6328), ((unsigned int*)&DAT_004e6320), (int)sizeof(OmMetaTypeAttribScalarInt), (int)__alignof(OmMetaTypeAttribScalarInt));
        temp.vftable = DAT_00429434;
        OmMetaTypeAttribScalarInt* p = (OmMetaTypeAttribScalarInt*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.reverb", HULK_LFX_AT(hal.reverb));
            p->base.vftable = DAT_00429610;
            p->minimum = -10000;
            p->defaultValue = 2000;
            p->current = -10000;
            p->label = "Reverb";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), (int)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
        temp.vftable = DAT_00429440;
        OmMetaTypeAttribScalarFloat* p = (OmMetaTypeAttribScalarFloat*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.reverbDelay", HULK_LFX_AT(hal.reverbDelay));
            p->base.vftable = DAT_0042962c;
            p->minimum = 0.0f;
            p->defaultValue = 0.1f;
            p->current = 0.0f;
            p->label = "Reverb Delay";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), (int)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
        temp.vftable = DAT_00429440;
        OmMetaTypeAttribScalarFloat* p = (OmMetaTypeAttribScalarFloat*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.diffusion", HULK_LFX_AT(hal.diffusion));
            p->base.vftable = DAT_0042962c;
            p->minimum = 0.0f;
            p->defaultValue = 100.0f;
            p->current = 0.0f;
            p->label = "Diffusion";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), (int)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
        temp.vftable = DAT_00429440;
        OmMetaTypeAttribScalarFloat* p = (OmMetaTypeAttribScalarFloat*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.density", HULK_LFX_AT(hal.density));
            p->base.vftable = DAT_0042962c;
            p->minimum = 0.0f;
            p->defaultValue = 100.0f;
            p->current = 0.0f;
            p->label = "Density";
            p->limit = &DAT_003f335c;
        }
    }
    {
        TypeTemp_24df00 temp;
        temp.FUN_002584d0(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), (int)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
        temp.vftable = DAT_00429440;
        OmMetaTypeAttribScalarFloat* p = (OmMetaTypeAttribScalarFloat*)FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p) {
            ((Attrib_24df00*)p)->FUN_0025fba0(((char*)&DAT_004e6360), "mHalListenerEffect.hFReference", HULK_LFX_AT(hal.hfReference));
            p->base.vftable = DAT_0042962c;
            p->minimum = 20.0f;
            p->defaultValue = 20000.0f;
            p->current = 20.0f;
            p->label = "HF Reference";
            p->limit = &DAT_003f335c;
        }
    }
    Registry_24df00* reg = ((Registry_24df00*)&DAT_004e6468);
    reg->v0();
}
} // namespace fn_0024df00


// 0x0024e440 om::MetaTypeAttrib<int>::vfunc_0 (31 B): matches/0x0024e440.cpp
// sym: ?f2@NonCopyable_24e440@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_24e440* pure3d::NonCopyable_24e440::f2(unsigned char param) {
    *(void**)this = (void**)DAT_00429420;
    if ((param & 1) != 0)
        FUN_0024e460(this);
    return this;
}


// 0x0024e460 FUN_0024e460 (64 B): matches/0x0024e460.cpp [wrapped: conflict: FUN_0024e460]
// sym: _FUN_0024e460
namespace fn_0024e460 {

extern "C" char DAT_0042986c[];
typedef unsigned int u32_24e460;
extern char hulk_at_004e6348;
struct A_24e460 {
    void Init_002584d0(void*, void*, int, int);
};
extern void Work_00247550(void*, u32_24e460);
struct C_24e460 {
    void End_002580e0();
};
extern "C" void FUN_0024e460(u32_24e460 value) {
    char local[sizeof(OmType)];  // an om::Type (records.h)
    ((A_24e460*)local)->Init_002584d0(&hulk_at_004e6348, ((char*)&DAT_004e6340), 0x1c, 4);
    *(void**)local = (void*)((hulk_intptr)DAT_0042986c);
    Work_00247550(local, value);
    ((C_24e460*)local)->End_002580e0();
}
} // namespace fn_0024e460


// 0x0024e4a0 om::MetaTypeAttrib<float>::vfunc_0 (31 B): matches/0x0024e4a0.cpp
// sym: ?f2@NonCopyable_24e4a0@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_24e4a0* pure3d::NonCopyable_24e4a0::f2(unsigned char param) {
    *(void**)this = (void**)DAT_00429420;
    if ((param & 1) != 0)
        FUN_0024e4c0(this);
    return this;
}


// 0x0024e4c0 FUN_0024e4c0 (64 B): matches/0x0024e4c0.cpp [wrapped: conflict: FUN_0024e4c0]
// sym: _FUN_0024e4c0
namespace fn_0024e4c0 {

extern char hulk_at_004e6358;
class Type_24e4c0 {
  public:
    virtual void vf();
    Type_24e4c0(void*, void*, int, int);
    unsigned int reserved04;  // records.h OmType
    OmTypeBody body;
};
class TypeT_24e4c0 : public Type_24e4c0 {
  public:
    virtual void vf();
    TypeT_24e4c0() : Type_24e4c0(&hulk_at_004e6358, ((char*)&DAT_004e6350), 0x1c, 4) {}
    ~TypeT_24e4c0();
};
extern void process_00247550(TypeT_24e4c0*, void*);
extern "C" void FUN_0024e4c0(void* p) {
    TypeT_24e4c0 t;
    process_00247550(&t, p);
}
} // namespace fn_0024e4c0

