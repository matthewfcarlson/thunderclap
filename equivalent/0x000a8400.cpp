// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000a8400 @ 0x000a8400
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0

void *thunk_FUN_0008d690(unsigned int size);

struct ResourceName {
    int word;
    void FUN_0027b040(const char *name);
};

class Target;

class Rig {
public:
    virtual void AddRef();
    Rig *FUN_002939a0();
};

class Controller {
public:
    virtual void AddRef();
    Controller *FUN_00292eb0();
    void FUN_00293100(Rig *rig);
};

class __declspec(novtable) CCameraBase {
public:
    virtual void v0();
    char pad04[4];
    ResourceName name;      // 0x08
    char pad0c[0xd0 - 0xc];
    int mode;               // 0xd0
    char padd4[0x170 - 0xd4];
    CCameraBase *FUN_000a9400();
    CCameraBase() { FUN_000a9400(); }
};

extern const char *DAT_0049ed3c;

class CDramaticCamera : public CCameraBase {
public:
    virtual void v0();
    Controller *controller;     // 0x170
    Rig *rig;                   // 0x174
    float f178;
    CDramaticCamera();
};

CDramaticCamera::CDramaticCamera()
{
    mode = 1;
    name.FUN_0027b040(DAT_0049ed3c);
    void *mem = thunk_FUN_0008d690(0x118);
    Controller *c = 0;
    if (mem != 0)
        c = ((Controller *)mem)->FUN_00292eb0();
    controller = c;
    c->AddRef();
    mem = thunk_FUN_0008d690(0xf8);
    Rig *r = 0;
    if (mem != 0)
        r = ((Rig *)mem)->FUN_002939a0();
    rig = r;
    r->AddRef();
    controller->FUN_00293100(rig);
    f178 = 1.0f;
}
