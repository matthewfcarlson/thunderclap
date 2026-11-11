// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024dce0..0x0024e520 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "gen/om.h"
#define TREE_TU_BEGIN namespace fn_fb3c10a1 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fb3c10a1 {} using namespace fn_fb3c10a1;
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
struct TypeT_24de80 {
    char pad[0x48];
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
template <> unsigned int om::MetaTypeAttribScalar<int>::vfunc_4() {
    return this->f_28;
}


// 0x0024dde0 om::MetaTypeAttribScalar<int>::vfunc_5 (4 B): matches/0x0024dde0.cpp
// sym: ?vfunc_5@?$MetaTypeAttribScalar@H@om@@UAEIXZ
// Same code shape as 0x000862b0 (propagated; names are from that function)
template <> unsigned int om::MetaTypeAttribScalar<int>::vfunc_5() {
    return *(unsigned int*)((char*)this + 0x2c);
}


// 0x0024ddf0 om::MetaTypeAttribScalar<int>::vfunc_3 (16 B): matches/0x0024ddf0.cpp
// sym: ?vfunc_3@?$MetaTypeAttribScalar@H@om@@UAEXH@Z
template <> void om::MetaTypeAttribScalar<int>::vfunc_3(hulk_intptr p) {
    *(int*)((char*)p + this->f_14) = this->f_24;
}


// 0x0024de50 om::MetaTypeAttribScalar<float>::vfunc_4 (4 B): matches/0x0024de50.cpp
// sym: ?vfunc_4@?$MetaTypeAttribScalar@H@om@@UAEIXZ
// Same code shape as 0x000862a0 (propagated; names are from that function)
template <> unsigned int om::MetaTypeAttribScalar<float>::vfunc_4() {
    return this->f_28;
}


// 0x0024de60 om::MetaTypeAttribScalar<float>::vfunc_5 (4 B): matches/0x0024de60.cpp
// sym: ?vfunc_5@?$MetaTypeAttribScalar@H@om@@UAEIXZ
// Same code shape as 0x000862b0 (propagated; names are from that function)
template <> unsigned int om::MetaTypeAttribScalar<float>::vfunc_5() {
    return *(unsigned int*)((char*)this + 0x2c);
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
extern "C++" { extern void* g_BaseVftable; }

struct TypeT_24dec0 {
    char pad[0x48];
    void* Build_0024d6b0();
    void Destroy_002580e0();
};

MetaTypeAttribScalar* MetaTypeAttribScalar::vfunc_0(unsigned char flags) {
    *(void**)this = &g_BaseVftable;
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


namespace om {
class __declspec(novtable) TypeBase {
  public:
    virtual void v0();
    virtual void v1();
    unsigned int reserved04; // records.h OmType
    OmTypeBody body;
    void FUN_002580e0();
    void FUN_002584d0(const void* a, const void* b, int size, int align);
    TypeBase(const void* a, const void* b, int size, int align) { FUN_002584d0(a, b, size, align); }
};
template <class T> class TypeT : public TypeBase {
  public:
    TypeT(const void* a, const void* b, int size, int align) : TypeBase(a, b, size, align) {}
    virtual void v0();
    virtual void v1();
};
class __declspec(novtable) AttribBase {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad04[0x18];
    void FUN_0025fba0(const void* reg, const char* name, int offset);
    AttribBase(const void* reg, const char* name, int offset) { FUN_0025fba0(reg, name, offset); }
};
template <class T> class MetaTypeAttribScalar : public AttribBase {
  public:
    MetaTypeAttribScalar(const void* reg, const char* name, int offset, T mn, T def, T cur, const char* label,
                         const float* limit)
        : AttribBase(reg, name, offset) {
        lo = mn;
        value = def;
        hi = cur;
        this->label = label;
        this->limit = limit;
    }
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    T lo;
    T value;
    T hi;
    const char* label;
    const float* limit;
};
} // namespace om
struct Registry_24df00 {
    virtual void v0();
};
extern void* __cdecl FUN_00247530(om::TypeBase* temp);
extern "C" void FUN_0024df00() {
    HULK_SIZE32(om::MetaTypeAttribScalar<int>, 0x30);
    HULK_SIZE32(om::MetaTypeAttribScalar<float>, 0x30);
    {
        om::TypeT<om::MetaTypeAttribScalar<int> > temp(((unsigned int*)&DAT_004e6328),
                                                       ((unsigned int*)&DAT_004e6320), (int)sizeof(om::MetaTypeAttribScalar<int>), (int)__alignof(om::MetaTypeAttribScalar<int>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<int>(((char*)&DAT_004e6360), "mHalListenerEffect.room", 0x28,
                                                  -10000, 0, -10000, "Room", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<int> > temp(((unsigned int*)&DAT_004e6328),
                                                       ((unsigned int*)&DAT_004e6320), (int)sizeof(om::MetaTypeAttribScalar<int>), (int)__alignof(om::MetaTypeAttribScalar<int>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<int>(((char*)&DAT_004e6360), "mHalListenerEffect.roomHF", 0x2c,
                                                  -10000, 0, -10000, "Room High Frequency", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338),
                                                         ((unsigned int*)&DAT_004e6330), (int)sizeof(om::MetaTypeAttribScalar<float>), (int)__alignof(om::MetaTypeAttribScalar<float>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)&DAT_004e6360),
                                                    "mHalListenerEffect.roomRolloffFactor", 0x30, 0.0f, 10.0f,
                                                    0.0f, "Room Roll Off Factor", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338),
                                                         ((unsigned int*)&DAT_004e6330), (int)sizeof(om::MetaTypeAttribScalar<float>), (int)__alignof(om::MetaTypeAttribScalar<float>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)&DAT_004e6360), "mHalListenerEffect.decayTime",
                                                    0x34, 0.1f, 20.0f, 0.1f, "Decay Time", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338),
                                                         ((unsigned int*)&DAT_004e6330), (int)sizeof(om::MetaTypeAttribScalar<float>), (int)__alignof(om::MetaTypeAttribScalar<float>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)&DAT_004e6360), "mHalListenerEffect.decayHFRatio",
                                                    0x38, 0.1f, 2.0f, 0.1f, "Decay HF Ratio", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<int> > temp(((unsigned int*)&DAT_004e6328),
                                                       ((unsigned int*)&DAT_004e6320), (int)sizeof(om::MetaTypeAttribScalar<int>), (int)__alignof(om::MetaTypeAttribScalar<int>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<int>(((char*)&DAT_004e6360), "mHalListenerEffect.reflections",
                                                  0x3c, -10000, 1000, -10000, "Reflections", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338),
                                                         ((unsigned int*)&DAT_004e6330), (int)sizeof(om::MetaTypeAttribScalar<float>), (int)__alignof(om::MetaTypeAttribScalar<float>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p)
                om::MetaTypeAttribScalar<float>(((char*)&DAT_004e6360), "mHalListenerEffect.reflectionsDelay",
                                                0x40, 0.0f, 0.3f, 0.0f, "Reflections Delay", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<int> > temp(((unsigned int*)&DAT_004e6328),
                                                       ((unsigned int*)&DAT_004e6320), (int)sizeof(om::MetaTypeAttribScalar<int>), (int)__alignof(om::MetaTypeAttribScalar<int>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<int>(((char*)&DAT_004e6360), "mHalListenerEffect.reverb", 0x44,
                                                  -10000, 2000, -10000, "Reverb", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338),
                                                         ((unsigned int*)&DAT_004e6330), (int)sizeof(om::MetaTypeAttribScalar<float>), (int)__alignof(om::MetaTypeAttribScalar<float>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)&DAT_004e6360), "mHalListenerEffect.reverbDelay",
                                                    0x48, 0.0f, 0.1f, 0.0f, "Reverb Delay", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338),
                                                         ((unsigned int*)&DAT_004e6330), (int)sizeof(om::MetaTypeAttribScalar<float>), (int)__alignof(om::MetaTypeAttribScalar<float>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)&DAT_004e6360), "mHalListenerEffect.diffusion",
                                                    0x4c, 0.0f, 100.0f, 0.0f, "Diffusion", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338),
                                                         ((unsigned int*)&DAT_004e6330), (int)sizeof(om::MetaTypeAttribScalar<float>), (int)__alignof(om::MetaTypeAttribScalar<float>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)&DAT_004e6360), "mHalListenerEffect.density",
                                                    0x50, 0.0f, 100.0f, 0.0f, "Density", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338),
                                                         ((unsigned int*)&DAT_004e6330), (int)sizeof(om::MetaTypeAttribScalar<float>), (int)__alignof(om::MetaTypeAttribScalar<float>));
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p)
                om::MetaTypeAttribScalar<float>(((char*)&DAT_004e6360), "mHalListenerEffect.hFReference",
                                                0x54, 20.0f, 20000.0f, 20.0f, "HF Reference", &DAT_003f335c);
    }
    Registry_24df00* reg = ((Registry_24df00*)&DAT_004e6468);
    reg->v0();
}
} // namespace fn_0024df00


// 0x0024e440 om::MetaTypeAttrib<int>::vfunc_0 (31 B): matches/0x0024e440.cpp
// sym: ?f2@NonCopyable_24e440@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_24e440* pure3d::NonCopyable_24e440::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
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
    *(void**)this = refcount_vftable;
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
    Type_24e4c0(void*, void*, int, int) throw();
    unsigned int reserved04;  // records.h OmType
    OmTypeBody body;
};
class TypeT_24e4c0 : public Type_24e4c0 {
  public:
    virtual void vf();
    TypeT_24e4c0() throw() : Type_24e4c0(&hulk_at_004e6358, ((char*)&DAT_004e6350), 0x1c, 4) {}
    ~TypeT_24e4c0() throw();
};
extern void process_00247550(TypeT_24e4c0*, void*) throw();
extern "C" void FUN_0024e4c0(void* p) {
    TypeT_24e4c0 t;
    process_00247550(&t, p);
}
} // namespace fn_0024e4c0

