// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 20/20)
// hulkfight::motion::CollisionSourceSizeCondition::vfunc_6 @ 0x0014eb10
extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);

struct Body {
    char pad0[0x11c];
    struct Sized* sized;    // 0x11c
};

struct Sized {
    char pad0[0x14];
    int size;               // 0x14
};

struct Link {
    char pad0[8];
    Body* body;             // 0x08
    int kind;               // 0x0c
};

struct Holder {
    char pad0[0x4c];
    Link* link;             // 0x4c
};

class Entity {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Holder* vfunc_3();
};

namespace hulkfight {
namespace motion {
class CollisionSourceSizeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused1, Entity* entity, int unused2);
    char pad04[8];
    int mode;               // 0x0c
    int value;              // 0x10
};
}
}

bool hulkfight::motion::CollisionSourceSizeCondition::vfunc_6(int unused1, Entity* entity, int unused2)
{
    if (!FUN_00344e74(entity, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Holder* holder = entity->vfunc_3();
    if (!holder || !holder->link)
        return false;
    Link* link = holder->link;
    if (link->kind != 1 || !link->body || !link->body->sized)
        return false;
    int size = link->body->sized->size;
    switch (mode) {
    case 0:
        return size == value;
    case 1:
        return size != value;
    }
    return false;
}
