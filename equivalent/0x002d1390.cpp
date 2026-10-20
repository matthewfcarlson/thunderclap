// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 0/0)
// FUN_002d1390 @ 0x002d1390
#include "decls/data/game/global.h"

extern "C" double __cdecl atan2(double y, double x);

struct V3_2d1390 {
    float x, y, z;
};

struct Heading_2d1390 {
    V3_2d1390 pos;
    char pad0c[0x14 - 0xc];
    float angle;
    char pad18[4];
    float angleOffset;
};

class Mapper_2d1390 {
public:
    void FUN_002947e0(V3_2d1390 in, V3_2d1390 *out);
};

struct Manager_2d1390 {
    char pad0[8];
    Mapper_2d1390 *mapper;
};

struct Globals_2d1390 {
    Manager_2d1390 *manager;
};


// Sets from->angle to the angle of the mapped vector (from - to) plus from->angleOffset.
void FUN_002d1390(int unused1, int unused2, int unused3, int unused4, Heading_2d1390 *from, Heading_2d1390 *to) {
    Mapper_2d1390 *mapper = (*(Globals_2d1390**)&DAT_0052c2b0)->manager->mapper;
    V3_2d1390 a;
    V3_2d1390 b;
    mapper->FUN_002947e0(from->pos, &a);
    mapper->FUN_002947e0(to->pos, &b);
    from->angle = (float)(atan2(a.y - b.y, a.x - b.x) + from->angleOffset);
}
