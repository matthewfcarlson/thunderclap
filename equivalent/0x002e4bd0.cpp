// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 8/8)
// FUN_002e4bd0 @ 0x002e4bd0
void *__cdecl FUN_00263ea0(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *s);
void __cdecl FUN_0028fcc0(const char *fmt, ...);
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace pure3d { class Shader; }

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

class ShaderObj {
public:
    virtual void v0();
    virtual void v1();
    ShaderObj *FUN_0028edf0(const char *name, int flags);
};

class LoadContext {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ShaderObj *lookup(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster,
                              unsigned __int64 id);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    int FUN_00266c30();
};

struct Frame {
    int scratch;             // 0x08
    char pad[3];
    unsigned char len;       // 0x0f
    char name[0x100];        // 0x10
};

class ShaderLoader {
public:
    char pad0[8];
    ShaderObj *shader;       // 0x08
    int word0c;
    int mask;                // 0x10
    int word14;
    int word18;
    int word1c;
    int word20;
    int word24;
    char FUN_002e4bd0(Stream *s, LoadContext *ctx);
};

char ShaderLoader::FUN_002e4bd0(Stream *s, LoadContext *ctx)
{
    Frame f;
    if (s->FUN_00266c30() != 0x10002)
        return 0;

    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    f.name[f.len] = 0;

    if (shader) {
        shader->v1();
        shader = 0;
    }
    unsigned __int64 id = FUN_0027b020(f.name);
    // The original reuses the scratch slot for the caster object.
    content::LoadInventory::DynamicCaster<pure3d::Shader> *caster =
        new (&f.scratch) content::LoadInventory::DynamicCaster<pure3d::Shader>();
    shader = ctx->lookup(caster, id);
    if (shader == 0) {
        FUN_0028fcc0("warning : shader \"%s\" not found during primgroup load\n", f.name);
        void *mem = FUN_00263ea0(0x20);
        ShaderObj *err = 0;
        if (mem)
            err = static_cast<ShaderObj *>(mem)->FUN_0028edf0("error", 0);
        shader = err;
    }
    shader->v0();

    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word0c = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word14 = mask & f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word18 = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word1c = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word20 = f.scratch;
    word14 |= 0x2000;
    return 1;
}
