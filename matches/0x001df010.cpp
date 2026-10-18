// FUN_001df010 @ 0x001df010
#include "decls/address.h"

struct Mat4_1df010 {
    float m[12];
    int tx, ty, tz;
    float w;
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
};

struct Index_1df010 {
    int FUN_0027b200(unsigned __int64 key);
};

struct Holder_1df010 {
    char pad00[8];
    Index_1df010 *index;
};

struct Part;

struct Actor_1df010 {
    char pad00[0x120];
    Holder_1df010 *holder;
    void FUN_0003acf0(int a, Part *part, int index, int c, int d, Mat4_1df010 *mat);
};

struct Registry_1df010 {
    Actor_1df010 *FUN_00024280(unsigned __int64 id);
};

struct Group_1df010 {
    char pad00[0x20];
    Registry_1df010 *registry;
};

class Owner_1df010 {
public:
    char pad00[0x1e830];
    Group_1df010 *group;
    Part *FUN_001def30(int a);
    void FUN_001df010(int a1, const char *actorName, int a3, const char *partName, int px, int py, int pz,
                      float rx, float ry, float rz);
};

void Owner_1df010::FUN_001df010(int a1, const char *actorName, int a3, const char *partName, int px, int py, int pz,
                         float rx, float ry, float rz)
{
    Registry_1df010 *registry = group->registry;
    Actor_1df010 *actor = registry->FUN_00024280(FUN_002672f0(actorName, 0, 0));
    Part *part = FUN_001def30(a1);
    if (!actor || !part)
        return;
    int index = 0xffff;
    if (actor->holder) {
        Index_1df010 *table = actor->holder->index;
        index = table->FUN_0027b200(FUN_0027b020(partName));
    }
    Mat4_1df010 m;
    m.FUN_0022b980();
    m.FUN_0022bc20(rx * 0.01745329238474369f, ry * 0.01745329238474369f, rz * 0.01745329238474369f);
    m.tx = px;
    m.ty = py;
    m.tz = pz;
    actor->FUN_0003acf0(a3, part, index, 0, 0, &m);
}
