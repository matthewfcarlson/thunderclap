// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 18/18)
// FUN_0028ea80 @ 0x0028ea80
#include "compat/ptr.h"
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace pure3d { class Entity; }

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

class Entity {
public:
    virtual void AddRef();
};

struct Stream {
    void FUN_002647e0(void *dest, unsigned count, unsigned size, int flag);
};

struct EntityChannel_28ea80 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *field_14;
    Entity **field_18;
    EntityChannel_28ea80 *FUN_0028c2a0(unsigned x, void *parent);
};

class LoadContext_28ea80 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Entity *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned __int64 id);
};

class Parent_28ea80 {
public:
    void *FUN_002888c0(int size, int tag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

void *FUN_0008d690(unsigned size);

struct Frame_28ea80 {
    char pad[3];
    unsigned char len;     // 0x0b
    int a;                 // 0x0c, later reused as the caster object
    unsigned x;            // 0x10
    char name[0x100];      // 0x14
};

EntityChannel_28ea80 *__stdcall FUN_0028ea80(Reader *r, LoadContext_28ea80 *ctx, Parent_28ea80 *parent)
{
    Frame_28ea80 f;
    EntityChannel_28ea80 *node;

    r->stream->FUN_002647e0(&f.a, 1, 4, 1);
    r->stream->FUN_002647e0(&f.a, 1, 4, 1);
    r->stream->FUN_002647e0(&f.x, 1, 4, 1);

    if (parent == 0) {
        void *mem = FUN_0008d690(0x1c);
        node = 0;
        if (mem)
            node = ((EntityChannel_28ea80 *)mem)->FUN_0028c2a0(f.x, 0);
    } else {
        void *mem = parent->FUN_002888c0(0x1c, 7);
        node = 0;
        if (mem)
            node = ((EntityChannel_28ea80 *)mem)->FUN_0028c2a0(f.x, parent);
    }

    node->field_08 = f.a;
    r->stream->FUN_002647e0(node->field_14, f.x, 2, 1);

    for (unsigned i = 0; i < f.x; i++) {
        r->stream->FUN_002647e0(&f.len, 1, 1, 1);
        r->stream->FUN_002647e0(f.name, f.len, 1, 1);
        f.name[f.len] = 0;
        unsigned __int64 id = FUN_0027b020(f.name);
        content::LoadInventory::DynamicCaster<pure3d::Entity> *caster =
            new (&f.a) content::LoadInventory::DynamicCaster<pure3d::Entity>();
        node->field_18[i] = ctx->lookup(caster, id);
        Entity *e = node->field_18[i];
        if (e != 0)
            e->AddRef();
    }

    while (r->FUN_002669f0()) {
        if ((char *)r->FUN_00266a30() == ((char*)0x00121110)) {
            r->stream->FUN_002647e0(&f.x, 1, 4, 1);
            r->stream->FUN_002647e0(&f.a, 1, 4, 1);
            node->field_04 = f.a;
        }
        r->FUN_00266be0();
    }
    return node;
}
