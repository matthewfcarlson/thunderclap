// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 33/34, incomplete)
// FUN_0003aaf0 @ 0x0003aaf0
struct V3_3aaf0 {
    float x, y, z;
    float FUN_000111f0();
};

struct Ref_3aaf0 { int FUN_001d64a0(); };

struct Ent_3aaf0 {
    char pad0[8];
    Ref_3aaf0* ref;
    int type;
};

struct Cam_3aaf0 { bool FUN_00059a50(V3_3aaf0* out); };

struct Host_3aaf0 {
    char pad0[0x10];
    Cam_3aaf0* cam;
    char pad14[0x14c - 0x14];
    Ent_3aaf0* current;
    char pad150[0x3a4 - 0x150];
    Ent_3aaf0* target;

    bool FUN_0003a9d0(Ent_3aaf0* e);
    bool FUN_0003a830(Ent_3aaf0* e, V3_3aaf0* out);
    bool FUN_00039440(Ent_3aaf0* e, V3_3aaf0* a, int* b, int c);

    bool Select(Ent_3aaf0* e);
};

static int Rank(Ent_3aaf0* e)
{
    int t = 0;
    if (e->type == 5) t = e->ref->FUN_001d64a0();
    if (t == 2 || t == 17) return -1;
    if (t == 3 || t == 4 || t == 6 || t == 7 || t == 18 || t == 19) return -3;
    if (t == 5 || t == 20) return -2;
    if (t == 8 || t == 9 || t == 10 || t == 12) return -4;
    return 0;
}

bool Host_3aaf0::Select(Ent_3aaf0* e)
{
    if (e == 0 || e == current) return 0;
    if (target == 0) return FUN_0003a9d0(e);

    V3_3aaf0 camPos;
    camPos.x = 0; camPos.y = 0; camPos.z = 0;
    cam->FUN_00059a50(&camPos);
    V3_3aaf0 ePos;
    if (!FUN_0003a830(e, &ePos)) return 0;

    int rankNew = Rank(e);
    V3_3aaf0 tPos;
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
