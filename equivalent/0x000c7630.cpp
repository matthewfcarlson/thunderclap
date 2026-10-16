// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 42/42)
// FUN_000c7630 @ 0x000c7630
// equiv-map: ?FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
namespace pure3d {
class DrawableHierarchy {
public:
    virtual void AddRef();
    virtual void Release();
};
}

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

struct Key_c7630 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
};

struct NameHolder_c7630 {
    char pad[8];
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[4];
    NameHolder_c7630 nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

struct IconSlot {
    int id;
    int f4;
    int f8;
    int fc;
    Key_c7630 key;
    int f18;
    int pad1c;
};

class Factory_c7630 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual pure3d::DrawableHierarchy *f3(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *caster,
                                          unsigned int lo, unsigned int hi);
};

struct Holder44_c7630 { Factory_c7630 *FUN_00203d70(); };
struct Holder28_c7630 { Holder44_c7630 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_c7630 *holder; };


class CHudIcons : public pure3d::Entity {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char enabled;
    char pad11[3];
    int f14;
    int f18;
    pure3d::DrawableHierarchy* enemyShape;
    pure3d::DrawableHierarchy* arrowRed;
    pure3d::DrawableHierarchy* smashShape;
    pure3d::DrawableHierarchy* arrowRed2;
    pure3d::DrawableHierarchy* grabShape;
    pure3d::DrawableHierarchy* arrowYellow;
    pure3d::DrawableHierarchy* defendShape;
    pure3d::DrawableHierarchy* arrowBlue;
    pure3d::DrawableHierarchy* gotoShape;
    pure3d::DrawableHierarchy* arrowGreen;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    char pad5c[4];
    IconSlot slots[16];
    CHudIcons();
};

CHudIcons::CHudIcons()
{
    enabled = 1;
    for (int i = 0; i < 16; i++) {
        slots[i].id = -1;
        slots[i].f4 = 0;
        slots[i].f8 = 0;
        slots[i].fc = 0;
        slots[i].key.FUN_0027af00();
        slots[i].f18 = 0;
    }
    Factory_c7630 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    f14 = 0;
    f18 = 0;
    enemyShape = 0;
    arrowRed = 0;
    smashShape = 0;
    arrowRed2 = 0;
    grabShape = 0;
    arrowYellow = 0;
    defendShape = 0;
    arrowBlue = 0;
    gotoShape = 0;
    arrowGreen = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f50 = 0;
    f54 = 0;
    f58 = 0;
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_enemyShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (enemyShape)
            enemyShape->Release();
        enemyShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_smashShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (smashShape)
            smashShape->Release();
        smashShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_grabShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (grabShape)
            grabShape->Release();
        grabShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_defendShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (defendShape)
            defendShape->Release();
        defendShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_gotoShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (gotoShape)
            gotoShape->Release();
        gotoShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_red");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowRed)
            arrowRed->Release();
        arrowRed = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_red");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowRed2)
            arrowRed2->Release();
        arrowRed2 = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_yellow");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowYellow)
            arrowYellow->Release();
        arrowYellow = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_blue");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowBlue)
            arrowBlue->Release();
        arrowBlue = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_green");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowGreen)
            arrowGreen->Release();
        arrowGreen = obj;
    }
}
