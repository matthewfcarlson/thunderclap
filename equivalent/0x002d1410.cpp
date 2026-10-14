// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1410 @ 0x002d1410
extern "C" double __cdecl atan2(double y, double x);

struct V3 {
    float x, y, z;
};

struct Heading {
    V3 pos;
    char pad0c[0x14 - 0xc];
    float angle;
    char pad18[4];
    float angleOffset;
};

class Mapper {
public:
    void FUN_002947e0(V3 in, V3 *out);
};

struct Manager {
    char pad0[8];
    Mapper *mapper;
};

struct Globals {
    Manager *manager;
};

extern Globals *DAT_0052c2b0;

// Sets from->angle to the angle of the mapped vector (from - to) plus from->angleOffset.
void FUN_002d1410(int unused1, int unused2, Heading *from, Heading *to) {
    Mapper *mapper = DAT_0052c2b0->manager->mapper;
    V3 a;
    V3 b;
    mapper->FUN_002947e0(from->pos, &a);
    mapper->FUN_002947e0(to->pos, &b);
    from->angle = (float)(atan2(a.y - b.y, a.x - b.x) + from->angleOffset);
}
