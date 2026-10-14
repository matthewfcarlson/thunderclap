// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022b4d0 @ 0x0022b4d0
struct Vec3_22b4d0 {
    float x, y, z;
};

struct Quat_22b4d0 {
    float x, y, z, w;
    void Rotate(const Vec3_22b4d0 *v, Vec3_22b4d0 *out);
};

void __cdecl FUN_0022b080(Quat_22b4d0 *out, const Quat_22b4d0 *a, const Quat_22b4d0 *b);

void Quat_22b4d0::Rotate(const Vec3_22b4d0 *v, Vec3_22b4d0 *out)
{
    Quat_22b4d0 tmp;
    Quat_22b4d0 vec;
    vec.x = v->x;
    vec.y = v->y;
    vec.z = v->z;
    vec.w = 0;
    FUN_0022b080(&tmp, this, &vec);
    vec.x = -x;
    vec.y = -y;
    vec.z = -z;
    vec.w = w;
    FUN_0022b080(&tmp, &tmp, &vec);
    out->x = tmp.x;
    out->y = tmp.y;
    out->z = tmp.z;
}
