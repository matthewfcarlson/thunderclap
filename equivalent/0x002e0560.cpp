// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 4/4)
// pure3d::PrimGroupSkinnedStreamed::vfunc_10 @ 0x002e0560
// 0x002e0560: PrimGroupSkinnedStreamed::vfunc_10: rebuild the bounding box and sphere from the skin points
struct Vec3 {
    float x, y, z;
};

struct Sphere {
    float x, y, z, r;
};

struct BBox {
    Vec3 lo;
    Vec3 hi;
    void FUN_000a87f0(const Vec3* p);
    Sphere* FUN_000a8890(Sphere* out);
};

struct SkinData {
    char pad00[0x20];
    Vec3* points;
};
struct SkinHolder {
    char pad00[0x20];
    Vec3* points;
};

class PrimGroup {
public:
    char pad00[0x14];
    BBox box;
    Sphere sphere;
    char pad3c[0x10];
    unsigned int count;
    char pad50[0xc];
    SkinHolder* skin;
    void FUN_002e0560();
};

void PrimGroup::FUN_002e0560()
{
    Sphere tmp;
    const Vec3* pts = skin->points;
    box.lo = pts[0];
    box.hi = pts[0];
    for (unsigned int i = 1; i < count; i++)
        box.FUN_000a87f0(&pts[i]);
    const Sphere* s = box.FUN_000a8890(&tmp);
    sphere = *s;
}
