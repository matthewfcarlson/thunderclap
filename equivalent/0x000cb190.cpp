// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000cb190 @ 0x000cb190
struct Vec3_cb190 { float x, y, z; };

struct Inner_cb190 {
    int FUN_000c93e0(int a, int b, Vec3_cb190 p, Vec3_cb190 q, Vec3_cb190 r);
};

struct Wrapper_cb190 {
    char pad00[0x88];
    Inner_cb190* inner;         // 0x88
    int Forward(int a, int b, Vec3_cb190 p, Vec3_cb190 q, Vec3_cb190 r);
};

int Wrapper_cb190::Forward(int a, int b, Vec3_cb190 p, Vec3_cb190 q, Vec3_cb190 r)
{
    if (inner == 0)
        return -1;
    return inner->FUN_000c93e0(a, b, p, q, r);
}
