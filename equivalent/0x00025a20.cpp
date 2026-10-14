// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00025a20 @ 0x00025a20
struct Vec3I { int x, y, z; };
struct Params {
    char pad00[0xc];
    int state;          // 0x0c
    char pad10[0x48 - 0x10];
    int a;              // 0x48
    int b;              // 0x4c
    Vec3I v0;           // 0x50
    Vec3I v1;           // 0x5c
    int lo;             // 0x68
    int hi;             // 0x6c
    void Set(int a, int b, const Vec3I* v0, const Vec3I* v1, float lo, float hi);
};
void Params::Set(int a_, int b_, const Vec3I* p0, const Vec3I* p1, float lo_, float hi_)
{
    a = a_;
    b = b_;
    state = 0;
    v0 = *p0;
    v1 = *p1;
    lo = reinterpret_cast<int&>(lo_);
    if (lo_ >= hi_)
        hi = reinterpret_cast<int&>(lo_);
    else
        hi = reinterpret_cast<int&>(hi_);
}
