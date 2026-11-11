// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002980b0..0x0029b100 (kind game, layer engine, confidence high), dominant class pure3d::OldCompositeDrawableLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#define TREE_TU_BEGIN namespace fn_f0ae8a57 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0ae8a57 {} using namespace fn_f0ae8a57;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_f0ae8a57 {
struct Stream {
    char FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};
struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};
struct NameField_29a190 {
    void FUN_0027b040(const char *s);
};
namespace pure3d {
class Skeleton;
}
namespace pure3d {
class DrawableContainer;
}
namespace content {
class ObjectLoader {
public:
    virtual void v0();
    virtual void v1();
};
}
namespace content { namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
} }
struct RefObj_29a190 {
    virtual void v0();
    virtual void v1();
};
struct Handle_29a190 {
    RefObj_29a190 *FUN_0027b240();
};
struct Inventory_29a190 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *v3(void *caster, unsigned __int64 key);
};
namespace pure3d {
class FrameController {
public:
    virtual void v0();
    virtual void v1();
};
}
namespace pure3d {
class PoseAnimationController : public FrameController {
public:
    void FUN_00288080(RefObj_29a190 *skel);
};
}
namespace pure3d {
class CompDrawVisibilityAnimationController : public FrameController {
public:
    void FUN_002a8310(CompositeDrawable *cd);
};
}
namespace pure3d {
class FrameControllerLoader : public content::ObjectLoader {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(FrameController **out, unsigned __int64 *id, Reader *r, Inventory_29a190 *inv);
};
}
namespace pure3d {
class DrawableContainer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual DrawableContainer *v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(RefObj_29a190 *skel);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void *v15();
    char pad[0x44 - 4];
    void *owner;
};
}
namespace pure3d {
class DrawableBase {
public:
    DrawableBase();
    virtual void v0_00038290();
    virtual void v1_000382a0();
    virtual void v2();
    virtual void v3_00298280();
    virtual void v4_0029a170();
    virtual void v5_00298270();
    virtual void v6();
    virtual void v7_00298c00();
    virtual void v8();
    virtual void v9_00298e60();
    virtual void v10();
    virtual void v11_00298260();
    virtual void v12_002992c0();
    char pad4[4];
    NameField_29a190 name;
    char pad9[0x40 - 9];
};
}
namespace pure3d {
struct Rec_29a190 {
    int f0;
    int f4;
    DrawableContainer *f8;
};
}
namespace pure3d {
class Table_29a190 {
public:
    virtual void v0();
    char pad4[4];
    unsigned char *map;
    char pad0c[0x14 - 0xc];
    unsigned char *counts;
    char pad18[0x3c - 0x18];
    Rec_29a190 *recs;
    Table_29a190 *FUN_00299cd0(unsigned int n);
    void FUN_00298870();
};
}
namespace pure3d {
class CompositeDrawable : public DrawableBase {
public:
    CompositeDrawable() {
        skel = 0;
        table = 0;
        f48 = 0;
        f4c = 0;
        f50 = 0;
    }
    RefObj_29a190 *skel;
    Table_29a190 *table;
    int f48;
    RefObj_29a190 *f4c;
    RefObj_29a190 *f50;
    char pad54[4];
};
}
struct Registry_29a190 {
    content::ObjectLoader *FUN_00265310(int id);
};
void *FUN_00263ea0(unsigned int size);
extern "C" void *FUN_0008d690(unsigned int size);
extern "C" void __cdecl FUN_0028fd70(Inventory_29a190 *inv);
extern "C" int __cdecl FUN_00298180(void *p);
class CompositeDrawableLoader {
public:
    void vfunc_5(pure3d::CompositeDrawable **out, unsigned __int64 *outId, Reader *r, Inventory_29a190 *inv);
};
struct Frame_29a190 {
    char pad00[2];
    unsigned char len;
    bool flag;
    pure3d::FrameController *fc;
    char c1[4];
    char c2[4];
    int k;
    int n;
    int d;
    int b;
    int a;
    int c;
    unsigned __int64 fid;
    char name1[0x100];
    char name2[0x100];
    char name3[0x100];
};


