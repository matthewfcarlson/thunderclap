// STATUS: equivalent (tools/equiv.py level 3: 3106 inputs, branch coverage 70/76, incomplete)
// FUN_000c5180 @ 0x000c5180
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int strcmp(const char *, const char *);
extern "C" char *__cdecl strncpy(char *, const char *, unsigned int);

extern unsigned int DAT_004d9968;

class Menu_c5180;


class Node {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual const char *vfunc_8();
};

class Service_c5180 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int a);
};

class Timer {
public:
    void FUN_000b0080(int dt);
};

class Source_c5180 {
public:
    void *FUN_000862d0();
    Timer *FUN_00086330();
    int FUN_00086300();
};

class Probe_c5180 {
public:
    char pad0[0x2218];
    struct Flags_c5180 *flags;
};

struct Flags_c5180 {
    char pad0[0x9a8];
    char enabled;
};

class Block4_c5180 {
public:
    int f0;
    int f4;
};

class Target34 {
public:
    void FUN_00089880(int *a, int *b);
};

class Hooked {
public:
    void FUN_00086400();
};

class Aux54 {
public:
    void FUN_001b8ae0();
};

class Aux5c {
public:
    void FUN_001c04e0(int dt);
};

class Aux38 {
public:
    int FUN_001cc840();
};

struct Flag4 {
    char pad0[4];
    char on;
};

void FUN_000fc150();
void FUN_000fc280(const char *s);
void FUN_000fc340(const char *s);
void FUN_000fc170(int v);
void FUN_000fc330();
Probe_c5180 *FUN_000fc3d0();
Node *FUN_000fc310();
Flag4 *FUN_0008e090();

extern char DAT_004e222c;
extern Service_c5180 *DAT_0052c2a8;

struct Frame_c5180 {
    Node *cur;
    char name[0x40];
    unsigned int cookie;
};

class Menu_c5180 {
public:
    char pad0[0x10];
    int state;
    char pad14[0x30 - 0x14];
    void *f30;
    Target34 *f34;
    Aux38 *f38;
    int f3c;
    Block4_c5180 *f40;
    char pad44[0x54 - 0x44];
    Aux54 *f54;
    char pad58[4];
    Aux5c *f5c;
    char pad60[0x1a06 - 0x60];
    char f1a06;
    char pad1a07[0x1c8c - 0x1a07];
    char pendingName[0x20];
    char savedName[0x40];
    char pad1cec[0x1cfc - 0x1cec];
    float f1cfc;
    char pad1d00[0x1d34 - 0x1d00];
    float f1d34;
    void FUN_000b9090(int dt);
    void FUN_000bfbe0(Source_c5180 *src, int dt);
    void FUN_000b8c50(const char *a, const char *b);
    void FUN_000b9620();
    void FUN_000b9ad0();
    void FUN_000c4220(int a);
    void FUN_000c2990(int a);
    void FUN_000c3db0();
    void FUN_000b9650();
    void FUN_000b96e0();
    void FUN_000be100();
    void FUN_000b9770();
    void FUN_000b9830();
    void FUN_000b97d0();
    void FUN_000bcf40(void *a);
    void FUN_000b90c0(int a);
    void FUN_000c5180(Source_c5180 *src, void *a1, float dt, int a3, Aux54 *a4);
};

