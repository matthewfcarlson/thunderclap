// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000cb190 @ 0x000cb190
struct Vec3 { float x, y, z; };

struct Inner {
    int FUN_000c93e0(int a, int b, Vec3 p, Vec3 q, Vec3 r);
};

struct Wrapper {
    char pad00[0x88];
    Inner* inner;         // 0x88
    int Forward(int a, int b, Vec3 p, Vec3 q, Vec3 r);
};

int Wrapper::Forward(int a, int b, Vec3 p, Vec3 q, Vec3 r)
{
    if (inner == 0)
        return -1;
    return inner->FUN_000c93e0(a, b, p, q, r);
}
