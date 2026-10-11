// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// pure3d::VertexOffsetExpressionMixerLoader::vfunc_5 @ 0x002b16a0
void *__cdecl FUN_00263ea0(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *s);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
void __cdecl FUN_0028fcc0(const char *fmt, ...);
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace pure3d { class ExpressionGroup; class PolySkin; }

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

struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct ExprGroup;

struct ExprMixer {
    char pad0[8];
    Name name;
    char pad10[0x38 - 0x10];
    ExprMixer *FUN_002b15d0(ExprGroup *group);
};

struct SkinHolder {
    void FUN_002a9ea0(ExprMixer *mixer);
};

struct Skin {
    char pad0[0x6c];
    SkinHolder *holder;
};

class LoadContext {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned __int64 id);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
};

struct Frame {
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
    virtual void vfunc_5(ExprMixer **out, unsigned __int64 *outId, Stream *s, LoadContext *ctx);
};

void VertexOffsetExpressionMixerLoader::vfunc_5(ExprMixer **out, unsigned __int64 *outId, Stream *s, LoadContext *ctx)
{
    Frame f;
    s->reader->FUN_002647e0(&f.cell, 1, 4, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.mixerName, f.len, 1, 1);
    f.mixerName[f.len] = 0;

    s->reader->FUN_002647e0(&f.cell, 1, 4, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.skinName, f.len, 1, 1);
    f.skinName[f.len] = 0;

    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.groupName, f.len, 1, 1);
    f.groupName[f.len] = 0;

    unsigned __int64 groupId = FUN_0027b020(f.groupName);
    content::LoadInventory::DynamicCaster<pure3d::ExpressionGroup> *groupCaster =
        new (&f.cell) content::LoadInventory::DynamicCaster<pure3d::ExpressionGroup>();
    ExprGroup *group = (ExprGroup *)ctx->lookup(groupCaster, groupId);
    if (group == 0)
        FUN_0028fcc0("Warning : can't find expression group '%s' for mixer '%s'\n", f.groupName, f.mixerName);

    void *mem = FUN_00263ea0(0x38);
    ExprMixer *mixer = 0;
    if (mem)
        mixer = static_cast<ExprMixer *>(mem)->FUN_002b15d0(group);
    mixer->name.FUN_0027b040(f.mixerName);

    unsigned __int64 skinId = FUN_0027b020(f.skinName);
    content::LoadInventory::DynamicCaster<pure3d::PolySkin> *skinCaster =
        new (&f.cell) content::LoadInventory::DynamicCaster<pure3d::PolySkin>();
    Skin *skin = (Skin *)ctx->lookup(skinCaster, skinId);
    if (skin && skin->holder)
        skin->holder->FUN_002a9ea0(mixer);

    *out = mixer;
    *outId = FUN_002672f0(f.mixerName, 0);
}
