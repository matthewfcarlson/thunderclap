// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00202460 @ 0x00202460
// FUN_00202460 @ 0x00202460: forwards a point offset along a normalised direction to FUN_00201e00
struct Vec3_202460 {
    float x, y, z;
    float FUN_0022d110();
};

class Mover_202460 {
public:
    void FUN_00201e00(Vec3_202460 *from, Vec3_202460 *to, int a, int b, int c, int d, int e);
    void FUN_00202460(Vec3_202460 *from, Vec3_202460 *direction, float distance, int a, int b, int c, int d, int e);
};

void Mover_202460::FUN_00202460(Vec3_202460 *from, Vec3_202460 *direction, float distance, int a, int b, int c, int d, int e)
{
    Vec3_202460 dir = *direction;
    dir.FUN_0022d110();
    Vec3_202460 to;
    to.x = dir.x * distance + from->x;
    to.y = dir.y * distance + from->y;
    to.z = dir.z * distance + from->z;
    FUN_00201e00(from, &to, a, b, c, d, e);
}