// 0x0029a190 pure3d::CompositeDrawableLoader::vfunc_5 (1180 B): equivalent/0x0029a190.cpp
// sym: ?vfunc_5@CompositeDrawableLoader@fn_f0ae8a57@@QAEXPAPAVCompositeDrawable@pure3d@2@PA_KPAUReader@2@PAUInventory_29a190@2@@Z @6df3852a0f10 @w11d9a14c50e2
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 45/50, incomplete)
// pure3d::CompositeDrawableLoader::vfunc_5 @ 0x0029a190
// equiv-map: ??0DrawableBase@pure3d@@QAE@XZ = 0x002a3480
void CompositeDrawableLoader::vfunc_5(pure3d::CompositeDrawable **out, unsigned __int64 *outId, Reader *r, Inventory_29a190 *inv)
{
    Frame_29a190 f;

    r->stream->FUN_002647e0(&f.d, 1, 4, 1);
    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int l1 = f.len;
    r->stream->FUN_002647e0(f.name1, l1, 1, 1);
    f.name1[l1] = 0;
    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int l2 = f.len;
    r->stream->FUN_002647e0(f.name2, l2, 1, 1);
    f.name2[l2] = 0;
    r->stream->FUN_002647e0(&f.n, 1, 4, 1);

    f.k = 0;
    void *mem = FUN_00263ea0(0x58);
    pure3d::CompositeDrawable *cd = 0;
    if (mem)
        cd = new (mem) pure3d::CompositeDrawable;

    cd->name.FUN_0027b040(f.name1);
    {
        unsigned __int64 key = FUN_0027b020(f.name2);
        content::LoadInventory::DynamicCaster<pure3d::Skeleton> *caster =
            new (f.c1) content::LoadInventory::DynamicCaster<pure3d::Skeleton>;
        Handle_29a190 *h = (Handle_29a190 *)inv->v3(caster, key);
        if (h) {
            RefObj_29a190 *s = h->FUN_0027b240();
            if (s)
                s->v0();
            if (cd->skel)
                cd->skel->v1();
            cd->skel = s;
        }
    }

    void *tmem = FUN_0008d690(0x48);
    pure3d::Table_29a190 *t = 0;
    if (tmem)
        t = ((pure3d::Table_29a190 *)tmem)->FUN_00299cd0(f.n);
    cd->table = t;
    t->v0();

    if (r->FUN_002669f0()) {
        do {
            int id = r->FUN_00266a30();
            if (id == 0x121201) {
                pure3d::FrameControllerLoader *fl =
                    dynamic_cast<pure3d::FrameControllerLoader *>((*(Registry_29a190**)&DAT_00527c58)->FUN_00265310(0x121201));
                fl->v0();
                f.fc = 0;
                fl->v5(&f.fc, &f.fid, r, inv);
                if (f.fc) {
                    pure3d::PoseAnimationController *pc = dynamic_cast<pure3d::PoseAnimationController *>(f.fc);
                    pure3d::CompDrawVisibilityAnimationController *vc =
                        dynamic_cast<pure3d::CompDrawVisibilityAnimationController *>(f.fc);
                    *(pure3d::CompDrawVisibilityAnimationController **)f.c2 = vc;
                    if (pc) {
                        pc->v0();
                        if (cd->f4c)
                            cd->f4c->v1();
                        cd->f4c = (RefObj_29a190 *)pc;
                        if (pc)
                            pc->FUN_00288080(cd->skel);
                    } else if (vc) {
                        vc->v0();
                        if (cd->f50)
                            cd->f50->v1();
                        cd->f50 = (RefObj_29a190 *)vc;
                        if (vc)
                            vc->FUN_002a8310(cd);
                    } else {
                        f.fc->v1();
                        f.fc = 0;
                    }
                }
                fl->v1();
            } else if (id == 0x123001) {
                r->stream->FUN_002647e0(&f.a, 1, 4, 1);
                r->stream->FUN_002647e0(&f.b, 1, 4, 1);
                f.flag = f.b != 0;
                r->stream->FUN_002647e0(&f.len, 1, 1, 1);
                unsigned int l3 = f.len;
                r->stream->FUN_002647e0(f.name3, l3, 1, 1);
                f.name3[l3] = 0;
                r->stream->FUN_002647e0(&f.c, 1, 4, 1);
                unsigned __int64 key = FUN_0027b020(f.name3);
                content::LoadInventory::DynamicCaster<pure3d::DrawableContainer> *caster =
                    new (f.c2) content::LoadInventory::DynamicCaster<pure3d::DrawableContainer>;
                pure3d::DrawableContainer *dc = (pure3d::DrawableContainer *)inv->v3(caster, key);
                if (!dc)
                    FUN_0028fd70(inv);
                if (f.flag == 1)
                    dc = dc->v4();
                unsigned int idx = (unsigned char)f.k;
                pure3d::Rec_29a190 *slot = &cd->table->recs[idx];
                if (dc)
                    dc->v0();
                if (slot->f8)
                    slot->f8->v1();
                slot->f8 = dc;
                dc->v10(cd->skel);
                dc->owner = cd;
                r->stream->FUN_002647e0(&f.d, 1, 4, 1);
                cd->table->recs[idx].f4 = f.d;
                f.k++;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    int cur = 0;
    for (unsigned int i = 0; i < (unsigned int)f.n; i++) {
        unsigned int bi = (unsigned char)i;
        if (cd->table->recs[bi].f8->v15()) {
            cur = FUN_00298180(cd->table->recs[bi].f8->v15());
            cd->table->map[cur] = (unsigned char)i;
        }
        cd->table->counts[cur]++;
    }
    cd->table->FUN_00298870();
    cd->v12_002992c0();
    *out = cd;
    *outId = FUN_002672f0(f.name1, 0, 0);
}

} // namespace fn_f0ae8a57
