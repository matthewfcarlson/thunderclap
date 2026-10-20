// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 0/0)
// FUN_002d1410 @ 0x002d1410
#include "decls/data/game/global.h"

extern "C" double __cdecl atan2(double y, double x);

struct V3_2d1410 {
    float x, y, z;
};

struct Heading_2d1410 {
    V3_2d1410 pos;
    char pad0c[0x14 - 0xc];
    float angle;
    char pad18[4];
    float angleOffset;
};

class Mapper_2d1410 {
public:
    void FUN_002947e0(V3_2d1410 in, V3_2d1410 *out);
};

struct Manager_2d1410 {
    char pad0[8];
    Mapper_2d1410 *mapper;
};

struct Globals_2d1410 {
    Manager_2d1410 *manager;
};


// Sets from->angle to the angle of the mapped vector (from - to) plus from->angleOffset.
void FUN_002d1410(int unused1, int unused2, Heading_2d1410 *from, Heading_2d1410 *to) {
    Mapper_2d1410 *mapper = (*(Globals_2d1410**)&DAT_0052c2b0)->manager->mapper;
    V3_2d1410 a;
    V3_2d1410 b;
    mapper->FUN_002947e0(from->pos, &a);
    mapper->FUN_002947e0(to->pos, &b);
    from->angle = (float)(atan2(a.y - b.y, a.x - b.x) + from->angleOffset);
}
