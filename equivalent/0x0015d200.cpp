// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 24/24)
// hulkfight::motion::JointPlantedCondition::vfunc_6 @ 0x0015d200
struct Mat_15d200 {
    float m[16];
};

struct BoneEntry_15d200 {
    char pad0[0x10];
    unsigned int *bits;
    char pad14[0x28 - 0x14];
};

struct Finder_15d200 {
    char pad0[0x44];
    BoneEntry_15d200 *begin;
    BoneEntry_15d200 *end;
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton {
    char pad0[8];
    Finder_15d200 *finder;
    char pad0c[0x1c - 0xc];
    Mat_15d200 *matrices;
};

struct Body_15d200 {
    char pad0[0x64];
    Skeleton *skeleton;
    void FUN_00224540(BoneEntry_15d200 *entry, float *out);
};

struct Stats_15d200 {
    char pad0[0x140];
    int mode;
    char pad144[0x1a48 - 0x144];
    float f1a48;
    float f1a4c;
    float f1a50;
    char pad1a54[0x1ad4 - 0x1a54];
    float f1ad4, f1ad8, f1adc;
    float f1ae0, f1ae4, f1ae8;
    float f1aec, f1af0, f1af4;
    float f1af8, f1afc, f1b00;
    char pad1b04[4];
    char f1b08;
};

struct Handle_15d200 {
    Stats_15d200 *FUN_00059a30();
    Body_15d200 *FUN_00059a40();
};

namespace fight {
class Params {
public:
    virtual void p0();
};
}

class CFightParams : public fight::Params {
public:
    Handle_15d200 *FUN_000592a0();
};

namespace hulkfight {
namespace motion {
class JointPlantedCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a1, fight::Params *params, int a3);

    char pad04[0xc];
    unsigned int idLo;
    unsigned int idHi;
    float threshold;
    char expected;
};

bool JointPlantedCondition::vfunc_6(int a1, fight::Params *params, int a3)
{
    if (!dynamic_cast<CFightParams *>(params))
        return false;

    Handle_15d200 *handle = ((CFightParams *)params)->FUN_000592a0();
    Stats_15d200 *stats = handle->FUN_00059a30();
    Body_15d200 *body = handle->FUN_00059a40();
    Skeleton *skel = body->skeleton;
    Finder_15d200 *finder = skel->finder;
    unsigned int id = finder->FUN_0027b200(idLo, idHi);
    if (id == 0xffff)
        return false;

    unsigned int count = (unsigned int)(finder->end - finder->begin);
    BoneEntry_15d200 *e = finder->begin;
    for (unsigned int i = 0; i < count; i++, e++) {
        if (e->bits[(id >> 5) + 1] & (1u << (id & 0x1f))) {
            float v = 0.0f;
            body->FUN_00224540(e, &v);
            return (v > 0.5f) == expected;
        }
    }

    float ax, ay, az, dot;
    if (stats->mode == 4) {
        if (stats->f1b08 == 0) {
            ax = stats->f1ae0;
            ay = stats->f1ae4;
            az = stats->f1ae8;
            dot = (az * stats->f1adc + ay * stats->f1ad8) + ax * stats->f1ad4;
        } else {
            ax = stats->f1af8;
            ay = stats->f1afc;
            az = stats->f1b00;
            dot = (az * stats->f1af4 + ay * stats->f1af0) + ax * stats->f1aec;
        }
    } else {
        ax = 0.0f;
        ay = 1.0f;
        az = 0.0f;
        dot = (stats->f1a50 * 0.0f + stats->f1a48 * 0.0f) + stats->f1a4c;
    }
    float *p = skel->matrices[id].m + 12;
    float val = ((p[2] * az + p[1] * ay) + p[0] * ax) + (-dot);
    return (val < threshold) == expected;
}
}
}
