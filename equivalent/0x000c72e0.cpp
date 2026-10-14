// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_000c72e0 @ 0x000c72e0
extern "C" double sqrt(double);

struct Mat_c72e0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bab0(float angle);
};

struct V3_c72e0 {
    float x, y, z;
    void FUN_0022d210(const Mat_c72e0 *m);
    void FUN_0022d110();
};

struct V4_c72e0 { float x, y, z, w; };

struct Cam_c72e0 {
    char FUN_001c4050(V4_c72e0 *p);
    const Mat_c72e0 *FUN_001c3fd0();
};

struct Pos_c72e0 {
    void FUN_00059a50(V3_c72e0 *out);
};

struct Fade_c72e0 {
    virtual void v0();
    virtual void v1();
    Fade_c72e0 *FUN_0028ee60(int tag, float f);
};

struct Eff_c72e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(Fade_c72e0 *f);
    virtual void v14();
};

struct Mgr_c72e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
    virtual void v17(int a, Mat_c72e0 *m);
};

struct Meter_c72e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual float v16();
};

struct Holder_c72e0 {
    Mgr_c72e0 *mgr;
    void FUN_00293d00(V3_c72e0 *p);
    void FUN_00293da0(float a, float b, float c);
};

struct Player_c72e0 {
    char pad0[0x10];
    Pos_c72e0 *pos;               // 0x10
};

struct Me_c72e0 {
    char pad0[0x124];
    Player_c72e0 *player;         // 0x124
};

struct Game_c72e0 {
    char pad0[0x20];
    Me_c72e0 *me;                 // 0x20
};

struct Slot_c72e0 {
    Eff_c72e0 *a;
    Eff_c72e0 *b;
};

struct Entry_c72e0 {
    int idx;
    V3_c72e0 p;
    char pad10[0x10];
};

extern Game_c72e0 *DAT_004dd700;
extern Meter_c72e0 *DAT_0052c2a4;
extern Holder_c72e0 *DAT_0052c2ac;
extern float DAT_0049fb8c;
extern Cam_c72e0 *FUN_001c3d90();
extern float FUN_00018a20(float x);
extern void *FUN_0008d690(unsigned int size);

struct Self_c72e0 {
    char pad0[0x10];
    char active;            // 0x10
    char pad11[3];
    Slot_c72e0 slots[1];          // 0x14
    char pad1c[0x60 - 0x1c];
    Entry_c72e0 entries[16];      // 0x60
    void FUN_000c72e0();
};

void Self_c72e0::FUN_000c72e0()
{
    if (!active)
        return;
    for (int n = 0; n < 16; n++) {
        Entry_c72e0 *e = &entries[n];
        if (e->idx == -1)
            continue;
        V3_c72e0 pos;
        DAT_004dd700->me->player->pos->FUN_00059a50(&pos);
        float dx = e->p.x - pos.x;
        float dz = e->p.z - pos.z;
        Cam_c72e0 *cam = FUN_001c3d90();
        V4_c72e0 v4;
        v4.x = e->p.x;
        v4.y = e->p.y;
        v4.z = e->p.z;
        v4.w = 1.0f;
        if (cam->FUN_001c4050(&v4) == 1)
            continue;
        const Mat_c72e0 *src = cam->FUN_001c3fd0();
        float pz = e->p.z;
        float px = e->p.x;
        Mat_c72e0 M = *src;
        V3_c72e0 P;
        P.x = px;
        P.y = e->p.y;
        P.z = pz;
        P.FUN_0022d210(&M);
        P.z = 0.0f;
        P.FUN_0022d110();
        float c = DAT_0049fb8c;
        P.z = c;
        float angle = FUN_00018a20(P.x * 0.0f + P.y);
        double t = DAT_0052c2a4->v16() * P.x * 0.65f;
        P.x = (float)t;
        P.y = P.y * 0.65f;
        if (t > 0.0)
            angle = -angle;
        Mat_c72e0 Q;
        Q.FUN_0022b980();
        Q.FUN_0022bab0(angle);
        DAT_0052c2ac->mgr->v15(0);
        DAT_0052c2ac->mgr->v13(0);
        DAT_0052c2ac->FUN_00293d00(&P);
        DAT_0052c2ac->FUN_00293da0(0.075f, 0.075f, 0.075f);
        double d = sqrt(dz * dz + dx * dx);
        if (d > 60.0f)
            d = 60.0f;
        float f = (float)(d / 60.0f * 0.6f);
        void *mem = FUN_0008d690(0x10);
        Fade_c72e0 *fd = 0;
        if (mem != 0)
            fd = ((Fade_c72e0 *)mem)->FUN_0028ee60(0x45444146, f);
        fd->v0();
        int i0 = e->idx;
        if (slots[i0].a != 0) {
            slots[i0].a->v13(fd);
            slots[e->idx].a->v8(0, 0);
            slots[e->idx].a->v14();
        }
        DAT_0052c2ac->mgr->v17(0, &Q);
        int i1 = e->idx;
        if (slots[i1].b != 0) {
            slots[i1].b->v13(fd);
            slots[e->idx].b->v8(0, 0);
            slots[e->idx].b->v14();
        }
        DAT_0052c2ac->mgr->v16(0);
        fd->v1();
    }
}
