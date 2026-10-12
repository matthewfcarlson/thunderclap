// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 14/14)
// hulkfight::motion::JointRelativeAction::vfunc_3 @ 0x001714b0
struct Vec3 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct Quat {
    float x, y, z, w;
    void FUN_0022b370(const Matrix* m);
    void FUN_0022b220(float x, float y, float z);
};

void FUN_0022b080(Quat* out, Quat* a, Quat* b);
void* FUN_00263ea0(unsigned int size);

struct NameField {
    void FUN_0027b040(const char* s);
};

struct Xform {
    char data[0x54];
    void FUN_00221cf0(const Quat* q);
    void FUN_0022be40(const Vec3* p);
};

class JointDriver {
public:
    virtual void AddRef();
    char pad04[4];
    NameField name;
    char pad0c[4];
    int jointIndex;
    int flags;
    Xform xform;
    JointDriver* FUN_002248a0();
};

struct Anim;

struct Anim {
    char pad00[0x14];
    Quat* bindQuats;
    Matrix* bindPoses;
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton {
    char pad00[8];
    Anim* anim;
    char pad0c[8];
    Matrix* matrices;
};

struct Player {
    char pad00[0x120];
    Skeleton* skeleton;
};

struct Tracker {
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};

struct Clock {
    Player* FUN_00059a30();
    Tracker* FUN_00059a40();
};

struct Target {
    Clock* FUN_000592a0();
};

struct Config {
    char pad00[0x18];
    unsigned int nameLo;
    unsigned int nameHi;
    char useBind;
    char flag21;
    char pad22[2];
    Vec3 offset;
    char flag30;
    char pad31[3];
    Vec3 scale;
    float limitA;
    float limitB;
    float limitC;
};

namespace hulkfight {
namespace motion {

class JointRelativeAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    virtual void v4();
    virtual void v5();

    char pad04[0x1c - 4];
    Config* cfg;
    Target* owner;
    JointDriver* driver;
    Quat jointRot;
    Vec3 jointPos;
    Quat relRot;
    Vec3 relPos;
};

bool JointRelativeAction::vfunc_3(int a, int b)
{
    Clock* clock = owner->FUN_000592a0();
    Player* player = clock->FUN_00059a30();
    Tracker* tracker = clock->FUN_00059a40();
    if (tracker == 0)
        return false;

    Config* c = cfg;
    Skeleton* skel = player->skeleton;
    Anim* anim = skel->anim;
    int idx = 0;
    if ((c->nameLo | c->nameHi) != 0) {
        idx = anim->FUN_0027b200(c->nameLo, c->nameHi);
        if (idx == 0xffff)
            idx = 0;
    }

    Vec3 unused;
    Matrix m = skel->matrices[idx];
    jointRot.FUN_0022b370(&m);
    jointPos.x = m.m[12];
    jointPos.y = m.m[13];
    jointPos.z = m.m[14];

    Vec3 s = cfg->scale;
    relRot.FUN_0022b220(s.x, s.y, s.z);
    unused = cfg->offset;
    relPos = unused;

    if (cfg->useBind) {
        FUN_0022b080(&relRot, &relRot, &anim->bindQuats[idx]);
        const Vec3* t = (const Vec3*)((char*)anim->bindPoses + idx * 64 + 0x30);
        relPos.x = t->x + relPos.x;
        relPos.y = t->y + relPos.y;
        relPos.z = t->z + relPos.z;
    } else {
        FUN_0022b080(&relRot, &relRot, &jointRot);
        relPos.x = jointPos.x + relPos.x;
        relPos.y = jointPos.y + relPos.y;
        relPos.z = jointPos.z + relPos.z;
    }

    void* mem = FUN_00263ea0(0x70);
    JointDriver* d = 0;
    if (mem)
        d = ((JointDriver*)mem)->FUN_002248a0();
    driver = d;
    d->name.FUN_0027b040("jointRelative");
    driver->AddRef();
    driver->jointIndex = idx;
    driver->xform.FUN_00221cf0(&jointRot);
    driver->xform.FUN_0022be40(&jointPos);
    int flags = 0;
    if (cfg->flag21)
        flags = 1;
    if (cfg->flag30)
        flags |= 2;
    driver->flags = flags;
    tracker->FUN_00222890(driver, -1.0f, cfg->limitA, 1.0f, cfg->limitB, cfg->limitC, -1.0f);
    return true;
}

}
}
