// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 14/14)
// CSmartPropSpawnAction::vfunc_7 @ 0x00015e40
struct Vec3_15e40 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat_15e40 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022c120();
    void FUN_0022ca90(Mat_15e40 *a, Mat_15e40 *b);
};

struct JointFinder_15e40 {
    unsigned int FUN_0027b200(int lo, int hi);
};

struct SkeletonData_15e40 {
    char pad0[8];
    JointFinder_15e40 *finder;
    char pad0c[0x1c - 0xc];
    Mat_15e40 *mats;
};

struct Body_15e40 {
    char pad0[0x64];
    SkeletonData_15e40 *skeleton;
};

struct Fighter_15e40 {
    char pad[4];
};

struct Entity {
    void FUN_00035160(Mat_15e40 *out);
    void FUN_0003acf0(int a, void *b, unsigned int joint, int p1, int p2, Mat_15e40 *m);
};

class MatSource_15e40 {
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
    virtual Mat_15e40 *getMat();
};

struct SpawnData {
    char pad0[0x90];
    int f90;
    char pad94[4];
    int idLo;
    int idHi;
    int p1;
    int p2;
    char hasEuler;
    char pada9[3];
    Vec3_15e40 anchor;
    Vec3_15e40 euler;
    float stiffness;
};

Fighter_15e40 *__fastcall FUN_000592a0(void *owner);
Entity *__fastcall FUN_00059a30(Fighter_15e40 *f);
Body_15e40 *__fastcall FUN_00059a40(Fighter_15e40 *f);

class CSmartPropSpawnAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(int arg);
    virtual void vfunc_8();
    char pad04[0x18];
    void *owner;
    SpawnData *data;
    MatSource_15e40 *source;
};

char CSmartPropSpawnAction::vfunc_7(int arg)
{
    Mat_15e40 result;
    Mat_15e40 parent;
    Mat_15e40 inv;
    Vec3_15e40 pos;
    Vec3_15e40 anchor;
    int p1, p2;

    Fighter_15e40 *fighter = FUN_000592a0(owner);
    Entity *stats = FUN_00059a30(fighter);
    Body_15e40 *body = FUN_00059a40(fighter);
    SkeletonData_15e40 *skel = 0;
    unsigned int joint = 0xffff;
    if (body != 0) {
        skel = body->skeleton;
        if (skel != 0) {
            if ((data->idLo | data->idHi) == 0)
                joint = 0;
            else
                joint = skel->finder->FUN_0027b200(data->idLo, data->idHi);
        }
    }

    p2 = data->p2;
    p1 = data->p1;
    if (data->hasEuler) {
        result.FUN_0022b980();
        result.FUN_0022bc20(data->euler.x, data->euler.y, data->euler.z);
        pos = data->anchor;
        result.m[12] = pos.x;
        result.m[13] = pos.y;
        result.m[14] = pos.z;
    } else {
        if (joint != 0xffff)
            inv = skel->mats[joint];
        else
            stats->FUN_00035160(&inv);
        inv.FUN_0022c120();
        parent = *source->getMat();
        result.FUN_0022ca90(&parent, &inv);
        float s = data->stiffness;
        if (s > 0.0f) {
            pos.x = result.m[12];
            pos.y = result.m[13];
            pos.z = result.m[14];
            anchor = data->anchor;
            pos.x = pos.x - anchor.x;
            pos.y = pos.y - anchor.y;
            pos.z = pos.z - anchor.z;
            if (pos.FUN_0022d110() > s) {
                pos.x = pos.x * s;
                pos.y = pos.y * s;
                pos.z = pos.z * s;
                anchor = data->anchor;
                pos.z = anchor.z + pos.z;
                result.m[14] = pos.z;
                result.m[12] = anchor.x + pos.x;
                result.m[13] = anchor.y + pos.y;
            }
        }
    }
    stats->FUN_0003acf0(data->f90, source, joint, p1, p2, &result);
    return 0;
}
