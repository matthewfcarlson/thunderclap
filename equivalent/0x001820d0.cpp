// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 10/10)
// hulkfight::motion::PropSpawnAction::vfunc_3 @ 0x001820d0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

struct Vec3 {
    float x, y, z;
};

struct Mat {
    float m[16];
    void FUN_0022ba00();
    void FUN_0022bc20(Vec3 euler);
    void FUN_0022ca90(const Mat* a, const Mat* b);
    void FUN_0022c3b0(const Vec3* in, Vec3* out);
    void FUN_0022c2b0(const Vec3* in, Vec3* out);
};

struct BoneTable {
    char pad0[0x10];
    unsigned int FUN_0027b200(int a, int b);
};

struct Skel {
    char pad0[8];
    BoneTable* table;
    char pad0c[0x1c - 0xc];
    Mat* matrices;
};

struct Holder {
    char pad0[0x120];
    Skel* skel;
};

struct Clock {
    Holder* FUN_00059a30();
};

struct Owner {
    Clock* FUN_000592a0();
};

struct Config {
    char pad0[0x10];
    int f10;
    char pad14[4];
    int keyA;
    int keyB;
    Vec3 pos;
    Vec3 rot;
    Vec3 dir;
    Vec3 pt;
};

struct Spawner {
    void FUN_001e5860(const char* name, int f10, Vec3 pos);
    void* FUN_001def30(const char* name);
};

struct Prop {
    char pad0[0xa0];
    void* node;
    void FUN_001d6b60(Mat m, int flag);
    int FUN_001d72e0();
    void FUN_001d7510();
    void FUN_001d86d0(Vec3* dir, Vec3* pos);
};

struct World {
    char pad0[0xc];
    Spawner* spawner;
};

extern World* DAT_004dd700;
extern int DAT_004e1504;

int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);

class PropSpawnAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad4[0x1c - 4];
    Config* cfg;
    Owner* owner;
};

bool PropSpawnAction::vfunc_3(int a, int b)
{
    volatile unsigned int cookie = DAT_004d9968;
    struct Frame {
        Vec3 tmp;
        Vec3 dir;
        Vec3 pos;
        Mat world;
        Mat local;
        char name[0x80];
    } fr;
    if (owner) {
        Holder* h = owner->FUN_000592a0()->FUN_00059a30();
        Skel* skel = h->skel;
        BoneTable* table = skel->table;
        unsigned int bone = 0;
        int keyA = cfg->keyA;
        int keyB = cfg->keyB;
        if ((keyA | keyB) != 0) {
            bone = table->FUN_0027b200(keyA, keyB);
            if (bone == 0xffff)
                bone = 0;
        }
        Mat* parent = skel->matrices + bone;
        fr.local.FUN_0022ba00();
        fr.tmp = cfg->pos;
        fr.local.m[12] = fr.tmp.x;
        fr.local.m[13] = fr.tmp.y;
        fr.local.m[14] = fr.tmp.z;
        fr.local.FUN_0022bc20(cfg->rot);
        fr.world.FUN_0022ca90(&fr.local, parent);
        FUN_00267760(fr.name, 0x80, "propSpawn%d", DAT_004e1504);
        Spawner* spawner = DAT_004dd700->spawner;
        DAT_004e1504++;
        Vec3 where;
        where.x = fr.world.m[12];
        where.y = fr.world.m[13];
        where.z = fr.world.m[14];
        spawner->FUN_001e5860(fr.name, cfg->f10, where);
        Prop* prop = (Prop*)spawner->FUN_001def30(fr.name);
        if (prop) {
            prop->FUN_001d6b60(fr.world, 0);
            if (prop->FUN_001d72e0()) {
                prop->FUN_001d7510();
                fr.tmp = cfg->dir;
                fr.world.FUN_0022c3b0(&fr.tmp, &fr.dir);
                fr.tmp = cfg->pt;
                fr.world.FUN_0022c2b0(&fr.tmp, &fr.pos);
                prop->FUN_001d86d0(&fr.dir, &fr.pos);
            }
        }
    }
    __security_check_cookie(cookie);
    return false;
}
