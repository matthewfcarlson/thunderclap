// STATUS: equivalent (tools/equiv.py level 3: 168 inputs, branch coverage 49/52, incomplete)
// FUN_002ac180 @ 0x002ac180
#include "compat/ptr.h"
#include "decls/data/engine/content.h"

void* FUN_00263ea0(unsigned int size);
void* FUN_0008d690(hulk_uintptr size);

struct Stream {
    char pad[0xc];
    char FUN_002647e0(void* dst, int a, int size, int b);
};

struct Source_2ac180;
struct Reader {
    char pad000[0x284];
    Stream* stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

struct Item_2ac180 {
};

class Releasable_2ac180 {
public:
    virtual void AddRef();
    virtual void Release();
};

namespace content {
class ObjectLoader {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Load(Source_2ac180** out0, unsigned int* out1, Reader* r, void* arg);
};
}

namespace pure3d {
class AnimationLoader : public content::ObjectLoader {
public:
    int FUN_00288e90();
    void FUN_00288e80(int v);
};
}

struct Registry_2ac180 {
    content::ObjectLoader* FUN_00265310(int id);
};


class Element_2ac180 {
public:
    virtual void AddRef();
    Element_2ac180* FUN_002d2bd0(Item_2ac180* item);
    Element_2ac180* FUN_002d2570(Item_2ac180* item);
    Element_2ac180* FUN_002d2130(Item_2ac180* item);
};

struct Source_2ac180 : public Releasable_2ac180 {
    char pad04[0x24];
    int count;
    Item_2ac180** items;
    Item_2ac180* FUN_00288a10(int index);
};

struct ElementList_2ac180 {
    Element_2ac180** begin;
    Element_2ac180** end;
    char FUN_002aba00(unsigned int n, Element_2ac180* const* fill);
    char FUN_002ab9a0(unsigned int n, Element_2ac180* const* fill);
    char FUN_002ab940(unsigned int n, Element_2ac180* const* fill);
};

class Generator_2ac180 {
public:
    virtual void v0();
    char pad04[0x18];
    int used;
    char pad20[8];
    Releasable_2ac180* source;
    ElementList_2ac180 elements;
    char pad34[0x60 - 0x34];
    Generator_2ac180* FUN_002d3b40();
    Generator_2ac180* FUN_002d3930();
    Generator_2ac180* FUN_002d3740();
};

struct Frame_2ac180 {
    Source_2ac180* out0;
    pure3d::AnimationLoader* loader;
    void* z;
    unsigned int old;
    unsigned int out1[2];
};

Generator_2ac180* __stdcall FUN_002ac180(Reader* r, void* arg, int kind)
{
    Frame_2ac180 f;
    r->stream->FUN_002647e0(&f.old, 1, 4, 1);
    f.loader = dynamic_cast<pure3d::AnimationLoader*>((*(Registry_2ac180**)&DAT_00527c58)->FUN_00265310(0x121000));
    f.loader->AddRef();
    f.old = f.loader->FUN_00288e90();
    f.loader->FUN_00288e80(1);
    Generator_2ac180* gen = 0;
    if (r->FUN_002669f0() != 0) {
        do {
            if (r->FUN_00266a30() == 0x121000) {
                f.out0 = 0;
                f.loader->Load(&f.out0, f.out1, r, arg);
                if (f.out0 != 0) {
                    if (kind == 0x15b02) {
                        void* mem = FUN_00263ea0(0x48);
                        gen = 0;
                        if (mem != 0)
                            gen = ((Generator_2ac180*)mem)->FUN_002d3b40();
                        Source_2ac180* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002aba00(n, (Element_2ac180* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element_2ac180* e = (Element_2ac180*)FUN_0008d690(0x10);
                            f.z = e;
                            if (e != 0)
                                e = e->FUN_002d2bd0(f.out0->FUN_00288a10(i));
                            gen->elements.begin[gen->used] = e;
                            gen->elements.begin[gen->used]->AddRef();
                            gen->used++;
                        }
                    } else if (kind == 0x15b01) {
                        void* mem = FUN_00263ea0(0x60);
                        gen = 0;
                        if (mem != 0)
                            gen = ((Generator_2ac180*)mem)->FUN_002d3930();
                        Source_2ac180* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002ab9a0(n, (Element_2ac180* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element_2ac180* e = (Element_2ac180*)FUN_0008d690(0x1c);
                            f.z = e;
                            if (e != 0)
                                e = e->FUN_002d2570(f.out0->FUN_00288a10(i));
                            gen->elements.begin[gen->used] = e;
                            gen->elements.begin[gen->used]->AddRef();
                            gen->used++;
                        }
                    } else if (kind == 0x15b00) {
                        void* mem = FUN_00263ea0(0x50);
                        gen = 0;
                        if (mem != 0)
                            gen = ((Generator_2ac180*)mem)->FUN_002d3740();
                        Source_2ac180* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002ab940(n, (Element_2ac180* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element_2ac180* e = (Element_2ac180*)FUN_0008d690(0x14);
                            f.z = e;
                            if (e != 0)
                                e = e->FUN_002d2130(f.out0->FUN_00288a10(i));
                            gen->elements.begin[gen->used] = e;
                            gen->elements.begin[gen->used]->AddRef();
                            gen->used++;
                        }
                    }
                }
            }
            r->FUN_00266be0();
            if (gen != 0)
                break;
        } while (r->FUN_002669f0() != 0);
    }
    f.loader->FUN_00288e80(f.old);
    f.loader->Release();
    return gen;
}
