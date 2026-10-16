// STATUS: equivalent (tools/equiv.py level 3: 3088 inputs, branch coverage 96/97, incomplete)
// MyDriveErrorCallback::vfunc_0 @ 0x0008e1f0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Ctl_8e1f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9(int i);
};

struct Item_8e1f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual Ctl_8e1f0 *v10(const char *name);
};

struct Mgr_8e1f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual Item_8e1f0 *v4(int i);
};

struct Fade_8e1f0 {
    void FUN_001b8160();
    void FUN_001b8110(int ms);
};

struct Audio_8e1f0 {
    void FUN_001eb870();
    void FUN_001eb2a0(float a, int b);
    void FUN_001eb890();
};

struct Pad_8e1f0 {
    void FUN_000afe80();
};

struct Sys_8e1f0 {
    Fade_8e1f0 *FUN_00086300();
    Audio_8e1f0 *FUN_000862e0();
    Pad_8e1f0 *FUN_00086330();
};

struct World {
    char pad[0x54];
    Sys_8e1f0 *f54;
    char pad58[0x9d - 0x58];
    char b9d;
};


class MyControllerCallback {
public:
    MyControllerCallback()
    {
        b5 = 0;
        b6 = 0;
        b7 = 0;
        b4 = 0;
        b8 = 0;
        b9 = 0;
    }
    virtual void v0();
    char b4;
    char b5;
    char b6;
    char b7;
    char b8;
    char b9;
};


void __cdecl FUN_001bb0b0(const char *key);
char __cdecl FUN_0008d910(int a3);
void __cdecl FUN_00240bb0();
Mgr_8e1f0 *__cdecl FUN_002684b0();
void __cdecl FUN_002684c0();
void *FUN_0008d690(unsigned int size);
MyControllerCallback *FUN_0008e090();

class MyDriveErrorCallback {
public:
    virtual char vfunc_0(unsigned int code, int a1, int a2, int a3, int a4);
    const char *f4;
    const char *f8;
    char b0c;
    char b0d;
    char b0e;
    char b0f;
};

char MyDriveErrorCallback::vfunc_0(unsigned int code, int a1, int a2, int a3, int a4)
{
    if (b0e) {
        FUN_001bb0b0(f4);
        return 1;
    }
    char result = 1;
    if (code == 0)
        b0c = 0;
    else
        b0c = 1;
    switch (code) {
    case 0:
        f8 = "No Error: Success";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_XBOX";
        result = 0;
        b0c = 0;
        break;
    case 1:
        f8 = "Error: File Not Found";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 2:
        f8 = "Error: Shell Open";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 3:
        f8 = "Error: Wrong Media";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 4:
        f8 = "Error: No Media";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 5:
        f8 = "Error: Media Not Formatted";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 6:
        f8 = "Error: Media Corrupt";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 7:
        f8 = "Error: No Free Space";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 8:
        f8 = "Error: Hardware Failure";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 9:
        f8 = "Error: Media Encoding Error";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 10:
        f8 = "Error: Media Wrong Type";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 11:
        f8 = "Error: Media Invalid";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 12:
        f8 = "Error: Data Corrupt";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    default:
        f8 = "Error: Unknown Reason";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    }

    if (code == 1) {
        if (DAT_004dd8e6) {
            result = 0;
            b0c = 0;
        }
        if (!FUN_0008d910(a3)) {
            result = 0;
            b0c = 0;
        }
    }

    if (b0c) {
        World *g = DAT_004dd700;
        if (g) {
            if (g->b9d && g->f54) {
                if (g->f54->FUN_00086300())
                    DAT_004dd700->f54->FUN_00086300()->FUN_001b8160();
                g = DAT_004dd700;
            }
            if (g) {
                if (g->b9d && g->f54) {
                    if (g->f54->FUN_000862e0()) {
                        if (!b0f) {
                            DAT_004dd700->f54->FUN_000862e0()->FUN_001eb870();
                            DAT_004dd700->f54->FUN_000862e0()->FUN_001eb2a0(0.016666668f, 0);
                            DAT_004dd700->f54->FUN_000862e0()->FUN_001eb2a0(0.016666668f, 0);
                            b0f = 1;
                        }
                        FUN_00240bb0();
                    }
                    g = DAT_004dd700;
                }
                if (g && g->b9d && g->f54 && g->f54->FUN_00086330())
                    DAT_004dd700->f54->FUN_00086330()->FUN_000afe80();
            }
        }
        if (!b0d)
            b0d = 1;
        FUN_001bb0b0(f4);
        return result;
    }

    if (!b0d)
        return result;
    b0d = 0;
    FUN_001bb0b0(f4);
    bool found = false;
    do {
        int n = FUN_002684b0()->v3();
        if (n > 0) {
            int i = 0;
            do {
                if (FUN_002684b0()->v4(i)) {
                    if (FUN_002684b0()->v4(i)->v3()) {
                        Item_8e1f0 *it = FUN_002684b0()->v4(i);
                        Ctl_8e1f0 *c1 = it->v10("Start");
                        Ctl_8e1f0 *c2 = it->v10("A");
                        if (c1->v9(0) > 0.2f || c2->v9(0) > 0.2f) {
                            found = true;
                            break;
                        }
                    }
                }
                i++;
            } while (i < FUN_002684b0()->v3());
        }
        (*(int*)&DAT_004dda40)++;
        FUN_002684c0();
    } while (!found);

    MyControllerCallback *c = (*(MyControllerCallback**)&DAT_004dd7e0);
    (*(char*)&DAT_004e222d) = 1;
    DAT_004e222c = 1;
    if (!c) {
        void *m = FUN_0008d690(0xc);
        if (m)
            c = new (m) MyControllerCallback;
        else
            c = 0;
        (*(MyControllerCallback**)&DAT_004dd7e0) = c;
    }
    if (c->b5) {
        World *g = DAT_004dd700;
        if (g) {
            if (g->b9d && g->f54) {
                if (g->f54->FUN_00086300()) {
                    DAT_004dd700->f54->FUN_00086300()->FUN_001b8110(500);
                }
                g = DAT_004dd700;
            }
            if (g && g->b9d && g->f54 && g->f54->FUN_000862e0()) {
                DAT_004dd700->f54->FUN_000862e0()->FUN_001eb890();
                b0f = 0;
                FUN_0008e090()->b9 = 0;
            }
        }
    }
    return result;
}
