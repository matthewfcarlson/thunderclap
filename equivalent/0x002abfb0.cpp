// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 16/18, incomplete)
// FUN_002abfb0 @ 0x002abfb0
#include "decls/data/engine/content.h"
#include "gen/pure3d.h"

void* FUN_00263ea0(unsigned int size);
void* FUN_0008d690(unsigned int size);

struct Stream_2abfb0 {
    char pad[0xc];
    char FUN_002647e0(void* dst, int a, int size, int b);
};

struct Source_2abfb0;
struct Reader_2abfb0 {
    char pad000[0x284];
    Stream_2abfb0* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Item_2abfb0 {
};

class Releasable_2abfb0 {
public:
    virtual void AddRef();
    virtual void Release();
};

namespace content {
class ObjectLoader_2abfb0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Load(Source_2abfb0** out0, unsigned int* out1, Reader_2abfb0* r, void* arg);
};
}

namespace pure3d {
class AnimationLoader_2abfb0 : public content::ObjectLoader_2abfb0 {
public:
    int FUN_00288e90();
    void FUN_00288e80(int v);
};
}

struct Registry_2abfb0 {
    content::ObjectLoader_2abfb0* FUN_00265310(int id);
};


struct GeneratorBlendState_nv_2abfb0 {
    ::pure3d::ParticleSphereGenerator::GeneratorBlendState* FUN_002d2bd0(Item_2abfb0* item);
};

struct Source_2abfb0 : public Releasable_2abfb0 {
    char pad04[0x24];
    int count;
    Item_2abfb0** items;
    Item_2abfb0* FUN_00288a10(int index);
};

struct ElementList_2abfb0 {
    ::pure3d::ParticleSphereGenerator::GeneratorBlendState** begin;
    ::pure3d::ParticleSphereGenerator::GeneratorBlendState** end;
    char FUN_002aba00(unsigned int n, ::pure3d::ParticleSphereGenerator::GeneratorBlendState* const* fill);
};

class Generator_2abfb0 {
public:
    virtual void v0();
    char pad04[0x18];
    int used;
    char pad20[8];
    Releasable_2abfb0* source;
    ElementList_2abfb0 elements;
    char pad34[4];
    unsigned int dim0;
    unsigned int dim1;
    char pad40[8];
    Generator_2abfb0* FUN_002d3b40();
};

struct Frame_2abfb0 {
    Source_2abfb0* out0;
    unsigned int y;
    void* z;
    unsigned int old;
    unsigned int out1;
    unsigned int pad14;
};

Generator_2abfb0* __stdcall FUN_002abfb0(Reader_2abfb0* r, void* arg)
{
    Frame_2abfb0 f;
    r->stream->FUN_002647e0(&f.old, 1, 4, 1);
    Generator_2abfb0* gen = 0;
    void* mem = FUN_00263ea0(0x48);
    if (mem != 0)
        gen = ((Generator_2abfb0*)mem)->FUN_002d3b40();
    r->stream->FUN_002647e0(&f.y, 1, 4, 1);
    gen->dim0 = f.y;
    r->stream->FUN_002647e0(&f.y, 1, 4, 1);
    gen->dim1 = f.y;
    while (r->FUN_002669f0() != 0) {
        if (r->FUN_00266a30() == 0x121000) {
            pure3d::AnimationLoader_2abfb0* loader = dynamic_cast<pure3d::AnimationLoader_2abfb0*>((*(Registry_2abfb0**)&DAT_00527c58)->FUN_00265310(0x121000));
            loader->AddRef();
            f.old = loader->FUN_00288e90();
            loader->FUN_00288e80(1);
            loader->Load(&f.out0, &f.out1, r, arg);
            if (f.out0 != 0) {
                Source_2abfb0* src = f.out0;
                src->AddRef();
                if (gen->source != 0)
                    gen->source->Release();
                gen->source = src;
                f.y = f.out0->count;
                f.z = 0;
                gen->elements.FUN_002aba00(f.y, (::pure3d::ParticleSphereGenerator::GeneratorBlendState* const*)&f.z);
                for (int i = 0; i < (int)f.y; i++) {
                    ::pure3d::ParticleSphereGenerator::GeneratorBlendState* e = (::pure3d::ParticleSphereGenerator::GeneratorBlendState*)FUN_0008d690(0x10);
                    f.z = e;
                    if (e != 0)
                        e = ((GeneratorBlendState_nv_2abfb0*)(e))->FUN_002d2bd0(f.out0->FUN_00288a10(i));
                    gen->elements.begin[gen->used] = e;
                    gen->elements.begin[gen->used]->vfunc_0();
                    gen->used++;
                }
            }
            loader->FUN_00288e80(f.old);
            loader->Release();
        }
        r->FUN_00266be0();
    }
    return gen;
}
