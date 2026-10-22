// STATUS: equivalent (tools/equiv.py level 3: 3151 inputs, branch coverage 77/78, incomplete)
// FUN_000d8410 @ 0x000d8410
// cl-flags: /GS
#include "decls/data/game/global.h"


struct Dummy_d8410 {
    int FUN_0008c740(int zero, unsigned int *out1, int *out2);
    void FUN_0008c920();
};

struct Mid_d8410 {
    Dummy_d8410 *FUN_00089a50();
};

struct Mgr_d8410 {
    Mid_d8410 *FUN_000b5000();
};

struct Player_d8410 {
    char pad0[0x9a8];
    char busy;
};

class Game_d8410 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual int v44();
    char pad04[0x2218 - 4];
    Player_d8410 *player;
    void FUN_000e63a0();
};

Game_d8410 *FUN_000fc3d0();

struct Timer {
    int value;
    void FUN_000f8500(const char *name, int a, int flag);
};

class FEMemCardControl_d8410 {
public:
    void FUN_000d8410();

    char pad0[0x150];
    Mgr_d8410 *mgr;
    char pad154[0x1d0 - 0x154];
    int pending;
    char pad1d4[0x34c - 0x1d4];
    unsigned int kind;
    int prevState;
    int state;
    char pad358[4];
    Timer timer;
    char pad360[0x380 - 0x360];
    char started;
    char pad381[0x3ac - 0x381];
    int mode;
    char pad3b0[0x3eb - 0x3b0];
    char flag3eb;
    char pad3ec[0x418 - 0x3ec];
    int altMode;
};

void FEMemCardControl_d8410::FUN_000d8410()
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    unsigned int o1;
    int o2;

    mgr->FUN_000b5000()->FUN_00089a50()->FUN_0008c920();
    int r = mgr->FUN_000b5000()->FUN_00089a50()->FUN_0008c740(0, &o1, &o2);
    if (r == 0 && o1 < 4)
        r = 7;
    prevState = state;
    state = r;
    kind = o1;

    int handle = FUN_000fc3d0()->v44();
    timer.value = 0;
    timer.FUN_000f8500((*(const char**)&DAT_004a0c64), handle, 1);

    int old = prevState;
    int next = state;
    if (old == next && started) {
        return;
    }
    started = 1;
    int m = mode;
    int check = m;
    if (m == 0x1d)
        check = altMode;
    if (check == 4 || check == 5 || check == 6 || check == 0x1c || check == 7 || check == 0x10 || check == 0x1f) {
        return;
    }
    if (flag3eb) {
        if (old != 4 || next == old) {
            return;
        }
        for (;;) {
            Player_d8410 *pl = FUN_000fc3d0()->player;
            if (pl == 0 || !pl->busy)
                break;
            FUN_000fc3d0()->FUN_000e63a0();
        }
        if (mode == 0x1d)
            altMode = 0xf;
        else
            mode = 0xf;
        return;
    }
    if (pending != 0) {
        return;
    }
    if (m == 8 || m == 9 || m == 0xb || m == 0xc || m == 0xd || m == 0x19 || m == 0x12 || m == 0x1e || m == 0x14) {
        for (;;) {
            Player_d8410 *pl = FUN_000fc3d0()->player;
            if (pl == 0 || !pl->busy)
                break;
            FUN_000fc3d0()->FUN_000e63a0();
        }
    }
    if (mode == 0x1d)
        altMode = 0;
    else
        mode = 0;
}
