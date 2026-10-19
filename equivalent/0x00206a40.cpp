// STATUS: equivalent (tools/equiv.py level 3: 10099 inputs, branch coverage 16/16)
// FUN_00206a40 @ 0x00206a40
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" int sprintf(char *buf, const char *fmt, ...);

namespace pure3d { class LightGroup; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Slot_206a40 {
    char pad00[0x28];
    char flag28;
};

struct Mixer {
    void FUN_0029f8c0(Slot_206a40 *s);
};

struct Lists_206a40 {
    char pad00[0xc0];
    Mixer *mixC0;
    Mixer *mixC4;
};

struct List_206a40 {
    char pad00[0x10];
    int size;
    int count;
    Slot_206a40 **data;
};

struct Loader_206a40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual List_206a40 *v3(content::LoadInventory::DynamicCaster<pure3d::LightGroup> *caster, unsigned int lo, unsigned int hi);
};

struct Entry38 {
    char pad00[0x38];
    Loader_206a40 *loader;
};

struct Obj_206a40 {
    char pad00[8];
    char f8;
    void FUN_001c6cb0(int v);
    void FUN_001c6ce0(int v);
};

struct NameKey_206a40 {
    int f0;
    int f4;
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Mgr_206a40 {
    Obj_206a40 *FUN_001c7f70(NameKey_206a40 *key);
};

struct Single {
    Lists_206a40 *f0;
    Mgr_206a40 *f4;
};

struct SubA_206a40 { void FUN_001b5f60(int i); };
struct SubB_206a40 { void FUN_001e73b0(int i); };
struct SubC_206a40 { void FUN_001fd220(int i); };
struct SubD { void FUN_00079980(int i); };

struct Sub0C_206a40 {
    char pad00[0xc];
    SubB_206a40 *b0c;
    SubA_206a40 *a10;
    char pad14[0x28 - 0x14];
    SubC_206a40 *c28;
    char pad2c[0x4c - 0x2c];
    SubD *d4c;
};

struct Hold588 {
    char pad00[0xc];
    Sub0C_206a40 *f0c;
};

struct Tmp_206a40 {
    char pad[0x18];
    void FUN_001cad80(int i);
};

struct Target30 {
    void FUN_001cbc20(Tmp_206a40 *t);
};

struct World {
    char pad00[0x30];
    Target30 *f30;
};

Single *FUN_001c3d90();


class Scene_206a40 {
public:
    char pad00[0x24];
    char name[0x20];
    char pad44[0x588 - 0x44];
    Hold588 *f588;
    char pad58c[0x5a4 - 0x58c];
    char flags[0x100];

    Entry38 *FUN_00204540(const char *s);
    void Load(int idx);
};

void Scene_206a40::Load(int idx)
{
    struct Frame {
        Lists_206a40 *lists;
        union {
            NameKey_206a40 key;
            char casterBuf[sizeof(content::LoadInventory::DynamicCaster<pure3d::LightGroup>)];
        } u;
        Tmp_206a40 tmp;
        char buf1[0x100];
        char buf2[0x100];
    } f;

    sprintf(f.buf1, "%s_r%03d", name, idx);
    Loader_206a40 *loader = 0;
    if ((*(char*)&DAT_004c91d8))
        loader = FUN_00204540(f.buf1)->loader;
    Mgr_206a40 *mgr = FUN_001c3d90()->f4;
    f.lists = FUN_001c3d90()->f0;
    if (mgr) {
        f.u.key.FUN_0027b0e0(f.buf1);
        Obj_206a40 *obj = mgr->FUN_001c7f70(&f.u.key);
        f.u.key.FUN_0027af50();
        obj->FUN_001c6cb0(0);
        obj->FUN_001c6ce0(0);
        sprintf(f.buf2, "%sScene", f.buf1);
        unsigned __int64 h = FUN_002672f0(f.buf2, 0, 0);
        content::LoadInventory::DynamicCaster<pure3d::LightGroup> *caster =
            new (f.u.casterBuf) content::LoadInventory::DynamicCaster<pure3d::LightGroup>;
        List_206a40 *list = loader->v3(caster, (unsigned int)h, (unsigned int)(h >> 32));
        if (list) {
            for (int i = 0; i < list->count; i++) {
                Slot_206a40 *s = i < list->size ? list->data[i] : 0;
                if (s->flag28)
                    f.lists->mixC4->FUN_0029f8c0(s);
                else
                    f.lists->mixC0->FUN_0029f8c0(s);
            }
        }
        obj->f8 = 0;
    }
    f588->f0c->a10->FUN_001b5f60(idx);
    flags[idx] = 0;
    f588->f0c->b0c->FUN_001e73b0(idx);
    f588->f0c->c28->FUN_001fd220(idx);
    f588->f0c->d4c->FUN_00079980(idx);
    if (!(*(char*)&DAT_004e5a58)) {
        f.tmp.FUN_001cad80(idx);
        DAT_004dd700->f30->FUN_001cbc20(&f.tmp);
    }
}
