// STATUS: equivalent (tools/equiv.py level 3: 427 inputs, branch coverage 16/16)
// fight::ParamValueInventoryEntity::vfunc_10 @ 0x002358c0
// ParamValueInventoryEntity: find an entity by 64-bit id, first in the global inventory, then among our own entries.
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
namespace pure3d { class Entity; }

class Entity {
public:
    char pad0[8];
    unsigned int idLo;
    unsigned int idHi;
};

class Loader_2358c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Entity *v3(content::LoadInventory::DynamicCaster<pure3d::Entity> *caster, unsigned int lo, unsigned int hi);
};
extern Loader_2358c0 *DAT_004e5bb8;

class ParamValueInventoryEntity {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void *owner, Entity *entity);
    virtual Entity *vfunc_7(void *owner, int index);
    virtual int vfunc_8(void *owner);

    Entity *FUN_002358c0(void *owner, unsigned int idLo, unsigned int idHi);
};

Entity *ParamValueInventoryEntity::FUN_002358c0(void *owner, unsigned int idLo, unsigned int idHi)
{
    if (DAT_004e5bb8) {
        content::LoadInventory::DynamicCaster<pure3d::Entity> caster;
        Entity *found = DAT_004e5bb8->v3(&caster, idLo, idHi);
        if (found && vfunc_6(owner, found)) {
            return found;
        }
    }
    int count = vfunc_8(owner);
    for (int i = 0; i < count; i++) {
        Entity *e = vfunc_7(owner, i);
        if (e && idLo == e->idLo && idHi == e->idHi) {
            return e;
        }
    }
    return 0;
}
