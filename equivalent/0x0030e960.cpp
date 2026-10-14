// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::CollisionWall::vfunc_8 @ 0x0030e960
// physics::CollisionWall::vfunc_8: per-axis inverse extents, "infinite" (5e8) unless the axis is a unit direction
class CollisionWall {
public:
    char pad00[0x28];
    float inv[3];
    char pad34[4];
    float dir[3];

    void FUN_0030e960();
};

union FloatBits_30e960 {
    float f;
    unsigned int u;
};

void CollisionWall::FUN_0030e960()
{
    FloatBits_30e960 a;
    a.f = dir[0];
    a.u &= 0x7fffffff;
    inv[0] = (1.0f - a.f < 1e-5f) ? 0.0f : 5e8f;
    FloatBits_30e960 b;
    b.f = dir[1];
    b.u &= 0x7fffffff;
    inv[1] = (1.0f - b.f < 1e-5f) ? 0.0f : 5e8f;
    FloatBits_30e960 c;
    c.f = dir[2];
    c.u &= 0x7fffffff;
    inv[2] = (1.0f - c.f < 1e-5f) ? 0.0f : 5e8f;
}
