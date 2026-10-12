// STATUS: equivalent (tools/equiv.py level 3: 168 inputs, branch coverage 49/52, incomplete)
// FUN_002ac180 @ 0x002ac180
void* FUN_00263ea0(unsigned int size);
void* FUN_0008d690(unsigned int size);

struct Stream {
    char pad[0xc];
    char FUN_002647e0(void* dst, int a, int size, int b);
};

struct Source;
struct Reader {
    char pad000[0x284];
    Stream* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Item {
};

class Releasable {
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
    virtual void Load(Source** out0, unsigned int* out1, Reader* r, void* arg);
};
}

namespace pure3d {
class AnimationLoader : public content::ObjectLoader {
public:
    int FUN_00288e90();
    void FUN_00288e80(int v);
};
}

struct Registry {
    content::ObjectLoader* FUN_00265310(int id);
};

extern Registry* DAT_00527c58;

class Element {
public:
    virtual void AddRef();
    Element* FUN_002d2bd0(Item* item);
    Element* FUN_002d2570(Item* item);
    Element* FUN_002d2130(Item* item);
};

struct Source : public Releasable {
    char pad04[0x24];
    int count;
    Item** items;
    Item* FUN_00288a10(int index);
};

struct ElementList {
    Element** begin;
    Element** end;
    char FUN_002aba00(unsigned int n, Element* const* fill);
    char FUN_002ab9a0(unsigned int n, Element* const* fill);
    char FUN_002ab940(unsigned int n, Element* const* fill);
};

class Generator {
public:
    virtual void v0();
    char pad04[0x18];
    int used;
    char pad20[8];
    Releasable* source;
    ElementList elements;
    char pad34[0x60 - 0x34];
    Generator* FUN_002d3b40();
    Generator* FUN_002d3930();
    Generator* FUN_002d3740();
};

struct Frame {
    Source* out0;
    pure3d::AnimationLoader* loader;
    void* z;
    unsigned int old;
    unsigned int out1[2];
};

Generator* __stdcall FUN_002ac180(Reader* r, void* arg, int kind)
{
    Frame f;
    r->stream->FUN_002647e0(&f.old, 1, 4, 1);
    f.loader = dynamic_cast<pure3d::AnimationLoader*>(DAT_00527c58->FUN_00265310(0x121000));
    f.loader->AddRef();
    f.old = f.loader->FUN_00288e90();
    f.loader->FUN_00288e80(1);
    Generator* gen = 0;
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
                            gen = ((Generator*)mem)->FUN_002d3b40();
                        Source* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002aba00(n, (Element* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element* e = (Element*)FUN_0008d690(0x10);
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
                            gen = ((Generator*)mem)->FUN_002d3930();
                        Source* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002ab9a0(n, (Element* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element* e = (Element*)FUN_0008d690(0x1c);
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
                            gen = ((Generator*)mem)->FUN_002d3740();
                        Source* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002ab940(n, (Element* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element* e = (Element*)FUN_0008d690(0x14);
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
