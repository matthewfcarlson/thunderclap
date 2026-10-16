// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_000f3000 @ 0x000f3000
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" void* memset(void* dst, int c, unsigned int n);
namespace pure3d {
class DrawableHierarchy;
namespace scenegraph { class Scenegraph; }
}

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void* p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void* p);
};
}
}

void* FUN_0008d690(unsigned int size);

class Scenegraph {
public:
    virtual void addRef();
};

class Inventory_f3000 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Scenegraph* find(content::LoadInventory::DynamicCasterBase* caster, unsigned __int64 key);
};

void __cdecl FUN_000f69e0(Scenegraph* shape, float* scale);

class FEThingsBase;

struct PoolA {
    PoolA* FUN_000df690();
};

struct PoolB {
    PoolB* FUN_000f8bb0(FEThingsBase* owner);
};

class FEAnimationHolder {
public:
    __forceinline FEAnimationHolder()
    {
        memset(slots, 0, sizeof(slots));
        owner = 0;
    }
    virtual void v0();
    FEThingsBase* owner;
    void* slots[32];
};

class FEThingsBase {
public:
    FEThingsBase();
    virtual void v0();

    PoolA* poolA;                   // 0x4
    PoolB* poolB;                   // 0x8
    int arr0[0x40];                 // 0xc
    int arr1[0x40];                 // 0x10c
    int arr2[0x100];                // 0x20c
    int arr3[0x400];                // 0x60c
    int arr4[0x40];                 // 0x160c
    char f170c;
    char pad170d[0x175c - 0x170d];
    int f175c;
    int f1760;
    char pad1764[4];
    int f1768;
    int f176c;
    int arr5[0x10];                 // 0x1770
    int f17b0;
    int arr6[0x10];                 // 0x17b4
    int f17f4;
    char pad17f8[4];
    int f17fc;
    float f1800;
    int f1804;
    char pad1808[4];
    float f180c;
    float f1810;
    float f1814;
    Scenegraph* cursorGroup;        // 0x1818
    float cursorScale[3];           // 0x181c
    int f1828;
    int f182c;
    int f1830;
    char pad1834[4];
    int f1838;
    char pad183c[0x184c - 0x183c];
    char f184c;
    char pad184d[3];
    unsigned int f1850;
    int f1854[2];                   // 0x1854
    char pad185c[0x1a5c - 0x185c];
    int f1a5c[2];                   // 0x1a5c
    char pad1a64[0x1c64 - 0x1a64];
    int f1c64[2];                   // 0x1c64
    int f1c6c[2];                   // 0x1c6c
    char pad1c74[0x2074 - 0x1c74];
    char f2074;
    char pad2075[3];
    FEAnimationHolder anim;         // 0x2078
    int f2100;
    char f2104;
    char pad2105[0x2205 - 0x2105];
    char f2205;
    char pad2206[2];
    int f2208;
    int f220c;
    int f2210;
    int f2214;
    int f2218;
    int f221c;
    char f2220;
};

FEThingsBase::FEThingsBase()
{
    f184c = 0;
    f2074 = 1;
    f2205 = 0;
    f2208 = 0;
    f220c = 0;
    f1828 = 0;
    memset(arr0, 0, 0x40 * sizeof(int));
    memset(arr1, 0, 0x40 * sizeof(int));
    memset(arr3, 0, 0x400 * sizeof(int));
    memset(arr2, 0, 0x100 * sizeof(int));
    memset(arr4, 0, 0x40 * sizeof(int));
    f170c = 0;
    f175c = 0;
    f1768 = 0;
    f1760 = 0;
    f182c = 0;
    f2218 = 0;
    f221c = 3;
    memset(arr5, 0, 0x10 * sizeof(int));
    f17b0 = -1;
    memset(arr6, 0, 0x10 * sizeof(int));
    f17f4 = -1;

    void* mem = FUN_0008d690(0x800);
    PoolA* a = 0;
    if (mem)
        a = ((PoolA*)mem)->FUN_000df690();
    poolA = a;

    mem = FUN_0008d690(0x204);
    PoolB* b = 0;
    if (mem)
        b = ((PoolB*)mem)->FUN_000f8bb0(this);
    poolB = b;

    f176c = 0;
    f1830 = 0;
    anim.owner = this;
    f2210 = 0;
    f2214 = 0;
    f1c64[0] = 0;
    f1c64[1] = 0;
    f1c6c[0] = 0;
    f1c6c[1] = 0;
    f1a5c[0] = 0;
    f1a5c[1] = 0;
    f1854[0] = 0;
    f1854[1] = 0;
    f180c = 0.25f;
    f1810 = 40.0f;
    f1814 = -200.0f;
    f17fc = 0;
    f1800 = 1.0f;
    f1804 = 0;
    f2100 = 0;

    {
        content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph> caster;
        Inventory_f3000* inv = (*(Inventory_f3000**)&DAT_004dd9cc);
        unsigned __int64 key = FUN_0027b020("cursor_group");
        Scenegraph* sg = inv->find(&caster, key);
        cursorGroup = sg;
        if (sg)
            sg->addRef();
    }
    cursorScale[0] = 1.0f;
    cursorScale[1] = 1.0f;
    cursorScale[2] = 1.0f;
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        Inventory_f3000* inv = (*(Inventory_f3000**)&DAT_004dd9cc);
        unsigned __int64 key = FUN_0027b020("cursor_planeShape");
        Scenegraph* shape = inv->find(&caster, key);
        if (shape)
            FUN_000f69e0(shape, cursorScale);
    }
    f184c = 0;
    f2104 = 0;
    f1838 = 0;
    f1850 = 0xff000000;
    DAT_004de94c = 0;
    f2220 = 0;
}
