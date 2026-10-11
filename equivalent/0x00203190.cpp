// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 13/14, incomplete)
// FUN_00203190 @ 0x00203190
struct V3 {
    float x, y, z;
};

struct Hit {
    int kind;
    int pad4[5];
    char flag;
};

struct Target {
    char pad0[0xc];
    int kind;
};

struct Weapon {
    char pad0[0x1b0];
    int f1b0;
};

struct Actor {
    char pad0[0x11c];
    Weapon *weapon;
    char pad120[0x1ca4 - 0x120];
    struct Tracer *tracer;
    void FUN_000368d0(int a);
};

struct Game;

struct Tracer {
    bool FUN_0010aa90(Game *g, V3 *a, V3 *b, float scale, V3 *o3, V3 *o2, V3 *o1,
                      Actor *actor, Target *t, int zero0, int zero1);
};

struct Probe {
    bool FUN_00201e00(V3 *a, V3 *b, int one, V3 *o1, V3 *o2, int zero0, int zero1);
};

struct Camera {
    void FUN_00025260(int a, int b, int c);
    void FUN_000253c0(int a);
    void FUN_00025310(int a, int b);
};

struct Exec {
    bool FUN_002edce0(Hit *h, V3 *a, V3 *b, int zero);
};

struct Holder10 {
    char pad0[8];
    Exec *exec;
};

struct Game {
    char pad0[0x10];
    Holder10 *holder;
    char pad14[0x20 - 0x14];
    Camera *camera;
    Probe *probe;
};

extern Game *DAT_004dd700;

bool __cdecl FUN_00202c30(V3 *a, V3 *b, float c, int one, V3 *o3, V3 *o2, int p3, Target *t, int p5, Actor *actor);

struct Frame {
    V3 diff;
    V3 o2;
    V3 o3;
    Hit hit;
};

bool FUN_00203190(V3 *a1, V3 *a2, int a3, Target *a4, int a5, Actor *a6)
{
    Frame f;
    Game *game = DAT_004dd700;

    if (a4 && a4->kind != 1) {
        f.diff.x = a2->x - a1->x;
        f.diff.y = a2->y - a1->y;
        f.diff.z = a2->z - a1->z;
        if (a6 && a6->tracer)
            return a6->tracer->FUN_0010aa90(game, a1, a2, 0.5f, &f.o3, &f.o2, &f.diff, a6, a4, 0, 0);
        return FUN_00202c30(a1, a2, 0.1f, 1, &f.o3, &f.o2, a3, a4, a5, a6);
    }

    if (game->probe->FUN_00201e00(a1, a2, 1, &f.o2, &f.o3, 0, 0))
        return false;

    Camera *cam = game->camera;
    cam->FUN_00025260(0, 0, 0);
    cam->FUN_000253c0(0);
    if (a6) {
        cam->FUN_00025310(a6->weapon->f1b0, 1);
        a6->FUN_000368d0(0);
    }
    f.hit.kind = 2;
    f.hit.pad4[0] = 0;
    f.hit.pad4[1] = 0;
    f.hit.pad4[2] = 0;
    f.hit.pad4[3] = 0;
    f.hit.pad4[4] = 0;
    f.hit.flag = 1;
    bool hit = game->holder->exec->FUN_002edce0(&f.hit, a1, a2, 0);
    cam->FUN_000253c0(1);
    cam->FUN_00025260(1, 0, 0);
    return !hit;
}
