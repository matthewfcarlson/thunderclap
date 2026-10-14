// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ad2b0 @ 0x001ad2b0
struct Vec3 {
    float x, y, z;
};

struct Source;

struct Accessor {
    Vec3* FUN_001b56a0(Source* src, int index);
};

class Sum3 {
public:
    Source* source;         // 0x00
    int f04;
    float x;                // 0x08
    float y;                // 0x0c
    float z;                // 0x10
    void FUN_001ad2b0(Accessor** acc);
};

void Sum3::FUN_001ad2b0(Accessor** acc)
{
    Vec3* a = (*acc)->FUN_001b56a0(source, 0);
    Vec3* b = (*acc)->FUN_001b56a0(source, 1);
    Vec3* c = (*acc)->FUN_001b56a0(source, 2);
    volatile float y0 = b->y + a->y;
    volatile float z0 = b->z + a->z;
    // every input is read before this is written: a, b and c may point into this
    float nx = (b->x + a->x) + c->x;
    float ny = y0 + c->y;
    float nz = z0 + c->z;
    z = nz;
    x = nx;
    y = ny;
}
