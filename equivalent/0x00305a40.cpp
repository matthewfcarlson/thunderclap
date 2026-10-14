// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00305a40 @ 0x00305a40
struct Vec3 { float x, y, z; };
int __cdecl FUN_00305a40(const Vec3* v, unsigned char absolute)
{
    float x=v->x, y=v->y, z=v->z;
    if (absolute) {
        union Bits { float f; unsigned int u; } a,b,c;
        a.f=x; b.f=y; c.f=z;
        a.u &= 0x7fffffff; b.u &= 0x7fffffff; c.u &= 0x7fffffff;
        x=a.f; y=b.f; z=c.f;
    }
    if (x > y) return x > z ? 0 : 2;
    return y > z ? 1 : 2;
}