// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 62/62)
// FUN_000d2c30 @ 0x000d2c30
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d {
class CompositeDrawable;
class Locator;
}

class Res {
public:
    virtual void AddRef();
    virtual void Release();
};

class Composite : public Res {
public:
    char pad04[0x44];
    Res *child48;
    void FUN_002998d0(int v);
};

class Inventory {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res *get(void *caster, unsigned int lo, unsigned int hi);
};

struct Flags {
    bool FUN_00092940(int id);
};

struct Holder {
    Flags *FUN_00086340();
};

struct Manager {
    char pad0[0x54];
    Holder *holder;
};

extern Manager *DAT_004dd700;
extern Inventory *DAT_004dd9cc;
extern "C" unsigned __int64 __cdecl FUN_0027b020(const char *s);

static Res *GetLocator(const char *name)
{
    Inventory *inv = DAT_004dd9cc;
    unsigned __int64 h = FUN_0027b020(name);
    content::LoadInventory::DynamicCaster<pure3d::Locator> c;
    return inv->get(&c, (unsigned int)h, (unsigned int)(h >> 32));
}

class HealthBar {
public:
    char pad0[0x164];
    Res *r164;
    Res *r168;
    char pad16c[0x1a4 - 0x16c];
    Res *r1a4;
    Res *r1a8;
    Res *r1ac;
    Res *r1b0;
    Res *r1b4;
    Res *r1b8;
    char pad1bc[0x1e0 - 0x1bc];
    Res *r1e0;
    Res *r1e4;
    Res *r1e8;
    void FUN_000d2c30();
};

void HealthBar::FUN_000d2c30()
{
    Flags *fl = DAT_004dd700->holder->FUN_00086340();
    const char *n1;
    const char *n2;
    const char *n3;
    if (!fl->FUN_00092940(0x27b)) {
        n1 = "FE_healthmin";
        n2 = "LOC_health_topdistanceShape";
        n3 = "LOC_health_top_topdistanceShape";
    } else if (!fl->FUN_00092940(0x298)) {
        n1 = "FE_healthmin1";
        n2 = "LOC_health1_topdistanceShape";
        n3 = "LOC_health_top_topdistance1Shape";
    } else if (!fl->FUN_00092940(0x2ba)) {
        n1 = "FE_healthmin2";
        n2 = "LOC_health2_topdistanceShape";
        n3 = "LOC_health_top_topdistance2Shape";
    } else {
        n1 = "FE_healthmin3";
        n2 = "LOC_health3_topdistanceShape";
        n3 = "LOC_health_top_topdistance3Shape";
    }

    Composite *comp;
    {
        Inventory *inv = DAT_004dd9cc;
        unsigned __int64 h = FUN_0027b020(n1);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> c;
        comp = (Composite *)inv->get(&c, (unsigned int)h, (unsigned int)(h >> 32));
    }
    Res *r = GetLocator(n2);
    if (r)
        r->AddRef();
    if (r1ac)
        r1ac->Release();
    r1ac = r;

    r = GetLocator(n3);
    if (r)
        r->AddRef();
    if (r1b8)
        r1b8->Release();
    r1b8 = r;
    comp->FUN_002998d0(0);

    if (comp)
        comp->AddRef();
    if (r164)
        r164->Release();
    r164 = comp;
    Res *ch = comp->child48;
    if (ch)
        ch->AddRef();
    if (r168)
        r168->Release();
    r168 = ch;

    r = GetLocator("LOC_health_topShape");
    if (r)
        r->AddRef();
    if (r1a4)
        r1a4->Release();
    r1a4 = r;

    r = GetLocator("LOC_health_botShape");
    if (r)
        r->AddRef();
    if (r1a8)
        r1a8->Release();
    r1a8 = r;

    r = GetLocator("LOC_health_2_topShape");
    if (r)
        r->AddRef();
    if (r1b0)
        r1b0->Release();
    r1b0 = r;

    r = GetLocator("LOC_health_2_botShape");
    if (r)
        r->AddRef();
    if (r1b4)
        r1b4->Release();
    r1b4 = r;

    r = GetLocator("LOC_adrenaline_surge_topShape");
    if (r)
        r->AddRef();
    if (r1e0)
        r1e0->Release();
    r1e0 = r;

    r = GetLocator("LOC_adrenaline_surge_botShape");
    if (r)
        r->AddRef();
    if (r1e4)
        r1e4->Release();
    r1e4 = r;

    r = GetLocator("LOC_adrenaline_surge_topdistanceShape");
    if (r)
        r->AddRef();
    if (r1e8)
        r1e8->Release();
    r1e8 = r;
}