void Menu_c5180::FUN_000c5180(Source_c5180 *src, void *a1, float dt, int a3, Aux54 *a4)
{
    Frame_c5180 f;
    f.cookie = DAT_004d9968;
    Block4_c5180 *blk = f40;
    f30 = a1;
    f3c = a3;
    blk->f4 = a3;
    void *res = src->FUN_000862d0();
    int dtBits = *(int *)&dt;
    f54 = a4;
    src->FUN_00086330()->FUN_000b0080(dtBits);
    Probe_c5180 *probe = FUN_000fc3d0();
    if (probe->flags && probe->flags->enabled)
        f1d34 = dt + f1d34;
    f1cfc = dt + f1cfc;

    switch (state) {
    case 0:
        FUN_000fc170(dtBits);
        f.cur = FUN_000fc310();
        if (f.cur) {
            if (strcmp(f.cur->vfunc_8(), "main") == 0)
                FUN_000bfbe0(src, dtBits);
            if (strcmp(f.cur->vfunc_8(), "credits") == 0) {
                FUN_000b9620();
            } else {
                f54->FUN_001b8ae0();
            }
        } else {
            f54->FUN_001b8ae0();
        }
        if (f1a06 && f3c)
            FUN_000b9ad0();
        if (f.cur && strcmp(f.cur->vfunc_8(), "blonsky_file") == 0) {
            if (f5c)
                f5c->FUN_001c04e0(dtBits);
        }
        break;
    case 1:
        FUN_000fc150();
        FUN_000fc280("splash");
        state = 2;
        break;
    case 2:
        FUN_000fc170(dtBits);
        FUN_000bfbe0(src, dtBits);
        break;
    case 4:
        FUN_0008e090()->on = 1;
        FUN_000fc150();
        FUN_000fc340("main");
        FUN_000fc280("story_mode");
        state = 0;
        if (f34) {
            int *outA = (int *)&dt;
            int *outB = (int *)&src;
            f34->FUN_00089880(outA, outB);
            if (*outA >= 0 && *outB >= 0) {
                FUN_000b8c50("story_mode", "story_mode_continue_game");
                FUN_000b8c50("main", "main_story_mode");
            }
        }
        break;
    case 5:
        FUN_0008e090()->on = 1;
        FUN_000fc150();
        FUN_000fc330();
        if (strcmp(pendingName, "computer_interface") == 0) {
            FUN_000fc340("main");
            FUN_000fc340("story_mode");
            FUN_000fc280("computer_interface");
        } else if (strcmp(pendingName, "buy_menu") == 0) {
            FUN_000fc340("main");
            FUN_000fc340("story_mode");
            FUN_000fc340("computer_interface");
            FUN_000fc280("buy_menu");
        } else if (strcmp(pendingName, "side_missions") == 0) {
            FUN_000fc340("main");
            FUN_000fc340("story_mode");
            FUN_000fc340("computer_interface");
            FUN_000fc280("side_missions");
        } else {
            FUN_000fc280("main");
            state = 0;
            break;
        }
        FUN_000b8c50("story_mode", "story_mode_continue_game");
        FUN_000b8c50("main", "main_story_mode");
        state = 0;
        pendingName[0] = 0;
        break;
    case 7:
        FUN_000c4220(src->FUN_00086300());
        break;
    case 8:
        FUN_000fc170(dtBits);
        FUN_000bcf40(res);
        break;
    case 9:
        f.name[0] = 0;
        if (FUN_000fc310()) {
            if (FUN_000fc310()->vfunc_8()) {
                const char *s = FUN_000fc310()->vfunc_8();
                char *d = f.name;
                char c;
                do {
                    c = *s++;
                    *d++ = c;
                } while (c);
            }
        }
        FUN_000fc170(dtBits);
        if (FUN_000fc310() == 0) {
            if (strcmp(f.name, "pause") == 0 || strcmp(f.name, "location_map") == 0 ||
                strcmp(f.name, "mission_objectives") == 0 || strcmp(f.name, "options") == 0 ||
                strcmp(f.name, "move_gallery") == 0)
                strncpy(savedName, f.name, 0x40);
            state = 8;
            if (f30)
                ((Hooked *)f30)->FUN_00086400();
            DAT_004e222c = 1;
            if (f38->FUN_001cc840() == 5)
                DAT_0052c2a8->vfunc_12(1);
            FUN_000b90c0(0);
        }
        break;
    case 10:
    case 15:
        FUN_000fc170(dtBits);
        break;
    case 12:
        FUN_000c3db0();
        break;
    case 13:
        FUN_000c2990(src->FUN_00086300());
        break;
    case 16:
        FUN_000fc150();
        FUN_000fc280("init_mem_check");
        FUN_000fc170(0);
        state = 0x11;
        break;
    case 17:
        FUN_000b9090(dtBits);
        break;
    case 18:
        FUN_000fc170(dtBits);
        FUN_000b9650();
        break;
    case 19:
        FUN_000fc170(dtBits);
        FUN_000b96e0();
        break;
    case 20:
        FUN_000fc170(dtBits);
        FUN_000b9770();
        break;
    case 21:
        FUN_000fc170(dtBits);
        FUN_000b97d0();
        break;
    case 22:
        FUN_000fc170(dtBits);
        FUN_000b9830();
        break;
    case 23:
        FUN_000fc170(dtBits);
        FUN_000be100();
        break;
    }
    __security_check_cookie(f.cookie);
}
