// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000a2de0 @ 0x000a2de0
struct V3_a2de0 {
    float x, y, z;
};

V3_a2de0 *__cdecl FUN_0009f8c0(V3_a2de0 *out, int a, int b, int c);

class Obj_a2de0 {
public:
    char pad0[0x1c4];
    float ox, oy, oz;
    void FUN_000a1930(V3_a2de0 pos, int d);
    void FUN_000a2de0(int a, int b, int c, int d);
};

void Obj_a2de0::FUN_000a2de0(int a, int b, int c, int d)
{
    V3_a2de0 tmp;
    V3_a2de0 *r = FUN_0009f8c0(&tmp, a, b, c);
    V3_a2de0 p;
    p.x = r->x + ox;
    p.y = r->y + oy;
    p.z = r->z + oz;
    FUN_000a1930(p, d);
}
