// STATUS: equivalent (tools/equiv.py level 3: 136 inputs, branch coverage 63/63)
// FUN_00013f20 @ 0x00013f20
struct Slot_13f20;
struct Slot_13f20 {
    int FUN_001d5e80(int id);
};
struct Pad_13f20 {
    char pad0[0x40];
    int id;
    char pad44[0xec - 0x44];
    Slot_13f20 *slot;
    void FUN_001d6ec0(int a, int b, int c);
};
struct Cfg_13f20 {
    char pad0[0x3c];
    char forceMax;          // 0x3c
    char pad3d[3];
    int count;              // 0x40
    char pad44[4];
    int mode;               // 0x48
    char pad4c[0xb8 - 0x4c];
    float lo;               // 0xb8
    float hi;               // 0xbc
};
struct Ctrl2 {
    char pad0[0x170];
    float mult;             // 0x170
    char pad174[0x30c - 0x174];
    float scale;            // 0x30c
};
struct Player_13f20 {
    char pad0[0x11c];
    Ctrl2 *ctrl;            // 0x11c
    char pad120[0x12c - 0x120];
    int val;                // 0x12c
    char pad130[0x1b28 - 0x130];
    int flag;               // 0x1b28
    float FUN_0003ebb0(int a);
    Pad_13f20 *FUN_00035ef0(int idx);
};
struct PlayerRef_13f20 {
    Player_13f20 *FUN_00059a30();
};
struct Owner_13f20 {
    PlayerRef_13f20 *FUN_000592a0();
};
struct Item_13f20 {
    char pad0[0x10];
    char dead;              // 0x10
    char pad11[3];
    int kind;               // 0x14
};
struct Holder_13f20 {
    char pad0[0x11c];
    Item_13f20 *item;             // 0x11c
};
struct Target_13f20 {
    char pad0[8];
    Holder_13f20 *holder;         // 8
    int type;               // 0xc
};
struct Text_13f20 {
    char pad0[4];
    void FUN_000d4620(int a, const char *s, int b, int c, float d);
};
struct Hud_13f20 {
    char pad0[4];
    Text_13f20 *text;             // 4
};
struct Flags_13f20 {
    bool FUN_00092940(int id);
};
struct Opt_13f20 {
    Flags_13f20 *FUN_00086340();
};
struct Game_13f20 {
    char pad0[0x20];
    struct Me_13f20 *me;          // 0x20
    char pad24[0x3c - 0x24];
    Hud_13f20 *hud;               // 0x3c
    char pad40[0x54 - 0x40];
    Opt_13f20 *opt;               // 0x54
};
struct Me_13f20 {
    char pad0[0x124];
    Player_13f20 *player;         // 0x124
    const char *FUN_00025890(int a);
    int *FUN_00025930(void *out, int a);
};

extern Game_13f20 *DAT_004dd700;

struct Self_13f20 {
    char pad0[0x1c];
    Owner_13f20 *owner;           // 0x1c
    Cfg_13f20 *cfg;               // 0x20
    char pad24[0x34 - 0x24];
    int state;              // 0x34
    void FUN_00013f20(float k, Target_13f20 *t, float *outA, float *outB);
};

void Self_13f20::FUN_00013f20(float k, Target_13f20 *t, float *outA, float *outB)
{
    Game_13f20 *g = DAT_004dd700;
    Me_13f20 *me = g->me;
    Player_13f20 *p = owner->FUN_000592a0()->FUN_00059a30();
    float r = p->FUN_0003ebb0(1);
    *outB = r;
    float v = cfg->lo;
    *outA = v;
    float hi = cfg->hi;
    if (hi > 0.0f)
        *outA = v + (hi - v) * r;
    if (p->flag != 0 || cfg->forceMax != 0)
        *outB = 1.0f;
    *outA = k * *outA;
    int count = cfg->count;
    if (count > 0) {
        int f0, f1;
        if (p->FUN_00035ef0(0) != 0) {
            int id = p->FUN_00035ef0(0)->id;
            f0 = p->FUN_00035ef0(0)->slot->FUN_001d5e80(id) == 1;
        } else {
            f0 = 0;
        }
        if (p->FUN_00035ef0(1) != 0) {
            int id = p->FUN_00035ef0(1)->id;
            int r = p->FUN_00035ef0(1)->slot->FUN_001d5e80(id);
            f1 = (r == 1) ? 1 : 0;
        } else {
            f1 = 0;
        }
        f1 <<= 1;
        int m = (f1 | f0) & count;
        if (m != 0) {
            *outA = *outA + *outA;
            *outB = 1.0f;
            if (state == 1) {
                if ((f0 & m) != 0 && p->FUN_00035ef0(0) != 0)
                    p->FUN_00035ef0(0)->FUN_001d6ec0(4, p->val, 1);
                if ((f1 & m) != 0 && p->FUN_00035ef0(1) != 0)
                    p->FUN_00035ef0(1)->FUN_001d6ec0(4, p->val, 1);
            }
        }
    }
    {
        float s = p->ctrl->scale;
        if (p->flag != 0)
            s = s * p->ctrl->mult;
        *outA = s * *outA;
    }
    if (t != 0) {
        int mode = cfg->mode;
        if (t->type == 1 && t->holder != 0 && t->holder->item != 0) {
            Item_13f20 *it = t->holder->item;
            if (it->dead == 0) {
                int kind = it->kind;
                bool ok = false;
                switch (mode) {
                case 1: ok = (kind == 0); break;
                case 2: ok = (kind == 1); break;
                case 3:
                case 4: ok = (kind == 2 || kind == 3); break;
                case 5:
                case 6: ok = (kind == 4); break;
                case 7:
                case 8: ok = (kind == 5); break;
                default: break;
                }
                if (ok) {
                    *outA = *outA + *outA;
                    const char *s = me->FUN_00025890(mode - 1);
                    if (s != 0 && *s != 0) {
                        int sink[2];
                        Text_13f20 *txt = g->hud->text;
                        int *r = me->FUN_00025930(sink, 1);
                        txt->FUN_000d4620(1, s, -1, *r, -1.0f);
                    }
                }
            }
        }
    }
    if (me->player == p) {
        if (g->opt->FUN_00086340()->FUN_00092940(0x2e1))
            *outA = 100000.0f;
    }
}
