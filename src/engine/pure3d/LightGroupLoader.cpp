// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c14c0..0x002c16f0 (kind game, layer engine, confidence medium), dominant class pure3d::LightGroupLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#define TREE_TU_BEGIN namespace fn_fbf43e6a {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fbf43e6a {} using namespace fn_fbf43e6a;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fbf43e6a {
extern int gVtable_2c14c0;
class LightGroupLoader {
  public:
    hulk_intptr vf;
    int a;
    int b;
    int c;
    int d;
    LightGroupLoader();
};
class SimpleChunkHandler_2c14e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2c14e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
} // namespace fn_fbf43e6a
inline void *operator new(size_t, void *p) { return p; }
namespace fn_fbf43e6a {
namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
} }
namespace content { namespace LoadInventory {
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
} }
struct Hash64 {
    unsigned int lo;
    unsigned int hi;
};
struct Stream {
    void FUN_002647e0(void *dest, int a, int b, int c);
};
struct Reader {
    char pad0[0x284];
    Stream *stream;
};
class Factory_2c1520 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual pure3d::Light *f3(content::LoadInventory::DynamicCaster<pure3d::Light> *caster,
                              unsigned int lo, unsigned int hi);
};
namespace pure3d {
class Light {
public:
    virtual void AddRef();
};
}
struct Name_2c1520 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};
struct LightArray {
    pure3d::Light **data;
    pure3d::Light **end;
    bool FUN_002a10a0(unsigned int n, int *fill);
};
struct LightGroup {
    char pad0[8];
    Name_2c1520 name;              // 0x08
    int count;              // 0x10
    int loaded;             // 0x14
    LightArray lights;      // 0x18
    int pad20[2];
    LightGroup *FUN_002a1100();
};
void *FUN_00263ea0(unsigned int size);
namespace pure3d {
class LightGroupLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(LightGroup **out, Hash64 *id, Reader *rd, Factory_2c1520 *factory);
};
}


// 0x002c14c0 FUN_002c14c0 (27 B): matches/0x002c14c0.cpp
// sym: ??0LightGroupLoader@fn_fbf43e6a@@QAE@XZ
LightGroupLoader::LightGroupLoader() {
    a = 0;
    b = 0x2380;
    c = 0;
    d = 0;
    vf = (hulk_intptr)&gVtable_2c14c0;
}


// 0x002c14e0 pure3d::LightGroupLoader::vfunc_2 (31 B): matches/0x002c14e0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fbf43e6a@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x002c1520 pure3d::LightGroupLoader::vfunc_5 (428 B): equivalent/0x002c1520.cpp
// sym: ?vfunc_5@LightGroupLoader@pure3d@fn_fbf43e6a@@UAEXPAPAULightGroup@3@PAUHash64@3@PAUReader@3@PAVFactory_2c1520@3@@Z
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 8/8)
// pure3d::LightGroupLoader::vfunc_5 @ 0x002c1520
namespace pure3d {
void LightGroupLoader::vfunc_5(LightGroup **out, Hash64 *id, Reader *rd, Factory_2c1520 *factory)
{
    struct Frame {
        unsigned char pad10[3];
        unsigned char len;
        int n;
        LightGroup *group;
        int index;
        char caster[4];
        int pad24;
        unsigned int hashHi;
        char buf[0x100];
    } f;

    LightGroup *group;
    void *mem = FUN_00263ea0(0x28);
    if (mem)
        group = ((LightGroup *)mem)->FUN_002a1100();
    else
        group = 0;
    f.group = group;
    *out = group;

    rd->stream->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int len = f.len;
    rd->stream->FUN_002647e0(f.buf, len, 1, 1);
    f.buf[len] = 0;
    group->name.FUN_0027b040(f.buf);
    unsigned __int64 h = FUN_002672f0(f.buf, 0, 0);
    id->lo = (unsigned int)h;
    id->hi = (unsigned int)(h >> 32);

    rd->stream->FUN_002647e0(&f.n, 1, 4, 1);
    int count = f.n;
    group->count = count;
    group->loaded = count;
    f.n = 0;
    f.group->lights.FUN_002a10a0(count, &f.n);

    f.n = 0;
    f.index = 0;
    if (group->count <= 0) {
        group->loaded = 0;
        return;
    }
    do {
        rd->stream->FUN_002647e0(&f.len, 1, 1, 1);
        unsigned int l = f.len;
        rd->stream->FUN_002647e0(f.buf, l, 1, 1);
        f.buf[l] = 0;
        unsigned __int64 key = FUN_0027b020(f.buf);
        pure3d::Light **slot = &f.group->lights.data[f.index];
        f.hashHi = (unsigned int)(key >> 32);
        *slot = factory->f3(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::Light>,
                            (unsigned int)key, f.hashHi);
        pure3d::Light *light = f.group->lights.data[f.index];
        if (light) {
            f.n++;
            light->AddRef();
        }
        f.index++;
    } while (f.index < f.group->count);
    f.group->loaded = f.n;
}
}

} // namespace fn_fbf43e6a
