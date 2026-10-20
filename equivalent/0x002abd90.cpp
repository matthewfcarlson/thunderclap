// STATUS: equivalent (tools/equiv.py level 3: 15652 inputs, branch coverage 18/18)
// FUN_002abd90 @ 0x002abd90
#include "decls/data/engine/content.h"
#include "gen/pure3d.h"

struct Stream_2abd90 {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};

struct Reader_2abd90 {
    char pad0[0x284];
    Stream_2abd90 *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class AnimObj {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0x28 - 4];
    int count;
    void *FUN_00288a10(int index);
};

struct GeneratorBlendState_nv_2abd90 {
    ::pure3d::ParticlePlaneGenerator::GeneratorBlendState *FUN_002d2570(void *channels);
};

struct ElemArray_2abd90 {
    ::pure3d::ParticlePlaneGenerator::GeneratorBlendState **data;
    char pad[8];
    bool FUN_002ab9a0(unsigned int count, int *init);
};

class Generator_2abd90 {
public:
    virtual void v0();
    char pad04[0x1c - 4];
    int used;
    char pad20[0x28 - 0x20];
    AnimObj *anim;
    ElemArray_2abd90 array;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    char pad4c[0x60 - 0x4c];
    Generator_2abd90 *FUN_002d3930();
};

namespace content {
class ObjectLoader_2abd90 {
public:
    virtual void v0();
};
}

namespace pure3d {
class AnimationLoader_2abd90 : public content::ObjectLoader_2abd90 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned __int64 v5(AnimObj **out, unsigned __int64 *hash, Reader_2abd90 *r, int flag);
    int FUN_00288e90();
    void FUN_00288e80(int value);
};
}

struct Registry_2abd90 {
    content::ObjectLoader_2abd90 *FUN_00265310(int key);
};


void *FUN_00263ea0(unsigned int size);
void *FUN_0008d690(unsigned int size);

Generator_2abd90 * __stdcall FUN_002abd90(Reader_2abd90 *r, int flag)
{
    struct Frame {
        AnimObj *obj;
        int b;
        int d;
        int a;
        unsigned __int64 hash;
    } fr;

    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    void *mem = FUN_00263ea0(0x60);
    Generator_2abd90 *g = 0;
    if (mem)
        g = ((Generator_2abd90 *)mem)->FUN_002d3930();
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f38 = fr.b;
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f3c = fr.b;
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f40 = fr.b;
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f44 = fr.b;
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f48 = fr.b;

    if (r->FUN_002669f0()) {
        do {
            int id = r->FUN_00266a30();
            if (id == 0x121000) {
                pure3d::AnimationLoader_2abd90 *al = dynamic_cast<pure3d::AnimationLoader_2abd90 *>((*(Registry_2abd90**)&DAT_00527c58)->FUN_00265310(id));
                al->v0();
                fr.a = al->FUN_00288e90();
                al->FUN_00288e80(1);
                al->v5(&fr.obj, &fr.hash, r, flag);
                AnimObj *o = fr.obj;
                if (o != 0) {
                    o->v0();
                    if (g->anim != 0)
                        g->anim->v1();
                    g->anim = o;
                    fr.b = fr.obj->count;
                    fr.d = 0;
                    g->array.FUN_002ab9a0(fr.b, &fr.d);
                    for (int i = 0; i < fr.b; i++) {
                        ::pure3d::ParticlePlaneGenerator::GeneratorBlendState *e = (::pure3d::ParticlePlaneGenerator::GeneratorBlendState *)FUN_0008d690(0x1c);
                        if (e != 0)
                            e = ((GeneratorBlendState_nv_2abd90*)(e))->FUN_002d2570(fr.obj->FUN_00288a10(i));
                        g->array.data[g->used] = e;
                        g->array.data[g->used]->vfunc_0();
                        g->used++;
                    }
                }
                al->FUN_00288e80(fr.a);
                al->v1();
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    return g;
}
