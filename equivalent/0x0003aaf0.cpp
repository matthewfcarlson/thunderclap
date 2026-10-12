// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 33/34, incomplete)
// FUN_0003aaf0 @ 0x0003aaf0
struct V3 {
    float x, y, z;
    float FUN_000111f0();
};

struct Ref { int FUN_001d64a0(); };

struct Ent {
    char pad0[8];
    Ref* ref;
    int type;
};

struct Cam { bool FUN_00059a50(V3* out); };

struct Host {
    char pad0[0x10];
    Cam* cam;
    char pad14[0x14c - 0x14];
    Ent* current;
    char pad150[0x3a4 - 0x150];
    Ent* target;

    bool FUN_0003a9d0(Ent* e);
    bool FUN_0003a830(Ent* e, V3* out);
    bool FUN_00039440(Ent* e, V3* a, int* b, int c);

    bool Select(Ent* e);
};

static int Rank(Ent* e)
{
    int t = 0;
    if (e->type == 5) t = e->ref->FUN_001d64a0();
    if (t == 2 || t == 17) return -1;
    if (t == 3 || t == 4 || t == 6 || t == 7 || t == 18 || t == 19) return -3;
    if (t == 5 || t == 20) return -2;
    if (t == 8 || t == 9 || t == 10 || t == 12) return -4;
    return 0;
}

bool Host::Select(Ent* e)
{
    if (e == 0 || e == current) return 0;
    if (target == 0) return FUN_0003a9d0(e);

    V3 camPos;
    camPos.x = 0; camPos.y = 0; camPos.z = 0;
    cam->FUN_00059a50(&camPos);
    V3 ePos;
    if (!FUN_0003a830(e, &ePos)) return 0;

    int rankNew = Rank(e);
    V3 tPos;
    int extra = 0;
    if (FUN_00039440(target, &tPos, &extra, 0)) {
        int rankOld = Rank(target);
        if (rankNew < rankOld) return FUN_0003a9d0(e);
        if (rankNew > rankOld) return 0;
        tPos.x -= camPos.x; tPos.y -= camPos.y; tPos.z -= camPos.z;
        ePos.x -= camPos.x; ePos.y -= camPos.y; ePos.z -= camPos.z;
        float lenNew = ePos.FUN_000111f0();
        float lenOld = tPos.FUN_000111f0();
        if (lenOld <= lenNew) return 0;
    }
    return FUN_0003a9d0(e);
}
