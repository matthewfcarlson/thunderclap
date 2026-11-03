// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// pure3d::VertexOffsetExpressionMixerLoader::vfunc_5 @ 0x002b16a0
#include "gen/owners.h"
void *__cdecl FUN_00263ea0(unsigned int size);
extern "C" unsigned __int64 __cdecl FUN_0027b020(const char *s);
extern "C" unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
extern "C" void __cdecl FUN_0028fcc0(const char *fmt, ...);
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace pure3d { class ExpressionGroup_2b16a0; class PolySkin_2b16a0; }

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

struct Name_2b16a0 {
    char data[8];
};

struct ExprGroup;

struct VertexOffsetExpressionMixer_2b16a0 {
    char pad0[8];
    Name_2b16a0 name;
    char pad10[0x38 - 0x10];
    VertexOffsetExpressionMixer_2b16a0 *FUN_002b15d0(ExprGroup *group);
};

struct SkinHolder_2b16a0 {
    void FUN_002a9ea0(VertexOffsetExpressionMixer_2b16a0 *mixer);
};

struct Skin_2b16a0 {
    char pad0[0x6c];
    SkinHolder_2b16a0 *holder;
};

class LoadContext_2b16a0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned __int64 id);
};

struct Reader {
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
};

struct Frame_2b16a0 {
    char pad[3];
    unsigned char len;       // 0x0f
    int cell;                // 0x10, reused as the caster object
    char mixerName[0x100];   // 0x14
    char groupName[0x100];   // 0x114
    char skinName[0x100];    // 0x214
};

class VertexOffsetExpressionMixerLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(VertexOffsetExpressionMixer_2b16a0 **out, unsigned __int64 *outId, Stream *s, LoadContext_2b16a0 *ctx);
};

void VertexOffsetExpressionMixerLoader::vfunc_5(VertexOffsetExpressionMixer_2b16a0 **out, unsigned __int64 *outId, Stream *s, LoadContext_2b16a0 *ctx)
{
    Frame_2b16a0 f;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.cell), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.mixerName), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    f.mixerName[f.len] = 0;

    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.cell), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.skinName), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    f.skinName[f.len] = 0;

    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.groupName), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    f.groupName[f.len] = 0;

    unsigned __int64 groupId = FUN_0027b020(f.groupName);
    content::LoadInventory::DynamicCaster<pure3d::ExpressionGroup_2b16a0> *groupCaster =
        new (&f.cell) content::LoadInventory::DynamicCaster<pure3d::ExpressionGroup_2b16a0>();
    ExprGroup *group = (ExprGroup *)ctx->lookup(groupCaster, groupId);
    if (group == 0)
        FUN_0028fcc0("Warning : can't find expression group '%s' for mixer '%s'\n", f.groupName, f.mixerName);

    void *mem = FUN_00263ea0(0x38);
    VertexOffsetExpressionMixer_2b16a0 *mixer = 0;
    if (mem)
        mixer = static_cast<VertexOffsetExpressionMixer_2b16a0 *>(mem)->FUN_002b15d0(group);
    ((owners::Target_27b040 *)&(mixer->name))->FUN_0027b040((hulk_uintptr)(f.mixerName));

    unsigned __int64 skinId = FUN_0027b020(f.skinName);
    content::LoadInventory::DynamicCaster<pure3d::PolySkin_2b16a0> *skinCaster =
        new (&f.cell) content::LoadInventory::DynamicCaster<pure3d::PolySkin_2b16a0>();
    Skin_2b16a0 *skin = (Skin_2b16a0 *)ctx->lookup(skinCaster, skinId);
    if (skin && skin->holder)
        skin->holder->FUN_002a9ea0(mixer);

    *out = mixer;
    *outId = FUN_002672f0(f.mixerName, 0);
}
