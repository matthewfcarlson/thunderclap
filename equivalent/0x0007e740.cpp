// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 20/20)
// FUN_0007e740 @ 0x0007e740
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" double sin(double);
extern "C" double cos(double);

extern unsigned int DAT_004d9968;
extern int DAT_004dd074;
extern float DAT_003f32e0;
extern float DAT_003feed8;  // 80
extern float DAT_003fef48;  // 10
extern float DAT_003f7548;  // 0.8
extern float DAT_0049b8ac;  // -1
extern float DAT_0049b8b0;  // 3
extern float DAT_0049b8b4;  // 9

struct V3_7e740 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mgr10_7e740 {
    bool FUN_00059a50(V3_7e740 *out);
};

struct Player_7e740 {
    char pad0[0x10];
    Mgr10_7e740 *f10;
    void FUN_00035660(V3_7e740 *out);
    void FUN_00035550(V3_7e740 *out);
};

struct Zone_7e740 {
    char pad0[0x124];
    Player_7e740 *player;         // 0x124
};

struct Rng_7e740 {
    float FUN_000787e0(float lo, float hi);
};

struct Cells {
    int FUN_00204200(V3_7e740 pos);
};

struct Grid_7e740 {
    Cells *FUN_000862a0();
};

struct Mgr382c {
    char pad0[0x20];
    Zone_7e740 *zone;             // 0x20
    char pad24[0x54 - 0x24];
    Grid_7e740 *grid;             // 0x54
};

struct Item_7e740 {
    V3_7e740 *FUN_00082cf0();
};

struct Cell_7e740 {
    char pad0[3];
    char flag;
    int next;
};

Rng_7e740 *FUN_000964d0();
void FUN_00224d70(float angle, V3_7e740 *v);
char __cdecl FUN_00202560(V3_7e740 *origin, float dist, int a, V3_7e740 *outB, V3_7e740 *outA, int b, int c, int d);
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

class Game_7e740 {
public:
    char pad0[8];
    Cell_7e740 cells[0x6ff];      // 0x8
    Item_7e740 *items[10];        // 0x3800
    int count;              // 0x3828
    Mgr382c *mgr;           // 0x382c
    void FUN_0007de00(const char *name, int zero, V3_7e740 pos, V3_7e740 dir);
    void FUN_0007e740();
};

void Game_7e740::FUN_0007e740()
{
    struct Frame {
        V3_7e740 q;
        V3_7e740 w;
        float ang;
        V3_7e740 p;
        V3_7e740 r2;
        V3_7e740 r1;
        char name[0x20];
        unsigned int cookie;
    } f;

    f.cookie = DAT_004d9968;
    Player_7e740 *pl = mgr->zone->player;
    pl->f10->FUN_00059a50(&f.p);
    pl->FUN_00035660(&f.q);
    if (f.q.x == DAT_003f32e0 && f.q.z == DAT_003f32e0)
        pl->FUN_00035550(&f.q);
    f.q.y = 0.0f;
    f.q.FUN_0022d110();
    f.ang = FUN_000964d0()->FUN_000787e0(-1.5707964f, 1.5707964f);
    FUN_00224d70(f.ang, &f.q);

    f.q.x = f.q.x * DAT_003feed8;
    f.q.y = f.q.y * DAT_003feed8;
    f.q.z = f.q.z * DAT_003feed8;
    f.q.x = f.p.x + f.q.x;
    f.q.y = f.p.y + f.q.y;
    f.q.z = f.p.z + f.q.z;

    Cells *grid = mgr->grid->FUN_000862a0();
    int idx = grid->FUN_00204200(f.q);
    if (cells[idx].flag) {
        f.q.y = f.q.y + DAT_003fef48;
        if (FUN_00202560(&f.q, 20.0f, 0, &f.r2, &f.r1, 0, 0, 0)) {
            if (!(f.r1.y < DAT_003f7548) && !(f.r2.y < DAT_0049b8ac) && !(f.r2.y > DAT_0049b8b0)) {
                f.q.y = f.r2.y;
                bool blocked = false;
                for (int i = count - 1; i >= 0; i--) {
                    V3_7e740 *wp = items[i]->FUN_00082cf0();
                    f.w = *wp;
                    if ((f.w.y - f.q.y) * (f.w.y - f.q.y) + (f.w.z - f.q.z) * (f.w.z - f.q.z) + (f.w.x - f.q.x) * (f.w.x - f.q.x) < DAT_0049b8b4) {
                        blocked = true;
                        break;
                    }
                }
                if (!blocked) {
                    float phi = FUN_000964d0()->FUN_000787e0(0.0f, 6.2831855f);
                    int n = DAT_004dd074 + 1;
                    DAT_004dd074 = n;
                    f.w.x = (float)cos((double)phi);
                    f.w.y = 0.0f;
                    f.w.z = (float)sin((double)phi);
                    FUN_000964a0(f.name, 0x20, "cow%d", n);
                    FUN_0007de00(f.name, 0, f.q, f.w);
                }
            }
        }
    }
    __security_check_cookie(f.cookie);
}
