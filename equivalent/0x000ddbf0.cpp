// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 8/8)
// FUN_000ddbf0 @ 0x000ddbf0
#include "compat/ptr.h"
struct V3_ddbf0 { float x, y, z; };

void* FUN_0008d690(hulk_uintptr size);
void* FUN_00263ea0(unsigned int size);
float __cdecl FUN_000ddbe0();
extern float (__cdecl *DAT_004de948)();

class Camera {
public:
    virtual void AddRef();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void SetNear(float f);
    virtual void v8();
    virtual void SetFar(float f);
    Camera* FUN_002939a0();
    void FUN_00293af0(V3_ddbf0* v);
    void FUN_00293a90(V3_ddbf0* v);
};

class Screen_ddbf0 {
public:
    virtual void AddRef();
    Screen_ddbf0* FUN_00294880();
    void FUN_00293e90(unsigned int color);
    void FUN_00294980(Camera* cam);
    char pad4[0x1c - 4];
    unsigned int f1c;
    unsigned int f20;
    char pad24[4];
    int f28;
    int f2c;
};

class Widget_ddbf0 {
public:
    Widget_ddbf0* FUN_000f6ef0();
};

class __declspec(novtable) FEThingsBase {
public:
    virtual void vfunc_0();
    char pad4[0x1828 - 4];
    Camera* camera;
    char pad182c[0x2224 - 0x182c];
    void FUN_000f3000();
    FEThingsBase() { FUN_000f3000(); }
};

class FEThings : public FEThingsBase {
public:
    FEThings(Screen_ddbf0* existing);
    virtual void vfunc_0();
    Screen_ddbf0* screen;
    char ownsScreen;
    char pad2229[3];
    int f222c;
    Widget_ddbf0* widget;
};

FEThings::FEThings(Screen_ddbf0* existing)
{
    Screen_ddbf0* s = existing;
    if (existing != 0) {
        ownsScreen = 0;
    } else {
        void* mem = FUN_0008d690(0x140);
        if (mem != 0)
            s = ((Screen_ddbf0*)mem)->FUN_00294880();
        else
            s = 0;
        ownsScreen = 1;
    }
    screen = s;
    s->AddRef();
    f222c = 0;
    screen->f28 = 0;
    screen->f2c = 6;
    screen->f20 = 0xff000000;
    screen->FUN_00293e90(0xff505050);
    void* cmem = FUN_00263ea0(0xf8);
    Camera* cam;
    if (cmem != 0)
        cam = ((Camera*)cmem)->FUN_002939a0();
    else
        cam = 0;
    camera = cam;
    cam->AddRef();
    camera->SetNear(0.1f);
    camera->SetFar(100.0f);
    V3_ddbf0 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = -10.0f;
    camera->FUN_00293af0(&pos);
    V3_ddbf0 dir;
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 1.0f;
    camera->FUN_00293a90(&dir);
    screen->FUN_00294980(camera);
    void* wmem = FUN_0008d690(0x120);
    if (wmem != 0)
        widget = ((Widget_ddbf0*)wmem)->FUN_000f6ef0();
    else
        widget = 0;
    DAT_004de948 = FUN_000ddbe0;
}
