// STATUS: equivalent (tools/equiv.py level 3: 11965 inputs, branch coverage 10/10)
// hulkfight::motion::PropSpawnAction::vfunc_3 @ 0x001820d0
// cl-flags: /GS
#include "gen/hulkfight.h"
#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"


struct Vec3_1820d0 {
    float x, y, z;
};

struct Mat_1820d0 {
    float m[16];
    void FUN_0022ba00();
    void FUN_0022bc20(Vec3_1820d0 euler);
    void FUN_0022ca90(const Mat_1820d0* a, const Mat_1820d0* b);
    void FUN_0022c3b0(const Vec3_1820d0* in, Vec3_1820d0* out);
    void FUN_0022c2b0(const Vec3_1820d0* in, Vec3_1820d0* out);
};

struct BoneTable_1820d0 {
    char pad0[0x10];
    unsigned int FUN_0027b200(int a, int b);
};

struct Skel_1820d0 {
    char pad0[8];
    BoneTable_1820d0* table;
    char pad0c[0x1c - 0xc];
    Mat_1820d0* matrices;
};

struct Holder_1820d0 {
    char pad0[0x120];
    Skel_1820d0* skel;
};

struct Clock_1820d0 {
    Holder_1820d0* FUN_00059a30();
};

struct Owner_1820d0 {
    Clock_1820d0* FUN_000592a0();
};

struct Config_1820d0 {
    char pad0[0x10];
    int f10;
    char pad14[4];
    int keyA;
    int keyB;
    Vec3_1820d0 pos;
    Vec3_1820d0 rot;
    Vec3_1820d0 dir;
    Vec3_1820d0 pt;
};

struct Spawner_1820d0 {
    void FUN_001e5860(const char* name, int f10, Vec3_1820d0 pos);
    void* FUN_001def30(const char* name);
};

struct Prop_1820d0 {
    char pad0[0xa0];
    void* node;
    void FUN_001d6b60(Mat_1820d0 m, int flag);
    int FUN_001d72e0();
    void FUN_001d7510();
    void FUN_001d86d0(Vec3_1820d0* dir, Vec3_1820d0* pos);
};

struct World {
    char pad0[0xc];
    Spawner_1820d0* spawner;
};


int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);

bool hulkfight::motion::PropSpawnAction::vfunc_3(int a, int b) {
    struct Frame {
        Vec3_1820d0 tmp;
        Vec3_1820d0 dir;
        Vec3_1820d0 pos;
        Mat_1820d0 world;
        Mat_1820d0 local;
        char name[0x80];
    } fr;
    if ((*(Owner_1820d0 * *)&this->f_20)) {
        Holder_1820d0* h = (*(Owner_1820d0 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
        Skel_1820d0* skel = h->skel;
        BoneTable_1820d0* table = skel->table;
        unsigned int bone = 0;
        int keyA = (*(Config_1820d0 * *)&this->f_1c)->keyA;
        int keyB = (*(Config_1820d0 * *)&this->f_1c)->keyB;
        if ((keyA | keyB) != 0) {
            bone = table->FUN_0027b200(keyA, keyB);
            if (bone == 0xffff)
                bone = 0;
        }
        Mat_1820d0* parent = skel->matrices + bone;
        fr.local.FUN_0022ba00();
        fr.tmp = (*(Config_1820d0 * *)&this->f_1c)->pos;
        fr.local.m[12] = fr.tmp.x;
        fr.local.m[13] = fr.tmp.y;
        fr.local.m[14] = fr.tmp.z;
        fr.local.FUN_0022bc20((*(Config_1820d0 * *)&this->f_1c)->rot);
        fr.world.FUN_0022ca90(&fr.local, parent);
        FUN_00267760(fr.name, 0x80, "propSpawn%d", DAT_004e1504);
        Spawner_1820d0* spawner = DAT_004dd700->spawner;
        DAT_004e1504++;
        Vec3_1820d0 where;
        where.x = fr.world.m[12];
        where.y = fr.world.m[13];
        where.z = fr.world.m[14];
        spawner->FUN_001e5860(fr.name, (*(Config_1820d0 * *)&this->f_1c)->f10, where);
        Prop_1820d0* prop = (Prop_1820d0*)spawner->FUN_001def30(fr.name);
        if (prop) {
            prop->FUN_001d6b60(fr.world, 0);
            if (prop->FUN_001d72e0()) {
                prop->FUN_001d7510();
                fr.tmp = (*(Config_1820d0 * *)&this->f_1c)->dir;
                fr.world.FUN_0022c3b0(&fr.tmp, &fr.dir);
                fr.tmp = (*(Config_1820d0 * *)&this->f_1c)->pt;
                fr.world.FUN_0022c2b0(&fr.tmp, &fr.pos);
                prop->FUN_001d86d0(&fr.dir, &fr.pos);
            }
        }
    }
    return false;
}
