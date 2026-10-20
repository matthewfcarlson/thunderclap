// STATUS: equivalent (tools/equiv.py level 3: 3044 inputs, branch coverage 45/48, incomplete)
// MyControllerCallback::vfunc_0 @ 0x0008dbb0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" int strcmp(const char *a, const char *b);

struct Item_8dbb0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual const char *v6();
};

struct Mgr_8dbb0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Count();
    virtual Item_8dbb0 *Get(int i);
};
Mgr_8dbb0 *FUN_002684b0();

struct Table_8dbb0 {
    char pad0[0x134];
    char name[1];
};

struct Profile_8dbb0 {
    char pad0[4];
    Table_8dbb0 *table;
    void FUN_000ae8a0(const char *key);
    void FUN_000ae8b0(const char *key);
};

struct Fx_8dbb0 {
    char pad0[8];
    char enabled;
    void FUN_001eb870();
    void FUN_001eb2a0(float f, int zero);
};
struct Cam_8dbb0 {
    void FUN_001b8160();
};
struct Rumble {
    void FUN_000afe80();
};

struct Manager_8dbb0 {
    char pad0[0x10];
};

struct World {
    char pad0[0x54];
    Manager_8dbb0 *mgr;
};

Profile_8dbb0 *__fastcall FUN_000862c0(Manager_8dbb0 *m);
Cam_8dbb0 *__fastcall FUN_00086300(Manager_8dbb0 *m);
Rumble *__fastcall FUN_00086330(Manager_8dbb0 *m);
Fx_8dbb0 *__fastcall FUN_000862e0(Manager_8dbb0 *m);


class IController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual const char *v6();
};

class MyControllerCallback {
public:
    virtual void vfunc_0(IController *c);
    char f4;
    char f5;
    char pad06;
    char f7;
    char f8;
    char f9;
};

void MyControllerCallback::vfunc_0(IController *c)
{
    char connected = 0;
    if (c->v3())
        connected = 1;

    const char *name = 0;
    if (DAT_004dd700 != 0 && DAT_004dd700->mgr != 0 && FUN_000862c0(DAT_004dd700->mgr) != 0) {
        if (FUN_000862c0(DAT_004dd700->mgr)->table->name[0] != 0)
            name = FUN_000862c0(DAT_004dd700->mgr)->table->name;
    }

    f5 = 0;
    for (int i = 0; i < FUN_002684b0()->Count(); i++) {
        if (FUN_002684b0()->Get(i) != 0 && FUN_002684b0()->Get(i)->v3() != 0) {
            if (name == 0 || strcmp(name, FUN_002684b0()->Get(i)->v6()) == 0)
                f5 = 1;
        }
    }
    if (f5)
        f8 = 1;

    if (DAT_004dd700 != 0 && DAT_004dd700->mgr != 0 && FUN_000862c0(DAT_004dd700->mgr) != 0) {
        if (c->v3()) {
            Manager_8dbb0 *m = DAT_004dd700->mgr;
            FUN_000862c0(m)->FUN_000ae8a0(c->v6());
        } else {
            Manager_8dbb0 *m = DAT_004dd700->mgr;
            FUN_000862c0(m)->FUN_000ae8b0(c->v6());
        }
    }

    if (f4 != 0 && f5 == 0 && connected == 0) {
        f7 = 1;
        FUN_00086300(DAT_004dd700->mgr)->FUN_001b8160();
        FUN_00086330(DAT_004dd700->mgr)->FUN_000afe80();
        if (f9 == 0) {
            FUN_000862e0(DAT_004dd700->mgr)->FUN_001eb870();
            FUN_000862e0(DAT_004dd700->mgr)->FUN_001eb2a0(0.016666668f, 0);
            FUN_000862e0(DAT_004dd700->mgr)->FUN_001eb2a0(0.016666668f, 0);
            f9 = 1;
        }
    }
    DAT_004e222c = 1;
    (*(char*)&DAT_004ddbe1) = 1;
    (*(char*)&DAT_004e222d) = 1;
}
