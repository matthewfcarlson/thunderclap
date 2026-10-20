// STATUS: equivalent (tools/equiv.py level 3: 16764 inputs, branch coverage 4/4)
// pure3d::PrimGroupSkinnedStreamed::vfunc_10 @ 0x002e0560
// 0x002e0560: PrimGroupSkinnedStreamed::vfunc_10: rebuild the bounding box and sphere from the skin points
struct Vec3_2e0560 {
    float x, y, z;
};

struct Sphere_2e0560 {
    float x, y, z, r;
};

struct BBox {
    Vec3_2e0560 lo;
    Vec3_2e0560 hi;
    void FUN_000a87f0(const Vec3_2e0560* p);
    Sphere_2e0560* FUN_000a8890(Sphere_2e0560* out);
};

struct SkinData {
    char pad00[0x20];
    Vec3_2e0560* points;
};
struct SkinHolder_2e0560 {
    char pad00[0x20];
    Vec3_2e0560* points;
};

class PrimGroupSkinnedStreamed_2e0560 {
public:
    char pad00[0x14];
    BBox box;
    Sphere_2e0560 sphere;
    char pad3c[0x10];
    unsigned int count;
    char pad50[0xc];
    SkinHolder_2e0560* skin;
    void FUN_002e0560();
};

void PrimGroupSkinnedStreamed_2e0560::FUN_002e0560()
{
    Sphere_2e0560 tmp;
    const Vec3_2e0560* pts = skin->points;
    box.lo = pts[0];
    box.hi = pts[0];
    for (unsigned int i = 1; i < count; i++)
        box.FUN_000a87f0(&pts[i]);
    const Sphere_2e0560* s = box.FUN_000a8890(&tmp);
    sphere = *s;
}
