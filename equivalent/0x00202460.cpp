// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00202460 @ 0x00202460
// FUN_00202460 @ 0x00202460: forwards a point offset along a normalised direction to FUN_00201e00
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

class Mover {
public:
    void FUN_00201e00(Vec3 *from, Vec3 *to, int a, int b, int c, int d, int e);
    void FUN_00202460(Vec3 *from, Vec3 *direction, float distance, int a, int b, int c, int d, int e);
};

void Mover::FUN_00202460(Vec3 *from, Vec3 *direction, float distance, int a, int b, int c, int d, int e)
{
    Vec3 dir = *direction;
    dir.FUN_0022d110();
    Vec3 to;
    to.x = dir.x * distance + from->x;
    to.y = dir.y * distance + from->y;
    to.z = dir.z * distance + from->z;
    FUN_00201e00(from, &to, a, b, c, d, e);
}
