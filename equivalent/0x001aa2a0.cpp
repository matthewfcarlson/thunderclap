// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 14/14)
// FUN_001aa2a0 @ 0x001aa2a0
namespace core {
struct IRefCount {
    virtual void r0();
    virtual void r1();
    virtual void r2();
};
}

namespace pure3d {
class Camera : public core::IRefCount {
};
class CameraAnimationController : public core::IRefCount {
public:
    Camera *FUN_00292f20();
};
}

namespace content {
class LoadInventory {
  public:
    template <class T> class DynamicCaster {
      public:
        virtual T *Cast(void *p);
    };
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void *Find(const DynamicCaster<pure3d::Camera> &c, __int64 uid);
    char pad04[8];
    unsigned int f0c;
};
}

unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);

struct Cursor {
    unsigned int a;
    int b;
    content::LoadInventory *c;
    void FUN_002314a0(unsigned int v);
    core::IRefCount *FUN_00231640();
    pure3d::CameraAnimationController *FUN_001a6e50();
    pure3d::Camera *FUN_001a92e0();
};

struct Owner {
    char pad00[0x30];
    unsigned char f30;
    char pad31[3];
    int f34, f38, f3c, f40, f44, f48;
    char pad4c[0x54 - 0x4c];
    int f54;
};

struct Registry {
    content::LoadInventory *FUN_00203d60(int index);
};

struct Scene {
    void FUN_0009a400(struct Manager *m);
    void FUN_000990d0(int a, int b, int c, int d, int e, int f);
    void FUN_0009bf50(struct Manager *m, pure3d::Camera *cam);
};

struct Ent {
    char pad[0x31];
    unsigned char flag31;
};

struct EntList {
    Ent *FUN_00086290();
};

struct Manager {
    char pad00[8];
    Scene *scene;
    char pad0c[0x54 - 0xc];
    EntList *ents;
};

extern Manager *DAT_004dd700;

class CameraRig {
public:
    char pad00[0x1c];
    Owner *owner;
    char pad20[4];
    pure3d::CameraAnimationController *controller;
    pure3d::Camera *camera;
    char pad2c[0x20c - 0x2c];
    Registry *registry;
    char pad210[4];
    unsigned char noOwner;

    void FUN_001a55d0();
    void FUN_001aa2a0();
};

void CameraRig::FUN_001aa2a0()
{
    if (!owner->f30)
        return;

    int idx;
    if (noOwner)
        idx = 0;
    else
        idx = owner->f54;
    content::LoadInventory *inv = registry->FUN_00203d60(idx);

    Cursor it;
    it.FUN_002314a0(inv->f0c);
    it.c = inv;
    core::IRefCount *e = it.FUN_00231640();
    pure3d::CameraAnimationController *cc = dynamic_cast<pure3d::CameraAnimationController *>(e);
    if (cc != 0)
        controller = (pure3d::CameraAnimationController *)e;
    else
        controller = it.FUN_001a6e50();

    if (controller != 0) {
        controller->r0();
        camera = controller->FUN_00292f20();
    }
    if (camera == 0) {
        camera = (pure3d::Camera *)inv->Find(content::LoadInventory::DynamicCaster<pure3d::Camera>(), FUN_002672f0("nis_camera", 0));
        if (camera == 0) {
            Cursor it2;
            it2.FUN_002314a0(inv->f0c);
            it2.c = inv;
            camera = it2.FUN_001a92e0();
        }
        FUN_001a55d0();
    }
    if (camera == 0)
        return;

    camera->r0();
    DAT_004dd700->scene->FUN_0009a400(DAT_004dd700);
    Owner *o = owner;
    DAT_004dd700->scene->FUN_000990d0(o->f34, o->f38, o->f3c, o->f40, o->f44, o->f48);
    DAT_004dd700->scene->FUN_0009bf50(DAT_004dd700, camera);
    DAT_004dd700->ents->FUN_00086290()->flag31 = 0;
}
