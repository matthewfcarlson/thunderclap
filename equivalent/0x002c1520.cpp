// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 8/8)
// pure3d::LightGroupLoader::vfunc_5 @ 0x002c1520
inline void *operator new(unsigned int, void *p) { return p; }

namespace pure3d { class Light; }

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

class Factory {
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

struct Name {
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
    Name name;              // 0x08
    int count;              // 0x10
    int loaded;             // 0x14
    LightArray lights;      // 0x18
    int pad20[2];
    LightGroup *FUN_002a1100();
};

void *FUN_00263ea0(unsigned int size);
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
unsigned __int64 __cdecl FUN_0027b020(const char *name);

namespace pure3d {

class LightGroupLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(LightGroup **out, Hash64 *id, Reader *rd, Factory *factory);
};

void LightGroupLoader::vfunc_5(LightGroup **out, Hash64 *id, Reader *rd, Factory *factory)
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
