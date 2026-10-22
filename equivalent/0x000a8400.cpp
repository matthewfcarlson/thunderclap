// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000a8400 @ 0x000a8400
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/data/game/global.h"

void *thunk_FUN_0008d690(unsigned int size);

struct ResourceName_a8400 {
    int word;
    void FUN_0027b040(const char *name);
};

class Target;

class VectorCamera_a8400 {
public:
    virtual void AddRef();
    VectorCamera_a8400 *FUN_002939a0();
};

class CameraAnimationController_a8400 {
public:
    virtual void AddRef();
    CameraAnimationController_a8400 *FUN_00292eb0();
    void FUN_00293100(VectorCamera_a8400 *rig);
};

class __declspec(novtable) CGameCamera_a8400 {
public:
    virtual void v0();
    char pad04[4];
    ResourceName_a8400 name;      // 0x08
    char pad0c[0xd0 - 0xc];
    int mode;               // 0xd0
    char padd4[0x170 - 0xd4];
    CGameCamera_a8400 *FUN_000a9400();
    CGameCamera_a8400() { FUN_000a9400(); }
};


class CDramaticCamera : public CGameCamera_a8400 {
public:
    virtual void v0();
    CameraAnimationController_a8400 *controller;     // 0x170
    VectorCamera_a8400 *rig;                   // 0x174
    float f178;
    CDramaticCamera();
};

CDramaticCamera::CDramaticCamera()
{
    mode = 1;
    name.FUN_0027b040((*(const char**)&DAT_0049ed3c));
    void *mem = thunk_FUN_0008d690(0x118);
    CameraAnimationController_a8400 *c = 0;
    if (mem != 0)
        c = ((CameraAnimationController_a8400 *)mem)->FUN_00292eb0();
    controller = c;
    c->AddRef();
    mem = thunk_FUN_0008d690(0xf8);
    VectorCamera_a8400 *r = 0;
    if (mem != 0)
        r = ((VectorCamera_a8400 *)mem)->FUN_002939a0();
    rig = r;
    r->AddRef();
    controller->FUN_00293100(rig);
    f178 = 1.0f;
}
