// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 32/32)
// CGrappleAttachAction::vfunc_6 @ 0x00015480
struct Vec3_15480 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_00011160(float s, Vec3_15480* d);
};

struct Mat_15480 {
    float m[12];
    Vec3_15480 t;
    float w;
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
    void FUN_0022bc20(float a, float b, float c);
    void FUN_0022c120();
    void FUN_0022c2b0(Vec3_15480* in, Vec3_15480* out);
    void FUN_0022ca90(Mat_15480* a, Mat_15480* b);
};

struct JointFinder_15480 {
    unsigned int FUN_0027b200(int a, int b);
};

struct SkeletonData_15480 {
    char pad0[8];
    JointFinder_15480* finder;
    char pad0c[0x1c - 0xc];
    Mat_15480* mats;
};

struct Resource_15480 {
    char pad0[0x64];
    SkeletonData_15480* skeleton;
};

struct IdHolder_15480 {
    Resource_15480* FUN_00059a40();
};

struct Entity {
    char pad00[0x10];
    IdHolder_15480* idHolder;
    char pad14[0x12c - 0x14];
    int f12c;
    char pad130[0x328 - 0x130];
    int f328;
    char pad32c[0x330 - 0x32c];
    Entity* p330;
    Entity* link;
    Entity* p338;
    char pad33c[0x20a8 - 0x33c];
    int f20a8;
    void FUN_000393c0();
    void FUN_00035160(Mat_15480* out);
    void FUN_0003a680(Entity* target, int a, int b, int c, Mat_15480* m, float e5, float e6, float e7);
};

struct GrappleData_15480 {
    char pad0[0x10];
    int jointA;
    int jointB;
    int f18;
    int f1c;
    unsigned char useOffset;
    char pad21[3];
    Vec3_15480 offset;
    float f30;
    Vec3_15480 v34;
    int f40;
    int f44;
    Vec3_15480 v48;
    float f54;
    float f58;
    char b5c;
    char pad5d[3];
    float f60;
    float f64;
};

void* __fastcall FUN_000592a0(void* owner);
Entity* __fastcall FUN_00059a30(void* x);
extern "C" float __cdecl FUN_00224f10(Vec3_15480* v);

union SkelOrLen {
    SkeletonData_15480* skel;
    float len;
};

class CGrappleAttachAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void* owner;
    GrappleData_15480* data;
};

char CGrappleAttachAction::vfunc_6(int arg)
{
    struct Frame {
        float tmp;
        SkelOrLen u;
        Vec3_15480 d;
        unsigned int id;
        Vec3_15480 r;
        Vec3_15480 q;
        Mat_15480 A;
        Mat_15480 C;
        Mat_15480 B;
    } f;

    Entity* a = FUN_00059a30(FUN_000592a0(owner));
    Entity* b = a->link;
    if (b == 0) {
        b = a->p330;
        if (b == 0) {
            b = a->p338;
            if (b == 0)
                return 0;
        }
    }
    if (data->b5c) {
        Entity* t = a;
        a = b;
        b = t;
    }
    Resource_15480* res = a->idHolder->FUN_00059a40();
    a->link = b;
    a->FUN_0003a680(0, -1, 0, 0, 0, data->f60, 1.0f, data->f64);
    if (a->f20a8 >= 0 && a->f328 == b->f12c)
        a->FUN_000393c0();

    f.id = 0xffff;
    f.u.skel = 0;
    if (res != 0) {
        f.u.skel = res->skeleton;
        if (f.u.skel != 0)
            f.id = f.u.skel->finder->FUN_0027b200(data->jointA, data->jointB);
    }
    if (data->useOffset) {
        f.A.FUN_0022b980();
        f.d = data->offset;
        f.A.t = f.d;
        f.r.y = data->v34.y;
        f.A.FUN_0022bc20(data->v34.x, f.r.y + data->f30, data->v34.z);
    } else {
        if (f.id != 0xffff)
            f.B = f.u.skel->mats[f.id];
        else
            a->FUN_00035160(&f.B);
        f.B.FUN_0022c120();
        b->FUN_00035160(&f.C);
        if (f.u.skel != 0 && (data->f40 | data->f44) != 0) {
            unsigned int j = f.u.skel->finder->FUN_0027b200(data->f40, data->f44);
            if (j != 0xffff) {
                f.q = data->v48;
                f.u.skel->mats[j].FUN_0022c2b0(&f.q, &f.r);
                f.d.x = f.r.x - f.C.t.x;
                f.d.y = 0.0f;
                f.d.z = f.r.z - f.C.t.z;
                f.u.len = f.d.FUN_0022d110();
                if (f.u.len > data->f54) {
                    f.tmp = FUN_00224f10(&f.d);
                    f.C.FUN_0022ba70(f.tmp);
                }
                f.tmp = data->f58;
                if (f.tmp > 0.0f && f.u.len > f.tmp)
                    f.C.t.FUN_00011160(f.u.len - f.tmp, &f.d);
            }
        }
        f.A.FUN_0022ca90(&f.C, &f.B);
    }
    b->FUN_0003a680(a, f.id, data->f18, data->f1c, &f.A, data->f60, 1.0f, data->f64);
    b->link = 0;
    return 0;
}
