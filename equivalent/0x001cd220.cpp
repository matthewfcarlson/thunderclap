// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 18/18)
// FUN_001cd220 @ 0x001cd220
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

struct Msg {
    int w0, w1, w2, w3, w4, w5;
    Msg *FUN_001ca060(int v);
    Msg *FUN_001ca0d0();
};

struct Sink {
    int FUN_001cbc20(Msg *m);
};

struct Loader {
    int FUN_001d3600(char *path, int flag);
};

struct Visibility {
    void FUN_000d6fb0(char v);
};

struct Child {
    char pad00[0x3c];
    Visibility *vis;
};

struct Holder {
    char pad00[0xc];
    Child *child;
};

extern Holder *DAT_004dd6ec;

struct Obj24 {
    int FUN_001b9130(int v);
};

struct Obj28 {
    int FUN_002088a0();
    int FUN_002089f0();
};

struct Obj54 {
    Obj24 *FUN_00086290();
    Obj28 *FUN_000862a0();
};

struct Game {
    char pad00[0x54];
    Obj54 *f54;
};

extern Game *DAT_004dd700;

extern Loader *__cdecl FUN_001d4c90();

struct Names {
    char *FUN_000897e0();
    char *FUN_000897f0();
    char *FUN_0008a2d0();
};

struct Target4 {
    char pad00[0x30];
    Sink *sink;
};

struct Frame {
    Msg msg;
    char buf[0x80];
    unsigned int cookie;
};

struct Slot {
    char used;
    char pad[0x1f];
};

class Mission {
public:
    char pad00[4];
    Target4 *f4;
    Names *names;
    int f0c;
    char pad10[0x1190 - 0x10];
    int f1190;
    int f1194;
    int f1198;
    float f119c;
    char b11a0;
    char pad11a1[0x1418 - 0x11a1];
    Slot slots[4];
    int slotVals[4];
    void FUN_001ccb80();
    void FUN_001cd220(char flag);
};

void Mission::FUN_001cd220(char flag)
{
    Frame f;
    f.cookie = DAT_004d9968;
    f0c = 0;
    f1198 = 0;
    b11a0 = 0;
    f119c = -1.0f;
    FUN_001ccb80();
    for (int i = 0; i < 4; i++) {
        slots[i].used = 0;
        slotVals[i] = 0;
    }
    Loader *loader = FUN_001d4c90();
    if (loader) {
        Holder *h = DAT_004dd6ec;
        if (h && h->child && h->child->vis)
            h->child->vis->FUN_000d6fb0(0);
        DAT_004dd700->f54->FUN_00086290()->FUN_001b9130(0);
        if (flag) {
            char *a = names->FUN_000897f0();
            char *b = names->FUN_000897e0();
            FUN_00267760(f.buf, 0x80, "art/locations/%s/%s.lua", b, a);
            loader->FUN_001d3600(f.buf, 0);
            char *c = names->FUN_0008a2d0();
            char *d = names->FUN_0008a2d0();
            FUN_00267760(f.buf, 0x80, "art/missions/%s/%s.lua", d, c);
            loader->FUN_001d3600(f.buf, 0);
        }
        DAT_004dd700->f54->FUN_000862a0()->FUN_002088a0();
        DAT_004dd700->f54->FUN_000862a0()->FUN_002089f0();
        if (f4) {
            Sink *sink = f4->sink;
            if (sink) {
                if (flag) {
                    f.msg.FUN_001ca0d0();
                } else {
                    f.msg.FUN_001ca060(f1194);
                }
                sink->FUN_001cbc20(&f.msg);
            }
        }
    }
    __security_check_cookie(f.cookie);
}
